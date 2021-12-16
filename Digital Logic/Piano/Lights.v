module Lights (input iClk,
               input iReset_n,
               input[7:0] iEnable,
               output reg oLights
               );
    
    always @(posedge iClk) begin
        if (!iReset_n)
        begin
            oLights <= 0;
        end
        else
        begin
            oLights = (iEnable==0 || iEnable==99)? 0 : 1;
        end
    end
endmodule

module Lights2 (input iClk,
               input iReset_n,
               input iEnable,
               output reg oLights
               );
    
    always @(posedge iClk) begin
        if (!iReset_n)
        begin
            oLights <= 0;
        end
        else
        begin
            oLights = (iEnable==0)? 0 : 1;
        end
    end
endmodule