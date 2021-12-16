module Buzzer(clk, rst_n, data_n,data,beep);

	input clk;
	input rst_n;
	input [7:0] data_n;
	output [10:0] data;
    output reg beep;

	reg [10:0] music_data;

	always @ (posedge clk)
		if(!rst_n)
			begin
				music_data <= 0;
			end
		else
			case (data_n)
            1:  // C#3 138
            music_data <= 1000000/138;
            2:  // D3 146
            music_data <= 1000000/146;
            3:  // D#3 155
            music_data <= 1000000/155;
            4:  // E3 164
            music_data <= 1000000/164;
            5:  // F3 174
            music_data <= 1000000/174;
            6:  // F#3 185
            music_data <= 1000000/185;
            7:  // G3 196
            music_data <= 1000000/196;
            8:  // G#3 207
            music_data <= 1000000/207;
            9:  // A3 220
            music_data <= 1000000/220;
            10: // A#3 233
            music_data <= 1000000/233;
            11: // B3 246
            music_data <= 1000000/246;
            12: // C4 261
            music_data <= 1000000/261;
            13: // C#4 277
            music_data <= 1000000/277;
            14: // D4 293
            music_data <= 1000000/293;
            15: // D#4 311
            music_data <= 1000000/311;
            16: // E4 329
            music_data <= 1000000/329;
            17: // F4 349
            music_data <= 1000000/349;
            18: // F#4 370
            music_data <= 1000000/370;
            19: // G4 392
            music_data <= 1000000/392;
            20: // G#4 415
            music_data <= 1000000/415;
            21: // A4 440   MAIN music_data 6
            music_data <= 1000000/440;
            22: // A#4 466
            music_data <= 1000000/466;
            23: // B4 494
            music_data <= 1000000/494;
            24: // C5 523   1^1
            music_data <= 1000000/523;
            25: // C#5 554
            music_data <= 1000000/554;
            26: // D5 587
            music_data <= 1000000/587;
            27: // D#5 622
            music_data <= 1000000/622;
            28: // E5 659
            music_data <= 1000000/659;
            29: // F5 698
            music_data <= 1000000/698;
            30: // F#5 740
            music_data <= 1000000/740;
            31: // G5 784
            music_data <= 1000000/784;
            32: // G#5 831
            music_data <= 1000000/831;
            33: // A5 880   6^1
            music_data <= 1000000/880;
            34: // A#5 932
            music_data <= 1000000/932;
            35: // B5 988
            music_data <= 1000000/988;
            36: // C6 1047  1^2
            music_data <= 1000000/1047;
            37: // C#6 1109
            music_data <= 1000000/1109;
            38: // D6 1175
            music_data <= 1000000/1175;
            39: // D#6 1245
            music_data <= 1000000/1245;
            40: // E6 1319
            music_data <= 1000000/1319;
            41: // F6 1397
            music_data <= 1000000/1397;
            42: // F#6 1480
            music_data <= 1000000/1480;
            43: // G6 1568
            music_data <= 1000000/1568;
            44: // G#6 1661
            music_data <= 1000000/1661;
            45: // A6 1760  6^2
            music_data <= 1000000/1760;
            46: // A#6 1865
            music_data <= 1000000/1865;
            47: // B6 1976
            music_data <= 1000000/1976;
            48: // C7 2093
            music_data <= 1000000/2093;
            49: // C#7 2217
            music_data <= 1000000/2217;
            50: // D7 2349
            music_data <= 1000000/2349;
            51: // D#7 2489
            music_data <= 1000000/2489;
            52: // E7 2637
            music_data <= 1000000/2637;
            53: // F7 2794
            music_data <= 1000000/2794;
            54: // F#7 2960
            music_data <= 1000000/2960;
            55: // G7 3136
            music_data <= 1000000/3136;
            56: // G#7 3322
            music_data <= 1000000/3322;
            57: // A7 3520
            music_data <= 1000000/3520;
            58: // A#7 3729
            music_data <= 1000000/3729;
            59: // B7 3951
            music_data <= 1000000/3951;
            
            default:
            music_data <= 0;
			endcase
	
	
	reg [20:0] count, cnt;

	always @ (posedge clk)
		if(!rst_n && !data_n)
			begin
				count <= 0;
			end
		else
			if(count < 100_000 - 1)
				begin
					if(!data_n)	//when no data, speed up detection 100x
						begin
							count <= count + 100;
						end
					count <= count + 1;
				end
			else
				begin
					count <= 0;
				end
	
	//计数0.1S的时�?
	assign data = (count >= 100_000 - 1) ? music_data : data;

	always @ (posedge clk)
		if(!rst_n)
			begin
				cnt <= 1;
				beep <= 0;
			end
		else
			if(data == 0)    //???????
				begin
					cnt <= 1;
					beep <= 0;
				end
			else if(cnt < data)    //???????
				begin
					cnt <= cnt + 1;
				end
			else
				begin
					cnt <= 1;     //????
					beep <= ~beep;
				end
endmodule 