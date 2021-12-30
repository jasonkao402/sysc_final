#include "Dense_1.h"

#include "define.h"

void Dense_1::flaten() {
    for (int i = 0; i < 256; i++) {
        flat[i] = input[(i % 16) * 16 + i / 16];
    }
}
void Dense_1::calc(int idx) {
    MUL_DATA_TYPE sum = bias;
    for (int i = 0; i < 256; i++)
        sum += weight[i] * flat[i];
    if(sum >= 0)
        ans[idx] = sum;
    else
        ans[idx] = 0;
}

void Dense_1::run() {
    if (rst) {
        flag = 1;
        output_state = 0;
        read_weight_state = 0;
        output_index = 0;
    } else {
        if (dense_1_en.read()) {
            int romAddr = rom_addr.read();
            int ramAddr = ram_addr.read();
            DATA_TYPE data = ram_data_out.read();
            if (flag) {
                dense_2_en.write(0);
                ram_wr.write(1);
                ram_addr.write(0);
                flag = 0;
            } else if (dense_2_en.read()) {
                return;
            } else if (output_state) {
                if (output_index < 120) {
                    ram_addr.write(output_index);
                    #ifdef fixed_DATA_TYPE
                        ram_data_in.write(ans[output_index].range(25,10));
                    #else
                        ram_data_in.write(ans[output_index]);
                    #endif
                    
                    // cout<<"Dense_1: "<<output_index<<'
                    // '<<ans[output_index]<<'\n';
                    output_index++;
                } else {
                    dense_2_en.write(1);
                }
            } else if (read_weight_state) {
                DATA_TYPE romdata = rom_data_out.read();
                if (romAddr < 33412) {
                    int index = (romAddr - 2572) % 257;
                    if (index == 256) {
                        bias = romdata;
                        calc((romAddr - 2572) / 257);
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
                } else if (ramAddr - 1 <= 255) {
                    input[ramAddr - 1] = data;
                    //cout<<"Dense_1: "<<ramAddr-1<<' '<<data<<'\n';
                    if (ramAddr - 1 == 255) {
                        flaten();
                        rom_addr.write(2572);
                        rom_rd.write(1);
                        read_weight_state = 1;
                    } else
                        ram_addr.write(ramAddr + 1);
                }
            }
        }
    }
}
