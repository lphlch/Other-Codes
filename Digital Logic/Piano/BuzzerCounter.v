module BuzzerCounter (input iClk,
                      input iReset_n,
                      input iCountEnable,
                      output oRing);
    
    // iCountEnable: if 1, oRing always 1(press down key), if 0, start counting after a cycle
    // oRing: if 1, note is able to play. Default to play 0.2s. 0 to stop playing
    
    parameter i = 200000;   //0.2s
    reg[20:0] count;
    always @(posedge iClk) //counter, sound lasting 0.2s in default
    begin 
        if (!iReset_n)
        begin   //reset
            count <= 0;
            oRing <= 0;
        end
        else
        begin
            if (iCountEnable) //always 1
            begin
                count <= 0;
                oRing <= 1;
            end
            else    //stop after a cycle
            begin
                if (count == i) begin   //count to 0.2s
                    count <= 0;
                    oRing <= 0;
                end
                
                if (count != 0) begin   //continue counting
                    count <= count + 1;
                    oRing <= 1;
                end
            end

        end
        
    end
    
endmodule
