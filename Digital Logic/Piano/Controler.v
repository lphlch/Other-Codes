module Controler (input iClk,
                  input iReset_n,
                  input [7:0] iPs2_Data,
                  input [7:0] iSong_Data,
                  input iSongSelect,
                  output [7:0] oFreq_Data,
                  output reg oCountEnable);
    //iPs2_Data: keyboard data after decoded, if 99, stop playing note after a cycle


    always @(posedge iClk or negedge iReset_n)
    begin
        if (!iReset_n)
        begin
            oCountEnable <= 0;
        end
        else
        begin
            if (iPs2_Data == 99 ||iPs2_Data ==0)   //stop after a cycle
            begin
                oCountEnable <= 0;
            end
            else
            begin
                oCountEnable <= 1;
            end

            if(iSongSelect == 1)begin
                oCountEnable<=1;
            end
        end
    end
    
    assign oFreq_Data=iSongSelect?iSong_Data:iPs2_Data;

    
    
    
    
    
endmodule
