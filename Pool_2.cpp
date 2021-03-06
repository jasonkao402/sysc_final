#include "Pool_2.h"

#include <math.h>

#include "define.h"

void Pool_2::calc() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j += 2) {
            for (int k = 0; k < 8; k += 2) {
                // max(a,b) may cause error
                ans[16 * i + 4 * (j / 2) + (k / 2)] =
                    max(input[64 * i + 8 * j + k],
                        max(input[64 * i + 8 * j + k + 1],
                            max(input[64 * i + 8 * (j + 1) + k],
                                input[64 * i + 8 * (j + 1) + k + 1])));
            }
        }
    }
}

void Pool_2::run() {
    if (rst) {
        flag = 1;
        output_index = 0;
        output_state = 0;
    } else {
        if (pool_2_en.read()) {
            int ramAddr = ram_addr.read();
            DATA_TYPE data = ram_data_out.read();
            if (flag) {
                dense_1_en.write(0);
                ram_wr.write(1);
                ram_addr.write(0);
                flag = 0;
            } else if (dense_1_en.read()) {
                return;
            } else if (output_state) {
                if (output_index < 256) {
                    ram_addr.write(output_index);
                    ram_data_in.write(ans[output_index]);
                    // cout<<"Pool_2: "<<output_index<<'
                    // '<<ans[output_index]<<'\n';
                    output_index++;
                } else {
                    dense_1_en.write(1);
                }
            } else {
                if (ramAddr <= 0) {
                    ram_addr.write(ramAddr + 1);
                } else if (ramAddr - 1 <= 1023) {
                    input[ramAddr - 1] = data;
                    // cout<<"Pool_2: "<<ramAddr-1<<' '<<data<<'\n';
                    if (ramAddr - 1 == 1023) {
                        calc();
                        ram_addr.write(0);
                        ram_wr.write(0);
                        output_state = 1;
                    } else
                        ram_addr.write(ramAddr + 1);
                }
            }
        }
    }
}
