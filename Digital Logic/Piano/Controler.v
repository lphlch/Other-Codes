module Controler (input iClk,
                  input iReset_n,
                  input [7:0] iPs2_Data,
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

            //oRing<=iCount;
        end
    end
    
    

    
    
    
    
    
endmodule
