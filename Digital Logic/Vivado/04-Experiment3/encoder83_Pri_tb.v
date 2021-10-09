`timescale 1ns/1ns
module encoder83_Pri_tb ();
    reg [7:0] iData;
    reg iEI;
    wire [2:0] oData;
    wire oEO;
    encoder83_Pri uut(iData,iEI,oData,oEO);
    initial
    begin
        #50
        iData=8'b00000000;
        #50 iData=8'b00000001;
        #50 iData=8'b00000010;
        #50 iData=8'b00000100;
        #50 iData=8'b00001000;
        #50 iData=8'b00010000;
        #50 iData=8'b00100000;
        #50 iData=8'b01000000;
        #50 iData=8'b10000000;

        #50 iData=8'b00000000;
        #50 iData=8'b00000001;
        #50 iData=8'b00000010;
        #50 iData=8'b00000100;
        #50 iData=8'b00001000;
        #50 iData=8'b00010000;
        #50 iData=8'b00100000;
        #50 iData=8'b01000000;
        #50 iData=8'b10000000;
    end

    initial
    begin
        #50
        iEI=0;
        #400 iEI=1;
    end
endmodule