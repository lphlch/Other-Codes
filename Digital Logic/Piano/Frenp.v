module Frenp(clk,rst_n,clk_1M);

	input clk;
	input rst_n;
	
	output reg clk_1M;
	
	reg [4:0] count;
	
	always @(posedge clk or negedge rst_n)
		if(!rst_n)
			begin
				count <= 5'd0;
				clk_1M <= 1'b1;
			end
		else
			begin
				if(count == 50_000_000 / 1000_000 / 2 - 1)
					begin
						count <= 5'd0;
						clk_1M <= ~clk_1M;
					end
				else
					begin
						count <= count + 1'b1;
					end
			end

endmodule 