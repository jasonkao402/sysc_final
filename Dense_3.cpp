#include "Dense_3.h"

#include "define.h"

void Dense_3::calc(int idx) {
    float sum = bias;
    for (int i = 0; i < 84; i++) {
        sum += weight[i] * input[i];
    }
    ans[idx] = sum;
}

void Dense_3::run() {
    if (rst) {
        flag = 1;
        output_state = 0;
        output_index = 0;
        read_weight_state = 0;
    } else {
        if (dense_3_en.read()) {
            int romAddr = rom_addr.read();
            int ramAddr = ram_addr.read();
            DATA_TYPE data = ram_data_out.read();
            if (flag) {
                output_valid.write(0);
                ram_wr.write(1);
                ram_addr.write(0);
                flag = 0;
            } else if (output_state) {
                if (output_index < 10) {
                    result.write(ans[output_index]);
                    output_index++;
                }
            } else if (read_weight_state) {
                DATA_TYPE romdata = rom_data_out.read();
                if (romAddr < 44426) {
                    int index = (romAddr - 43576) % 85;
                    if (index == 84) {
                        bias = romdata;
                        calc((romAddr - 43576) / 85);
                    } else {
                        weight[index] = romdata;
                    }
                    rom_addr.write(romAddr + 1);
                } else {
                    output_state = 1;
                    output_valid.write(1);
                }
            } else {
                if (ramAddr <= 83) {
                    input[ramAddr] = data;
                    if (ramAddr == 83) {
                        rom_rd.write(1);
                        rom_addr.write(43576);
                        read_weight_state = 1;
                    } else
                        ram_addr.write(ramAddr + 1);
                }
            }
        }
    }
}
