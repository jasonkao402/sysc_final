#include <iostream>

#include "define.h"
#include "systemc.h"

using namespace std;

SC_MODULE(Conv_1) {
    sc_in_clk clk;
    sc_in<bool> rst;

    sc_out<bool> rom_rd;
    sc_out<sc_uint<16> > rom_addr;
    sc_in<DATA_TYPE> rom_data_out;

    sc_out<bool> ram_wr;
    sc_out<sc_uint<16> > ram_addr;
    sc_out<DATA_TYPE> ram_data_in;

    sc_out<bool> pool_1_en;

    void run();
    void calc(int, int);
    DATA_TYPE input[784], ans[3456], filter[150], bias[6];
    bool flag, output_state, stop;

    SC_CTOR(Conv_1) {
        SC_METHOD(run);
        sensitive << rst.pos() << clk.neg();
    }
};
