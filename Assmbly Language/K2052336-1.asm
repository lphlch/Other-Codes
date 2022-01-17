DATA SEGMENT
	INPUTTIPS    DB "Please input 6 numbers that packages delivered each day, each number should be followed with an ENTER: ",0DH,0AH,'$'
	COUNTINGTIPS DB 0DH,0AH,"Input done, counting pays......",'$'
	ERRORA1      DB 0DH,0AH,"ERROR A1:Input non-number!",'$'
	ERRORA2      DB 0DH,0AH,"ERROR A2:Input overflow!",'$'
	DAY          DW 0,0,0,0,0,0
	SUM          DW 13200
	RESULTSTR    DB "Total pays:",5 DUP(?),'$'
DATA   ENDS

;打印错误信息并中止程序宏
;输入：_ads 错误信息的字符串首地址
;输出：一串字符串，并中止程序
PRINTERROR MACRO _ads
	                 LEA    DX,_ads
	                 MOV    AH,09H
	                 INT    21H

	                 MOV    AH,4CH
	                 INT    21H
ENDM

CODE SEGMENT
	                 ASSUME CS:CODE,DS:DATA
	START:           MOV    AX,DATA
	                 MOV    DS,AX

	                 CALL   INPUTNUM              	;数据输入

	                 LEA    DX,COUNTINGTIPS       	;输入完毕提示
	                 MOV    AH,09H
	                 INT    21H

	                 CALL   ADDITION              	;计算附加工资

	                 MOV    BX,10
	                 MOV    AX,SUM
	                 MOV    DX,0
	                 DIV    BX                    	;32位除16位，商在AX

	                 CALL   HEXTODEC				;10进制转换

	                 MOV    DL,0DH
	                 MOV    AH,02H
	                 INT    21H
	                 MOV    DL,0AH
	                 MOV    AH,02H
	                 INT    21H
	                 LEA    DX,RESULTSTR			;输出结果
	                 MOV    AH,09H
	                 INT    21H

	                 MOV    AH,4CH
	                 INT    21H


	
	
;计算附加工资子程序
;输入：每日快递量DAY、基本工资SUM
;输出：周工资SUM
ADDITION PROC
	                 PUSH   DX
	                 PUSH   BX
	                 PUSH   CX
	                 PUSH   AX
	                 PUSH   SI
	                 PUSHF

	                 MOV    SI,0
	ADDITION_LOOP:   MOV    AX,WORD PTR DAY[SI]
	                 CMP    AX,100
	                 JA     MORE
	                 JB     LESS
	                 JE     ADDITION_NEXTDAY

	MORE:            SUB    AX,100
	                 MOV    BX,15
	                 MUL    BX
	                 ADD    SUM,AX
	                 JMP    ADDITION_NEXTDAY

	LESS:            MOV    BX,100
	                 SUB    BX,AX
	                 MOV    AX,BX
	                 MOV    BX,12
	                 MUL    BX
	                 SUB    SUM,AX
	                 JMP    ADDITION_NEXTDAY

	ADDITION_NEXTDAY:ADD    SI,2
	                 CMP    SI,12
	                 JB     ADDITION_LOOP

	                 POPF
	                 POP    SI
	                 POP    AX
	                 POP    CX
	                 POP    BX
	                 POP    DX
	                 RET
ADDITION ENDP

;进制转换子程序
;输入：要转换的量AX
;输出：转换后的字符串字面值
HEXTODEC PROC
	                 PUSH   BX
	                 PUSH   CX
	                 PUSH   DX
	                 PUSH   DI
	                 PUSHF
		
	                 MOV    CX,4
	                 MOV    BX,10
	                 MOV    DI,OFFSET RESULTSTR+15

	JYB:             XOR    DX,DX
	                 DIV    BX
	                 OR     DL,30H
	                 MOV    BYTE PTR [DI],DL
	                 DEC    DI
	                 LOOP   JYB

	                 POPF
	                 POP    DI
	                 POP    DX
	                 POP    CX
	                 POP    BX
	                 RET
HEXTODEC ENDP

;数据输入子程序
;输入：无
;输出：每日快递量DAY
INPUTNUM PROC
	                 PUSH   AX
	                 PUSH   BX
	                 PUSH   CX
	                 PUSH   DX
	                 PUSH   SI
	                 PUSHF

	                 LEA    DX, INPUTTIPS         	;输出提示信息
	                 MOV    AH, 09H
	                 INT    21H

	                 MOV    CX,0
	                 MOV    SI,0
	INPUT:           MOV    AH, 1                 	;输入一个字符
	                 INT    21H

	                 CMP    AL,0DH                	;回车跳出
	                 JE     NEXTDAY
	                 CMP    AL,'0'
	                 JB     P_ERRORA1             	;小于0，转到其他
	                 CMP    AL,'9'
	                 JA     P_ERRORA1             	;大于9，转到其他

	NUMBER:          MOV    BX,0
	                 MOV    BL,AL
	                 SUB    BL,30H
	                 MOV    AX,WORD PTR DAY[SI]
	                 MOV    DX,10
	                 MUL    DX
	                 JO     P_ERRORA2
	                 ADD    AX,BX
					 CMP	AX,500
					 JO		P_ERRORA2
					 JA		P_ERRORA2
	                 MOV    WORD PTR DAY[SI],AX
	                 JMP    INPUT

	P_ERRORA1:       PRINTERROR ERRORA1	;调用错误输出
	P_ERRORA2:       PRINTERROR ERRORA2

	NEXTDAY:         INC    CX
	                 INC    SI
	                 INC    SI
	                 CMP    CX,6
	                 JAE    EXIT
	                 JMP    INPUT

	EXIT:            POPF
	                 POP    SI
	                 POP    DX
	                 POP    CX
	                 POP    BX
	                 POP    AX
	                 RET

INPUTNUM ENDP

CODE    ENDS
	   	END	START

