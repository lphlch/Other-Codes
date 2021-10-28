`timescale 1ns/1ns
module Synchronous_D_FF_tb ();
    reg clk,d,reset;
    wire out1,out2;
    
    Synchronous_D_FF uut (clk,d,reset,out1,out2);
    
    initial begin
        reset = 0;
        d     = 0;
        #30
        d = 1;
        #30
        d = 0;
        #30
        d     = 1;
        reset = 1;
        #30
        d = 0;
    end
    
    initial begin
        clk = 0;
        
        repeat(10) begin
            #13 clk = ~clk;
        end
    end
    
endmodule
