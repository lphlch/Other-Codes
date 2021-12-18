module Displayer (input iClk,
                  input iReset_n,
                  input [7:0] iFreqType,
                  //input [11:0] iRGB,
                  output reg oVGA_Hsync,
                  output reg oVGA_Vsync,
                  output [3:0] oVGA_Red,
                  output [3:0] oVGA_Green,
                  output [3:0] oVGA_Blue);
    
    reg [11:0] rgb_vga;
    wire clk_vga;  //65MHZ
    
    // Horizontal Parameter(Pixel)
    parameter
    H_DISP = 11'd1024,
    H_FRONT = 11'd24,
    H_SYNC = 11'd136,
    H_BACK = 11'd160,
    H_TOTAL = 11'd1344,
    // Virtical Parameter(Line)
    V_DISP = 11'd768,
    V_FRONT = 11'd3,
    V_SYNC = 11'd6,
    V_BACK = 11'd29,
    V_TOTAL = 11'd806,
    // Picture Parameter
    P_WIDTH = 11'd200,
    P_HEIGHT = 11'd200;
    
    //IP core 65MHZ
    clk_vga_1024_768 clk_vga_inst(
    .clk_in1(iClk),
    .resetn(iReset_n),
    .clk_out1(clk_vga)
    );
    
    //hsync count
    reg [10:0] hcnt;
    reg oVGA_Hsync;
    always @ (posedge clk_vga or negedge iReset_n)
    begin
        if (!iReset_n)
            hcnt <= 0;
        else
        begin
            if (hcnt < H_TOTAL - 1'b1)  //[0, H_TOTAL - 1'b1]
                hcnt <= hcnt + 1'b1;
            else
                hcnt <= 0;
        end
    end
    
    //hsync
    always @ (posedge clk_vga or negedge iReset_n)
    begin
        if (!iReset_n)
            oVGA_Hsync <= 0;
        else
        begin
            if (hcnt >= (H_DISP + H_FRONT - 1'b1) && hcnt < (H_DISP + H_FRONT + H_SYNC - 1'b1))
                oVGA_Hsync <= 1;
            else
                oVGA_Hsync <= 0;
        end
    end
    
    //vsync counter
    reg [10:0] vcnt;
    reg oVGA_Vsync;
    always @ (posedge clk_vga or negedge iReset_n)
    begin
        if (!iReset_n)
            vcnt <= 0;
        else
        begin
            if (hcnt == H_DISP - 1'b1)
            begin
                if (vcnt < V_TOTAL - 1'b1)
                    vcnt <= vcnt + 1'b1;
                else
                    vcnt <= 0;
            end
            else
                vcnt <= vcnt;
        end
        $display("iReset_n = %d,hcnt = %d ,vcnt = %d", iReset_n,hcnt,vcnt);
    end
    
    //vsync
    always @ (posedge clk_vga or negedge iReset_n)
    begin
        if (!iReset_n)
            oVGA_Vsync <= 0;
        else
        begin
            if (vcnt >= (V_DISP + V_FRONT - 1'b1) && vcnt < (V_DISP + V_FRONT + V_SYNC - 1'b1))
                oVGA_Vsync <= 1;
            else
                oVGA_Vsync <= 0;
        end
    end
    
    //x y
    wire [10:0] xpos_vga, ypos_vga;
    assign xpos_vga = (hcnt < H_DISP) ? (hcnt + 1'b1) : 11'd0;  //??? + 1??1~H_DISP?
    assign ypos_vga = (vcnt < V_DISP) ? (vcnt + 1'b1) : 11'd0;  //??? + 1??1~V_DISP?
    
    /* 79 in total,1^-3 - 7^3, main 49keys , half 35keys
     1024*768
     
     18pixels mian, plus 1p black, total 931
     
     if half key == 3 or 7 ,do not display
     from 8, 8 = C2,9 = C#2,11 = D#2,14 = F#2,16 = G#2,18 = A#2,19 = B2
     12 freq types per group
     
     */


    parameter left_blanking        = 20;
    parameter top_blanking         = 200;
    parameter half_key_count       = 35;
    parameter half_key_height      = 80;
    parameter half_key_width_total = 19;
    parameter half_key_offset      = 9;
    parameter main_key_count       = 49;
    parameter main_key_height      = 160;
    parameter main_key_width_total = 19;
    parameter blanking             = 5;
    parameter ship_key1            = 3;
    parameter ship_key2            = 7;
    parameter keys_per_group       = 7;
    parameter key_per_freq_group   = 12;
    parameter white                = 12'b111111111111;
    parameter black                = 12'b000000000000;
    parameter yellow               = 12'b111111110000;
    parameter blue                 = 12'b000000001111;
    parameter green                = 12'b000011110000;
    reg [7:0] main_keys,half_keys;
    reg [7:0] main_keys_number,half_keys_number;
    always @(*) begin
        if(iFreqType==0) begin
            main_keys_number<=99;
            half_keys_number<=99;
        end
        else if(iFreqType<=7) begin
            main_keys_number <= iFreqType-1;
            half_keys_number <= 99;
        end
        else begin
            case ((iFreqType-7)%key_per_freq_group)
                1: begin
                    main_keys_number <= 7+(iFreqType-7)/key_per_freq_group*keys_per_group;
                    half_keys_number <= 99;
                end
                2: begin
                    main_keys_number <= 99;
                    half_keys_number <= 8+(iFreqType-7)/key_per_freq_group*keys_per_group;
                end
                3: begin
                    main_keys_number <= 8+(iFreqType-7)/key_per_freq_group*keys_per_group;
                    half_keys_number <= 99;
                end
                4: begin
                    main_keys_number <= 99;
                    half_keys_number <= 9+(iFreqType-7)/key_per_freq_group*keys_per_group;
                end
                5: begin
                    main_keys_number <= 9+(iFreqType-7)/key_per_freq_group*keys_per_group;
                    half_keys_number <= 99;
                end
                6: begin
                    main_keys_number <= 10+(iFreqType-7)/key_per_freq_group*keys_per_group;
                    half_keys_number <= 99;
                end
                7: begin
                    main_keys_number <= 99;
                    half_keys_number <= 11+(iFreqType-7)/key_per_freq_group*keys_per_group;
                end
                8: begin
                    main_keys_number <= 11+(iFreqType-7)/key_per_freq_group*keys_per_group;
                    half_keys_number <= 99;
                end
                9: begin
                    main_keys_number <= 99;
                    half_keys_number <= 12+(iFreqType-7)/key_per_freq_group*keys_per_group;
                end
                10: begin
                    main_keys_number <= 12+(iFreqType-7)/key_per_freq_group*keys_per_group;
                    half_keys_number <= 99;
                end
                11: begin
                    main_keys_number <= 99;
                    half_keys_number <= 13+(iFreqType-7)/key_per_freq_group*keys_per_group;
                end
                0: begin
                    main_keys_number <= 6+(iFreqType-7)/key_per_freq_group*keys_per_group;
                    half_keys_number <= 99;
                end
                default: begin
                    main_keys_number<=99;
                    half_keys_number<=99;
                end
            endcase
        end
    end

    //display
    always @ (posedge clk_vga or negedge iReset_n)
    begin

        if (!iReset_n) begin
            rgb_vga   <= 0;
            main_keys <= 0;
            half_keys <= 0;
        end
        else begin

            //key area
            if (xpos_vga>left_blanking+blanking && ypos_vga>top_blanking &&ypos_vga-top_blanking<main_key_height) begin
                if (((xpos_vga-left_blanking) % main_key_width_total) >= blanking && main_keys <main_key_count) begin  //main key
                    if(main_keys==main_keys_number) rgb_vga <= green;
                    else rgb_vga <= white;
                end
                else if (main_keys < main_key_count) begin
                    rgb_vga <= blue;
                end
                else begin
                    rgb_vga <= black;
                end
                
                //half key
                if (ypos_vga-top_blanking < half_key_height) begin   //y range
                    if ((((xpos_vga-left_blanking-half_key_offset) % half_key_width_total) > blanking)
                        && (half_keys <= main_key_count)
                        && (half_keys % keys_per_group != 3)
                        && (half_keys % keys_per_group != 0)) begin
                        
                        if(half_keys==half_keys_number) rgb_vga <= green;
                        else rgb_vga <= yellow;

                    end
                end
                    
                if (((xpos_vga-left_blanking) % main_key_width_total) == 0) begin
                    main_keys <= main_keys+1;  //count keys
                end
                
                if (((xpos_vga-left_blanking-half_key_offset) % half_key_width_total) == 0) begin
                    half_keys <= half_keys+1;
                end
            end
            else begin
                main_keys <= 0;
                half_keys <= 0;
                
                rgb_vga <= 0;  //background
            end
                
                
        end
    end
        
        
        
        //????
        assign oVGA_Red   = rgb_vga[11:8];
        assign oVGA_Green = rgb_vga[7:4];
        assign oVGA_Blue  = rgb_vga[3:0];
        endmodule
