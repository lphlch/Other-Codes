module ram (input clk,
            input ena,
            input wena,
            input [4:0] addr,
            input [31:0] data_in,
            output [31:0] data_out);
    
    reg [31:0] ram_data;
    always @(posedge clk) begin
        if (ena) begin
            if (wena) begin
                ram_data[addr] <= data_in;
            end
            else begin
                data_out <= ram_data[addr];
            end
        end
        else begin
            data_out <= 32'bz;
        end
        
    end
endmodule
