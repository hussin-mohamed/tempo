// (c) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// (c) Copyright 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of AMD and is protected under U.S. and international copyright
// and other intellectual property laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// AMD, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) AMD shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or AMD had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// AMD products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of AMD products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


#include "design_1_auto_pc_0_sc.h"

#include "design_1_auto_pc_0.h"

#include "axi_protocol_converter.h"

#include <map>
#include <string>





#ifdef XILINX_SIMULATOR
design_1_auto_pc_0::design_1_auto_pc_0(const sc_core::sc_module_name& nm) : design_1_auto_pc_0_sc(nm), aclk("aclk"), aresetn("aresetn"), s_axi_awid("s_axi_awid"), s_axi_awaddr("s_axi_awaddr"), s_axi_awlen("s_axi_awlen"), s_axi_awsize("s_axi_awsize"), s_axi_awburst("s_axi_awburst"), s_axi_awlock("s_axi_awlock"), s_axi_awcache("s_axi_awcache"), s_axi_awprot("s_axi_awprot"), s_axi_awqos("s_axi_awqos"), s_axi_awvalid("s_axi_awvalid"), s_axi_awready("s_axi_awready"), s_axi_wid("s_axi_wid"), s_axi_wdata("s_axi_wdata"), s_axi_wstrb("s_axi_wstrb"), s_axi_wlast("s_axi_wlast"), s_axi_wvalid("s_axi_wvalid"), s_axi_wready("s_axi_wready"), s_axi_bid("s_axi_bid"), s_axi_bresp("s_axi_bresp"), s_axi_bvalid("s_axi_bvalid"), s_axi_bready("s_axi_bready"), s_axi_arid("s_axi_arid"), s_axi_araddr("s_axi_araddr"), s_axi_arlen("s_axi_arlen"), s_axi_arsize("s_axi_arsize"), s_axi_arburst("s_axi_arburst"), s_axi_arlock("s_axi_arlock"), s_axi_arcache("s_axi_arcache"), s_axi_arprot("s_axi_arprot"), s_axi_arqos("s_axi_arqos"), s_axi_arvalid("s_axi_arvalid"), s_axi_arready("s_axi_arready"), s_axi_rid("s_axi_rid"), s_axi_rdata("s_axi_rdata"), s_axi_rresp("s_axi_rresp"), s_axi_rlast("s_axi_rlast"), s_axi_rvalid("s_axi_rvalid"), s_axi_rready("s_axi_rready"), m_axi_awaddr("m_axi_awaddr"), m_axi_awprot("m_axi_awprot"), m_axi_awvalid("m_axi_awvalid"), m_axi_awready("m_axi_awready"), m_axi_wdata("m_axi_wdata"), m_axi_wstrb("m_axi_wstrb"), m_axi_wvalid("m_axi_wvalid"), m_axi_wready("m_axi_wready"), m_axi_bresp("m_axi_bresp"), m_axi_bvalid("m_axi_bvalid"), m_axi_bready("m_axi_bready"), m_axi_araddr("m_axi_araddr"), m_axi_arprot("m_axi_arprot"), m_axi_arvalid("m_axi_arvalid"), m_axi_arready("m_axi_arready"), m_axi_rdata("m_axi_rdata"), m_axi_rresp("m_axi_rresp"), m_axi_rvalid("m_axi_rvalid"), m_axi_rready("m_axi_rready")
{

  // initialize pins
  mp_impl->aclk(aclk);
  mp_impl->aresetn(aresetn);

  // initialize transactors
  mp_S_AXI_transactor = NULL;
  mp_s_axi_awlen_converter = NULL;
  mp_s_axi_awlock_converter = NULL;
  mp_s_axi_arlen_converter = NULL;
  mp_s_axi_arlock_converter = NULL;
  mp_M_AXI_transactor = NULL;

  // initialize socket stubs

}

void design_1_auto_pc_0::before_end_of_elaboration()
{
  // configure 'S_AXI' transactor

  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_auto_pc_0", "S_AXI_TLM_MODE") != 1)
  {
    // Instantiate Socket Stubs

  // 'S_AXI' transactor parameters
    xsc::common_cpp::properties S_AXI_transactor_param_props;
    S_AXI_transactor_param_props.addLong("DATA_WIDTH", "32");
    S_AXI_transactor_param_props.addLong("FREQ_HZ", "100000000");
    S_AXI_transactor_param_props.addLong("ID_WIDTH", "12");
    S_AXI_transactor_param_props.addLong("ADDR_WIDTH", "32");
    S_AXI_transactor_param_props.addLong("AWUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("ARUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("WUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("RUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("BUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("HAS_BURST", "1");
    S_AXI_transactor_param_props.addLong("HAS_LOCK", "1");
    S_AXI_transactor_param_props.addLong("HAS_PROT", "1");
    S_AXI_transactor_param_props.addLong("HAS_CACHE", "1");
    S_AXI_transactor_param_props.addLong("HAS_QOS", "1");
    S_AXI_transactor_param_props.addLong("HAS_REGION", "0");
    S_AXI_transactor_param_props.addLong("HAS_WSTRB", "1");
    S_AXI_transactor_param_props.addLong("HAS_BRESP", "1");
    S_AXI_transactor_param_props.addLong("HAS_RRESP", "1");
    S_AXI_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "0");
    S_AXI_transactor_param_props.addLong("NUM_READ_OUTSTANDING", "8");
    S_AXI_transactor_param_props.addLong("NUM_WRITE_OUTSTANDING", "8");
    S_AXI_transactor_param_props.addLong("MAX_BURST_LENGTH", "16");
    S_AXI_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    S_AXI_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    S_AXI_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    S_AXI_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    S_AXI_transactor_param_props.addLong("HAS_SIZE", "1");
    S_AXI_transactor_param_props.addLong("HAS_RESET", "1");
    S_AXI_transactor_param_props.addFloat("PHASE", "0.0");
    S_AXI_transactor_param_props.addString("PROTOCOL", "AXI3");
    S_AXI_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    S_AXI_transactor_param_props.addString("CLK_DOMAIN", "design_1_processing_system7_0_0_FCLK_CLK0");

    mp_S_AXI_transactor = new xtlm::xaximm_pin2xtlm_t<32,32,12,1,1,1,1,1>("S_AXI_transactor", S_AXI_transactor_param_props);

    // S_AXI' transactor ports

    mp_S_AXI_transactor->AWID(s_axi_awid);
    mp_S_AXI_transactor->AWADDR(s_axi_awaddr);
    mp_s_axi_awlen_converter = new xsc::common::vector2vector_converter<4,8>("s_axi_awlen_converter");
    mp_s_axi_awlen_converter->vector_in(s_axi_awlen);
    mp_s_axi_awlen_converter->vector_out(m_s_axi_awlen_converter_signal);
    mp_S_AXI_transactor->AWLEN(m_s_axi_awlen_converter_signal);
    mp_S_AXI_transactor->AWSIZE(s_axi_awsize);
    mp_S_AXI_transactor->AWBURST(s_axi_awburst);
    mp_s_axi_awlock_converter = new xsc::common::vectorN2scalar_converter<2>("s_axi_awlock_converter");
    mp_s_axi_awlock_converter->vector_in(s_axi_awlock);
    mp_s_axi_awlock_converter->scalar_out(m_s_axi_awlock_converter_signal);
    mp_S_AXI_transactor->AWLOCK(m_s_axi_awlock_converter_signal);
    mp_S_AXI_transactor->AWCACHE(s_axi_awcache);
    mp_S_AXI_transactor->AWPROT(s_axi_awprot);
    mp_S_AXI_transactor->AWQOS(s_axi_awqos);
    mp_S_AXI_transactor->AWVALID(s_axi_awvalid);
    mp_S_AXI_transactor->AWREADY(s_axi_awready);
    mp_S_AXI_transactor->WDATA(s_axi_wdata);
    mp_S_AXI_transactor->WSTRB(s_axi_wstrb);
    mp_S_AXI_transactor->WLAST(s_axi_wlast);
    mp_S_AXI_transactor->WVALID(s_axi_wvalid);
    mp_S_AXI_transactor->WREADY(s_axi_wready);
    mp_S_AXI_transactor->BID(s_axi_bid);
    mp_S_AXI_transactor->BRESP(s_axi_bresp);
    mp_S_AXI_transactor->BVALID(s_axi_bvalid);
    mp_S_AXI_transactor->BREADY(s_axi_bready);
    mp_S_AXI_transactor->ARID(s_axi_arid);
    mp_S_AXI_transactor->ARADDR(s_axi_araddr);
    mp_s_axi_arlen_converter = new xsc::common::vector2vector_converter<4,8>("s_axi_arlen_converter");
    mp_s_axi_arlen_converter->vector_in(s_axi_arlen);
    mp_s_axi_arlen_converter->vector_out(m_s_axi_arlen_converter_signal);
    mp_S_AXI_transactor->ARLEN(m_s_axi_arlen_converter_signal);
    mp_S_AXI_transactor->ARSIZE(s_axi_arsize);
    mp_S_AXI_transactor->ARBURST(s_axi_arburst);
    mp_s_axi_arlock_converter = new xsc::common::vectorN2scalar_converter<2>("s_axi_arlock_converter");
    mp_s_axi_arlock_converter->vector_in(s_axi_arlock);
    mp_s_axi_arlock_converter->scalar_out(m_s_axi_arlock_converter_signal);
    mp_S_AXI_transactor->ARLOCK(m_s_axi_arlock_converter_signal);
    mp_S_AXI_transactor->ARCACHE(s_axi_arcache);
    mp_S_AXI_transactor->ARPROT(s_axi_arprot);
    mp_S_AXI_transactor->ARQOS(s_axi_arqos);
    mp_S_AXI_transactor->ARVALID(s_axi_arvalid);
    mp_S_AXI_transactor->ARREADY(s_axi_arready);
    mp_S_AXI_transactor->RID(s_axi_rid);
    mp_S_AXI_transactor->RDATA(s_axi_rdata);
    mp_S_AXI_transactor->RRESP(s_axi_rresp);
    mp_S_AXI_transactor->RLAST(s_axi_rlast);
    mp_S_AXI_transactor->RVALID(s_axi_rvalid);
    mp_S_AXI_transactor->RREADY(s_axi_rready);
    mp_S_AXI_transactor->CLK(aclk);
    mp_S_AXI_transactor->RST(aresetn);

    // S_AXI' transactor sockets

    mp_impl->target_rd_socket->bind(*(mp_S_AXI_transactor->rd_socket));
    mp_impl->target_wr_socket->bind(*(mp_S_AXI_transactor->wr_socket));
  }
  else
  {
  }

  // configure 'M_AXI' transactor

  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_auto_pc_0", "M_AXI_TLM_MODE") != 1)
  {
    // Instantiate Socket Stubs

  // 'M_AXI' transactor parameters
    xsc::common_cpp::properties M_AXI_transactor_param_props;
    M_AXI_transactor_param_props.addLong("DATA_WIDTH", "32");
    M_AXI_transactor_param_props.addLong("FREQ_HZ", "100000000");
    M_AXI_transactor_param_props.addLong("ID_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("ADDR_WIDTH", "32");
    M_AXI_transactor_param_props.addLong("AWUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("ARUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("WUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("RUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("BUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("HAS_BURST", "0");
    M_AXI_transactor_param_props.addLong("HAS_LOCK", "0");
    M_AXI_transactor_param_props.addLong("HAS_PROT", "1");
    M_AXI_transactor_param_props.addLong("HAS_CACHE", "0");
    M_AXI_transactor_param_props.addLong("HAS_QOS", "0");
    M_AXI_transactor_param_props.addLong("HAS_REGION", "0");
    M_AXI_transactor_param_props.addLong("HAS_WSTRB", "1");
    M_AXI_transactor_param_props.addLong("HAS_BRESP", "1");
    M_AXI_transactor_param_props.addLong("HAS_RRESP", "1");
    M_AXI_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "0");
    M_AXI_transactor_param_props.addLong("NUM_READ_OUTSTANDING", "8");
    M_AXI_transactor_param_props.addLong("NUM_WRITE_OUTSTANDING", "8");
    M_AXI_transactor_param_props.addLong("MAX_BURST_LENGTH", "1");
    M_AXI_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    M_AXI_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    M_AXI_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    M_AXI_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    M_AXI_transactor_param_props.addLong("HAS_SIZE", "0");
    M_AXI_transactor_param_props.addLong("HAS_RESET", "1");
    M_AXI_transactor_param_props.addFloat("PHASE", "0.0");
    M_AXI_transactor_param_props.addString("PROTOCOL", "AXI4LITE");
    M_AXI_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    M_AXI_transactor_param_props.addString("CLK_DOMAIN", "design_1_processing_system7_0_0_FCLK_CLK0");

    mp_M_AXI_transactor = new xtlm::xaximm_xtlm2pin_t<32,32,12,1,1,1,1,1>("M_AXI_transactor", M_AXI_transactor_param_props);

    // M_AXI' transactor ports

    mp_M_AXI_transactor->AWADDR(m_axi_awaddr);
    mp_M_AXI_transactor->AWPROT(m_axi_awprot);
    mp_M_AXI_transactor->AWVALID(m_axi_awvalid);
    mp_M_AXI_transactor->AWREADY(m_axi_awready);
    mp_M_AXI_transactor->WDATA(m_axi_wdata);
    mp_M_AXI_transactor->WSTRB(m_axi_wstrb);
    mp_M_AXI_transactor->WVALID(m_axi_wvalid);
    mp_M_AXI_transactor->WREADY(m_axi_wready);
    mp_M_AXI_transactor->BRESP(m_axi_bresp);
    mp_M_AXI_transactor->BVALID(m_axi_bvalid);
    mp_M_AXI_transactor->BREADY(m_axi_bready);
    mp_M_AXI_transactor->ARADDR(m_axi_araddr);
    mp_M_AXI_transactor->ARPROT(m_axi_arprot);
    mp_M_AXI_transactor->ARVALID(m_axi_arvalid);
    mp_M_AXI_transactor->ARREADY(m_axi_arready);
    mp_M_AXI_transactor->RDATA(m_axi_rdata);
    mp_M_AXI_transactor->RRESP(m_axi_rresp);
    mp_M_AXI_transactor->RVALID(m_axi_rvalid);
    mp_M_AXI_transactor->RREADY(m_axi_rready);
    mp_M_AXI_transactor->CLK(aclk);
    mp_M_AXI_transactor->RST(aresetn);

    // M_AXI' transactor sockets

    mp_impl->initiator_rd_socket->bind(*(mp_M_AXI_transactor->rd_socket));
    mp_impl->initiator_wr_socket->bind(*(mp_M_AXI_transactor->wr_socket));
  }
  else
  {
  }

}

#endif // XILINX_SIMULATOR




#ifdef XM_SYSTEMC
design_1_auto_pc_0::design_1_auto_pc_0(const sc_core::sc_module_name& nm) : design_1_auto_pc_0_sc(nm), aclk("aclk"), aresetn("aresetn"), s_axi_awid("s_axi_awid"), s_axi_awaddr("s_axi_awaddr"), s_axi_awlen("s_axi_awlen"), s_axi_awsize("s_axi_awsize"), s_axi_awburst("s_axi_awburst"), s_axi_awlock("s_axi_awlock"), s_axi_awcache("s_axi_awcache"), s_axi_awprot("s_axi_awprot"), s_axi_awqos("s_axi_awqos"), s_axi_awvalid("s_axi_awvalid"), s_axi_awready("s_axi_awready"), s_axi_wid("s_axi_wid"), s_axi_wdata("s_axi_wdata"), s_axi_wstrb("s_axi_wstrb"), s_axi_wlast("s_axi_wlast"), s_axi_wvalid("s_axi_wvalid"), s_axi_wready("s_axi_wready"), s_axi_bid("s_axi_bid"), s_axi_bresp("s_axi_bresp"), s_axi_bvalid("s_axi_bvalid"), s_axi_bready("s_axi_bready"), s_axi_arid("s_axi_arid"), s_axi_araddr("s_axi_araddr"), s_axi_arlen("s_axi_arlen"), s_axi_arsize("s_axi_arsize"), s_axi_arburst("s_axi_arburst"), s_axi_arlock("s_axi_arlock"), s_axi_arcache("s_axi_arcache"), s_axi_arprot("s_axi_arprot"), s_axi_arqos("s_axi_arqos"), s_axi_arvalid("s_axi_arvalid"), s_axi_arready("s_axi_arready"), s_axi_rid("s_axi_rid"), s_axi_rdata("s_axi_rdata"), s_axi_rresp("s_axi_rresp"), s_axi_rlast("s_axi_rlast"), s_axi_rvalid("s_axi_rvalid"), s_axi_rready("s_axi_rready"), m_axi_awaddr("m_axi_awaddr"), m_axi_awprot("m_axi_awprot"), m_axi_awvalid("m_axi_awvalid"), m_axi_awready("m_axi_awready"), m_axi_wdata("m_axi_wdata"), m_axi_wstrb("m_axi_wstrb"), m_axi_wvalid("m_axi_wvalid"), m_axi_wready("m_axi_wready"), m_axi_bresp("m_axi_bresp"), m_axi_bvalid("m_axi_bvalid"), m_axi_bready("m_axi_bready"), m_axi_araddr("m_axi_araddr"), m_axi_arprot("m_axi_arprot"), m_axi_arvalid("m_axi_arvalid"), m_axi_arready("m_axi_arready"), m_axi_rdata("m_axi_rdata"), m_axi_rresp("m_axi_rresp"), m_axi_rvalid("m_axi_rvalid"), m_axi_rready("m_axi_rready")
{

  // initialize pins
  mp_impl->aclk(aclk);
  mp_impl->aresetn(aresetn);

  // initialize transactors
  mp_S_AXI_transactor = NULL;
  mp_s_axi_awlen_converter = NULL;
  mp_s_axi_awlock_converter = NULL;
  mp_s_axi_arlen_converter = NULL;
  mp_s_axi_arlock_converter = NULL;
  mp_M_AXI_transactor = NULL;

  // initialize socket stubs

}

void design_1_auto_pc_0::before_end_of_elaboration()
{
  // configure 'S_AXI' transactor

  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_auto_pc_0", "S_AXI_TLM_MODE") != 1)
  {
    // Instantiate Socket Stubs

  // 'S_AXI' transactor parameters
    xsc::common_cpp::properties S_AXI_transactor_param_props;
    S_AXI_transactor_param_props.addLong("DATA_WIDTH", "32");
    S_AXI_transactor_param_props.addLong("FREQ_HZ", "100000000");
    S_AXI_transactor_param_props.addLong("ID_WIDTH", "12");
    S_AXI_transactor_param_props.addLong("ADDR_WIDTH", "32");
    S_AXI_transactor_param_props.addLong("AWUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("ARUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("WUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("RUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("BUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("HAS_BURST", "1");
    S_AXI_transactor_param_props.addLong("HAS_LOCK", "1");
    S_AXI_transactor_param_props.addLong("HAS_PROT", "1");
    S_AXI_transactor_param_props.addLong("HAS_CACHE", "1");
    S_AXI_transactor_param_props.addLong("HAS_QOS", "1");
    S_AXI_transactor_param_props.addLong("HAS_REGION", "0");
    S_AXI_transactor_param_props.addLong("HAS_WSTRB", "1");
    S_AXI_transactor_param_props.addLong("HAS_BRESP", "1");
    S_AXI_transactor_param_props.addLong("HAS_RRESP", "1");
    S_AXI_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "0");
    S_AXI_transactor_param_props.addLong("NUM_READ_OUTSTANDING", "8");
    S_AXI_transactor_param_props.addLong("NUM_WRITE_OUTSTANDING", "8");
    S_AXI_transactor_param_props.addLong("MAX_BURST_LENGTH", "16");
    S_AXI_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    S_AXI_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    S_AXI_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    S_AXI_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    S_AXI_transactor_param_props.addLong("HAS_SIZE", "1");
    S_AXI_transactor_param_props.addLong("HAS_RESET", "1");
    S_AXI_transactor_param_props.addFloat("PHASE", "0.0");
    S_AXI_transactor_param_props.addString("PROTOCOL", "AXI3");
    S_AXI_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    S_AXI_transactor_param_props.addString("CLK_DOMAIN", "design_1_processing_system7_0_0_FCLK_CLK0");

    mp_S_AXI_transactor = new xtlm::xaximm_pin2xtlm_t<32,32,12,1,1,1,1,1>("S_AXI_transactor", S_AXI_transactor_param_props);

    // S_AXI' transactor ports

    mp_S_AXI_transactor->AWID(s_axi_awid);
    mp_S_AXI_transactor->AWADDR(s_axi_awaddr);
    mp_s_axi_awlen_converter = new xsc::common::vector2vector_converter<4,8>("s_axi_awlen_converter");
    mp_s_axi_awlen_converter->vector_in(s_axi_awlen);
    mp_s_axi_awlen_converter->vector_out(m_s_axi_awlen_converter_signal);
    mp_S_AXI_transactor->AWLEN(m_s_axi_awlen_converter_signal);
    mp_S_AXI_transactor->AWSIZE(s_axi_awsize);
    mp_S_AXI_transactor->AWBURST(s_axi_awburst);
    mp_s_axi_awlock_converter = new xsc::common::vectorN2scalar_converter<2>("s_axi_awlock_converter");
    mp_s_axi_awlock_converter->vector_in(s_axi_awlock);
    mp_s_axi_awlock_converter->scalar_out(m_s_axi_awlock_converter_signal);
    mp_S_AXI_transactor->AWLOCK(m_s_axi_awlock_converter_signal);
    mp_S_AXI_transactor->AWCACHE(s_axi_awcache);
    mp_S_AXI_transactor->AWPROT(s_axi_awprot);
    mp_S_AXI_transactor->AWQOS(s_axi_awqos);
    mp_S_AXI_transactor->AWVALID(s_axi_awvalid);
    mp_S_AXI_transactor->AWREADY(s_axi_awready);
    mp_S_AXI_transactor->WDATA(s_axi_wdata);
    mp_S_AXI_transactor->WSTRB(s_axi_wstrb);
    mp_S_AXI_transactor->WLAST(s_axi_wlast);
    mp_S_AXI_transactor->WVALID(s_axi_wvalid);
    mp_S_AXI_transactor->WREADY(s_axi_wready);
    mp_S_AXI_transactor->BID(s_axi_bid);
    mp_S_AXI_transactor->BRESP(s_axi_bresp);
    mp_S_AXI_transactor->BVALID(s_axi_bvalid);
    mp_S_AXI_transactor->BREADY(s_axi_bready);
    mp_S_AXI_transactor->ARID(s_axi_arid);
    mp_S_AXI_transactor->ARADDR(s_axi_araddr);
    mp_s_axi_arlen_converter = new xsc::common::vector2vector_converter<4,8>("s_axi_arlen_converter");
    mp_s_axi_arlen_converter->vector_in(s_axi_arlen);
    mp_s_axi_arlen_converter->vector_out(m_s_axi_arlen_converter_signal);
    mp_S_AXI_transactor->ARLEN(m_s_axi_arlen_converter_signal);
    mp_S_AXI_transactor->ARSIZE(s_axi_arsize);
    mp_S_AXI_transactor->ARBURST(s_axi_arburst);
    mp_s_axi_arlock_converter = new xsc::common::vectorN2scalar_converter<2>("s_axi_arlock_converter");
    mp_s_axi_arlock_converter->vector_in(s_axi_arlock);
    mp_s_axi_arlock_converter->scalar_out(m_s_axi_arlock_converter_signal);
    mp_S_AXI_transactor->ARLOCK(m_s_axi_arlock_converter_signal);
    mp_S_AXI_transactor->ARCACHE(s_axi_arcache);
    mp_S_AXI_transactor->ARPROT(s_axi_arprot);
    mp_S_AXI_transactor->ARQOS(s_axi_arqos);
    mp_S_AXI_transactor->ARVALID(s_axi_arvalid);
    mp_S_AXI_transactor->ARREADY(s_axi_arready);
    mp_S_AXI_transactor->RID(s_axi_rid);
    mp_S_AXI_transactor->RDATA(s_axi_rdata);
    mp_S_AXI_transactor->RRESP(s_axi_rresp);
    mp_S_AXI_transactor->RLAST(s_axi_rlast);
    mp_S_AXI_transactor->RVALID(s_axi_rvalid);
    mp_S_AXI_transactor->RREADY(s_axi_rready);
    mp_S_AXI_transactor->CLK(aclk);
    mp_S_AXI_transactor->RST(aresetn);

    // S_AXI' transactor sockets

    mp_impl->target_rd_socket->bind(*(mp_S_AXI_transactor->rd_socket));
    mp_impl->target_wr_socket->bind(*(mp_S_AXI_transactor->wr_socket));
  }
  else
  {
  }

  // configure 'M_AXI' transactor

  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_auto_pc_0", "M_AXI_TLM_MODE") != 1)
  {
    // Instantiate Socket Stubs

  // 'M_AXI' transactor parameters
    xsc::common_cpp::properties M_AXI_transactor_param_props;
    M_AXI_transactor_param_props.addLong("DATA_WIDTH", "32");
    M_AXI_transactor_param_props.addLong("FREQ_HZ", "100000000");
    M_AXI_transactor_param_props.addLong("ID_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("ADDR_WIDTH", "32");
    M_AXI_transactor_param_props.addLong("AWUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("ARUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("WUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("RUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("BUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("HAS_BURST", "0");
    M_AXI_transactor_param_props.addLong("HAS_LOCK", "0");
    M_AXI_transactor_param_props.addLong("HAS_PROT", "1");
    M_AXI_transactor_param_props.addLong("HAS_CACHE", "0");
    M_AXI_transactor_param_props.addLong("HAS_QOS", "0");
    M_AXI_transactor_param_props.addLong("HAS_REGION", "0");
    M_AXI_transactor_param_props.addLong("HAS_WSTRB", "1");
    M_AXI_transactor_param_props.addLong("HAS_BRESP", "1");
    M_AXI_transactor_param_props.addLong("HAS_RRESP", "1");
    M_AXI_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "0");
    M_AXI_transactor_param_props.addLong("NUM_READ_OUTSTANDING", "8");
    M_AXI_transactor_param_props.addLong("NUM_WRITE_OUTSTANDING", "8");
    M_AXI_transactor_param_props.addLong("MAX_BURST_LENGTH", "1");
    M_AXI_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    M_AXI_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    M_AXI_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    M_AXI_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    M_AXI_transactor_param_props.addLong("HAS_SIZE", "0");
    M_AXI_transactor_param_props.addLong("HAS_RESET", "1");
    M_AXI_transactor_param_props.addFloat("PHASE", "0.0");
    M_AXI_transactor_param_props.addString("PROTOCOL", "AXI4LITE");
    M_AXI_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    M_AXI_transactor_param_props.addString("CLK_DOMAIN", "design_1_processing_system7_0_0_FCLK_CLK0");

    mp_M_AXI_transactor = new xtlm::xaximm_xtlm2pin_t<32,32,12,1,1,1,1,1>("M_AXI_transactor", M_AXI_transactor_param_props);

    // M_AXI' transactor ports

    mp_M_AXI_transactor->AWADDR(m_axi_awaddr);
    mp_M_AXI_transactor->AWPROT(m_axi_awprot);
    mp_M_AXI_transactor->AWVALID(m_axi_awvalid);
    mp_M_AXI_transactor->AWREADY(m_axi_awready);
    mp_M_AXI_transactor->WDATA(m_axi_wdata);
    mp_M_AXI_transactor->WSTRB(m_axi_wstrb);
    mp_M_AXI_transactor->WVALID(m_axi_wvalid);
    mp_M_AXI_transactor->WREADY(m_axi_wready);
    mp_M_AXI_transactor->BRESP(m_axi_bresp);
    mp_M_AXI_transactor->BVALID(m_axi_bvalid);
    mp_M_AXI_transactor->BREADY(m_axi_bready);
    mp_M_AXI_transactor->ARADDR(m_axi_araddr);
    mp_M_AXI_transactor->ARPROT(m_axi_arprot);
    mp_M_AXI_transactor->ARVALID(m_axi_arvalid);
    mp_M_AXI_transactor->ARREADY(m_axi_arready);
    mp_M_AXI_transactor->RDATA(m_axi_rdata);
    mp_M_AXI_transactor->RRESP(m_axi_rresp);
    mp_M_AXI_transactor->RVALID(m_axi_rvalid);
    mp_M_AXI_transactor->RREADY(m_axi_rready);
    mp_M_AXI_transactor->CLK(aclk);
    mp_M_AXI_transactor->RST(aresetn);

    // M_AXI' transactor sockets

    mp_impl->initiator_rd_socket->bind(*(mp_M_AXI_transactor->rd_socket));
    mp_impl->initiator_wr_socket->bind(*(mp_M_AXI_transactor->wr_socket));
  }
  else
  {
  }

}

#endif // XM_SYSTEMC




#ifdef RIVIERA
design_1_auto_pc_0::design_1_auto_pc_0(const sc_core::sc_module_name& nm) : design_1_auto_pc_0_sc(nm), aclk("aclk"), aresetn("aresetn"), s_axi_awid("s_axi_awid"), s_axi_awaddr("s_axi_awaddr"), s_axi_awlen("s_axi_awlen"), s_axi_awsize("s_axi_awsize"), s_axi_awburst("s_axi_awburst"), s_axi_awlock("s_axi_awlock"), s_axi_awcache("s_axi_awcache"), s_axi_awprot("s_axi_awprot"), s_axi_awqos("s_axi_awqos"), s_axi_awvalid("s_axi_awvalid"), s_axi_awready("s_axi_awready"), s_axi_wid("s_axi_wid"), s_axi_wdata("s_axi_wdata"), s_axi_wstrb("s_axi_wstrb"), s_axi_wlast("s_axi_wlast"), s_axi_wvalid("s_axi_wvalid"), s_axi_wready("s_axi_wready"), s_axi_bid("s_axi_bid"), s_axi_bresp("s_axi_bresp"), s_axi_bvalid("s_axi_bvalid"), s_axi_bready("s_axi_bready"), s_axi_arid("s_axi_arid"), s_axi_araddr("s_axi_araddr"), s_axi_arlen("s_axi_arlen"), s_axi_arsize("s_axi_arsize"), s_axi_arburst("s_axi_arburst"), s_axi_arlock("s_axi_arlock"), s_axi_arcache("s_axi_arcache"), s_axi_arprot("s_axi_arprot"), s_axi_arqos("s_axi_arqos"), s_axi_arvalid("s_axi_arvalid"), s_axi_arready("s_axi_arready"), s_axi_rid("s_axi_rid"), s_axi_rdata("s_axi_rdata"), s_axi_rresp("s_axi_rresp"), s_axi_rlast("s_axi_rlast"), s_axi_rvalid("s_axi_rvalid"), s_axi_rready("s_axi_rready"), m_axi_awaddr("m_axi_awaddr"), m_axi_awprot("m_axi_awprot"), m_axi_awvalid("m_axi_awvalid"), m_axi_awready("m_axi_awready"), m_axi_wdata("m_axi_wdata"), m_axi_wstrb("m_axi_wstrb"), m_axi_wvalid("m_axi_wvalid"), m_axi_wready("m_axi_wready"), m_axi_bresp("m_axi_bresp"), m_axi_bvalid("m_axi_bvalid"), m_axi_bready("m_axi_bready"), m_axi_araddr("m_axi_araddr"), m_axi_arprot("m_axi_arprot"), m_axi_arvalid("m_axi_arvalid"), m_axi_arready("m_axi_arready"), m_axi_rdata("m_axi_rdata"), m_axi_rresp("m_axi_rresp"), m_axi_rvalid("m_axi_rvalid"), m_axi_rready("m_axi_rready")
{

  // initialize pins
  mp_impl->aclk(aclk);
  mp_impl->aresetn(aresetn);

  // initialize transactors
  mp_S_AXI_transactor = NULL;
  mp_s_axi_awlen_converter = NULL;
  mp_s_axi_awlock_converter = NULL;
  mp_s_axi_arlen_converter = NULL;
  mp_s_axi_arlock_converter = NULL;
  mp_M_AXI_transactor = NULL;

  // initialize socket stubs

}

void design_1_auto_pc_0::before_end_of_elaboration()
{
  // configure 'S_AXI' transactor

  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_auto_pc_0", "S_AXI_TLM_MODE") != 1)
  {
    // Instantiate Socket Stubs

  // 'S_AXI' transactor parameters
    xsc::common_cpp::properties S_AXI_transactor_param_props;
    S_AXI_transactor_param_props.addLong("DATA_WIDTH", "32");
    S_AXI_transactor_param_props.addLong("FREQ_HZ", "100000000");
    S_AXI_transactor_param_props.addLong("ID_WIDTH", "12");
    S_AXI_transactor_param_props.addLong("ADDR_WIDTH", "32");
    S_AXI_transactor_param_props.addLong("AWUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("ARUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("WUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("RUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("BUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("HAS_BURST", "1");
    S_AXI_transactor_param_props.addLong("HAS_LOCK", "1");
    S_AXI_transactor_param_props.addLong("HAS_PROT", "1");
    S_AXI_transactor_param_props.addLong("HAS_CACHE", "1");
    S_AXI_transactor_param_props.addLong("HAS_QOS", "1");
    S_AXI_transactor_param_props.addLong("HAS_REGION", "0");
    S_AXI_transactor_param_props.addLong("HAS_WSTRB", "1");
    S_AXI_transactor_param_props.addLong("HAS_BRESP", "1");
    S_AXI_transactor_param_props.addLong("HAS_RRESP", "1");
    S_AXI_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "0");
    S_AXI_transactor_param_props.addLong("NUM_READ_OUTSTANDING", "8");
    S_AXI_transactor_param_props.addLong("NUM_WRITE_OUTSTANDING", "8");
    S_AXI_transactor_param_props.addLong("MAX_BURST_LENGTH", "16");
    S_AXI_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    S_AXI_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    S_AXI_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    S_AXI_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    S_AXI_transactor_param_props.addLong("HAS_SIZE", "1");
    S_AXI_transactor_param_props.addLong("HAS_RESET", "1");
    S_AXI_transactor_param_props.addFloat("PHASE", "0.0");
    S_AXI_transactor_param_props.addString("PROTOCOL", "AXI3");
    S_AXI_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    S_AXI_transactor_param_props.addString("CLK_DOMAIN", "design_1_processing_system7_0_0_FCLK_CLK0");

    mp_S_AXI_transactor = new xtlm::xaximm_pin2xtlm_t<32,32,12,1,1,1,1,1>("S_AXI_transactor", S_AXI_transactor_param_props);

    // S_AXI' transactor ports

    mp_S_AXI_transactor->AWID(s_axi_awid);
    mp_S_AXI_transactor->AWADDR(s_axi_awaddr);
    mp_s_axi_awlen_converter = new xsc::common::vector2vector_converter<4,8>("s_axi_awlen_converter");
    mp_s_axi_awlen_converter->vector_in(s_axi_awlen);
    mp_s_axi_awlen_converter->vector_out(m_s_axi_awlen_converter_signal);
    mp_S_AXI_transactor->AWLEN(m_s_axi_awlen_converter_signal);
    mp_S_AXI_transactor->AWSIZE(s_axi_awsize);
    mp_S_AXI_transactor->AWBURST(s_axi_awburst);
    mp_s_axi_awlock_converter = new xsc::common::vectorN2scalar_converter<2>("s_axi_awlock_converter");
    mp_s_axi_awlock_converter->vector_in(s_axi_awlock);
    mp_s_axi_awlock_converter->scalar_out(m_s_axi_awlock_converter_signal);
    mp_S_AXI_transactor->AWLOCK(m_s_axi_awlock_converter_signal);
    mp_S_AXI_transactor->AWCACHE(s_axi_awcache);
    mp_S_AXI_transactor->AWPROT(s_axi_awprot);
    mp_S_AXI_transactor->AWQOS(s_axi_awqos);
    mp_S_AXI_transactor->AWVALID(s_axi_awvalid);
    mp_S_AXI_transactor->AWREADY(s_axi_awready);
    mp_S_AXI_transactor->WDATA(s_axi_wdata);
    mp_S_AXI_transactor->WSTRB(s_axi_wstrb);
    mp_S_AXI_transactor->WLAST(s_axi_wlast);
    mp_S_AXI_transactor->WVALID(s_axi_wvalid);
    mp_S_AXI_transactor->WREADY(s_axi_wready);
    mp_S_AXI_transactor->BID(s_axi_bid);
    mp_S_AXI_transactor->BRESP(s_axi_bresp);
    mp_S_AXI_transactor->BVALID(s_axi_bvalid);
    mp_S_AXI_transactor->BREADY(s_axi_bready);
    mp_S_AXI_transactor->ARID(s_axi_arid);
    mp_S_AXI_transactor->ARADDR(s_axi_araddr);
    mp_s_axi_arlen_converter = new xsc::common::vector2vector_converter<4,8>("s_axi_arlen_converter");
    mp_s_axi_arlen_converter->vector_in(s_axi_arlen);
    mp_s_axi_arlen_converter->vector_out(m_s_axi_arlen_converter_signal);
    mp_S_AXI_transactor->ARLEN(m_s_axi_arlen_converter_signal);
    mp_S_AXI_transactor->ARSIZE(s_axi_arsize);
    mp_S_AXI_transactor->ARBURST(s_axi_arburst);
    mp_s_axi_arlock_converter = new xsc::common::vectorN2scalar_converter<2>("s_axi_arlock_converter");
    mp_s_axi_arlock_converter->vector_in(s_axi_arlock);
    mp_s_axi_arlock_converter->scalar_out(m_s_axi_arlock_converter_signal);
    mp_S_AXI_transactor->ARLOCK(m_s_axi_arlock_converter_signal);
    mp_S_AXI_transactor->ARCACHE(s_axi_arcache);
    mp_S_AXI_transactor->ARPROT(s_axi_arprot);
    mp_S_AXI_transactor->ARQOS(s_axi_arqos);
    mp_S_AXI_transactor->ARVALID(s_axi_arvalid);
    mp_S_AXI_transactor->ARREADY(s_axi_arready);
    mp_S_AXI_transactor->RID(s_axi_rid);
    mp_S_AXI_transactor->RDATA(s_axi_rdata);
    mp_S_AXI_transactor->RRESP(s_axi_rresp);
    mp_S_AXI_transactor->RLAST(s_axi_rlast);
    mp_S_AXI_transactor->RVALID(s_axi_rvalid);
    mp_S_AXI_transactor->RREADY(s_axi_rready);
    mp_S_AXI_transactor->CLK(aclk);
    mp_S_AXI_transactor->RST(aresetn);

    // S_AXI' transactor sockets

    mp_impl->target_rd_socket->bind(*(mp_S_AXI_transactor->rd_socket));
    mp_impl->target_wr_socket->bind(*(mp_S_AXI_transactor->wr_socket));
  }
  else
  {
  }

  // configure 'M_AXI' transactor

  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_auto_pc_0", "M_AXI_TLM_MODE") != 1)
  {
    // Instantiate Socket Stubs

  // 'M_AXI' transactor parameters
    xsc::common_cpp::properties M_AXI_transactor_param_props;
    M_AXI_transactor_param_props.addLong("DATA_WIDTH", "32");
    M_AXI_transactor_param_props.addLong("FREQ_HZ", "100000000");
    M_AXI_transactor_param_props.addLong("ID_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("ADDR_WIDTH", "32");
    M_AXI_transactor_param_props.addLong("AWUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("ARUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("WUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("RUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("BUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("HAS_BURST", "0");
    M_AXI_transactor_param_props.addLong("HAS_LOCK", "0");
    M_AXI_transactor_param_props.addLong("HAS_PROT", "1");
    M_AXI_transactor_param_props.addLong("HAS_CACHE", "0");
    M_AXI_transactor_param_props.addLong("HAS_QOS", "0");
    M_AXI_transactor_param_props.addLong("HAS_REGION", "0");
    M_AXI_transactor_param_props.addLong("HAS_WSTRB", "1");
    M_AXI_transactor_param_props.addLong("HAS_BRESP", "1");
    M_AXI_transactor_param_props.addLong("HAS_RRESP", "1");
    M_AXI_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "0");
    M_AXI_transactor_param_props.addLong("NUM_READ_OUTSTANDING", "8");
    M_AXI_transactor_param_props.addLong("NUM_WRITE_OUTSTANDING", "8");
    M_AXI_transactor_param_props.addLong("MAX_BURST_LENGTH", "1");
    M_AXI_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    M_AXI_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    M_AXI_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    M_AXI_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    M_AXI_transactor_param_props.addLong("HAS_SIZE", "0");
    M_AXI_transactor_param_props.addLong("HAS_RESET", "1");
    M_AXI_transactor_param_props.addFloat("PHASE", "0.0");
    M_AXI_transactor_param_props.addString("PROTOCOL", "AXI4LITE");
    M_AXI_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    M_AXI_transactor_param_props.addString("CLK_DOMAIN", "design_1_processing_system7_0_0_FCLK_CLK0");

    mp_M_AXI_transactor = new xtlm::xaximm_xtlm2pin_t<32,32,12,1,1,1,1,1>("M_AXI_transactor", M_AXI_transactor_param_props);

    // M_AXI' transactor ports

    mp_M_AXI_transactor->AWADDR(m_axi_awaddr);
    mp_M_AXI_transactor->AWPROT(m_axi_awprot);
    mp_M_AXI_transactor->AWVALID(m_axi_awvalid);
    mp_M_AXI_transactor->AWREADY(m_axi_awready);
    mp_M_AXI_transactor->WDATA(m_axi_wdata);
    mp_M_AXI_transactor->WSTRB(m_axi_wstrb);
    mp_M_AXI_transactor->WVALID(m_axi_wvalid);
    mp_M_AXI_transactor->WREADY(m_axi_wready);
    mp_M_AXI_transactor->BRESP(m_axi_bresp);
    mp_M_AXI_transactor->BVALID(m_axi_bvalid);
    mp_M_AXI_transactor->BREADY(m_axi_bready);
    mp_M_AXI_transactor->ARADDR(m_axi_araddr);
    mp_M_AXI_transactor->ARPROT(m_axi_arprot);
    mp_M_AXI_transactor->ARVALID(m_axi_arvalid);
    mp_M_AXI_transactor->ARREADY(m_axi_arready);
    mp_M_AXI_transactor->RDATA(m_axi_rdata);
    mp_M_AXI_transactor->RRESP(m_axi_rresp);
    mp_M_AXI_transactor->RVALID(m_axi_rvalid);
    mp_M_AXI_transactor->RREADY(m_axi_rready);
    mp_M_AXI_transactor->CLK(aclk);
    mp_M_AXI_transactor->RST(aresetn);

    // M_AXI' transactor sockets

    mp_impl->initiator_rd_socket->bind(*(mp_M_AXI_transactor->rd_socket));
    mp_impl->initiator_wr_socket->bind(*(mp_M_AXI_transactor->wr_socket));
  }
  else
  {
  }

}

#endif // RIVIERA




#ifdef VCSSYSTEMC
design_1_auto_pc_0::design_1_auto_pc_0(const sc_core::sc_module_name& nm) : design_1_auto_pc_0_sc(nm),  aclk("aclk"), aresetn("aresetn"), s_axi_awid("s_axi_awid"), s_axi_awaddr("s_axi_awaddr"), s_axi_awlen("s_axi_awlen"), s_axi_awsize("s_axi_awsize"), s_axi_awburst("s_axi_awburst"), s_axi_awlock("s_axi_awlock"), s_axi_awcache("s_axi_awcache"), s_axi_awprot("s_axi_awprot"), s_axi_awqos("s_axi_awqos"), s_axi_awvalid("s_axi_awvalid"), s_axi_awready("s_axi_awready"), s_axi_wid("s_axi_wid"), s_axi_wdata("s_axi_wdata"), s_axi_wstrb("s_axi_wstrb"), s_axi_wlast("s_axi_wlast"), s_axi_wvalid("s_axi_wvalid"), s_axi_wready("s_axi_wready"), s_axi_bid("s_axi_bid"), s_axi_bresp("s_axi_bresp"), s_axi_bvalid("s_axi_bvalid"), s_axi_bready("s_axi_bready"), s_axi_arid("s_axi_arid"), s_axi_araddr("s_axi_araddr"), s_axi_arlen("s_axi_arlen"), s_axi_arsize("s_axi_arsize"), s_axi_arburst("s_axi_arburst"), s_axi_arlock("s_axi_arlock"), s_axi_arcache("s_axi_arcache"), s_axi_arprot("s_axi_arprot"), s_axi_arqos("s_axi_arqos"), s_axi_arvalid("s_axi_arvalid"), s_axi_arready("s_axi_arready"), s_axi_rid("s_axi_rid"), s_axi_rdata("s_axi_rdata"), s_axi_rresp("s_axi_rresp"), s_axi_rlast("s_axi_rlast"), s_axi_rvalid("s_axi_rvalid"), s_axi_rready("s_axi_rready"), m_axi_awaddr("m_axi_awaddr"), m_axi_awprot("m_axi_awprot"), m_axi_awvalid("m_axi_awvalid"), m_axi_awready("m_axi_awready"), m_axi_wdata("m_axi_wdata"), m_axi_wstrb("m_axi_wstrb"), m_axi_wvalid("m_axi_wvalid"), m_axi_wready("m_axi_wready"), m_axi_bresp("m_axi_bresp"), m_axi_bvalid("m_axi_bvalid"), m_axi_bready("m_axi_bready"), m_axi_araddr("m_axi_araddr"), m_axi_arprot("m_axi_arprot"), m_axi_arvalid("m_axi_arvalid"), m_axi_arready("m_axi_arready"), m_axi_rdata("m_axi_rdata"), m_axi_rresp("m_axi_rresp"), m_axi_rvalid("m_axi_rvalid"), m_axi_rready("m_axi_rready")
{
  // initialize pins
  mp_impl->aclk(aclk);
  mp_impl->aresetn(aresetn);

  // initialize transactors
  mp_S_AXI_transactor = NULL;
  mp_s_axi_awlen_converter = NULL;
  mp_s_axi_awlock_converter = NULL;
  mp_s_axi_arlen_converter = NULL;
  mp_s_axi_arlock_converter = NULL;
  mp_M_AXI_transactor = NULL;

  // Instantiate Socket Stubs

  // configure S_AXI_transactor
    xsc::common_cpp::properties S_AXI_transactor_param_props;
    S_AXI_transactor_param_props.addLong("DATA_WIDTH", "32");
    S_AXI_transactor_param_props.addLong("FREQ_HZ", "100000000");
    S_AXI_transactor_param_props.addLong("ID_WIDTH", "12");
    S_AXI_transactor_param_props.addLong("ADDR_WIDTH", "32");
    S_AXI_transactor_param_props.addLong("AWUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("ARUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("WUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("RUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("BUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("HAS_BURST", "1");
    S_AXI_transactor_param_props.addLong("HAS_LOCK", "1");
    S_AXI_transactor_param_props.addLong("HAS_PROT", "1");
    S_AXI_transactor_param_props.addLong("HAS_CACHE", "1");
    S_AXI_transactor_param_props.addLong("HAS_QOS", "1");
    S_AXI_transactor_param_props.addLong("HAS_REGION", "0");
    S_AXI_transactor_param_props.addLong("HAS_WSTRB", "1");
    S_AXI_transactor_param_props.addLong("HAS_BRESP", "1");
    S_AXI_transactor_param_props.addLong("HAS_RRESP", "1");
    S_AXI_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "0");
    S_AXI_transactor_param_props.addLong("NUM_READ_OUTSTANDING", "8");
    S_AXI_transactor_param_props.addLong("NUM_WRITE_OUTSTANDING", "8");
    S_AXI_transactor_param_props.addLong("MAX_BURST_LENGTH", "16");
    S_AXI_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    S_AXI_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    S_AXI_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    S_AXI_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    S_AXI_transactor_param_props.addLong("HAS_SIZE", "1");
    S_AXI_transactor_param_props.addLong("HAS_RESET", "1");
    S_AXI_transactor_param_props.addFloat("PHASE", "0.0");
    S_AXI_transactor_param_props.addString("PROTOCOL", "AXI3");
    S_AXI_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    S_AXI_transactor_param_props.addString("CLK_DOMAIN", "design_1_processing_system7_0_0_FCLK_CLK0");

    mp_S_AXI_transactor = new xtlm::xaximm_pin2xtlm_t<32,32,12,1,1,1,1,1>("S_AXI_transactor", S_AXI_transactor_param_props);
  mp_S_AXI_transactor->AWID(s_axi_awid);
  mp_S_AXI_transactor->AWADDR(s_axi_awaddr);
  mp_s_axi_awlen_converter = new xsc::common::vector2vector_converter<4,8>("s_axi_awlen_converter");
  mp_s_axi_awlen_converter->vector_in(s_axi_awlen);
  mp_s_axi_awlen_converter->vector_out(m_s_axi_awlen_converter_signal);
  mp_S_AXI_transactor->AWLEN(m_s_axi_awlen_converter_signal);
  mp_S_AXI_transactor->AWSIZE(s_axi_awsize);
  mp_S_AXI_transactor->AWBURST(s_axi_awburst);
  mp_s_axi_awlock_converter = new xsc::common::vectorN2scalar_converter<2>("s_axi_awlock_converter");
  mp_s_axi_awlock_converter->vector_in(s_axi_awlock);
  mp_s_axi_awlock_converter->scalar_out(m_s_axi_awlock_converter_signal);
  mp_S_AXI_transactor->AWLOCK(m_s_axi_awlock_converter_signal);
  mp_S_AXI_transactor->AWCACHE(s_axi_awcache);
  mp_S_AXI_transactor->AWPROT(s_axi_awprot);
  mp_S_AXI_transactor->AWQOS(s_axi_awqos);
  mp_S_AXI_transactor->AWVALID(s_axi_awvalid);
  mp_S_AXI_transactor->AWREADY(s_axi_awready);
  mp_S_AXI_transactor->WDATA(s_axi_wdata);
  mp_S_AXI_transactor->WSTRB(s_axi_wstrb);
  mp_S_AXI_transactor->WLAST(s_axi_wlast);
  mp_S_AXI_transactor->WVALID(s_axi_wvalid);
  mp_S_AXI_transactor->WREADY(s_axi_wready);
  mp_S_AXI_transactor->BID(s_axi_bid);
  mp_S_AXI_transactor->BRESP(s_axi_bresp);
  mp_S_AXI_transactor->BVALID(s_axi_bvalid);
  mp_S_AXI_transactor->BREADY(s_axi_bready);
  mp_S_AXI_transactor->ARID(s_axi_arid);
  mp_S_AXI_transactor->ARADDR(s_axi_araddr);
  mp_s_axi_arlen_converter = new xsc::common::vector2vector_converter<4,8>("s_axi_arlen_converter");
  mp_s_axi_arlen_converter->vector_in(s_axi_arlen);
  mp_s_axi_arlen_converter->vector_out(m_s_axi_arlen_converter_signal);
  mp_S_AXI_transactor->ARLEN(m_s_axi_arlen_converter_signal);
  mp_S_AXI_transactor->ARSIZE(s_axi_arsize);
  mp_S_AXI_transactor->ARBURST(s_axi_arburst);
  mp_s_axi_arlock_converter = new xsc::common::vectorN2scalar_converter<2>("s_axi_arlock_converter");
  mp_s_axi_arlock_converter->vector_in(s_axi_arlock);
  mp_s_axi_arlock_converter->scalar_out(m_s_axi_arlock_converter_signal);
  mp_S_AXI_transactor->ARLOCK(m_s_axi_arlock_converter_signal);
  mp_S_AXI_transactor->ARCACHE(s_axi_arcache);
  mp_S_AXI_transactor->ARPROT(s_axi_arprot);
  mp_S_AXI_transactor->ARQOS(s_axi_arqos);
  mp_S_AXI_transactor->ARVALID(s_axi_arvalid);
  mp_S_AXI_transactor->ARREADY(s_axi_arready);
  mp_S_AXI_transactor->RID(s_axi_rid);
  mp_S_AXI_transactor->RDATA(s_axi_rdata);
  mp_S_AXI_transactor->RRESP(s_axi_rresp);
  mp_S_AXI_transactor->RLAST(s_axi_rlast);
  mp_S_AXI_transactor->RVALID(s_axi_rvalid);
  mp_S_AXI_transactor->RREADY(s_axi_rready);
  mp_S_AXI_transactor->CLK(aclk);
  mp_S_AXI_transactor->RST(aresetn);
  // configure M_AXI_transactor
    xsc::common_cpp::properties M_AXI_transactor_param_props;
    M_AXI_transactor_param_props.addLong("DATA_WIDTH", "32");
    M_AXI_transactor_param_props.addLong("FREQ_HZ", "100000000");
    M_AXI_transactor_param_props.addLong("ID_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("ADDR_WIDTH", "32");
    M_AXI_transactor_param_props.addLong("AWUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("ARUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("WUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("RUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("BUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("HAS_BURST", "0");
    M_AXI_transactor_param_props.addLong("HAS_LOCK", "0");
    M_AXI_transactor_param_props.addLong("HAS_PROT", "1");
    M_AXI_transactor_param_props.addLong("HAS_CACHE", "0");
    M_AXI_transactor_param_props.addLong("HAS_QOS", "0");
    M_AXI_transactor_param_props.addLong("HAS_REGION", "0");
    M_AXI_transactor_param_props.addLong("HAS_WSTRB", "1");
    M_AXI_transactor_param_props.addLong("HAS_BRESP", "1");
    M_AXI_transactor_param_props.addLong("HAS_RRESP", "1");
    M_AXI_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "0");
    M_AXI_transactor_param_props.addLong("NUM_READ_OUTSTANDING", "8");
    M_AXI_transactor_param_props.addLong("NUM_WRITE_OUTSTANDING", "8");
    M_AXI_transactor_param_props.addLong("MAX_BURST_LENGTH", "1");
    M_AXI_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    M_AXI_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    M_AXI_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    M_AXI_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    M_AXI_transactor_param_props.addLong("HAS_SIZE", "0");
    M_AXI_transactor_param_props.addLong("HAS_RESET", "1");
    M_AXI_transactor_param_props.addFloat("PHASE", "0.0");
    M_AXI_transactor_param_props.addString("PROTOCOL", "AXI4LITE");
    M_AXI_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    M_AXI_transactor_param_props.addString("CLK_DOMAIN", "design_1_processing_system7_0_0_FCLK_CLK0");

    mp_M_AXI_transactor = new xtlm::xaximm_xtlm2pin_t<32,32,12,1,1,1,1,1>("M_AXI_transactor", M_AXI_transactor_param_props);
  mp_M_AXI_transactor->AWADDR(m_axi_awaddr);
  mp_M_AXI_transactor->AWPROT(m_axi_awprot);
  mp_M_AXI_transactor->AWVALID(m_axi_awvalid);
  mp_M_AXI_transactor->AWREADY(m_axi_awready);
  mp_M_AXI_transactor->WDATA(m_axi_wdata);
  mp_M_AXI_transactor->WSTRB(m_axi_wstrb);
  mp_M_AXI_transactor->WVALID(m_axi_wvalid);
  mp_M_AXI_transactor->WREADY(m_axi_wready);
  mp_M_AXI_transactor->BRESP(m_axi_bresp);
  mp_M_AXI_transactor->BVALID(m_axi_bvalid);
  mp_M_AXI_transactor->BREADY(m_axi_bready);
  mp_M_AXI_transactor->ARADDR(m_axi_araddr);
  mp_M_AXI_transactor->ARPROT(m_axi_arprot);
  mp_M_AXI_transactor->ARVALID(m_axi_arvalid);
  mp_M_AXI_transactor->ARREADY(m_axi_arready);
  mp_M_AXI_transactor->RDATA(m_axi_rdata);
  mp_M_AXI_transactor->RRESP(m_axi_rresp);
  mp_M_AXI_transactor->RVALID(m_axi_rvalid);
  mp_M_AXI_transactor->RREADY(m_axi_rready);
  mp_M_AXI_transactor->CLK(aclk);
  mp_M_AXI_transactor->RST(aresetn);

  // initialize transactors stubs
  S_AXI_transactor_target_wr_socket_stub = nullptr;
  S_AXI_transactor_target_rd_socket_stub = nullptr;
  M_AXI_transactor_initiator_wr_socket_stub = nullptr;
  M_AXI_transactor_initiator_rd_socket_stub = nullptr;

}

void design_1_auto_pc_0::before_end_of_elaboration()
{
  // configure 'S_AXI' transactor
  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_auto_pc_0", "S_AXI_TLM_MODE") != 1)
  {
    mp_impl->target_rd_socket->bind(*(mp_S_AXI_transactor->rd_socket));
    mp_impl->target_wr_socket->bind(*(mp_S_AXI_transactor->wr_socket));
  
  }
  else
  {
    S_AXI_transactor_target_wr_socket_stub = new xtlm::xtlm_aximm_target_stub("wr_socket",0);
    S_AXI_transactor_target_wr_socket_stub->bind(*(mp_S_AXI_transactor->wr_socket));
    S_AXI_transactor_target_rd_socket_stub = new xtlm::xtlm_aximm_target_stub("rd_socket",0);
    S_AXI_transactor_target_rd_socket_stub->bind(*(mp_S_AXI_transactor->rd_socket));
    mp_S_AXI_transactor->disable_transactor();
  }

  // configure 'M_AXI' transactor
  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_auto_pc_0", "M_AXI_TLM_MODE") != 1)
  {
    mp_impl->initiator_rd_socket->bind(*(mp_M_AXI_transactor->rd_socket));
    mp_impl->initiator_wr_socket->bind(*(mp_M_AXI_transactor->wr_socket));
  
  }
  else
  {
    M_AXI_transactor_initiator_wr_socket_stub = new xtlm::xtlm_aximm_initiator_stub("wr_socket",0);
    M_AXI_transactor_initiator_wr_socket_stub->bind(*(mp_M_AXI_transactor->wr_socket));
    M_AXI_transactor_initiator_rd_socket_stub = new xtlm::xtlm_aximm_initiator_stub("rd_socket",0);
    M_AXI_transactor_initiator_rd_socket_stub->bind(*(mp_M_AXI_transactor->rd_socket));
    mp_M_AXI_transactor->disable_transactor();
  }

}

#endif // VCSSYSTEMC




#ifdef MTI_SYSTEMC
design_1_auto_pc_0::design_1_auto_pc_0(const sc_core::sc_module_name& nm) : design_1_auto_pc_0_sc(nm),  aclk("aclk"), aresetn("aresetn"), s_axi_awid("s_axi_awid"), s_axi_awaddr("s_axi_awaddr"), s_axi_awlen("s_axi_awlen"), s_axi_awsize("s_axi_awsize"), s_axi_awburst("s_axi_awburst"), s_axi_awlock("s_axi_awlock"), s_axi_awcache("s_axi_awcache"), s_axi_awprot("s_axi_awprot"), s_axi_awqos("s_axi_awqos"), s_axi_awvalid("s_axi_awvalid"), s_axi_awready("s_axi_awready"), s_axi_wid("s_axi_wid"), s_axi_wdata("s_axi_wdata"), s_axi_wstrb("s_axi_wstrb"), s_axi_wlast("s_axi_wlast"), s_axi_wvalid("s_axi_wvalid"), s_axi_wready("s_axi_wready"), s_axi_bid("s_axi_bid"), s_axi_bresp("s_axi_bresp"), s_axi_bvalid("s_axi_bvalid"), s_axi_bready("s_axi_bready"), s_axi_arid("s_axi_arid"), s_axi_araddr("s_axi_araddr"), s_axi_arlen("s_axi_arlen"), s_axi_arsize("s_axi_arsize"), s_axi_arburst("s_axi_arburst"), s_axi_arlock("s_axi_arlock"), s_axi_arcache("s_axi_arcache"), s_axi_arprot("s_axi_arprot"), s_axi_arqos("s_axi_arqos"), s_axi_arvalid("s_axi_arvalid"), s_axi_arready("s_axi_arready"), s_axi_rid("s_axi_rid"), s_axi_rdata("s_axi_rdata"), s_axi_rresp("s_axi_rresp"), s_axi_rlast("s_axi_rlast"), s_axi_rvalid("s_axi_rvalid"), s_axi_rready("s_axi_rready"), m_axi_awaddr("m_axi_awaddr"), m_axi_awprot("m_axi_awprot"), m_axi_awvalid("m_axi_awvalid"), m_axi_awready("m_axi_awready"), m_axi_wdata("m_axi_wdata"), m_axi_wstrb("m_axi_wstrb"), m_axi_wvalid("m_axi_wvalid"), m_axi_wready("m_axi_wready"), m_axi_bresp("m_axi_bresp"), m_axi_bvalid("m_axi_bvalid"), m_axi_bready("m_axi_bready"), m_axi_araddr("m_axi_araddr"), m_axi_arprot("m_axi_arprot"), m_axi_arvalid("m_axi_arvalid"), m_axi_arready("m_axi_arready"), m_axi_rdata("m_axi_rdata"), m_axi_rresp("m_axi_rresp"), m_axi_rvalid("m_axi_rvalid"), m_axi_rready("m_axi_rready")
{
  // initialize pins
  mp_impl->aclk(aclk);
  mp_impl->aresetn(aresetn);

  // initialize transactors
  mp_S_AXI_transactor = NULL;
  mp_s_axi_awlen_converter = NULL;
  mp_s_axi_awlock_converter = NULL;
  mp_s_axi_arlen_converter = NULL;
  mp_s_axi_arlock_converter = NULL;
  mp_M_AXI_transactor = NULL;

  // Instantiate Socket Stubs

  // configure S_AXI_transactor
    xsc::common_cpp::properties S_AXI_transactor_param_props;
    S_AXI_transactor_param_props.addLong("DATA_WIDTH", "32");
    S_AXI_transactor_param_props.addLong("FREQ_HZ", "100000000");
    S_AXI_transactor_param_props.addLong("ID_WIDTH", "12");
    S_AXI_transactor_param_props.addLong("ADDR_WIDTH", "32");
    S_AXI_transactor_param_props.addLong("AWUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("ARUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("WUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("RUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("BUSER_WIDTH", "0");
    S_AXI_transactor_param_props.addLong("HAS_BURST", "1");
    S_AXI_transactor_param_props.addLong("HAS_LOCK", "1");
    S_AXI_transactor_param_props.addLong("HAS_PROT", "1");
    S_AXI_transactor_param_props.addLong("HAS_CACHE", "1");
    S_AXI_transactor_param_props.addLong("HAS_QOS", "1");
    S_AXI_transactor_param_props.addLong("HAS_REGION", "0");
    S_AXI_transactor_param_props.addLong("HAS_WSTRB", "1");
    S_AXI_transactor_param_props.addLong("HAS_BRESP", "1");
    S_AXI_transactor_param_props.addLong("HAS_RRESP", "1");
    S_AXI_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "0");
    S_AXI_transactor_param_props.addLong("NUM_READ_OUTSTANDING", "8");
    S_AXI_transactor_param_props.addLong("NUM_WRITE_OUTSTANDING", "8");
    S_AXI_transactor_param_props.addLong("MAX_BURST_LENGTH", "16");
    S_AXI_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    S_AXI_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    S_AXI_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    S_AXI_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    S_AXI_transactor_param_props.addLong("HAS_SIZE", "1");
    S_AXI_transactor_param_props.addLong("HAS_RESET", "1");
    S_AXI_transactor_param_props.addFloat("PHASE", "0.0");
    S_AXI_transactor_param_props.addString("PROTOCOL", "AXI3");
    S_AXI_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    S_AXI_transactor_param_props.addString("CLK_DOMAIN", "design_1_processing_system7_0_0_FCLK_CLK0");

    mp_S_AXI_transactor = new xtlm::xaximm_pin2xtlm_t<32,32,12,1,1,1,1,1>("S_AXI_transactor", S_AXI_transactor_param_props);
  mp_S_AXI_transactor->AWID(s_axi_awid);
  mp_S_AXI_transactor->AWADDR(s_axi_awaddr);
  mp_s_axi_awlen_converter = new xsc::common::vector2vector_converter<4,8>("s_axi_awlen_converter");
  mp_s_axi_awlen_converter->vector_in(s_axi_awlen);
  mp_s_axi_awlen_converter->vector_out(m_s_axi_awlen_converter_signal);
  mp_S_AXI_transactor->AWLEN(m_s_axi_awlen_converter_signal);
  mp_S_AXI_transactor->AWSIZE(s_axi_awsize);
  mp_S_AXI_transactor->AWBURST(s_axi_awburst);
  mp_s_axi_awlock_converter = new xsc::common::vectorN2scalar_converter<2>("s_axi_awlock_converter");
  mp_s_axi_awlock_converter->vector_in(s_axi_awlock);
  mp_s_axi_awlock_converter->scalar_out(m_s_axi_awlock_converter_signal);
  mp_S_AXI_transactor->AWLOCK(m_s_axi_awlock_converter_signal);
  mp_S_AXI_transactor->AWCACHE(s_axi_awcache);
  mp_S_AXI_transactor->AWPROT(s_axi_awprot);
  mp_S_AXI_transactor->AWQOS(s_axi_awqos);
  mp_S_AXI_transactor->AWVALID(s_axi_awvalid);
  mp_S_AXI_transactor->AWREADY(s_axi_awready);
  mp_S_AXI_transactor->WDATA(s_axi_wdata);
  mp_S_AXI_transactor->WSTRB(s_axi_wstrb);
  mp_S_AXI_transactor->WLAST(s_axi_wlast);
  mp_S_AXI_transactor->WVALID(s_axi_wvalid);
  mp_S_AXI_transactor->WREADY(s_axi_wready);
  mp_S_AXI_transactor->BID(s_axi_bid);
  mp_S_AXI_transactor->BRESP(s_axi_bresp);
  mp_S_AXI_transactor->BVALID(s_axi_bvalid);
  mp_S_AXI_transactor->BREADY(s_axi_bready);
  mp_S_AXI_transactor->ARID(s_axi_arid);
  mp_S_AXI_transactor->ARADDR(s_axi_araddr);
  mp_s_axi_arlen_converter = new xsc::common::vector2vector_converter<4,8>("s_axi_arlen_converter");
  mp_s_axi_arlen_converter->vector_in(s_axi_arlen);
  mp_s_axi_arlen_converter->vector_out(m_s_axi_arlen_converter_signal);
  mp_S_AXI_transactor->ARLEN(m_s_axi_arlen_converter_signal);
  mp_S_AXI_transactor->ARSIZE(s_axi_arsize);
  mp_S_AXI_transactor->ARBURST(s_axi_arburst);
  mp_s_axi_arlock_converter = new xsc::common::vectorN2scalar_converter<2>("s_axi_arlock_converter");
  mp_s_axi_arlock_converter->vector_in(s_axi_arlock);
  mp_s_axi_arlock_converter->scalar_out(m_s_axi_arlock_converter_signal);
  mp_S_AXI_transactor->ARLOCK(m_s_axi_arlock_converter_signal);
  mp_S_AXI_transactor->ARCACHE(s_axi_arcache);
  mp_S_AXI_transactor->ARPROT(s_axi_arprot);
  mp_S_AXI_transactor->ARQOS(s_axi_arqos);
  mp_S_AXI_transactor->ARVALID(s_axi_arvalid);
  mp_S_AXI_transactor->ARREADY(s_axi_arready);
  mp_S_AXI_transactor->RID(s_axi_rid);
  mp_S_AXI_transactor->RDATA(s_axi_rdata);
  mp_S_AXI_transactor->RRESP(s_axi_rresp);
  mp_S_AXI_transactor->RLAST(s_axi_rlast);
  mp_S_AXI_transactor->RVALID(s_axi_rvalid);
  mp_S_AXI_transactor->RREADY(s_axi_rready);
  mp_S_AXI_transactor->CLK(aclk);
  mp_S_AXI_transactor->RST(aresetn);
  // configure M_AXI_transactor
    xsc::common_cpp::properties M_AXI_transactor_param_props;
    M_AXI_transactor_param_props.addLong("DATA_WIDTH", "32");
    M_AXI_transactor_param_props.addLong("FREQ_HZ", "100000000");
    M_AXI_transactor_param_props.addLong("ID_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("ADDR_WIDTH", "32");
    M_AXI_transactor_param_props.addLong("AWUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("ARUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("WUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("RUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("BUSER_WIDTH", "0");
    M_AXI_transactor_param_props.addLong("HAS_BURST", "0");
    M_AXI_transactor_param_props.addLong("HAS_LOCK", "0");
    M_AXI_transactor_param_props.addLong("HAS_PROT", "1");
    M_AXI_transactor_param_props.addLong("HAS_CACHE", "0");
    M_AXI_transactor_param_props.addLong("HAS_QOS", "0");
    M_AXI_transactor_param_props.addLong("HAS_REGION", "0");
    M_AXI_transactor_param_props.addLong("HAS_WSTRB", "1");
    M_AXI_transactor_param_props.addLong("HAS_BRESP", "1");
    M_AXI_transactor_param_props.addLong("HAS_RRESP", "1");
    M_AXI_transactor_param_props.addLong("SUPPORTS_NARROW_BURST", "0");
    M_AXI_transactor_param_props.addLong("NUM_READ_OUTSTANDING", "8");
    M_AXI_transactor_param_props.addLong("NUM_WRITE_OUTSTANDING", "8");
    M_AXI_transactor_param_props.addLong("MAX_BURST_LENGTH", "1");
    M_AXI_transactor_param_props.addLong("NUM_READ_THREADS", "4");
    M_AXI_transactor_param_props.addLong("NUM_WRITE_THREADS", "4");
    M_AXI_transactor_param_props.addLong("RUSER_BITS_PER_BYTE", "0");
    M_AXI_transactor_param_props.addLong("WUSER_BITS_PER_BYTE", "0");
    M_AXI_transactor_param_props.addLong("HAS_SIZE", "0");
    M_AXI_transactor_param_props.addLong("HAS_RESET", "1");
    M_AXI_transactor_param_props.addFloat("PHASE", "0.0");
    M_AXI_transactor_param_props.addString("PROTOCOL", "AXI4LITE");
    M_AXI_transactor_param_props.addString("READ_WRITE_MODE", "READ_WRITE");
    M_AXI_transactor_param_props.addString("CLK_DOMAIN", "design_1_processing_system7_0_0_FCLK_CLK0");

    mp_M_AXI_transactor = new xtlm::xaximm_xtlm2pin_t<32,32,12,1,1,1,1,1>("M_AXI_transactor", M_AXI_transactor_param_props);
  mp_M_AXI_transactor->AWADDR(m_axi_awaddr);
  mp_M_AXI_transactor->AWPROT(m_axi_awprot);
  mp_M_AXI_transactor->AWVALID(m_axi_awvalid);
  mp_M_AXI_transactor->AWREADY(m_axi_awready);
  mp_M_AXI_transactor->WDATA(m_axi_wdata);
  mp_M_AXI_transactor->WSTRB(m_axi_wstrb);
  mp_M_AXI_transactor->WVALID(m_axi_wvalid);
  mp_M_AXI_transactor->WREADY(m_axi_wready);
  mp_M_AXI_transactor->BRESP(m_axi_bresp);
  mp_M_AXI_transactor->BVALID(m_axi_bvalid);
  mp_M_AXI_transactor->BREADY(m_axi_bready);
  mp_M_AXI_transactor->ARADDR(m_axi_araddr);
  mp_M_AXI_transactor->ARPROT(m_axi_arprot);
  mp_M_AXI_transactor->ARVALID(m_axi_arvalid);
  mp_M_AXI_transactor->ARREADY(m_axi_arready);
  mp_M_AXI_transactor->RDATA(m_axi_rdata);
  mp_M_AXI_transactor->RRESP(m_axi_rresp);
  mp_M_AXI_transactor->RVALID(m_axi_rvalid);
  mp_M_AXI_transactor->RREADY(m_axi_rready);
  mp_M_AXI_transactor->CLK(aclk);
  mp_M_AXI_transactor->RST(aresetn);

  // initialize transactors stubs
  S_AXI_transactor_target_wr_socket_stub = nullptr;
  S_AXI_transactor_target_rd_socket_stub = nullptr;
  M_AXI_transactor_initiator_wr_socket_stub = nullptr;
  M_AXI_transactor_initiator_rd_socket_stub = nullptr;

}

void design_1_auto_pc_0::before_end_of_elaboration()
{
  // configure 'S_AXI' transactor
  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_auto_pc_0", "S_AXI_TLM_MODE") != 1)
  {
    mp_impl->target_rd_socket->bind(*(mp_S_AXI_transactor->rd_socket));
    mp_impl->target_wr_socket->bind(*(mp_S_AXI_transactor->wr_socket));
  
  }
  else
  {
    S_AXI_transactor_target_wr_socket_stub = new xtlm::xtlm_aximm_target_stub("wr_socket",0);
    S_AXI_transactor_target_wr_socket_stub->bind(*(mp_S_AXI_transactor->wr_socket));
    S_AXI_transactor_target_rd_socket_stub = new xtlm::xtlm_aximm_target_stub("rd_socket",0);
    S_AXI_transactor_target_rd_socket_stub->bind(*(mp_S_AXI_transactor->rd_socket));
    mp_S_AXI_transactor->disable_transactor();
  }

  // configure 'M_AXI' transactor
  if (xsc::utils::xsc_sim_manager::getInstanceParameterInt("design_1_auto_pc_0", "M_AXI_TLM_MODE") != 1)
  {
    mp_impl->initiator_rd_socket->bind(*(mp_M_AXI_transactor->rd_socket));
    mp_impl->initiator_wr_socket->bind(*(mp_M_AXI_transactor->wr_socket));
  
  }
  else
  {
    M_AXI_transactor_initiator_wr_socket_stub = new xtlm::xtlm_aximm_initiator_stub("wr_socket",0);
    M_AXI_transactor_initiator_wr_socket_stub->bind(*(mp_M_AXI_transactor->wr_socket));
    M_AXI_transactor_initiator_rd_socket_stub = new xtlm::xtlm_aximm_initiator_stub("rd_socket",0);
    M_AXI_transactor_initiator_rd_socket_stub->bind(*(mp_M_AXI_transactor->rd_socket));
    mp_M_AXI_transactor->disable_transactor();
  }

}

#endif // MTI_SYSTEMC




design_1_auto_pc_0::~design_1_auto_pc_0()
{
  delete mp_S_AXI_transactor;
  delete mp_s_axi_awlen_converter;
  delete mp_s_axi_awlock_converter;
  delete mp_s_axi_arlen_converter;
  delete mp_s_axi_arlock_converter;

  delete mp_M_AXI_transactor;

}

#ifdef MTI_SYSTEMC
SC_MODULE_EXPORT(design_1_auto_pc_0);
#endif

#ifdef XM_SYSTEMC
XMSC_MODULE_EXPORT(design_1_auto_pc_0);
#endif

#ifdef RIVIERA
SC_MODULE_EXPORT(design_1_auto_pc_0);
#endif

