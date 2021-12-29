#include <iostream>

#include "Conv_1.h"
#include "Conv_2.h"
#include "Dense_1.h"
#include "Dense_2.h"
#include "Dense_3.h"
#include "Pool_1.h"
#include "Pool_2.h"
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

    sc_signal<bool> pool_1_en, conv_2_en, pool_2_en, dense_1_en, dense_2_en,
        dense_3_en;

    void run();

    SC_CTOR(LeNet) {
        conv_1 = new Conv_1("c1");
        conv_2 = new Conv_2("c2");
        pool_1 = new Pool_1("p1");
        pool_2 = new Pool_2("p2");
        dense_1 = new Dense_1("d1");
        dense_2 = new Dense_2("d2");
        dense_3 = new Dense_3("d3");
        conv_1->clk(clk);
        conv_1->rst(rst);
        conv_1->rom_rd(rom_rd);
        conv_1->rom_addr(rom_addr);
        conv_1->rom_data_out(rom_data_out);
        conv_1->ram_wr(ram_wr);
        conv_1->ram_addr(ram_addr);
        conv_1->ram_data_in(ram_data_in);
        conv_1->pool_1_en(pool_1_en);
        pool_1->clk(clk);
        pool_1->rst(rst);
        pool_1->ram_wr(ram_wr);
        pool_1->ram_addr(ram_addr);
        pool_1->ram_data_out(ram_data_out);
        pool_1->ram_data_in(ram_data_in);
        pool_1->pool_1_en(pool_1_en);
        pool_1->conv_2_en(conv_2_en);
        conv_2->clk(clk);
        conv_2->rst(rst);
        conv_2->rom_rd(rom_rd);
        conv_2->rom_addr(rom_addr);
        conv_2->rom_data_out(rom_data_out);
        conv_2->ram_wr(ram_wr);
        conv_2->ram_addr(ram_addr);
        conv_2->ram_data_out(ram_data_out);
        conv_2->ram_data_in(ram_data_in);
        conv_2->conv_2_en(conv_2_en);
        conv_2->pool_2_en(pool_2_en);
        pool_2->clk(clk);
        pool_2->rst(rst);
        pool_2->ram_wr(ram_wr);
        pool_2->ram_addr(ram_addr);
        pool_2->ram_data_out(ram_data_out);
        pool_2->ram_data_in(ram_data_in);
        pool_2->pool_2_en(pool_2_en);
        pool_2->dense_1_en(dense_1_en);
        dense_1->clk(clk);
        dense_1->rst(rst);
        dense_1->rom_rd(rom_rd);
        dense_1->rom_addr(rom_addr);
        dense_1->rom_data_out(rom_data_out);
        dense_1->ram_wr(ram_wr);
        dense_1->ram_addr(ram_addr);
        dense_1->ram_data_out(ram_data_out);
        dense_1->ram_data_in(ram_data_in);
        dense_1->dense_1_en(dense_1_en);
        dense_1->dense_2_en(dense_2_en);
        dense_2->clk(clk);
        dense_2->rst(rst);
        dense_2->rom_rd(rom_rd);
        dense_2->rom_addr(rom_addr);
        dense_2->rom_data_out(rom_data_out);
        dense_2->ram_wr(ram_wr);
        dense_2->ram_addr(ram_addr);
        dense_2->ram_data_out(ram_data_out);
        dense_2->ram_data_in(ram_data_in);
        dense_2->dense_2_en(dense_2_en);
        dense_2->dense_3_en(dense_3_en);
        dense_3->clk(clk);
        dense_3->rst(rst);
        dense_3->rom_rd(rom_rd);
        dense_3->rom_addr(rom_addr);
        dense_3->rom_data_out(rom_data_out);
        dense_3->ram_wr(ram_wr);
        dense_3->ram_addr(ram_addr);
        dense_3->ram_data_out(ram_data_out);
        dense_3->dense_3_en(dense_3_en);
        dense_3->result(result);
        dense_3->output_valid(output_valid);
    }
};
// ^^^^^ put your code here ^^^^^
