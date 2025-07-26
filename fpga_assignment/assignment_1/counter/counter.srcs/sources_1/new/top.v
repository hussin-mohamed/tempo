`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07/22/2025 04:44:40 PM
// Design Name: 
// Module Name: top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module top(
    input clk,rst,output [2:0] count
    );
    wire clk_required;
    wire clk_used;
    wire locked;
    clk_wiz_0 PLL
   (
    // Clock out ports
    .clk_out1(clk_required),     // output clk_out1
    // Status and control signals
    .resetn(rst), // input reset
    .locked(locked),       // output locked
   // Clock in ports
    .clk_in1(clk)      // input clk_in1
);
    clock_divider divider(
    .clk(clk_required),
    .rst(locked),
    .clk_required(clk_used)
    );
    counter_3bits counter(
    .clk(clk_used),
    .rst(locked),
    .count(count)
    );
endmodule
