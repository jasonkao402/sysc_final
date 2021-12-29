#ifndef POOL2_H
#define POOL2_H
#include <iostream>

#include "define.h"
#include "systemc.h"

using namespace std;

SC_MODULE(Pool_2) {
    sc_in_clk clk;
    sc_in<bool> rst;

    sc_out<bool> ram_wr;
    sc_out<sc_uint<16> > ram_addr;
    sc_in<DATA_TYPE> ram_data_out;
    sc_out<DATA_TYPE> ram_data_in;

    sc_in<bool> pool_2_en;
    sc_out<bool> dense_1_en;

    void calc();
    void run();

    DATA_TYPE input[1024], ans[256];
    bool flag, output_state;
    int output_index;

    SC_CTOR(Pool_2) {
        SC_METHOD(run);
        sensitive << rst.pos() << clk.neg();
    }
};
#endif