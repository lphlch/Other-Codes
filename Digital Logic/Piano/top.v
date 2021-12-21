module top (input iClk,
            input iReset_n,
            input iPs2_Clk,
            input iPs2_Data,
            input [1:0] iSongSelect,
            input [1:0] iControl_Progress,
            input [2:0] iControl_Speed,
            input [2:0] iControl_Freq,
            output oVGA_Hsync,
            output oVGA_Vsync,
            output [3:0] oVGA_Red,
            output [3:0] oVGA_Green,
            output [3:0] oVGA_Blue,
            output oPWM,
            output oLightsRing,
            output oLightsS0,
            output oLightsS1,
            output [7:0] oSeg_LED,
            output [7:0] oSeg_An
/*             output oLightsFreq,
            output oLightsRing,
            output oLightCounter,
            output oLightPWM,
            output oLightBuzzerFreq */);

    wire buzzer_Ring_Enable,buzzer_Counter_Enable;
    wire [12:0] buzzer_Freq,progress[3:0],playing_progress;
    wire ps2_Flag,clk;
    wire [7:0] ps2_Data,ps2_Decoded_Data,song_Data[3:0],freq_Data,playing_song_Data;
    wire [3:0] songSelector;

	Frenp frep_dut(
		.iClk(iClk),
		.iReset_n(iReset_n),
		.oClk(clk)
		);

    Ps2Input ps2Input(
        .iClk(clk),
        .iReset_n(iReset_n),
        .iPs2_Clk(iPs2_Clk),
        .iPs2_Data(iPs2_Data),
        .oFlag(ps2_Flag),
        .oData(ps2_Data)
    );

    Ps2Decoder ps2Decoder(
    .iClk(clk),
    .iReset_n(iReset_n),
    .iFlag(ps2_Flag),
    .iData(ps2_Data),
    .oData(ps2_Decoded_Data)
    );
    
    Controler controler(
        .iClk(clk),
        .iReset_n(iReset_n),
        .iPs2_Data(ps2_Decoded_Data),
        .iSong_Data(playing_song_Data),
        .iSongSelect(iSongSelect),
        .oFreq_Data(freq_Data),
        .oCountEnable(buzzer_Counter_Enable),
        .oSongSelectSeq(songSelector)
    ); 

    OnlyMyRailGun song0(
        .iClk(clk),
        .iReset_n(iReset_n),
        .iEnable(songSelector[0]),
        .iControl_Progress(iControl_Progress),
        .iControl_Speed(iControl_Speed),
        .iControl_Freq(iControl_Freq),
        .oProgress(progress[0]),
        .oFreq(song_Data[0])
    );

    SistersNoise song1(
        .iClk(clk),
        .iReset_n(iReset_n),
        .iEnable(songSelector[1]),
        .iControl_Progress(iControl_Progress),
        .iControl_Speed(iControl_Speed),
        .iControl_Freq(iControl_Freq),
        .oProgress(progress[1]),
        .oFreq(song_Data[1])
    );

    Selector selectSongData(
        .iClk(clk),
        .iReset_n(iReset_n),
        .iData1(song_Data[0]),
        .iData2(song_Data[1]),
        .iData3(song_Data[2]),
        .iAddress(songSelector),
        .oData(playing_song_Data)
    );
    Selector selectProgressData(
        .iClk(clk),
        .iReset_n(iReset_n),
        .iData1(progress[0]),
        .iData2(progress[1]),
        .iData3(progress[2]),
        .iAddress(songSelector),
        .oData(playing_progress)
    );


    BuzzerDecoder buzzerDecoder(
        .iClk(clk),
        .iReset_n(iReset_n),
        .iFreqType(freq_Data),
        .oFreq(buzzer_Freq)
    );
    
    BuzzerCounter buzzerCounter(
        .iClk(clk),
        .iReset_n(iReset_n),
        .iCountEnable(buzzer_Counter_Enable),
        .oRing(buzzer_Ring_Enable)
    );

     NotePlayer notePlayer(
        .iClk(clk),
        .iReset_n(iReset_n),
        .iRing(buzzer_Ring_Enable),
        .iFreq(buzzer_Freq),
        .oNote(oPWM)
    ); 

    Displayer displayer(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iFreqType(freq_Data),
        .iProgress(playing_progress),
        .iSongSelected(songSelector),
        .oVGA_Hsync(oVGA_Hsync),
        .oVGA_Vsync(oVGA_Vsync),
        .oVGA_Red(oVGA_Red),
        .oVGA_Green(oVGA_Green),
        .oVGA_Blue(oVGA_Blue)
    );

    Seg8 seg8(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iControl_Speed(iControl_Speed),
        .iControl_Freq(iControl_Freq),
        .oSeg(oSeg_LED),
        .oAn(oSeg_An)
    );

/* 
    Lights lightsFreq(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iEnable(freq_Data),
        .oLights(oLightsFreq)
    );
*/
    Lights2 lightsRing(
        .iClk(clk),
        .iReset_n(iReset_n),
        .iEnable(buzzer_Ring_Enable),
        .oLights(oLightsRing)
    );

    Lights2 song0L(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iEnable(iSongSelect[0]),
        .oLights(oLightsS0)
    );
    
    Lights2 song1L(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iEnable(iSongSelect[1]),
        .oLights(oLightsS0)
    );

/*     Lights3 lightBUzzerFreq(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iEnable(buzzer_Freq),
        .oLights(oLightBuzzerFreq)
    );  */

endmodule
