module ram2 (
    input clk,
    input ena,
    input wena,
    input [4:0] addr,
    inout [31:0] data
);
    reg [31:0] ram_data [31:0];

    integer i;
    initial begin
        for ( i = 0;i <= 31;i = i+1 )
            ram_data[i] <= 0;
    end
    
    always @(posedge clk) begin
        if (ena) begin
            if (wena) begin
                ram_data[addr] <= data;
            end
        end        
    end
    always @(*) begin
        if (ena && wena == 0) begin
            data <= ram_data[addr];
        end
        else if(ena==0) begin
            data <= 32'bz;
        end
    end
endmodule