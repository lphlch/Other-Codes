module Divider (input I_CLK,
                input rst,
                output O_CLK);
    
    parameter i = 20;
    reg[31:0] counter;
    reg outputT;
    always @(posedge I_CLK or posedge rst) begin
        if (rst) begin
            counter <= 0;
            outputT <= 0;
        end
        else if (counter == i) begin
            counter <= 0;
            outputT   <= 1;
        end
        else begin
            counter <= counter + 1;
            outputT   <= 0;
        end
    end
    
    assign O_CLK = outputT;
endmodule
