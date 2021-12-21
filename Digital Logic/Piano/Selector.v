module Selector (input iClk,
                 input iReset_n,
                 input [7:0]iData1,
                 input [7:0]iData2,
                 input [7:0]iData3,
                 
                 input [3:0] iAddress,
                 output reg [7:0]oData);

    // iAddress: 0=not play built-in song

    always @(posedge iClk or negedge iReset_n) begin
        if (!iReset_n) begin
            oData <= 0;
        end
        else begin
            case(iAddress)
                1: oData       <= iData1;
                2: oData       <= iData2;
                4: oData       <= iData3;
                default: oData <= 0;
            endcase
        end
    end
    
endmodule
