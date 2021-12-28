#include "systemc.h"
#include "../Conv_1.h"
#include "../Conv_2.h"
#include "../Dense_1.h"
#include "../Dense_2.h"
#include "../Dense_3.h"
#include "../LeNet.h"
#include "../Monitor.h"
#include "../Pool_1.h"
#include "../Pool_2.h"
#include "../RAM.h"
#include "../ROM.h"
#include "../clockreset.h"
#include "cassert"
#include "cwr_dynamic_loader.h"
#include "cwr_sc_dynamic_stubs.h"
#include "cwr_sc_hierarch_module.h"
#include "cwr_sc_object_creator.h"
#include "scmlinc/scml_abstraction_level_switch.h"
#include "scmlinc/scml_property_registry.h"

using namespace conf;
using namespace std;


class Clock0Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    int division = scml_property_registry::inst().getIntProperty(
	      scml_property_registry::CONSTRUCTOR, hierach_name, "division");

    int cycle = scml_property_registry::inst().getIntProperty(
	      scml_property_registry::CONSTRUCTOR, hierach_name, "cycle");

    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "Clock/Clock: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&Clock::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "Clock/Clock: " << hierach_name << " created." << std::endl; }
      Clock* result = new Clock(name.c_str(), division, cycle);
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
      return result;
    }
  }
};


class Conv_10Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "Conv_1/Conv_1: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&Conv_1::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_1::rst, "rst" , string(static_cast<sc_object*>(result)->name()) + ".rst" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_1::rom_rd, "rom_rd" , string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_1::rom_addr, "rom_addr" , string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_1::rom_data_out, "rom_data_out" , string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_1::ram_wr, "ram_wr" , string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_1::ram_addr, "ram_addr" , string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_1::ram_data_in, "ram_data_in" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_1::pool_1_en, "pool_1_en" , string(static_cast<sc_object*>(result)->name()) + ".pool_1_en" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "Conv_1/Conv_1: " << hierach_name << " created." << std::endl; }
      Conv_1* result = new Conv_1(name.c_str());
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
       cwr_sc_object_registry::inst().addPort(&result->rst, string(static_cast<sc_object*>(result)->name()) + ".rst" );
       cwr_sc_object_registry::inst().addPort(&result->rom_rd, string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       cwr_sc_object_registry::inst().addPort(&result->rom_addr, string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       cwr_sc_object_registry::inst().addPort(&result->rom_data_out, string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->ram_wr, string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_addr, string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_in, string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
       cwr_sc_object_registry::inst().addPort(&result->pool_1_en, string(static_cast<sc_object*>(result)->name()) + ".pool_1_en" );
      return result;
    }
  }
};


class Conv_20Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "Conv_2/Conv_2: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&Conv_2::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_2::rst, "rst" , string(static_cast<sc_object*>(result)->name()) + ".rst" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_2::conv_2_en, "conv_2_en" , string(static_cast<sc_object*>(result)->name()) + ".conv_2_en" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_2::pool_2_en, "pool_2_en" , string(static_cast<sc_object*>(result)->name()) + ".pool_2_en" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_2::rom_rd, "rom_rd" , string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_2::rom_addr, "rom_addr" , string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_2::rom_data_out, "rom_data_out" , string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_2::ram_wr, "ram_wr" , string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_2::ram_addr, "ram_addr" , string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_2::ram_data_out, "ram_data_out" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&Conv_2::ram_data_in, "ram_data_in" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "Conv_2/Conv_2: " << hierach_name << " created." << std::endl; }
      Conv_2* result = new Conv_2(name.c_str());
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
       cwr_sc_object_registry::inst().addPort(&result->rst, string(static_cast<sc_object*>(result)->name()) + ".rst" );
       cwr_sc_object_registry::inst().addPort(&result->conv_2_en, string(static_cast<sc_object*>(result)->name()) + ".conv_2_en" );
       cwr_sc_object_registry::inst().addPort(&result->pool_2_en, string(static_cast<sc_object*>(result)->name()) + ".pool_2_en" );
       cwr_sc_object_registry::inst().addPort(&result->rom_rd, string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       cwr_sc_object_registry::inst().addPort(&result->rom_addr, string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       cwr_sc_object_registry::inst().addPort(&result->rom_data_out, string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->ram_wr, string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_addr, string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_out, string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_in, string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
      return result;
    }
  }
};


class Dense_10Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "Dense_1/Dense_1: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&Dense_1::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_1::rst, "rst" , string(static_cast<sc_object*>(result)->name()) + ".rst" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_1::ram_wr, "ram_wr" , string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_1::ram_addr, "ram_addr" , string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_1::dense_1_en, "dense_1_en" , string(static_cast<sc_object*>(result)->name()) + ".dense_1_en" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_1::dense_2_en, "dense_2_en" , string(static_cast<sc_object*>(result)->name()) + ".dense_2_en" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_1::rom_rd, "rom_rd" , string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_1::rom_addr, "rom_addr" , string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_1::rom_data_out, "rom_data_out" , string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_1::ram_data_out, "ram_data_out" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_1::ram_data_in, "ram_data_in" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "Dense_1/Dense_1: " << hierach_name << " created." << std::endl; }
      Dense_1* result = new Dense_1(name.c_str());
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
       cwr_sc_object_registry::inst().addPort(&result->rst, string(static_cast<sc_object*>(result)->name()) + ".rst" );
       cwr_sc_object_registry::inst().addPort(&result->ram_wr, string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_addr, string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       cwr_sc_object_registry::inst().addPort(&result->dense_1_en, string(static_cast<sc_object*>(result)->name()) + ".dense_1_en" );
       cwr_sc_object_registry::inst().addPort(&result->dense_2_en, string(static_cast<sc_object*>(result)->name()) + ".dense_2_en" );
       cwr_sc_object_registry::inst().addPort(&result->rom_rd, string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       cwr_sc_object_registry::inst().addPort(&result->rom_addr, string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       cwr_sc_object_registry::inst().addPort(&result->rom_data_out, string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_out, string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_in, string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
      return result;
    }
  }
};


class Dense_20Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "Dense_2/Dense_2: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&Dense_2::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_2::rst, "rst" , string(static_cast<sc_object*>(result)->name()) + ".rst" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_2::ram_wr, "ram_wr" , string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_2::ram_addr, "ram_addr" , string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_2::dense_2_en, "dense_2_en" , string(static_cast<sc_object*>(result)->name()) + ".dense_2_en" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_2::dense_3_en, "dense_3_en" , string(static_cast<sc_object*>(result)->name()) + ".dense_3_en" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_2::rom_rd, "rom_rd" , string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_2::rom_addr, "rom_addr" , string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_2::rom_data_out, "rom_data_out" , string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_2::ram_data_out, "ram_data_out" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_2::ram_data_in, "ram_data_in" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "Dense_2/Dense_2: " << hierach_name << " created." << std::endl; }
      Dense_2* result = new Dense_2(name.c_str());
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
       cwr_sc_object_registry::inst().addPort(&result->rst, string(static_cast<sc_object*>(result)->name()) + ".rst" );
       cwr_sc_object_registry::inst().addPort(&result->ram_wr, string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_addr, string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       cwr_sc_object_registry::inst().addPort(&result->dense_2_en, string(static_cast<sc_object*>(result)->name()) + ".dense_2_en" );
       cwr_sc_object_registry::inst().addPort(&result->dense_3_en, string(static_cast<sc_object*>(result)->name()) + ".dense_3_en" );
       cwr_sc_object_registry::inst().addPort(&result->rom_rd, string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       cwr_sc_object_registry::inst().addPort(&result->rom_addr, string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       cwr_sc_object_registry::inst().addPort(&result->rom_data_out, string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_out, string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_in, string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
      return result;
    }
  }
};


class Dense_30Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "Dense_3/Dense_3: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&Dense_3::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_3::rst, "rst" , string(static_cast<sc_object*>(result)->name()) + ".rst" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_3::ram_wr, "ram_wr" , string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_3::ram_addr, "ram_addr" , string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_3::ram_data_out, "ram_data_out" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_3::dense_3_en, "dense_3_en" , string(static_cast<sc_object*>(result)->name()) + ".dense_3_en" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_3::rom_rd, "rom_rd" , string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_3::rom_addr, "rom_addr" , string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_3::rom_data_out, "rom_data_out" , string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_3::result, "result" , string(static_cast<sc_object*>(result)->name()) + ".result" );
       conf::stub_port_registrator<>::register_stub_port(&Dense_3::output_valid, "output_valid" , string(static_cast<sc_object*>(result)->name()) + ".output_valid" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "Dense_3/Dense_3: " << hierach_name << " created." << std::endl; }
      Dense_3* result = new Dense_3(name.c_str());
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
       cwr_sc_object_registry::inst().addPort(&result->rst, string(static_cast<sc_object*>(result)->name()) + ".rst" );
       cwr_sc_object_registry::inst().addPort(&result->ram_wr, string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_addr, string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_out, string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->dense_3_en, string(static_cast<sc_object*>(result)->name()) + ".dense_3_en" );
       cwr_sc_object_registry::inst().addPort(&result->rom_rd, string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       cwr_sc_object_registry::inst().addPort(&result->rom_addr, string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       cwr_sc_object_registry::inst().addPort(&result->rom_data_out, string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->result, string(static_cast<sc_object*>(result)->name()) + ".result" );
       cwr_sc_object_registry::inst().addPort(&result->output_valid, string(static_cast<sc_object*>(result)->name()) + ".output_valid" );
      return result;
    }
  }
};

template <class BC>
class BusCreator : public ScObjectCreatorBase
{
  sc_object* create (const string& name) {
    ScGeneratedBaseBlockCreatorHelper helper(getHierarchicalName(name));
    if (helper.is_runtime_disabled()) {
      return new conf::StubBusCreator(name.c_str(), helper);
    } else {
      return new BC(name.c_str(), helper);
    }
  }
};

template <class GBC>
class GeneratedBlockCreator : public ScObjectCreatorBase
{
  sc_object* create (const string& name) {
    ScGeneratedBaseBlockCreatorHelper helper(getHierarchicalName(name));
    if (helper.is_runtime_disabled()) {
      return new conf::StubBusCreator(name.c_str(), helper);
    } else {
      return new GBC(name.c_str(), helper);
    }
  }
};



class LeNet0Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "LeNet/LeNet: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&LeNet::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
       conf::stub_port_registrator<>::register_stub_port(&LeNet::rst, "rst" , string(static_cast<sc_object*>(result)->name()) + ".rst" );
       conf::stub_port_registrator<>::register_stub_port(&LeNet::rom_rd, "rom_rd" , string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       conf::stub_port_registrator<>::register_stub_port(&LeNet::rom_addr, "rom_addr" , string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       conf::stub_port_registrator<>::register_stub_port(&LeNet::rom_data_out, "rom_data_out" , string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&LeNet::ram_wr, "ram_wr" , string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       conf::stub_port_registrator<>::register_stub_port(&LeNet::ram_addr, "ram_addr" , string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       conf::stub_port_registrator<>::register_stub_port(&LeNet::ram_data_out, "ram_data_out" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&LeNet::ram_data_in, "ram_data_in" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
       conf::stub_port_registrator<>::register_stub_port(&LeNet::result, "result" , string(static_cast<sc_object*>(result)->name()) + ".result" );
       conf::stub_port_registrator<>::register_stub_port(&LeNet::output_valid, "output_valid" , string(static_cast<sc_object*>(result)->name()) + ".output_valid" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "LeNet/LeNet: " << hierach_name << " created." << std::endl; }
      LeNet* result = new LeNet(name.c_str());
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
       cwr_sc_object_registry::inst().addPort(&result->rst, string(static_cast<sc_object*>(result)->name()) + ".rst" );
       cwr_sc_object_registry::inst().addPort(&result->rom_rd, string(static_cast<sc_object*>(result)->name()) + ".rom_rd" );
       cwr_sc_object_registry::inst().addPort(&result->rom_addr, string(static_cast<sc_object*>(result)->name()) + ".rom_addr" );
       cwr_sc_object_registry::inst().addPort(&result->rom_data_out, string(static_cast<sc_object*>(result)->name()) + ".rom_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->ram_wr, string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_addr, string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_out, string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_in, string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
       cwr_sc_object_registry::inst().addPort(&result->result, string(static_cast<sc_object*>(result)->name()) + ".result" );
       cwr_sc_object_registry::inst().addPort(&result->output_valid, string(static_cast<sc_object*>(result)->name()) + ".output_valid" );
      return result;
    }
  }
};


class Monitor0Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "Monitor/Monitor: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&Monitor::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
       conf::stub_port_registrator<>::register_stub_port(&Monitor::rst, "rst" , string(static_cast<sc_object*>(result)->name()) + ".rst" );
       conf::stub_port_registrator<>::register_stub_port(&Monitor::data_in, "data_in" , string(static_cast<sc_object*>(result)->name()) + ".data_in" );
       conf::stub_port_registrator<>::register_stub_port(&Monitor::data_valid, "data_valid" , string(static_cast<sc_object*>(result)->name()) + ".data_valid" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "Monitor/Monitor: " << hierach_name << " created." << std::endl; }
      Monitor* result = new Monitor(name.c_str());
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
       cwr_sc_object_registry::inst().addPort(&result->rst, string(static_cast<sc_object*>(result)->name()) + ".rst" );
       cwr_sc_object_registry::inst().addPort(&result->data_in, string(static_cast<sc_object*>(result)->name()) + ".data_in" );
       cwr_sc_object_registry::inst().addPort(&result->data_valid, string(static_cast<sc_object*>(result)->name()) + ".data_valid" );
      return result;
    }
  }
};


class Pool_10Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "Pool_1/Pool_1: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&Pool_1::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_1::rst, "rst" , string(static_cast<sc_object*>(result)->name()) + ".rst" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_1::ram_wr, "ram_wr" , string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_1::ram_addr, "ram_addr" , string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_1::pool_1_en, "pool_1_en" , string(static_cast<sc_object*>(result)->name()) + ".pool_1_en" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_1::conv_2_en, "conv_2_en" , string(static_cast<sc_object*>(result)->name()) + ".conv_2_en" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_1::ram_data_out, "ram_data_out" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_1::ram_data_in, "ram_data_in" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "Pool_1/Pool_1: " << hierach_name << " created." << std::endl; }
      Pool_1* result = new Pool_1(name.c_str());
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
       cwr_sc_object_registry::inst().addPort(&result->rst, string(static_cast<sc_object*>(result)->name()) + ".rst" );
       cwr_sc_object_registry::inst().addPort(&result->ram_wr, string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_addr, string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       cwr_sc_object_registry::inst().addPort(&result->pool_1_en, string(static_cast<sc_object*>(result)->name()) + ".pool_1_en" );
       cwr_sc_object_registry::inst().addPort(&result->conv_2_en, string(static_cast<sc_object*>(result)->name()) + ".conv_2_en" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_out, string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_in, string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
      return result;
    }
  }
};


class Pool_20Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "Pool_2/Pool_2: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&Pool_2::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_2::rst, "rst" , string(static_cast<sc_object*>(result)->name()) + ".rst" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_2::ram_wr, "ram_wr" , string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_2::ram_addr, "ram_addr" , string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_2::pool_2_en, "pool_2_en" , string(static_cast<sc_object*>(result)->name()) + ".pool_2_en" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_2::dense_1_en, "dense_1_en" , string(static_cast<sc_object*>(result)->name()) + ".dense_1_en" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_2::ram_data_out, "ram_data_out" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       conf::stub_port_registrator<>::register_stub_port(&Pool_2::ram_data_in, "ram_data_in" , string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "Pool_2/Pool_2: " << hierach_name << " created." << std::endl; }
      Pool_2* result = new Pool_2(name.c_str());
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
       cwr_sc_object_registry::inst().addPort(&result->rst, string(static_cast<sc_object*>(result)->name()) + ".rst" );
       cwr_sc_object_registry::inst().addPort(&result->ram_wr, string(static_cast<sc_object*>(result)->name()) + ".ram_wr" );
       cwr_sc_object_registry::inst().addPort(&result->ram_addr, string(static_cast<sc_object*>(result)->name()) + ".ram_addr" );
       cwr_sc_object_registry::inst().addPort(&result->pool_2_en, string(static_cast<sc_object*>(result)->name()) + ".pool_2_en" );
       cwr_sc_object_registry::inst().addPort(&result->dense_1_en, string(static_cast<sc_object*>(result)->name()) + ".dense_1_en" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_out, string(static_cast<sc_object*>(result)->name()) + ".ram_data_out" );
       cwr_sc_object_registry::inst().addPort(&result->ram_data_in, string(static_cast<sc_object*>(result)->name()) + ".ram_data_in" );
      return result;
    }
  }
};


class RAM0Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "RAM/RAM: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&RAM::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
       conf::stub_port_registrator<>::register_stub_port(&RAM::wr, "wr" , string(static_cast<sc_object*>(result)->name()) + ".wr" );
       conf::stub_port_registrator<>::register_stub_port(&RAM::addr, "addr" , string(static_cast<sc_object*>(result)->name()) + ".addr" );
       conf::stub_port_registrator<>::register_stub_port(&RAM::data_out, "data_out" , string(static_cast<sc_object*>(result)->name()) + ".data_out" );
       conf::stub_port_registrator<>::register_stub_port(&RAM::data_in, "data_in" , string(static_cast<sc_object*>(result)->name()) + ".data_in" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "RAM/RAM: " << hierach_name << " created." << std::endl; }
      RAM* result = new RAM(name.c_str());
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
       cwr_sc_object_registry::inst().addPort(&result->wr, string(static_cast<sc_object*>(result)->name()) + ".wr" );
       cwr_sc_object_registry::inst().addPort(&result->addr, string(static_cast<sc_object*>(result)->name()) + ".addr" );
       cwr_sc_object_registry::inst().addPort(&result->data_out, string(static_cast<sc_object*>(result)->name()) + ".data_out" );
       cwr_sc_object_registry::inst().addPort(&result->data_in, string(static_cast<sc_object*>(result)->name()) + ".data_in" );
      return result;
    }
  }
};


class ROM0Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "ROM/ROM: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&ROM::clk, "clk" , string(static_cast<sc_object*>(result)->name()) + ".clk" );
       conf::stub_port_registrator<>::register_stub_port(&ROM::ird, "ird" , string(static_cast<sc_object*>(result)->name()) + ".ird" );
       conf::stub_port_registrator<>::register_stub_port(&ROM::addr, "addr" , string(static_cast<sc_object*>(result)->name()) + ".addr" );
       conf::stub_port_registrator<>::register_stub_port(&ROM::data_out, "data_out" , string(static_cast<sc_object*>(result)->name()) + ".data_out" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "ROM/ROM: " << hierach_name << " created." << std::endl; }
      ROM* result = new ROM(name.c_str());
       cwr_sc_object_registry::inst().addPort(&result->clk, string(static_cast<sc_object*>(result)->name()) + ".clk" );
       cwr_sc_object_registry::inst().addPort(&result->ird, string(static_cast<sc_object*>(result)->name()) + ".ird" );
       cwr_sc_object_registry::inst().addPort(&result->addr, string(static_cast<sc_object*>(result)->name()) + ".addr" );
       cwr_sc_object_registry::inst().addPort(&result->data_out, string(static_cast<sc_object*>(result)->name()) + ".data_out" );
      return result;
    }
  }
};


class Reset0Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    int _ticks = scml_property_registry::inst().getIntProperty(
	      scml_property_registry::CONSTRUCTOR, hierach_name, "_ticks");

    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "Reset/Reset: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       conf::stub_port_registrator<>::register_stub_port(&Reset::rst, "rst" , string(static_cast<sc_object*>(result)->name()) + ".rst" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "Reset/Reset: " << hierach_name << " created." << std::endl; }
      Reset* result = new Reset(name.c_str(), _ticks);
       cwr_sc_object_registry::inst().addPort(&result->rst, string(static_cast<sc_object*>(result)->name()) + ".rst" );
      return result;
    }
  }
};



extern void scv_tr_cwrdb_init();

int sc_main(int argc, char* argv[])
{
  scv_tr_cwrdb_init();
  ScObjectFactory::inst().addCreator ("Clock0", new Clock0Creator());
  ScObjectFactory::inst().addCreator ("Conv_10", new Conv_10Creator());
  ScObjectFactory::inst().addCreator ("Conv_20", new Conv_20Creator());
  ScObjectFactory::inst().addCreator ("Dense_10", new Dense_10Creator());
  ScObjectFactory::inst().addCreator ("Dense_20", new Dense_20Creator());
  ScObjectFactory::inst().addCreator ("Dense_30", new Dense_30Creator());
  ScObjectFactory::inst().addCreator ("LeNet0", new LeNet0Creator());
  ScObjectFactory::inst().addCreator ("Monitor0", new Monitor0Creator());
  ScObjectFactory::inst().addCreator ("Pool_10", new Pool_10Creator());
  ScObjectFactory::inst().addCreator ("Pool_20", new Pool_20Creator());
  ScObjectFactory::inst().addCreator ("RAM0", new RAM0Creator());
  ScObjectFactory::inst().addCreator ("ROM0", new ROM0Creator());
  ScObjectFactory::inst().addCreator ("Reset0", new Reset0Creator());
  ScObjectFactory::inst().addCreator ("sc_signal<bool>", new ScPrimChannelCreator<sc_signal<bool> >());
  ScObjectFactory::inst().addCreator ("sc_signal<float>", new ScPrimChannelCreator<sc_signal<float> >());
  ScObjectFactory::inst().addCreator ("sc_signal<sc_uint<16> >", new ScPrimChannelCreator<sc_signal<sc_uint<16> > >());
  ScPortFactory::inst().addCreator ("sc_in<bool>", new ScPortCreator<sc_in<bool> >());
  ScPortFactory::inst().addCreator ("sc_in<float>", new ScPortCreator<sc_in<float> >());
  ScPortFactory::inst().addCreator ("sc_in<sc_uint<16> >", new ScPortCreator<sc_in<sc_uint<16> > >());
  ScPortFactory::inst().addCreator ("sc_inout<bool>", new ScPortCreator<sc_inout<bool> >());
  ScPortFactory::inst().addCreator ("sc_inout<float>", new ScPortCreator<sc_inout<float> >());
  ScPortFactory::inst().addCreator ("sc_inout<sc_uint<16> >", new ScPortCreator<sc_inout<sc_uint<16> > >());
  ScPortFactory::inst().addCreator ("sc_out<bool>", new ScPortCreator<sc_out<bool> >());
  ScPortFactory::inst().addCreator ("sc_out<float>", new ScPortCreator<sc_out<float> >());
  ScPortFactory::inst().addCreator ("sc_out<sc_uint<16> >", new ScPortCreator<sc_out<sc_uint<16> > >());
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "Clock/Clock loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "Conv_1/Conv_1 loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "Conv_2/Conv_2 loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "Dense_1/Dense_1 loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "Dense_2/Dense_2 loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "Dense_3/Dense_3 loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "LeNet/LeNet loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "Monitor/Monitor loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "Pool_1/Pool_1 loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "Pool_2/Pool_2 loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "RAM/RAM loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "ROM/ROM loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "Reset/Reset loaded." << std::endl; }

  scml_property_registry::inst().setXMLFile("Properties.xml");

  nSnps::nDynamicLoading::DynamicLoader dynamicLoader
    (scml_property_registry::inst().getStringProperty(scml_property_registry::GLOBAL, "", "/pct/runtime/dynamic_load_info"));

  string xml_file_path = scml_property_registry::inst().getPropertyXmlFilePath();
  string hierarchy_xml_file = xml_file_path + "/" + 
    scml_property_registry::inst().getStringProperty(
      scml_property_registry::GLOBAL, "", "system_hierarchy_xml_file");

  cwr_sc_hierarch_module* HARDWARE = new cwr_sc_hierarch_module("HARDWARE", hierarchy_xml_file);

  // Enable/disable backdoor accesses
  scml_abstraction_level_switch::instance().set_simulation_mode(scml_property_registry::inst().getStringProperty(scml_property_registry::GLOBAL, "", "/pct/runtime/simulation_mode")=="MODE_FULL_SIMULATION" ? scml_abstraction_level_switch::MODE_FULL_SIMULATION : scml_abstraction_level_switch::MODE_SPEED_OPTIMIZED);

  sc_start();

  if (sc_is_running()) {
    sc_stop();
  }
  delete HARDWARE;

  return 0;
}
