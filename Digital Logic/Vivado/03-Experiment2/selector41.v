module selector41(
    input [3:0] iC0,
    input [3:0] iC1,
    input [3:0] iC2,
    input [3:0] iC3,
    input iS1,
    input iS0,
    output [3:0] oZ
);
    assign oZ=iC0 & ~iS0 & ~iS1 | iC1 & ~iS1 & iS0 | iC2 & iS1 & ~iS0 | iC3 & iS1 &iS0;
endmodule