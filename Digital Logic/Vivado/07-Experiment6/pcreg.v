module pcreg (input clk,
              input rst,
              input ena,
              input[31:0] data_in,
              output reg[31:0] data_out);
    
    wire inputflag;
    assign inputflag = clk & ena;
    wire resetflag;
    assign resetflag=~rst;

    genvar i ;
    generate
        for(i=1; i<=31; i=i+1) begin: 
            Asynchronous_D_FF uut(clk,data_in[i],resetflag,data_out[i]);
        end
    endgenerate



endmodule
    
    
    module Asynchronous_D_FF (input CLK,
        input D,
        input RST_n,
        output reg Q1,
        output reg Q2);
        
        always @(posedge CLK or negedge RST_n)    begin
            if (RST_n == 0) begin
                Q1 = 0;
                Q2 = 1;
            end
            else begin
                Q1 = D;
                Q2 = ~D;
            end
        end
        
    endmodule
