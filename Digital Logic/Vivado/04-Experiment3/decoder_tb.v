module decoder_tb ();
    reg [2:0] iData;
    reg [1:0] iEna;
    wire [7:0] oData;
    decoder uut(iData,iEna,oData);
    initial
    begin
        iEna[1]=0;        
        iEna[0]=0;
        #200 
        iEna[1]=0;        
        iEna[0]=1;
        #200 
        iEna[1]=1;        
        iEna[0]=1;
        #200 
        iEna[1]=1;        
        iEna[0]=0;
    end
    initial
    begin
        iData=3'b000;
        #25 iData=3'b001;
        #25 iData=3'b010;
        #25 iData=3'b011;
        #25 iData=3'b100;
        #25 iData=3'b101;
        #25 iData=3'b110;
        #25 iData=3'b111;

        #25 iData=3'b000;
        #25 iData=3'b001;
        #25 iData=3'b010;
        #25 iData=3'b011;
        #25 iData=3'b100;
        #25 iData=3'b101;
        #25 iData=3'b110;
        #25 iData=3'b111;

        #25 iData=3'b000;
        #25 iData=3'b001;
        #25 iData=3'b010;
        #25 iData=3'b011;
        #25 iData=3'b100;
        #25 iData=3'b101;
        #25 iData=3'b110;
        #25 iData=3'b111;

        #25 iData=3'b000;
        #25 iData=3'b001;
        #25 iData=3'b010;
        #25 iData=3'b011;
        #25 iData=3'b100;
        #25 iData=3'b101;
        #25 iData=3'b110;
        #25 iData=3'b111;
    end
endmodule