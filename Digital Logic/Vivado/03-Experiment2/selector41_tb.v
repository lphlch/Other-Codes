`timescale 1ns/1ns
module selector41_tb;
    reg iS1;
    reg iS0;
    reg [3:0]iC0,iC1,iC2,iC3;
    wire oZ;
    initial
    begin
        iS1=0;
        #40 iS1=0;
        #40 iS1=0;
        #40 iS1=1;
        #40 iS1=1;
    end
    initial
    begin
        iS0=0;
        #40 iS0=0;
        #40 iS0=1;
        #40 iS0=0;
        #40 iS0=1;
    end
    initial
    begin
        iC0=0;
        #20 iC0=0;
        #20 iC0=1;
        #20 iC0=0;
        #20 iC0=1;
        #20 iC0=0;
        #20 iC0=1;
        #20 iC0=0;
        #20 iC0=1;
    end
        initial
    begin
        iC1=0;
        #20 iC1=0;
        #20 iC1=1;
        #20 iC1=0;
        #20 iC1=1;
        #20 iC1=0;
        #20 iC1=1;
        #20 iC1=0;
        #20 iC1=1;
    end
        initial
    begin
        iC2=0;
        #20 iC2=0;
        #20 iC2=1;
        #20 iC2=0;
        #20 iC2=1;
        #20 iC2=0;
        #20 iC2=1;
        #20 iC2=0;
        #20 iC2=1;
    end
            initial
    begin
        iC3=0;
        #20 iC3=0;
        #20 iC3=1;
        #20 iC3=0;
        #20 iC3=1;
        #20 iC3=0;
        #20 iC3=1;
        #20 iC3=0;
        #20 iC3=1;
    end
    selector41 uut(iC0,iC1,iC2,iC3,iS1,iS0,oZ);
endmodule