module BuzzerDecoder (input iClk,
                      input iReset_n,
                      input [7:0]iFreqType,
                      //output oBuzzerEnable,
                      output [12:0]oFreq);
    
    // iFreq: frequency type of the buzzer, from C3 to B7, 60 in total
    // oBuzzerEnable: enable the buzzer
    // oFreq: frequency of the buzzer
    
    reg [12:0]frequency;
    always @(posedge iClk) begin  // choose the frequency
        
        if (!iReset_n) begin
            //reset
            frequency <= 0;
        end
        else begin
            case (iFreqType)
            0:  // not defined
            frequency <= frequency;
            1:  // C#3 138
            frequency <= 1000000/138;
            2:  // D3 146
            frequency <= 1000000/146;
            3:  // D#3 155
            frequency <= 1000000/155;
            4:  // E3 164
            frequency <= 1000000/164;
            5:  // F3 174
            frequency <= 1000000/174;
            6:  // F#3 185
            frequency <= 1000000/185;
            7:  // G3 196
            frequency <= 1000000/196;
            8:  // G#3 207
            frequency <= 1000000/207;
            9:  // A3 220
            frequency <= 1000000/220;
            10: // A#3 233
            frequency <= 1000000/233;
            11: // B3 246
            frequency <= 1000000/246;
            12: // C4 261
            frequency <= 1000000/261;
            13: // C#4 277
            frequency <= 1000000/277;
            14: // D4 293
            frequency <= 1000000/293;
            15: // D#4 311
            frequency <= 1000000/311;
            16: // E4 329
            frequency <= 1000000/329;
            17: // F4 349
            frequency <= 1000000/349;
            18: // F#4 370
            frequency <= 1000000/370;
            19: // G4 392
            frequency <= 1000000/392;
            20: // G#4 415
            frequency <= 1000000/415;
            21: // A4 440   MAIN FREQUENCY 6
            frequency <= 1000000/440;
            22: // A#4 466
            frequency <= 1000000/466;
            23: // B4 494
            frequency <= 1000000/494;
            24: // C5 523   1^1
            frequency <= 1000000/523;
            25: // C#5 554
            frequency <= 1000000/554;
            26: // D5 587
            frequency <= 1000000/587;
            27: // D#5 622
            frequency <= 1000000/622;
            28: // E5 659
            frequency <= 1000000/659;
            29: // F5 698
            frequency <= 1000000/698;
            30: // F#5 740
            frequency <= 1000000/740;
            31: // G5 784
            frequency <= 1000000/784;
            32: // G#5 831
            frequency <= 1000000/831;
            33: // A5 880   6^1
            frequency <= 1000000/880;
            34: // A#5 932
            frequency <= 1000000/932;
            35: // B5 988
            frequency <= 1000000/988;
            36: // C6 1047  1^2
            frequency <= 1000000/1047;
            37: // C#6 1109
            frequency <= 1000000/1109;
            38: // D6 1175
            frequency <= 1000000/1175;
            39: // D#6 1245
            frequency <= 1000000/1245;
            40: // E6 1319
            frequency <= 1000000/1319;
            41: // F6 1397
            frequency <= 1000000/1397;
            42: // F#6 1480
            frequency <= 1000000/1480;
            43: // G6 1568
            frequency <= 1000000/1568;
            44: // G#6 1661
            frequency <= 1000000/1661;
            45: // A6 1760  6^2
            frequency <= 1000000/1760;
            46: // A#6 1865
            frequency <= 1000000/1865;
            47: // B6 1976
            frequency <= 1000000/1976;
            48: // C7 2093
            frequency <= 1000000/2093;
            49: // C#7 2217
            frequency <= 1000000/2217;
            50: // D7 2349
            frequency <= 1000000/2349;
            51: // D#7 2489
            frequency <= 1000000/2489;
            52: // E7 2637
            frequency <= 1000000/2637;
            53: // F7 2794
            frequency <= 1000000/2794;
            54: // F#7 2960
            frequency <= 1000000/2960;
            55: // G7 3136
            frequency <= 1000000/3136;
            56: // G#7 3322
            frequency <= 1000000/3322;
            57: // A7 3520
            frequency <= 1000000/3520;
            58: // A#7 3729
            frequency <= 1000000/3729;
            59: // B7 3951
            frequency <= 1000000/3951;
            
            99: // stop
            frequency <= frequency;
            default:
            frequency <= 0;
            endcase
        end
    end
    
    //assign oBuzzerEnable = (iFreqType==99)? 0:1;    //
    assign oFreq         = frequency;
endmodule
    
    