module DataCompare4 (input [3:0] iData_a,
                     input [3:0] iData_b,
                     input [2:0] iData,
                     output [2:0] oData);
    always @(*) begin
        if (iData_a>iData_b) begin
            oData=3'b100;
        end
        if(iData_a<iData_b) begin
            oData=3'b010;
        end
        if (iData_a=iData_b) begin
            oData=iData;
        end
    end
endmodule
