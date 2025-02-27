##Task 1\
MOV AX 3d -> no comma (syntax error)\
MOV 23, AX -> asignment to immediate number (logical error)\
MOV CX, CH -> assignment of separate sized registers (logical error)\
MOVE AX, 1h -> MOVE is not a valid command (syntax error)\
ADD 2, CX -> assignment to immediate number (logical error)\
ADD 3, 6 -> assignment to immediate number (logical error)\
INC AX, 2 -> inc does not take any source operand (syntax error)\
\
##Task 2\
```asm
TITLE task.asm
INCLUDE Irvine32.inc

.code
main PROC
	mov eax, 41h
	mov ebx, 42h
	mov ecx, 53h
	call dumpregs
exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/bcad71b4-0f45-4efb-bc73-79263d05f2a2)
\
\
##Task 3\
```asm
TITLE task.asm
INCLUDE Irvine32.inc

.data
	varB BYTE +10
	varW WORD -150
	varD DWORD 600

.code
main PROC
	movzx eax, varB
	movzx ebx, varW
	mov ecx, varD
	call dumpregs
exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/bb74e94a-ef4b-47ac-a0e0-796ad064cb94)
\
\
##Task 4\
```asm

```
