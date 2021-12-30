#include "Pool_1.h"

#include <math.h>

#include "define.h"

void Pool_1::calc() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 24; j += 2) {
            for (int k = 0; k < 24; k += 2) {
                // max(a,b) may cause error
                ans[144 * i + 12 * (j / 2) + (k / 2)] =
                    max(input[576 * i + 24 * j + k],
                        max(input[576 * i + 24 * j + k + 1],
                            max(input[576 * i + 24 * (j + 1) + k],
                                input[576 * i + 24 * (j + 1) + k + 1])));
            }
        }
    }
}

void Pool_1::run() {
    if (rst) {
        flag = 1;
        output_state = 0;
        output_index = 0;
    } else {
        if (pool_1_en.read()) {
            int ramAddr = ram_addr.read();
            DATA_TYPE data = ram_data_out.read();
            if (flag) {
                conv_2_en.write(0);
                ram_wr.write(1);
                ram_addr.write(0);
                flag = 0;
            } else if (conv_2_en.read()) {
                return;
            } else if (output_state) {
                if (output_index < 864) {
                    ram_addr.write(output_index);
                    ram_data_in.write(ans[output_index]);
                    //cout<<output_index<<' '<<ans[output_index]<<'\n';
                    output_index++;
                } else {
                    conv_2_en.write(1);
                }
            } else {
                if (ramAddr <= 0) {
                    ram_addr.write(ramAddr + 1);
                } else if (ramAddr - 1 <= 3455) {
                    input[ramAddr - 1] = data;
                    if (ramAddr - 1 == 3455) {
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
