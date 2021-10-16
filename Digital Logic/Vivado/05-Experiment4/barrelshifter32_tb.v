`timescale 1ns/1ns
module barrelshifter32_tb ();
    reg [31:0] a;
    reg [4:0]  b;
    reg [1:0]  aluc;
    wire [31:0] c;
    barrelshifter32 uut(a,b,aluc,c);
    repeat(4) begin
        a = 32'b101001011111000011000011;
        
        b     = 4'b0000;
        #25 b = 4'b0001;
        #25 b = 4'b0010;
        #25 b = 4'b0011;
        #25 b = 4'b0100;
        #25 b = 4'b0101;
        #25 b = 4'b0110;
        #25 b = 4'b0111;
        #25 b = 4'b1000;
        #25 b = 4'b1001;
        #25 b = 4'b1010;
        #25 b = 4'b1011;
        #25 b = 4'b1100;
        #25 b = 4'b1101;
        #25 b = 4'b1110;
        #25 b = 4'b1111;
    end
    initial begin
        aluc      = 2b'00;
        #400 aluc = 2b'01;
        #400 aluc = 2b'10;
        #400 aluc = 2b'11;
    end
endmodule
