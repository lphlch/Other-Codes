DATA   SEGMENT                               
INPUTTIPS  DB  "Please input: ",'$'
BUF DB  80				    ;输入后有效信息自BUF+2开始
       DB  ?				          
DATA   ENDS                                  


CODE SEGMENT
	        ASSUME CS:CODE,DS:DATA
	START:  MOV    AX,DATA
	        MOV    DS,AX


			
			CALL INPUTSTR	;输入字符串

			CALL PRINTCRLF

			LEA DX,BUF+2
        MOV AH, 09H							 
        INT 21H


			;循环统计字符串中各个字符个数
			;冒泡排序
			;
	        ;CALL   DISP


			MOV    AX,4C00H	
	        INT    21H
	;显示BX中的内容，16进制
	;影响寄存器：BX
DISP PROC
	        PUSH   AX
	        PUSH   CX
	        PUSH   DX
	        PUSHF

	        MOV    CH,4
	        MOV    CL,4
            
	ROTATE: ROL    BX,CL
	        MOV    AL,BL
	        AND    AL,0FH
	        ADD    AL,30H
	        CMP    AL,3AH
	        JL     PRINTIT
	        ADD    AL,7
	PRINTIT:MOV    DL,AL

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

;INPUTSTR:输入一串字符串，并给出输入提示
;output:DATA段BUF中
INPUTSTR PROC
	PUSHF
	PUSH AX
	PUSH DX
	PUSH SI

        LEA DX, INPUTTIPS                        ;打印提示输入信息    
        MOV AH, 09H							 
        INT 21H

        LEA DX,BUF                       ;接收字符串
        MOV AH, 0AH
        INT 21H
        MOV AL, BUF+1                     ;对字符串进行处理
        ADD AL, 2
        MOV AH, 0
        MOV SI, AX
        MOV BUF[SI], '$'

	POP SI
	POP DX
	POP AX
	POPF
	RET
INPUTSTR ENDP

;PRINTCRLF:输出换行
PRINTCRLF PROC
	PUSHF
	PUSH AX
	PUSH DX

	MOV DL,0DH
    MOV AH,2
    INT 21H
	MOV DL,0AH
       MOV AH,2
       INT 21H

	POP DX
	POP AX
	POPF
	RET
PRINTCRLF ENDP

CODE    ENDS
       	END	START

