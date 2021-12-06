`timescale 1 ns/ 1 ps
module VGA_color_line_vlg_tst();
    reg CLK, RST_N;  //系统时钟和低电平复位
    wire VGA_HSYNC, VGA_VSYNC;  //行同步VGA_HSYNC，场同步VGA_VSYNC
    wire [3:0] VGA_RED;
    wire [3:0] VGA_GREEN;
    wire [3:0] VGA_BLUE;  //像素三基色输出R、G、B

    VGA_color_line i1 (
        .CLK(CLK),
        .RST_N(RST_N),
        .VGA_HSYNC(VGA_HSYNC),
        .VGA_VSYNC(VGA_VSYNC),
        .VGA_RED(VGA_RED),
        .VGA_GREEN(VGA_GREEN),
        .VGA_BLUE(VGA_BLUE)
    );
    initial
        begin
            CLK = 0;
        end
    always
        begin
            #1 CLK = ~CLK;
        end
endmodule