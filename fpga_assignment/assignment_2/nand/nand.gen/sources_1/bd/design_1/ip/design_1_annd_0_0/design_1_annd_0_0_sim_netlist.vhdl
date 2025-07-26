-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.1 (lin64) Build 3865809 Sun May  7 15:04:56 MDT 2023
-- Date        : Tue Jul 22 18:21:31 2025
-- Host        : hhussien-lx01.engeu1.analog.com running 64-bit Red Hat Enterprise Linux release 8.8 (Ootpa)
-- Command     : write_vhdl -force -mode funcsim
--               /home/hhussien/fpga_assignment/assignment_2/nand/nand.gen/sources_1/bd/design_1/ip/design_1_annd_0_0/design_1_annd_0_0_sim_netlist.vhdl
-- Design      : design_1_annd_0_0
-- Purpose     : This VHDL netlist is a functional simulation representation of the design and should not be modified or
--               synthesized. This netlist cannot be used for SDF annotated simulation.
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity design_1_annd_0_0 is
  port (
    a : in STD_LOGIC;
    b : in STD_LOGIC;
    c : out STD_LOGIC
  );
  attribute NotValidForBitStream : boolean;
  attribute NotValidForBitStream of design_1_annd_0_0 : entity is true;
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of design_1_annd_0_0 : entity is "design_1_annd_0_0,annd,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of design_1_annd_0_0 : entity is "yes";
  attribute IP_DEFINITION_SOURCE : string;
  attribute IP_DEFINITION_SOURCE of design_1_annd_0_0 : entity is "module_ref";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of design_1_annd_0_0 : entity is "annd,Vivado 2023.1";
end design_1_annd_0_0;

architecture STRUCTURE of design_1_annd_0_0 is
begin
c_INST_0: unisim.vcomponents.LUT2
    generic map(
      INIT => X"8"
    )
        port map (
      I0 => a,
      I1 => b,
      O => c
    );
end STRUCTURE;
