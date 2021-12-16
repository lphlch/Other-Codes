module Ps2Decoder(
	input iClk,
	input iReset_n,
	input iFlag,
	input [7:0] iData,

	output reg [7:0] oData
	);

	reg [15:0] temp;
	
	always @ (posedge iClk or negedge iReset_n)
		if(!iReset_n)
			begin
				temp <= 16'd0;
			end
		else
			begin
				if(iFlag)
					begin
						temp = {temp[7:0],iData};   //move 8 bits to the left, adding the new data
					end
				else
					begin
						temp <= temp;
					end
			end
			
	always @ (posedge iClk or negedge iReset_n)
		if(!iReset_n)
			begin
				oData <= 8'b0;
			end
		else
			begin
				casex (temp)
					{8'hf0,8'hxx} : begin oData <=99; end    //when release, stop
					default :case(temp[7:0])
									//6 Mid Control
									8'h71:begin oData <= 36;end //del
									8'h69:begin oData <= 38;end //end
									8'h7a:begin oData <= 40;end //pgdn
									8'h70:begin oData <= 41;end //ins
									8'h6c:begin oData <= 43;end //home
									//8'h7d:begin oData <= 45;end   //pgup

									//small
									8'h75:begin oData <= 24;end //8
									8'h7d:begin oData <= 26;end //9
									8'h79:begin oData <= 28;end //+
									8'h77:begin oData <= 29;end //num
									8'h4a:begin oData <= 31;end // /
									8'h7c:begin oData <= 33;end //*
									8'h7b:begin oData <= 35;end //-

									8'he0:begin oData <= oData;end  //ignore E0
									default:begin oData <= 8'b0; end	//not defined
								endcase
				endcase
			end

endmodule 