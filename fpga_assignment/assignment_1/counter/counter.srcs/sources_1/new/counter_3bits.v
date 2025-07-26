`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07/22/2025 04:41:14 PM
// Design Name: 
// Module Name: counter_3bits
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


module counter_3bits(
    input clk,rst,output reg[2:0] count
    );
    always @(posedge clk or negedge rst) begin
        if(!rst) begin
        count<=0;
        end 
        else begin 
        count<=count+1;
        end
    end
endmodule
