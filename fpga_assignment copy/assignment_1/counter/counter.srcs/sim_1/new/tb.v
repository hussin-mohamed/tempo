`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07/23/2025 02:20:02 PM
// Design Name: 
// Module Name: tb
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


module tb(
    );
    reg clk,rst;
    wire [2:0]counter;
    top dut(.clk(clk),.rst(rst),.count(counter));
    always #5 clk=~clk;
    initial begin 
        clk=0;
        rst=0;
        @(negedge clk);
        @(negedge clk);
        rst=1;
        repeat(5000)
        @(negedge clk);
        $stop;
    end
endmodule
