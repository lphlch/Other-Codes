module barrelshifter32(input [31:0] a,
                       input [4:0] b,
                       input [1:0] aluc,
                       output reg [31:0] c);
reg [31:0] temp;
always @(*) begin
    case (aluc)
        2'b00: begin
            temp = b[0]?{a[31],a[31:1]}:a;
            temp = b[1]?{{2{temp[31]}},temp[31:2]}:temp;
            temp = b[2]?{{4{temp[31]}},temp[31:4]}:temp;
            temp = b[3]?{{8{temp[31]}},temp[31:8]}:temp;
            temp = b[4]?{{16{temp[31]}},temp[31:16]}:temp;
        end
        2'b10:begin
            temp = b[0]?{1'b0,temp[31:1]}:a;
            temp = b[1]?{{2{1'b0}},a[31:2]}:temp;
            temp = b[2]?{{4{1'b0}},a[31:4]}:temp;
            temp = b[3]?{{8{1'b0}},a[31:8]}:temp;
            temp = b[4]?{{16{1'b0}},a[31:16]}:temp;
        end
        //11 or 01
        default: begin
            temp = b[0]?{a[30:0],1'b0}:a;
            temp = b[1]?{a[29:0],{2{1'b0}}}:temp;
            temp = b[2]?{a[27:0],{4{1'b0}}}:temp;
            temp = b[3]?{a[23:0],{8{1'b0}}}:temp;
            temp = b[4]?{a[15:0],{16{1'b0}}}:temp;
        end
    endcase
    c = temp;
end

endmodule
