`timescale 1ns/1ns
module ram2_tb();
    reg clk,ena,wena;
    reg [4:0] addr;
    reg [31:0] data;

    ram2 uut (clk,ena,wena,addr,data);
    
    initial begin
        ena  = 0;
        wena = 0;
        addr = 0;
        data  = 0;
        #20
        ena  = 1;  //out 0
        wena = 1; //enable write
        #20
        data = 32'hffffffff;   //addr 0 = ffffffff
        #20
        addr = 4;
        data  = 32'h80008000;   //addr 4  = 80008000
        #20
        wena = 0; //out addr 4 = 80008000
        #20
        addr = 5; //out addr 5 = 0
        #20
        wena = 1; //addr5 = 80008000
        #20
        wena = 0; //out addr5 = 80008000
        #20
        addr=0; //out addr0=ffffffff
        #20
        ena = 0;  //out z
        #20
        addr = 6; //out z addr = 0
    end
    
    initial begin
        clk = 0;
        repeat(100) begin
            #5 clk = ~clk;
        end
    end
    
endmodule
