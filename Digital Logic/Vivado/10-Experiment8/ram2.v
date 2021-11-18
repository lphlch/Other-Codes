module ram2 (input clk,
             input ena,
             input wena,
             input [4:0] addr,
             inout [31:0] data);
    reg [31:0] ram_data [31:0];
    reg [31:0] data_tmp;
    integer i;
    initial begin
        for (i = 0;i <= 31;i = i+1)
            ram_data[i] <= 0;
    end
    
    always @(posedge clk) begin
        $monitor($time,"Data = %h, DataTmp = %h, Ram_data = %h, Addr=%d,wena=%d", data,data_tmp,ram_data[addr],addr,wena);
        if (ena) begin
            if (wena) begin
                ram_data[addr] <= data;
            end
            else begin
                data_tmp <= ram_data[addr];
            end
        end
        else begin
            data_tmp <= 32'bz;
        end
    end
    
    assign data = data_tmp;
endmodule
