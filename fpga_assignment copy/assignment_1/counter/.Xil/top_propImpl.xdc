set_property SRC_FILE_INFO {cfile:/home/hhussien/fpga_assignment/assignment_1/counter/counter.gen/sources_1/ip/clk_wiz_0/clk_wiz_0.xdc rfile:../counter.gen/sources_1/ip/clk_wiz_0/clk_wiz_0.xdc id:1 order:EARLY scoped_inst:PLL/inst} [current_design]
set_property SRC_FILE_INFO {cfile:/home/hhussien/fpga_assignment/assignment_1/counter/counter.srcs/constrs_1/new/cons1.xdc rfile:../counter.srcs/constrs_1/new/cons1.xdc id:2} [current_design]
current_instance PLL/inst
set_property src_info {type:SCOPED_XDC file:1 line:57 export:INPUT save:INPUT read:READ} [current_design]
set_input_jitter [get_clocks -of_objects [get_ports clk_in1]] 0.100
current_instance
set_property src_info {type:XDC file:2 line:3 export:INPUT save:INPUT read:READ} [current_design]
create_clock -name clock -period 10 [get_ports <clock port>]
set_property src_info {type:XDC file:2 line:44 export:INPUT save:INPUT read:READ} [current_design]
set_property IOSTANDARD LVCMOS33 [get_ports -of_objects [get_iobanks 33]];
set_property src_info {type:XDC file:2 line:49 export:INPUT save:INPUT read:READ} [current_design]
set_property IOSTANDARD LVCMOS18 [get_ports -of_objects [get_iobanks 34]];
set_property src_info {type:XDC file:2 line:54 export:INPUT save:INPUT read:READ} [current_design]
set_property IOSTANDARD LVCMOS18 [get_ports -of_objects [get_iobanks 35]];
set_property src_info {type:XDC file:2 line:57 export:INPUT save:INPUT read:READ} [current_design]
set_property IOSTANDARD LVCMOS33 [get_ports -of_objects [get_iobanks 13]];
