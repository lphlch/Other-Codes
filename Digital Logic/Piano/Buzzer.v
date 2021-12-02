module BuzzerDecoder (input iClk,
                      input iReset,
                      input iEnable,
                      input [5:0]iFreqType,
                      output oBuzzerEnable,
                      output [5:0]oFreq);
    
    // iReset: reset the buzzer
    // iEnable: when high, the buzzer is enabled to output the frequency
    // iFreq: frequency type of the buzzer, from C3 to B7, 60 in total
    // oBuzzerEnable: enable the buzzer
    // oFreq: frequency of the buzzer
    
    wire [11:0]frequency;
    always @(posedge clk) begin  // choose the frequency
        
        if (iReset) begin
            //reset
            frequency <= 0;
        end
        else begin
            case (iFreqType) begin
            0:  // C3 130
            frequency <= 130;
            1:  // C#3 138
            frequency <= 138;
            2:  // D3 146
            frequency <= 146;
            3:  // D#3 155
            frequency <= 155;
            4:  // E3 164
            frequency <= 164;
            5:  // F3 174
            frequency <= 174;
            6:  // F#3 185
            frequency <= 185;
            7:  // G3 196
            frequency <= 196;
            8:  // G#3 207
            frequency <= 207;
            9:  // A3 220
            frequency <= 220;
            10: // A#3 233
            frequency <= 233;
            11: // B3 246
            frequency <= 246;
            12: // C4 261
            frequency <= 261;
            13: // C#4 277
            frequency <= 277;
            14: // D4 293
            frequency <= 293;
            15: // D#4 311
            frequency <= 311;
            16: // E4 329
            frequency <= 329;
            17: // F4 349
            frequency <= 349;
            18: // F#4 370
            frequency <= 370;
            19: // G4 392
            frequency <= 392;
            20: // G#4 415
            frequency <= 415;
            21: // A4 440
            frequency <= 440;
            22: // A#4 466
            frequency <= 466;
            23: // B4 494
            frequency <= 494;
            24: // C5 523
            frequency <= 523;
            25: // C#5 554
            frequency <= 554;
            26: // D5 587
            frequency <= 587;
            27: // D#5 622
            frequency <= 622;
            28: // E5 659
            frequency <= 659;
            29: // F5 698
            frequency <= 698;
            30: // F#5 740
            frequency <= 740;
            31: // G5 784
            frequency <= 784;
            32: // G#5 831
            frequency <= 831;
            33: // A5 880
            frequency <= 880;
            34: // A#5 932
            frequency <= 932;
            35: // B5 988
            frequency <= 988;
            36: // C6 1047
            frequency <= 1047;
            37: // C#6 1109
            frequency <= 1109;
            38: // D6 1175
            frequency <= 1175;
            39: // D#6 1245
            frequency <= 1245;
            40: // E6 1319
            frequency <= 1319;
            41: // F6 1397
            frequency <= 1397;
            42: // F#6 1480
            frequency <= 1480;
            43: // G6 1568
            frequency <= 1568;
            44: // G#6 1661
            frequency <= 1661;
            45: // A6 1760
            frequency <= 1760;
            46: // A#6 1865
            frequency <= 1865;
            47: // B6 1976
            frequency <= 1976;
            48: // C7 2093
            frequency <= 2093;
            49: // C#7 2217
            frequency <= 2217;
            50: // D7 2349
            frequency <= 2349;
            51: // D#7 2489
            frequency <= 2489;
            52: // E7 2637
            frequency <= 2637;
            53: // F7 2794
            frequency <= 2794;
            54: // F#7 2960
            frequency <= 2960;
            55: // G7 3136
            frequency <= 3136;
            56: // G#7 3322
            frequency <= 3322;
            57: // A7 3520
            frequency <= 3520;
            58: // A#7 3729
            frequency <= 3729;
            59: // B7 3951
            frequency <= 3951;
            
            default:
            frequency <= 0;
            endcase
        end
    end
    
    assign oFreq         = iEnable? frequency,0;
    assign oBuzzerEnable = iReset? iEnable:0;
endmodule
    
    module BuzzerStimulater (
        input iClk,
        input iReset,
        input iBooster,
        input [5:0]iFreqType,
        output oBuzzerEnable,
        output [5:0]oFreq
        );
        // iReset: reset the buzzer
        // iBooster: booster of the buzzer, when high, start the counter(only this will be used in this module, other will be transferred to the BuzzerDecoder)
        // iFreq: frequency type of the buzzer, from C3 to B7, 60 in total
        // oBuzzerEnable: enable the buzzer
        // oFreq: frequency of the buzzer
        
        parameter i = 200000;   //0.2s
        reg[20:0] count;
        reg buzzerDecoderEnable;
        always @(posedge clk) begin //counter, sound lasting 0.2s in default
            if (iReset) begin   //reset
                count         <= 0;
                buzzerDecoderEnable <= 0;
            end
            else begin
                if (iBooster) begin //start counting
                    count         <= 1;
                    buzzerDecoderEnable <= 1;
                end
                
                if (count == i) begin   //count to 0.2s
                    count         <= 0;
                    buzzerDecoderEnable <= 0;
                end
                
                if (count != 0) begin   //continue counting
                    count         <= count + 1;
                    buzzerDecoderEnable <= 1;
                end
            end
            
        end

        BuzzerDecoder buzzerDecoder(iClk, iReset, buzzerDecoderEnable, iFreqType, oBuzzerEnable, oFreq);
    endmodule
