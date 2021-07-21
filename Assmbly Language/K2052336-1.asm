DATA SEGMENT
	INPUTTIPS DB "Please input 6 numbers that packages delivered each day, each number should be followed with an ENTER: ",'$'
	COUNTINGTIPS DB 0DH,0AH,"Input done, counting pays......",'$'
	ERRORA1  DB 0DH,0AH,"ERROR A1:Input non-number!",'$'
ERRORA2  DB 0DH,0AH,"ERROR A2:Input overflow!",'$'
	DAY       DW 0,0,0,0,0,0	;100,100,100,100,100,100;
	SUM			DW 13200
	RESULTSTR	DB "Total pays:",5 DUP(?),'$'
DATA   ENDS   

CODE SEGMENT
	           ASSUME CS:CODE,DS:DATA
	START:     MOV    AX,DATA
	           MOV    DS,AX

	           CALL   INPUTNUM	;数据输入

				LEA    DX,COUNTINGTIPS					;输入完毕提示
	           MOV    AH,09H
	           INT    21H

	           CALL   ADDITION	;计算附加

				MOV BX,10
				MOV AX,SUM
				MOV DX,0
				DIV BX			;32位除16位，商在AX

				CALL HEXTODEC

				MOV DL,0AH
				MOV AH,09H
				INT 21H
				MOV DL,0AH
				MOV AH,02H
				INT 21H
				LEA DX,RESULTSTR
				MOV AH,09H
				INT 21H

	           MOV    AH,4CH
	           INT    21H


;description
ADDITION PROC
	PUSH DX
         PUSH  BX
         PUSH   CX
         PUSH   AX
		 PUSH SI
         PUSHF

		MOV SI,0
ADDITION_LOOP:MOV AX,WORD PTR DAY[SI]
		CMP AX,100
		JA	MORE
		JB LESS
		JE ADDITION_NEXTDAY

MORE:	SUB	AX,100
		MOV BX,15
		MUL BX
		ADD SUM,AX
		JMP ADDITION_NEXTDAY

LESS:	MOV BX,100
		SUB BX,AX
		MOV AX,BX
		MOV BX,12
		MUL BX
		SUB SUM,AX
		JMP ADDITION_NEXTDAY

ADDITION_NEXTDAY:ADD SI,2
CMP SI,12
JB ADDITION_LOOP

         POPF
		 POP SI
         POP    AX
         POP    CX
		POP BX
		POP DX
         RET	
ADDITION ENDP

;进制转换子程序
;input:AX
HEXTODEC PROC
			 PUSH BX
         PUSH   CX
         PUSH   DX
		 PUSH DI
         PUSHF
		
        MOV     CX,4
        MOV     BX,10
        MOV     DI,OFFSET RESULTSTR+15

JYB:    XOR     DX,DX
        DIV     BX
        OR      DL,30H
        MOV     BYTE PTR [DI],DL
        DEC     DI
        LOOP    JYB

         POPF
		 POP DI
         POP    DX
         POP    CX
		 POP BX
         RET
HEXTODEC ENDP


;显示BX中的内容，16进制
;影响寄存器：BX
DISP PROC
	           PUSH   AX
	           PUSH   CX
	           PUSH   DX
	           PUSHF

	           MOV    CH,4
	           MOV    CL,4
			
	ROTATE:    ROL    BX,CL
	           MOV    AL,BL
	           AND    AL,0FH
	           ADD    AL,30H
	           CMP    AL,3AH
	           JL     PRINTIT
	           ADD    AL,7
	PRINTIT:   MOV    DL,AL

	           MOV    AH,2
	           INT    21H

	           DEC    CH
	           JNZ    ROTATE

	           MOV    AH,2
	           MOV    DL,48H
	           INT    21H

	           POPF
	           POP    DX
	           POP    CX
	           POP    AX
	           RET
DISP ENDP

	;数据输入，以回车作为数据分割，输入6个即退出
INPUTNUM PROC
	           PUSH   AX
	           PUSH   BX
	           PUSH   CX
	           PUSH   DX
	           PUSH   SI
	           PUSHF

	           LEA    DX, INPUTTIPS      	;输出提示信息
	           MOV    AH, 09H
	           INT    21H

	           MOV    CX,0
	           MOV    SI,0
	INPUT:     MOV    AH, 1              	;输入一个字符
	           INT    21H

	           CMP    AL,0DH             	;回车跳出
	           JE     NEXTDAY
	           CMP    AL,'0'
	           JB     P_ERRORA1              	;小于0，转到其他
	           CMP    AL,'9'
	           JA     P_ERRORA1              	;大于9，转到其他

	NUMBER:    MOV    BX,0
	           MOV    BL,AL
	           SUB    BL,30H
	           MOV    AX,WORD PTR DAY[SI]
	           MOV    DX,10
	           MUL    DX
			   JO	  P_ERRORA2
	           ADD    AX,BX
	           MOV    WORD PTR DAY[SI],AX
	           JMP    INPUT

	P_ERRORA1: CALL   PRINTERRORA1
	P_ERRORA2:CALL	PRINTERRORA2

	NEXTDAY:   MOV    BX,DAY[SI]
	           CALL   DISP
	           INC    CX
	           INC    SI
	           INC    SI
	           CMP    CX,6
	           JAE     EXIT
	           JMP    INPUT

	EXIT:      POPF
	           POP    SI
	           POP    DX
	           POP    CX
	           POP    BX
	           POP    AX
	           RET

INPUTNUM ENDP

	;description
PRINTERRORA1 PROC
	           PUSH   AX
	           PUSH   DX
	           PUSHF

	           LEA    DX,ERRORA1
	           MOV    AH,09H
	           INT    21H

	           MOV    AH,4CH
	           INT    21H

PRINTERRORA1 ENDP

PRINTERRORA2 PROC
	           PUSH   AX
	           PUSH   DX
	           PUSHF

	           LEA    DX,ERRORA2
	           MOV    AH,09H
	           INT    21H

	           MOV    AH,4CH
	           INT    21H

PRINTERRORA2 ENDP

CODE    ENDS
	   	END	START

