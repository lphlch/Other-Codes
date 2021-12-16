module top (input iClk,
            input iReset_n,
            input iPs2_Clk,
            input iPs2_Data,
            output oPWM
/*             output oLightsFreq,
            output oLightsRing,
            output oLightCounter,
            output oLightPWM,
            output oLightBuzzerFreq */);

    wire buzzer_Ring_Enable,buzzer_Counter_Enable;
    wire [12:0] buzzer_Freq;
    wire ps2_Flag,clk_1M;
    wire [7:0] ps2_Data,freq_Data;

	Frenp frep_dut(
		.clk(iClk),
		.rst_n(iReset_n),
		.clk_1M(clk_1M)
		);

    Ps2Input ps2Input(
        .iClk(clk_1M),
        .iReset_n(iReset_n),
        .iPs2_Clk(iPs2_Clk),
        .iPs2_Data(iPs2_Data),
        .oFlag(ps2_Flag),
        .oData(ps2_Data)
    );

    Ps2Decoder ps2Decoder(
    .iClk(clk_1M),
    .iReset_n(iReset_n),
    .iFlag(ps2_Flag),
    .iData(ps2_Data),
    .oData(freq_Data)
    );
    
    
/*     Controler controler(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iPs2_Data(freq_Data),
        .iCount(buzzer_Counter_Signal),
        //.oRing(buzzer_Ring_Enable),
        .oCountEnable(buzzer_Counter_Enable)
    ); */

    /* BuzzerDecoder buzzerDecoder(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iFreqType(freq_Data),
        .oFreq(buzzer_Freq)
    );
    
    BuzzerCounter buzzerCounter(
        .iClk(iClk),
        .iReset_n(iReset_n),
        //.iCountEnable(buzzer_Counter_Enable),
        .oRing(buzzer_Ring_Enable)
    ); */

    Buzzer buzzer(
        .clk(clk_1M),
        .rst_n(iReset_n),
        .data_n(freq_Data),
        .data(buzzer_Freq),
        .beep(oPWM)
    );

/*     NotePlayer notePlayer(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iRing(1),
        .iFreq(buzzer_Freq),
        .oNote(oPWM)
    ); */
/* 
    Lights lightsFreq(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iEnable(freq_Data),
        .oLights(oLightsFreq)
    );

    Lights2 lightsRing(
        .iClk(iClk),
        .iReset_n(iReset_n),
        .iEnable(buzzer_Ring_Enable),
        .oLights(oLightsRing)
    );

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
