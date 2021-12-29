#include <iostream>

#include "Conv_1.h"
#include "Conv_2.h"
#include "Dense_1.h"
#include "Dense_2.h"
#include "Dense_3.h"
#include "Pool_1.h"
#include "Pool_2.h"
#include "RAM.h"
#include "ROM.h"
#include "define.h"
#include "systemc.h"

using namespace std;

// vvvvv put your code here vvvvv
SC_MODULE(LeNet) {
    sc_in_clk clk;
    sc_in<bool> rst;

    sc_out<bool> rom_rd;
    sc_out<sc_uint<16> > rom_addr;
    sc_in<DATA_TYPE> rom_data_out;

    sc_out<bool> ram_wr;
    sc_out<sc_uint<16> > ram_addr;
    sc_in<DATA_TYPE> ram_data_out;
    sc_out<DATA_TYPE> ram_data_in;

    sc_out<DATA_TYPE> result;
    sc_out<bool> output_valid;
    Conv_1* conv_1;
    Conv_2* conv_2;
    Pool_1* pool_1;
    Pool_2* pool_2;
    Dense_1* dense_1;
    Dense_2* dense_2;
    Dense_3* dense_3;

    sc_port<bool> pool_1_en, conv_2_en, pool_2_en, dense_1_en, dense_2_en,
        dense_3_en;

    void run();

    SC_CTOR(LeNet) {
        (*conv_1)(clk, rst, rom_rd, rom_addr, rom_data_out, ram_wr, ram_addr,
                  ram_data_in, pool_1_en);
        (*pool_1)(clk, rst, ram_wr, ram_addr, ram_data_out, ram_data_in,
                  pool_1_en, conv_2_en);
        (*conv_2)(clk, rst, rom_rd, rom_addr, rom_data_out, ram_wr, ram_addr,
                  ram_data_out, ram_data_in, conv_2_en, pool_2_en);
        (*pool_2)(clk, rst, ram_wr, ram_addr, ram_data_out, ram_data_in,
                  pool_2_en, dense_1_en);
        (*dense_1)(clk, rst, rom_rd, rom_addr, rom_data_out, ram_wr, ram_addr,
                   ram_data_out, ram_data_in, dense_1_en, dense_2_en);
        (*dense_2)(clk, rst, rom_rd, rom_addr, rom_data_out, ram_wr, ram_addr,
                   ram_data_out, ram_data_in, dense_2_en, dense_3_en);
        (*dense_3)(clk, rst, rom_rd, rom_addr, rom_data_out, ram_wr, ram_addr,
                   ram_data_out, dense_3_en, result, output_valid);
    }
};
// ^^^^^ put your code here ^^^^^
