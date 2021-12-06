module VGA_color_line (CLK,
                       RST_N,
                       RGB,
                       VGA_HSYNC,
                       VGA_VSYNC,
                       VGA_RED,
                       VGA_GREEN,
                       VGA_BLUE);
    
    input CLK, RST_N;  //系统时钟和低电平复位
    input [11:0]RGB;         //RGB输入
    output VGA_HSYNC, VGA_VSYNC;  //行同步VGA_HSYNC，场同步VGA_VSYNC
    output [3:0] VGA_RED;
    output [3:0] VGA_GREEN;
    output [3:0] VGA_BLUE;  //像素三基色输出R、G、B
    reg [11:0] rgb_vga;  //4位一组，分别为R、G、B
    wire clk_vga;  //像素时钟 1688 * 1066 * 108 MZ
    
    // Horizontal Parameter(Pixel)
    parameter
    H_DISP = 11'd1280,
    H_FRONT = 11'd48,
    H_SYNC = 11'd112,
    H_BACK = 11'd248,
    H_TOTAL = 11'd1688,
    // Virtical Parameter(Line)
    V_DISP = 11'd1024,
    V_FRONT = 11'd1,
    V_SYNC = 11'd3,
    V_BACK = 11'd38,
    V_TOTAL = 11'd1066;
    
    //调用IP核，分频108 MHZ
    clk_wiz_0 clk_vga_inst(
    .clk_in1(CLK),
    .resetn(RST_N),
    .clk_out1(clk_vga)
    );
    
    //行同步计数
    reg [10:0] hcnt;
    reg VGA_HSYNC;
    always @ (posedge clk_vga or negedge RST_N)
    begin
        if (!RST_N)
            hcnt <= 0;  //清零
        else
        begin
            if (hcnt < H_TOTAL - 1'b1)  //判断扫描完一行,像素区间为[0, H_TOTAL - 1'b1]
                hcnt <= hcnt + 1'b1;
            else
                hcnt <= 0;
        end
    end
    //行同步
    always @ (posedge clk_vga or negedge RST_N)
    begin
        if (!RST_N)
            VGA_HSYNC <= 0; //清零
        else
        begin
            //像素(H_DISP + H_FRONT - 1, H_DISP + H_FRONT + H_SYNC - 1]区间同步
            if (hcnt >= (H_DISP + H_FRONT - 1'b1) && hcnt < (H_DISP + H_FRONT + H_SYNC - 1'b1))
                VGA_HSYNC <= 1;  //在同步区，行同步
            else
                VGA_HSYNC <= 0;
        end
    end
    
    //场同步计数
    reg [10:0] vcnt;
    reg VGA_VSYNC;
    always @ (posedge clk_vga or negedge RST_N)  //异步复位
    begin
        if (!RST_N)
            vcnt <= 0;  //清零
        else
        begin
            if (hcnt == H_DISP - 1'b1)  //判断显示区扫面完一行
            begin
                if (vcnt < V_TOTAL - 1'b1)  //判断扫面完一场
                    vcnt <= vcnt + 1'b1;
                else
                    vcnt <= 0;
            end
            else
                vcnt <= vcnt;
        end
    end
    //场同步
    always @ (posedge clk_vga or negedge RST_N)
    begin
        if (!RST_N)
            VGA_VSYNC <= 0;
        else
        begin
            if (vcnt >= (V_DISP + V_FRONT - 1'b1) && vcnt < (V_DISP + V_FRONT + V_SYNC - 1'b1))
                VGA_VSYNC <= 1;
            else
                VGA_VSYNC <= 0;
        end
    end
    
    //坐标在非显示期，坐标置零
    wire [10:0] xpos_vga, ypos_vga;
    assign xpos_vga = (hcnt < H_DISP) ? (hcnt + 1'b1) : 11'd0;  //横坐标 + 1（即1~H_DISP）
    assign ypos_vga = (vcnt < V_DISP) ? (vcnt + 1'b1) : 11'd0;  //竖坐标 + 1（即1~V_DISP）
    
    //显示
    always @ (posedge clk_vga or negedge RST_N)
    begin
        if (!RST_N)
            rgb_vga <= 0;
        else
        begin
            /*            测试彩条
             if (xpos_vga > 0 && xpos_vga        <= 80) rgb_vga        <= 9'b111111111;//white
             else if (xpos_vga > 80 && xpos_vga  <= 160) rgb_vga  <= 9'b111000000;//red
             else if (xpos_vga > 160 && xpos_vga <= 240) rgb_vga <= 9'b111000111;//mangenta
             else if (xpos_vga > 240 && xpos_vga <= 320) rgb_vga <= 9'b111111000;//yellow
             else if (xpos_vga > 320 && xpos_vga <= 400) rgb_vga <= 9'b000111000;//green
             else if (xpos_vga > 400 && xpos_vga <= 480) rgb_vga <= 9'b000000111;//blue
             else if (xpos_vga > 480 && xpos_vga <= 560) rgb_vga <= 9'b000111111;//cyan
             else if (xpos_vga > 560 && xpos_vga <= 640) rgb_vga <= 9'b000000000;
             
             else if (xpos_vga > 640 && xpos_vga  <= 720) rgb_vga  <= 9'b111111111;//white
             else if (xpos_vga > 720 && xpos_vga  <= 800) rgb_vga  <= 9'b111000000;//red
             else if (xpos_vga > 800 && xpos_vga  <= 880) rgb_vga  <= 9'b111000111;//mangenta
             else if (xpos_vga > 880 && xpos_vga  <= 960) rgb_vga  <= 9'b111111000;//yellow
             else if (xpos_vga > 960 && xpos_vga  <= 1040) rgb_vga  <= 9'b000111000;//green
             else if (xpos_vga > 1040 && xpos_vga <= 1120) rgb_vga <= 9'b000000111;//blue
             else if (xpos_vga > 1120 && xpos_vga <= 1200) rgb_vga <= 9'b000111111;//cyan
             else if (xpos_vga > 1200 && xpos_vga <= 1280) rgb_vga <= 9'b000000000;
             else rgb_vga                         <= 0;//black，这个很重要，不然颜色不怎么正常
             */
            
            //显示像素
            if (xpos_vga > 0 && xpos_vga <= 1280) begin
                rgb_vga <= RGB;
            end
            else
                rgb_vga <= 0;
            
        end
    end
    //分离颜色
    assign VGA_RED   = rgb_vga[11:8];
    assign VGA_GREEN = rgb_vga[7:4];
    assign VGA_BLUE  = rgb_vga[3:0];
    
endmodule
