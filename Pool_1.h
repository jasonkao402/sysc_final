#include <iostream>

#include "define.h"
#include "systemc.h"

using namespace std;

SC_MODULE(Pool_1) {
    sc_in_clk clk;
    sc_in<bool> rst;

    sc_out<bool> ram_wr;
    sc_out<sc_uint<16> > ram_addr;
    sc_in<DATA_TYPE> ram_data_out;
    sc_out<DATA_TYPE> ram_data_in;

    sc_in<bool> pool_1_en;
    sc_out<bool> conv_2_en;

    void calc();
    void run();
    DATA_TYPE input[3456], ans[864];
    bool flag, output_state;
    int output_index;

    SC_CTOR(Pool_1) {
        SC_METHOD(run);
        sensitive << rst.pos() << clk.neg();
    }
};
