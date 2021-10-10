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
        iData=8'b11111111;
        #50 iData=8'b11111110;
        #50 iData=8'b11111101;
        #50 iData=8'b11111011;
        #50 iData=8'b11110111;
        #50 iData=8'b11101111;
        #50 iData=8'b11011111;
        #50 iData=8'b10111111;
        #50 iData=8'b01111111;

        #50 iData=8'b11111110;
        #50 iData=8'b11111100;
        #50 iData=8'b11111001;
        #50 iData=8'b11110011;
        #50 iData=8'b11100110;
        #50 iData=8'b11010101;
        #50 iData=8'b10101010;
        #50 iData=8'b00001111;
        #50 iData=8'b01010100;

        #50 iData=8'b11111111;
        #50 iData=8'b11111110;
        #50 iData=8'b11111101;
        #50 iData=8'b11111011;
        #50 iData=8'b11110111;
        #50 iData=8'b11101111;
        #50 iData=8'b11011111;
        #50 iData=8'b10111111;
        #50 iData=8'b01111111;


    end

    initial
    begin
        #50
        iEI=0;
        #900 iEI=1;
    end
endmodule