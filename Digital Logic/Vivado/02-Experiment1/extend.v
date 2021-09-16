module extend #(parameter WIDTH= 16)(
    input[ WIDTH-1: 0]a,
    input sext,		//sext高电平为符号扩展,否则0扩展
    output [31: 0]b
    );
    assign b= sext?{{(32-WIDTH)(a[ WIDTH-1]}}, a}:{27'b0,a};
endmodule