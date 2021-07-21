STACK   SEGMENT PARA STACK
S_AREA  DW      100H DUP(?)
S_TOP   EQU     $-S_AREA
STACK   ENDS

DATA    SEGMENT PARA
VALUE   DW      0100H ;060314
RESULT  DB      5 DUP(?),'$'
DATA    ENDS

CODE    SEGMENT PARA
        ASSUME  CS:CODE,DS:DATA,SS:STACK

MAIN    PROC    FAR
        MOV     AX,DATA
        MOV     DS,AX
        MOV     AX,STACK
        MOV     SS,AX
        MOV     SP,S_TOP
        MOV     CX,5
        MOV     AX,VALUE
        MOV     BX,10
        MOV     DI,OFFSET RESULT+4

JYB:    XOR     DX,DX
        DIV     BX
        OR      DL,30H
        MOV     BYTE PTR [DI],DL
        DEC     DI
        LOOP    JYB
        MOV     DX,OFFSET RESULT
        MOV     AH,9
        INT     21H

EXIT:   MOV     AX,4C00H
        INT     21H
MAIN    ENDP
CODE    ENDS
        END     MAIN