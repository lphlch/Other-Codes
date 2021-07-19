DATA SEGMENT
	OUTPUT_LETTER DB 0DH,0AH,'LETTER:$'
	COUNT_LETTER  DB 0
	OUTPUT_NUMBER DB 0DH,0AH,'NUMBER:','$'
	COUNT_NUMBER  DB 0
	OUTPUT_OTHER  DB 0DH,0AH,'OTHER:','$'
	COUNT_OTHER   DB 0-1                  	;因为统计时会将终止符计入，所以此处为-1
	C10           DB 10
DATA ENDS

CODE SEGMENT
	                ASSUME CS: CODE, DS: DATA
	START:          MOV    AX, DATA
	                MOV    DS, AX
	INPUT:          MOV    AH, 1
	                INT    21H               	;输入一个字符
	                CMP    AL, 'a'
	                JB     SMALL_THAN_0x61   	;小于a，继续比较
	                CMP    AL, 'z'
	                JA     OTHER             	;大于z，转到其他
	                JMP    LETTER

	SMALL_THAN_0x61:CMP    AL,'A'
	                JB     SMALL_THAN_0x41   	;小于A
	                CMP    AL,'Z'
	                JA     OTHER             	;大于Z，转到其他
	                JMP    LETTER

	LETTER:         ADD    COUNT_LETTER,1
	                JMP    NEXT

	SMALL_THAN_0x41:CMP    AL,'0'
	                JB     OTHER             	;小于0，转到其他
	                CMP    AL,'9'
	                JA     OTHER             	;大于9，转到其他

	NUMBER:         ADD    COUNT_NUMBER,1
	                JMP    NEXT
					

	OTHER:          ADD    COUNT_OTHER,1

	NEXT:           CMP    AL,0DH            	;回车跳出
	                JNE    INPUT

	                LEA    DX,OUTPUT_LETTER  	;输出信息
	                MOV    AH,9
	                INT    21H
	                MOV    CX, 2
	                MOV    AL, COUNT_LETTER
	                CALL   FORMAT


	                LEA    DX,OUTPUT_NUMBER
	                MOV    AH,9
	                INT    21H
	                MOV    CX, 2
	                MOV    AL, COUNT_NUMBER
	                CALL   FORMAT

	                LEA    DX,OUTPUT_OTHER
	                MOV    AH,9
	                INT    21H
	                MOV    CX, 2
	                MOV    AL, COUNT_OTHER
	                CALL   FORMAT

	                MOV    AX,4C00H
	                INT    21H

	FORMAT:         NOP                      	;进制转换子程序
	FIRST:          MOV    AH, 0
	                DIV    C10
	                PUSH   AX
	                LOOP   FIRST
	                MOV    CX, 2
	SECOND:         POP    DX
	                XCHG   DH, DL
	                OR     DL, 30H
	                MOV    AH, 2
	                INT    21H
	                LOOP   SECOND
	                RET
CODE ENDS
END START