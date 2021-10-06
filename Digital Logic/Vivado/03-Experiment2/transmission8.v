module transmission8(
    input [7:0] iData,
    input A,B,C,
    output [7:0] oData
);
    wire [7:0]iS2,iS1,iS0;
    assign iS2={{7{A}},A};
    assign iS1={{7{B}},B};
    assign iS0={{7{C}},C};

    wire [7:0]Y;
    assign Y=   (iData[0] & ~iS0 & ~iS1 & ~iS2) | 
                (iData[1] & iS0 & ~iS1 & ~iS2) |
                (iData[2] & ~iS0 & iS1 & ~iS2) | 
                (iData[3] & iS0 & iS1 & ~iS2) | 
                (iData[4] & ~iS0 & ~iS1 & iS2) | 
                (iData[5] & iS0 & ~iS1 & iS2) | 
                (iData[6] & ~iS0 & iS1 & iS2) | 
                (iData[7] & iS0 & iS1 & iS2)

    assign oData[0]= Y | iS2 | iS1 | iS0;
    assign oData[1]= Y | iS2 | iS1 | ~iS0;
    assign oData[2]= Y | iS2 | ~iS1 | iS0;
    assign oData[3]= Y | iS2 | ~iS1 | ~iS0;
    assign oData[4]= Y | ~iS2 | iS1 | iS0;
    assign oData[5]= Y | ~iS2 | iS1 | ~iS0;
    assign oData[6]= Y | ~iS2 | ~iS1 | iS0;
    assign oData[7]= Y | ~iS2 | ~iS1 | ~iS0;
endmodule