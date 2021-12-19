module top (input iClk,
            input iReset_n,
            input iPs2_Clk,
            input iPs2_Data,
            input iSongSelect,
            input [1:0] iControl_Progress,
            input [2:0] iControl_Speed,
            input [2:0] iControl_Freq,
            output oVGA_Hsync,
            output oVGA_Vsync,
            output [3:0] oVGA_Red,
            output [3:0] oVGA_Green,
            output [3:0] oVGA_Blue,
            output oPWM,
            output oLightsRing
/*             output oLightsFreq,
            output oLightsRing,
            output oLightCounter,
            output oLightPWM,
            output oLightBuzzerFreq */);

    wire buzzer_Ring_Enable,buzzer_Counter_Enable;
    wire [12:0] buzzer_Freq,progress;
    wire ps2_Flag,clk;
    wire [7:0] ps2_Data,ps2_Decoded_Data,song_Data,freq_Data;
    wire songSelector;

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
        .iSong_Data(song_Data),
        .iSongSelect(iSongSelect),
        .oFreq_Data(freq_Data),
        .oCountEnable(buzzer_Counter_Enable)
    ); 

    OnlyMyRailGun song1(
        .iClk(clk),
        .iReset_n(iReset_n),
        .iEnable(iSongSelect),
        .iControl_Progress(iControl_Progress),
        .iControl_Speed(iControl_Speed),
        .iControl_Freq(iControl_Freq),
        .oProgress(progress),
        .oFreq(song_Data)
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
        .oVGA_Hsync(oVGA_Hsync),
        .oVGA_Vsync(oVGA_Vsync),
        .oVGA_Red(oVGA_Red),
        .oVGA_Green(oVGA_Green),
        .oVGA_Blue(oVGA_Blue)
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
/*
    Lights2 lightCounter(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iEnable(buzzer_Counter_Enable),
        .oLights(oLightCounter)
    );
    
    Lights2 lightNote(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iEnable(oPWM),
        .oLights(oLightPWM)
    );

    Lights3 lightBUzzerFreq(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iEnable(buzzer_Freq),
        .oLights(oLightBuzzerFreq)
    ); */

endmodule
