#include "Conv_2.h"

#include "define.h"

void Conv_2::calc() {
    MUL_DATA_TYPE tmp;
    for (int r = 0, s = 0, i, j, k; s < 16; s++) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                // calc
                for (tmp = bias[s], r = 0; r < 6; r++) {
                    for (k = 0; k < 25; k++) {
                        tmp += sixto16[s][r] * filter[150 * s + r * 25 + k] *
                               input[144 * r + i * 12 + j + offset_2[k]];
                    }
                }
                //cout<<s<<' '<<i<<' '<<j<<' '<<tmp<<'\n';
                if( tmp >= 0)ans[64 * s + i * 8 + j] = tmp;
                else ans[64 * s + i * 8 + j] = 0;
            }
        }
    }
}

void Conv_2::run() {
    if (rst) {
        flag = 1;
        output_index = 0;
        read_weight_state = 0;
        output_state = 0;
    } else {
        if (conv_2_en.read()) {
            int romAddr = rom_addr.read(), ramAddr = ram_addr.read();
            DATA_TYPE data = ram_data_out.read();
            if (flag) {
                pool_2_en.write(0);
                rom_rd.write(1);
                rom_addr.write(0);

                ram_wr.write(1);
                ram_addr.write(0);
                flag = 0;
            } else if (pool_2_en.read()) {
                return;
            } else if (output_state) {
                if (output_index < 1024) {
                    ram_addr.write(output_index);
                    #ifdef fixed_DATA_TYPE
                        ram_data_in.write(ans[output_index].range(25,10));
                    #else
                        ram_data_in.write(ans[output_index]);
                    #endif
                    
                    //cout<<"Conv2: "<<output_index<<' '<<ans[output_index].range(25,10)<<'\n';
                    output_index++;
                } else
                    pool_2_en.write(1);
            } else if (read_weight_state) {
                DATA_TYPE romdata = rom_data_out.read();
                if (romAddr < 2572) {
                    int index = romAddr - 156;
                    if ((index + 1) % 151 == 0) {
                        bias[index / 151] = romdata;
                    } else {
                        filter[index - index / 151] = romdata;
                    }
                    rom_addr.write(romAddr + 1);
                } else {
                    calc();
                    output_state = 1;
                    ram_wr.write(0);
                    ram_addr.write(0);
                }
            } else {
                if (ramAddr <= 0) {
                    ram_addr.write(ramAddr + 1);
                } else if (ramAddr - 1 <= 863) {
                    input[ramAddr - 1] = data;
                    if (ramAddr - 1 == 863) {
                        rom_addr.write(156);
                        rom_rd.write(1);
                        read_weight_state = 1;
                    } else
                        ram_addr.write(ramAddr + 1);
                }
            }
        }
    }
}
