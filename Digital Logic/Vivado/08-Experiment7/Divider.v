module Divider (input I_CLK,
                input rst,
                output O_CLK);
    
    parameter i       = 20;
    reg[31:0] counter = 0;
    reg outputT       = 0;
    always @(posedge I_CLK or posedge rst)
        if (rst) begin
            counter = 0;
            outputT   = 1;
        end
        else if (counter < i / 2 ) begin
            counter = counter + 1;
            outputT   = outputT;
        end
        else begin
            counter = 1;
            outputT   = ~outputT;
        end
    
    assign O_CLK = outputT;
endmodule
    
