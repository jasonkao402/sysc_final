#ifndef DENSE2_H
#define DENSE2_H
#include <iostream>

#include "define.h"
#include "systemc.h"

using namespace std;

SC_MODULE(Dense_2) {
    sc_in_clk clk;
    sc_in<bool> rst;

    sc_out<bool> rom_rd;
    sc_out<sc_uint<16> > rom_addr;
    sc_in<DATA_TYPE> rom_data_out;

    sc_out<bool> ram_wr;
    sc_out<sc_uint<16> > ram_addr;
    sc_in<DATA_TYPE> ram_data_out;
    sc_out<DATA_TYPE> ram_data_in;

    sc_in<bool> dense_2_en;
    sc_out<bool> dense_3_en;

    void calc(int);
    void run();

    DATA_TYPE input[120], ans[84], weight[120], bias;
    bool flag, output_state, read_weight_state;
    int output_index;

    SC_CTOR(Dense_2) {
        SC_METHOD(run);
        sensitive << rst.pos() << clk.neg();
    }
};
#endif