module NotePlayer (input iClk,
                   input iReset_n,
                   input iRing,
                   input[12:0] iFreq,
                   output reg oNote);
    //input iRing: control whether the note is ringing or not
    //output oNote: output to interface
    
    reg [20:0] cnt;
    always @ (posedge iClk)
    begin
        if (!iReset_n)
        begin
            cnt   <= 1;
            oNote <= 0;
        end
        else
        begin
            if (iRing == 0)    //unable to ring
            begin
                cnt   <= 1;
                oNote <= 0;
            end
            else if (cnt < iFreq)    //freq control
            begin
                cnt <= cnt + 1;
            end
            else
            begin
                cnt   <= 1;
                oNote <= ~oNote;
            end
        end
    end
endmodule
