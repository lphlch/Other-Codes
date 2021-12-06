/************************************************************************
*    Author         :    yllinux  博客：http://www.cnblogs.com/yllinux/
*    Module Name    :    vga_color_line.v
*    Tool versions  :    Quartus II 12.1；Cyclone IV E（EP4CE6F17C8）
*    Create Date    :    2017-7-21
*    Revision       :    v1.0
*    Description    :    使1280*1024@60HZ的VGA显示器显示竖彩条
************************************************************************/

module VGA_color_line (clk, rst_n, hs_vga, vs_vga, r_vga, g_vga, b_vga);

    input clk, rst_n;  //系统时钟和低电平复位
    output hs_vga, vs_vga;  //行同步hs_vga，场同步vs_vga
    output r_vga, g_vga , b_vga;  //像素三基色输出R、G、B
    reg [2:0] rgb_vga;  //相当于输入信号了
    wire clk_vga;  //像素时钟 1688 * 1066 * 60 MZ （工业标准 108 MHZ）

// VGA_1280_1024_60fps_50MHz
// Horizontal Parameter( Pixel )
    parameter
        H_DISP  = 11'd1280,
        H_FRONT = 11'd48,
        H_SYNC  = 11'd112,
        H_BACK  = 11'd248,
        H_TOTAL = 11'd1688,
// Virtical Parameter( Line )
        V_DISP  = 11'd1024,
        V_FRONT = 11'd1,
        V_SYNC  = 11'd3,
        V_BACK  = 11'd38,
        V_TOTAL = 11'd1066;

//调用IP核ALTPLL，像素频率108 MHZ
        clk_wiz_0 clk_vga_inst(
    .clk_in1(clk),
    .resetn(rst_n),
    .clk_out1(clk_vga)
    );

//行同步计数器(信号发生器)
    reg [10:0] hcnt;
    reg hs_vga;
    always @ (posedge clk_vga or negedge rst_n)
        begin
            if (!rst_n)
                hcnt <= 0;  //复位后计数清零
            else
                begin
                    if (hcnt < H_TOTAL - 1'b1)  //判断扫描完一行,像素区间为[0, H_TOTAL - 1'b1]
                        hcnt <= hcnt + 1'b1;
                    else
                        hcnt <= 0;
                end
        end
//行同步
    always @ (posedge clk_vga or negedge rst_n)
        begin
            if (!rst_n)
            hs_vga <= 0; //因为复位后计数器置零，而0 ~ (H_DISP - 1)区间为显示区，此处必为 0
            else
                begin
                //像素(H_DISP + H_FRONT - 1, H_DISP + H_FRONT + H_SYNC - 1]区间同步
                    if (hcnt >= (H_DISP + H_FRONT - 1'b1) && hcnt < (H_DISP + H_FRONT + H_SYNC - 1'b1))
                        hs_vga <= 1;  //在同步区置1，行同步
                    else
                        hs_vga <= 0;
                end
        end

//场同步计数器(信号发生器)
    reg [10:0] vcnt;
    reg vs_vga;
    always @ (posedge clk_vga or negedge rst_n)  //异步复位
        begin
            if (!rst_n)
            vcnt <= 0;  //复位后计数清零
            else
                begin
                    if (hcnt == H_DISP - 1'b1)  //判断显示区扫面完一行，此处也可判断整个一行扫描完
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
    always @ (posedge clk_vga or negedge rst_n)
        begin
            if (!rst_n)
                vs_vga <= 0;
            else
                begin
                    if (vcnt >= (V_DISP + V_FRONT - 1'b1) && vcnt < (V_DISP + V_FRONT + V_SYNC - 1'b1))
                        vs_vga <= 1;
                    else
                        vs_vga <= 0;
                end
        end

//在显示期坐标根据显示的扫描而改变，在非显示期，坐标置零
    wire [10:0] xpos_vga, ypos_vga;
    assign xpos_vga = (hcnt < H_DISP) ? (hcnt + 1'b1) : 11'd0;  //在显示区横坐标 + 1（即1~H_DISP）
    assign ypos_vga = (vcnt < V_DISP) ? (vcnt + 1'b1) : 11'd0;  //在显示区竖坐标 + 1（即1~V_DISP）

//竖彩条显示
    always @ (posedge clk_vga or negedge rst_n)
        if (!rst_n)
            rgb_vga <= 3'b000;
        else
            begin
                /*if (xpos_vga > 0 && xpos_vga < 80) rgb_vga <= 3'b010;
                else if (xpos_vga < 160) rgb_vga <= 3'b011;
                else if (xpos_vga < 240) rgb_vga <= 3'b100;
                else if (xpos_vga < 320) rgb_vga <= 3'b101;
                else if (xpos_vga < 400) rgb_vga <= 3'b110;
                else if (xpos_vga < 480) rgb_vga <= 3'b111;
                else if (xpos_vga < 560) rgb_vga <= 3'b001;
                else if (xpos_vga < 640) rgb_vga <= 3'b010;
                else if (xpos_vga < 720) rgb_vga <= 3'b011;
                else if (xpos_vga < 800) rgb_vga <= 3'b100;
                else if (xpos_vga < 880) rgb_vga <= 3'b101;
                else if (xpos_vga < 960) rgb_vga <= 3'b110;
                else if (xpos_vga < 1040) rgb_vga <= 3'b111;
                else if (xpos_vga < 1120) rgb_vga <= 3'b001;
                else if (xpos_vga < 1200) rgb_vga <= 3'b010;
                else if (xpos_vga <= 1280) rgb_vga <= 3'b011;
                else rgb_vga <= 3'b000;*/

            if (xpos_vga > 0 && xpos_vga <= 80) rgb_vga <= 3'b111;//white
            else if (xpos_vga > 80 && xpos_vga <= 160) rgb_vga <= 3'b100;//red
            else if (xpos_vga > 160 && xpos_vga <= 240) rgb_vga <= 3'b101;//mangenta
            else if (xpos_vga > 240 && xpos_vga <= 320) rgb_vga <= 3'b110;//yellow
            else if (xpos_vga > 320 && xpos_vga <= 400) rgb_vga <= 3'b010;//green
            else if (xpos_vga > 400 && xpos_vga <= 480) rgb_vga <= 3'b001;//blue
            else if (xpos_vga > 480 && xpos_vga <= 560) rgb_vga <= 3'b011;//cyan
            else if (xpos_vga > 560 && xpos_vga <= 640) rgb_vga <= 3'b000;

            else if (xpos_vga > 640 && xpos_vga <= 720) rgb_vga <= 3'b111;//white
            else if (xpos_vga > 720 && xpos_vga <= 800) rgb_vga <= 3'b100;
            else if (xpos_vga > 800 && xpos_vga <= 880) rgb_vga <= 3'b101;
            else if (xpos_vga > 880 && xpos_vga <= 960) rgb_vga <= 3'b110;
            else if (xpos_vga > 960 && xpos_vga <= 1040) rgb_vga <= 3'b010;
            else if (xpos_vga > 1040 && xpos_vga <= 1120) rgb_vga <= 3'b001;
            else if (xpos_vga > 1120 && xpos_vga <= 1200) rgb_vga <= 3'b011;
            else if (xpos_vga > 1200 && xpos_vga <= 1280) rgb_vga <= 3'b111;
            else rgb_vga <= 3'b000;//black，这个很重要，不然颜色不怎么正常

        end

//三基色分离（可省，直接用 rgb_vga）
    assign r_vga = rgb_vga[2];
    assign g_vga = rgb_vga[1];
    assign b_vga = rgb_vga[0];

endmodule