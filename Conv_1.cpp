#include "Conv_1.h"

#include "define.h"

void Conv_1::calc(int x, int y) {
    if (y > 23) {
        y = 0;
        x++;
    }
    if (x > 23) return;
    for (int i = 0; i < 6; i++) {
        float sum = bias[i];
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                sum +=
                    input[28 * x + y + 28 * j + k] * filter[25 * i + 5 * j + k];
        ans[576 * i + 24 * x + y] = (sum >= 0 ? sum : 0);
    }
    calc(x, y + 1);
}

void Conv_1::run() {
    if (rst) {
        flag = 1;
        output_state = 0;
        output_index = 0;
    } else {
        int romAddr = rom_addr.read(), ramAddr = ram_addr.read();
        DATA_TYPE data = rom_data_out.read();
        if (flag) {
            pool_1_en.write(0);
            rom_rd.write(1);
            rom_addr.write(0);

            ram_wr.write(0);
            ram_addr.write(0);
            flag = 0;
        } else if (pool_1_en.read()) {
            return;
        } else if (output_state) {
            if (output_index < 3456) {
                ram_addr.write(output_index);
                ram_data_in.write(ans[output_index]);
                // cout<<"Conv_1: "<<output_index<<' '<<ans[output_index]<<'\n';
                output_index++;
                ram_wr.write(0);
            } else
                pool_1_en.write(1);
        } else if (romAddr <= 155) {
            if ((romAddr + 1) % 26 == 0) {
                bias[romAddr / 26] = data;
            } else {
                filter[romAddr - romAddr / 26] = data;
            }
            if (romAddr == 155)
                rom_addr.write(44426);
            else
                rom_addr.write(romAddr + 1);
        } else {
            input[romAddr - 44426] = data;
            if (romAddr == 45209) {
                calc(0, 0);
                output_state = 1;
                ram_addr.write(0);
                ram_wr.write(0);
            } else
                rom_addr.write(romAddr + 1);
        }
    }
}
