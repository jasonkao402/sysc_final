#include "Dense_2.h"

#include "define.h"

void Dense_1::calc(int idx) {
    float sum = bias;
    for (int i = 0; i < 120; i++) {
        sum += weight[i] * flat[i];
    }
    ans[idx] = sum;
}

void Dense_1::run() {
    if (rst) {
        flag = 1;
        output_state = 0;
        read_weight_state = 0;
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
                if (ramAddr < 84) {
                    ram_data_in.write(ans[ramAddr]);
                    ram_addr.write(ramAddr + 1);
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
                if (ramAddr <= 119) {
                    input[ramAddr] = data;
                    if (ramAddr == 119) {
                        rom_addr.write(33412);
                        rom_wr.write(1);
                        read_weight_state = 1;
                    } else
                        ram_addr.write(ramAddr + 1);
                }
            }
        }
    }
}
