#include <iostream>

#include "define.h"
#include "systemc.h"

using namespace std;

SC_MODULE(Conv_2) {
    sc_in_clk clk;
    sc_in<bool> rst;

    sc_in<bool> conv_2_en;
    sc_out<bool> pool_2_en;

    sc_out<bool> rom_rd;
    sc_out<sc_uint<16> > rom_addr;
    sc_in<DATA_TYPE> rom_data_out;

    const int offset_1[25] = {0,  1,  2,   3,   4,   28,  29, 30, 31,
                              32, 56, 57,  58,  59,  60,  84, 85, 86,
                              87, 88, 112, 113, 114, 115, 116};
    const int sixto16[16][6] = {
        {1, 1, 1, 0, 0, 0}, {0, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 1},

        {1, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 1}, {1, 1, 0, 0, 1, 1}, {1, 1, 1, 0, 0, 1},

        {1, 1, 0, 1, 1, 0}, {0, 1, 1, 0, 1, 1}, {1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1},
    };

    sc_out<bool> ram_wr;
    sc_out<sc_uint<16> > ram_addr;
    sc_in<DATA_TYPE> ram_data_out;
    sc_out<DATA_TYPE> ram_data_in;

    void run();
    void calc();
    DATA_TYPE input[864], ans[1024], filter[2400], bias[16];
    bool flag, read_weight_state, output_state;

    SC_CTOR(Conv_2) {
        SC_METHOD(run);
        sensitive << rst.pos() << clk.neg();
    }
};
