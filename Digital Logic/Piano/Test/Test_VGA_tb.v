`timescale 1 ns/ 1 ps
module VGA_color_line_vlg_tst();
    reg clk;
    reg rst_n;
    // wires
    wire b_vga;
    wire g_vga;
    wire hs_vga;
    wire r_vga;
    wire vs_vga;

    VGA_color_line i1 (
        .b_vga(b_vga),
        .clk(clk),
        .g_vga(g_vga),
        .hs_vga(hs_vga),
        .r_vga(r_vga),
        .rst_n(rst_n),
        .vs_vga(vs_vga)
    );
    initial
        begin
            clk = 0;
        end
    always
        begin
            #1 clk = ~clk;
        end
endmodule