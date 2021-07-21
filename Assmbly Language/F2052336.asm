MYDATA SEGMENT
	DATA   DW  1234H,5678H,9D4CH,0D7H,0,-1,7D2AH,8A0EH,10F5H,645DH
	N      EQU $-DATA
MYDATA ENDS
EXTRN DISPBX:FAR

CODE SEGMENT
	ASSUME CS:CODE,DS:MYDATA
	START:  MOV    AX,MYDATA
	        MOV    DS,AX
	        MOV    AX,N
	        MOV    BX,2
	        DIV    BX
	        MOV    CX,AX
	        MOV    BX,OFFSET DATA

	        MOV    AX,7EEEH
	        DEC    BX
	        DEC    BX

	AGAIN:  INC    BX
	        INC    BX
	        TEST   WORD PTR [BX],0001H
	        JNZ    NEXT               	;奇数则不比较
	        CMP    AX,WORD PTR [BX]
	        JLE    NEXT               	;小于等于时跳转

	        MOV    AX,WORD PTR [BX]   	;大于时，替换
	NEXT:   LOOP   AGAIN

	        MOV    BX,AX              	;最小放入BX

	        CALL   DISPBX

	           MOV    AH,4CH
	           INT    21H
CODE    ENDS
       	END	START

