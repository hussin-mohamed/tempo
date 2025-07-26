`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07/22/2025 04:18:48 PM
// Design Name: 
// Module Name: clock_divider
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

// divide by 8 frequency

module clock_divider(
    input clk,rst,output clk_required
  );
  reg[2:0] counter;
    always @(posedge clk or negedge rst) begin
        if (!rst) begin
            counter<=0;
        end
        else begin
            counter<=counter+1;
        end
    end
    assign clk_required=(counter<4)?1:0;
endmodule
