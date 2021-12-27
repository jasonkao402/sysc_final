#include "Dense_1.h"

#include "define.h"

void Dense_1::flat() {
    for (int i = 0; i < 256; i++) {
        flat[i] = input[(i % 16) * 16 + i / 16];
    }
}
void Dense_1::calc(int idx) {
    float sum = bias;
    for (int i = 0; i < 256; i++) {
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
                if (ramAddr < 120) {
                    ram_data_in.write(ans[ramAddr]);
                    ram_addr.write(ramAddr + 1);
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
                if (ramAddr <= 255) {
                    input[ramAddr] = data;
                    if (ramAddr == 255) {
                        flat();
                        rom_addr.write(2572);
                        rom_wr.write(1);
                        read_weight_state = 1;
                    } else
                        ram_addr.write(ramAddr + 1);
                }
            }
        }
    }
}
