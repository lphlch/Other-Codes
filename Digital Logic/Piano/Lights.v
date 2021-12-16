module Lights (input iClk,
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
            oLights = iEnable;
        end
    end
endmodule
