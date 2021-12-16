module Frenp(input iClk,
             input iReset_n,
             output reg oClk);
    
    reg [4:0] count;
    
    always @(posedge iClk or negedge iReset_n)
        if (!iReset_n)
        begin
            count  <= 0;
            oClk <= 1;
        end
        else
        begin
            if (count == 50000000 / 1000000 / 2 - 1)
            begin
                count  <= 0;
                oClk <= ~oClk;
            end
            else
            begin
                count <= count + 1;
            end
        end
    
endmodule
