#include "Dense_2.h"

#include "define.h"

void Dense_2::calc(int idx) {
    MUL_DATA_TYPE sum = bias;
    for (int i = 0; i < 120; i++) {
        sum += weight[i] * input[i];
    }
    if(sum >= 0)
        ans[idx] = sum;
    else
        ans[idx] = 0;
}

void Dense_2::run() {
    if (rst) {
        flag = 1;
        output_state = 0;
        read_weight_state = 0;
        output_index = 0;
    } else {
        if (dense_2_en.read()) {
            int romAddr = rom_addr.read();
            int ramAddr = ram_addr.read();
            DATA_TYPE data = ram_data_out.read();
            if (flag) {
                dense_3_en.write(0);
                ram_wr.write(1);
                ram_addr.write(0);
                flag = 0;
            } else if (dense_3_en.read()) {
                return;
            } else if (output_state) {
                if (output_index < 84) {
                    ram_addr.write(output_index);
                    #ifdef fixed_DATA_TYPE
                        ram_data_in.write(ans[output_index].range(25,10));
                    #else
                        ram_data_in.write(ans[output_index]);
                    #endif
                    
                    // cout<<"Dense_2: "<<output_index<<'
                    // '<<ans[output_index]<<'\n';
                    output_index++;
                } else {
                    dense_3_en.write(1);
                }
            } else if (read_weight_state) {
                DATA_TYPE romdata = rom_data_out.read();
                if (romAddr < 43576) {
                    int index = (romAddr - 33412) % 121;
                    if (index == 120) {
                        bias = romdata;
                        calc((romAddr - 33412) / 121);
                    } else {
                        weight[index] = romdata;
                    }
                    rom_addr.write(romAddr + 1);
                } else {
                    output_state = 1;
                    ram_wr.write(0);
                    ram_addr.write(0);
                }
            } else {
                if (ramAddr <= 0) {
                    ram_addr.write(ramAddr + 1);
                } else if (ramAddr - 1 <= 119) {
                    input[ramAddr - 1] = data;
                    // cout<<"Dense_2: "<<ramAddr-1 <<' '<<data<<'\n';
                    if (ramAddr - 1 == 119) {
                        rom_addr.write(33412);
                        rom_rd.write(1);
                        read_weight_state = 1;
                    } else
                        ram_addr.write(ramAddr + 1);
                }
            }
        }
    }
}
