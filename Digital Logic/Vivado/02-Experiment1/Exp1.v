module logic_gates_1(iA, iB, oAnd, oOr, oNot);
input iA,iB;
output oAnd, oOr, oNot;
and and_inst(oAnd, iA, iB);
or or_inst(oOr, iA, iB);
not not_inst(oNot, iA);
endmodule

module logic_gates_2(iA, iB, oAnd, oOr, oNot);
input iA, iB;
output oAnd, oOr, oNot;
assign oAnd=iA & iB;
assign oOr= iA | iB;
assign oNot=~iA;
endmodule

module logic_gates_3( iA, iB, oAnd, oOr, oNot)
input iA, iB;
output reg oAnd, oOr, oNot;
always @ (*)
begin
oAnd = iA & iB;
oOr= iA | iB;
oNot = ~ iA;
end
endmodule

timescale 1ns/1ns
module logic_gates_tb;
reg iA;
reg iB;
wire oAnd;
wire oOr;
wire oNot;
initial
begin
iA=0;
#40 iA=1;
#40 iA=0;
#40 iA=1;
#40 iA=0;
end
initial
begin
iB=0;
#40 iB=0;
#40 iB=1;
#40 iB=1;
#40 iB=0;
end
logic_gates_1
logic_gates_inst(
.iA(iA),
.iB(iB),
.oAnd(oAnd),
.oOr(oOr),
.oNot(oNot)
);
endmodule

module three_state_gates(iA,iEna,oTri);
input iA;
input iEna;
output oTri;
assign oTri=(iEna==1)?iA:'bz;
endmodule

timescale 1ns/1ns
Module three_state_gates_tb;
reg iA;
reg iEna;;
wire oTriState;
three_state_gates uut(
.iA(iA),
.iEna(iEna),
.oTri(oTriState)
);
initial
begin
iA=0;
#40 iA=1;
#40 iA=0;
#40 iA=1;
end
initial
begin
iEna =1;
#20 iEna=0;
#40 iEna=1;
#20 iEna=0;
end
endmodule

module extend #(parameter WIDTH = 16)(
input [WIDTH-1:0] a,
input sext, //sext 有效是高电平为符号扩展，否则为 0 扩展
output [31:0] b
);
assign b=sext? {{(32-WIDTH){a[WIDTH-1]}},a} : {{(32-
WIDTH){1'b0}},a};
endmodule

timescale 1ns/1ns
module extend_tb;
reg [15:0] a;
reg sext;
wire [31:0] b;
// Instantiate the Unit Under Test (UUT)
extend uut (.a(a),.sext(sext),.b(b));
initial
begin
// Initialize Inputs
a=0;
sext=0;
// Wait 100 ns for global reset to finish
#100;
// Add stimulus here
sext =1;
a=16'h0000;
#100;
sext= 0;
a=16'h8000;
#100;
sext =1;
a=16'h8000;
#100;
sext= 0;
a= 16'hffff;
#100;
sext=1;
a= 16'hffff;
#100;
end
endmodule