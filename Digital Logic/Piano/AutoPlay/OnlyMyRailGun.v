module OnlyMyRailGun (input iClk,
                      input iReset_n,
                      input iEnable,
                      output reg[7:0] oFreq);
    
    parameter notes_speed = 135*4*4;    //notes every minutes = meter speed * notes per meter
    parameter notes_total = 500;
    reg [20:0] note,count;
    
    always @(posedge iClk or negedge iReset_n) begin
        
        if (!iReset_n) begin
            oFreq <= 0;
            note  <= 0;
            count <= 0;
        end
        else begin
            if (iEnable) begin
                if (count == 60*3000000/notes_speed) begin   //count to 0.15s
                    count <= 0;
                    note <= note+1;
                end
                else begin
                    count <= count+1;
                end

                if(note==notes_total) begin
                    note <= 0;
                end
                
                case (note)
                    257,258,259,260: oFreq <= 51;
                    262,264,265,266,267: oFreq <= 53;

                    268,269,270,271: oFreq <= 51;

                    273,274,275,276: oFreq <= 51;
                    278,280,281,282,283: oFreq <= 53;

                    285,286,287,288: oFreq <= 51;


                    290,291,292,293: oFreq <= 51;
                    295,297,298,299,300: oFreq <= 53;

                    302,303,304,305: oFreq <= 53;

                    307,308,309,310: oFreq <= 53;
                    312,313,314,315: oFreq <= 55;

                    317,318,319,320: oFreq <= 56;
                    322,323,324,325: oFreq <= 58;


                    327,328,329,330,331,332,333,334,335: oFreq <= 55;

                    337,338,339,340,341,342,343,344,345: oFreq <= 51;

                    347,348,349,350,351,352,353,354,355: oFreq <= 61;

                    357,358,359,360,361,362,363,364,365: oFreq <= 58;

                    default: oFreq<=100;
                endcase
                
                
                
                
                
                
            end
            else begin
                count <= 0;
                note  <= 0;
            end
        end
    end
endmodule
