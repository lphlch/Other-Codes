`timescale 1ns/1ns
module encoder83_Pri_tb ();
    reg [7:0] iData;
    reg iEI;
    wire [2:0] oData;
    wire oEO;
    encoder83_Pri uut(iData,iEI,oData,oEO);
    initial
    begin
        iData=8'b00000000;
        #100 iData=8'b00000001;
        #100 iData=8'b00000010;
        #100 iData=8'b00000100;
        #100 iData=8'b00001000;
        #100 iData=8'b00010000;
        #100 iData=8'b00100000;
        #100 iData=8'b01000000;
        #100 iData=8'b10000000;

        #100 iData=8'b00000000;
        #100 iData=8'b00000001;
        #100 iData=8'b00000010;
        #100 iData=8'b00000100;
        #100 iData=8'b00001000;
        #100 iData=8'b00010000;
        #100 iData=8'b00100000;
        #100 iData=8'b01000000;
        #100 iData=8'b10000000;
    end

    initial
    begin
        iEI=0;
        #800 iEI=1;
    end
endmodule