module Controler (input iClk,
                  input iReset_n,
                  input [7:0] iPs2_Data,
                  //input [12:0] iFreq,
                  input iCount,
                  output oRing,
                  output oCountEnable);
    //iPs2_Data: keyboard data after decoded, if 99, stop playing note after a cycle


    always @(posedge iClk or negedge iReset_n)
    begin
        if (!Reset_n)
        begin
            
        end
        else
        begin
            
            if (iPs2_Data == 99)   //stop after a cycle
            begin
                oCountEnable <= 0;
            end
            
                 
            
            
            
            
            
            
            
        end
    end
    
    
    assign oRing=iCount;
    
    
    
    
    
endmodule
