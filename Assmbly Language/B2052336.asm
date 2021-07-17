DATA SEGMENT
	A    DB 40H
	B    DB 30H
	C1   DB 20H
	D    DB 10H
	S    DW ?
DATA	ENDS
CODE SEGMENT
	      ASSUME CS: CODE, DS: DATA
	START:MOV    AX,DATA
	      MOV    DS,AX

	      MOV    AL,A
	      CBW
	      IMUL   B
	      PUSH   AX                	;A*B = 00C0

	      MOV    AL,C1
	      CBW
	      MOV    BL,D
	      CBW
	      ADD    AX,BX             	;C+D = 0030
	      MOV    BX,AX

	      POP    AX
	      IDIV   BX                	;(A*B)/(C+D) = 0040
	      MOV    DX,AX

	      MOV    AL,A
	      CBW
	      SUB    AL,B
	      MOV    BX,5
	      IMUL   BL
	      SAR    AX,1              	;5(A-B)/2 = 0028
	      ADD    AX,DX             	;(A*B)/(C+D)+5(A-B)/2 = 0068
	      MOV    DX,AX

	      MOV    AL,C1
	      CBW
	      MOV    BL,D
	      IDIV   BL                	;C/D = 0002
	      ADD    AX,DX             	;(A*B)/(C+D)+5(A-B)/2+C/D = 006A
	      MOV    S,AX

	      MOV    AX, 4C00H
	      INT    21H
        CODE ENDS
	END	START
