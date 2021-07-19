DATA SEGMENT
	X    DB 0A0H	;源
	C10  DB 10
DATA		ENDS
CODE SEGMENT
	      ASSUME DS: DATA, CS: CODE
	START:MOV    AX, DATA
	      MOV    DS, AX
	      MOV    CX, 3
	      MOV    AL, 0a0h
	ONE:  MOV    AH, 0
	      DIV    C10
	      PUSH   AX
	      LOOP   ONE
	      MOV    CX, 3
	TWO:  POP    DX
	      XCHG   DH, DL
	      OR     DL, 30H
	      MOV    AH, 2
	      INT    21H
	      LOOP   TWO
	      MOV    AX, 4C00H
	      INT    21H
CODE	ENDS
	END   START
