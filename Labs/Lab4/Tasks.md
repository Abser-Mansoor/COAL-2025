## Task 1
MOV AX 3d -> no comma (syntax error)\
MOV 23, AX -> asignment to immediate number (logical error)\
MOV CX, CH -> assignment of separate sized registers (logical error)\
MOVE AX, 1h -> MOVE is not a valid command (syntax error)\
ADD 2, CX -> assignment to immediate number (logical error)\
ADD 3, 6 -> assignment to immediate number (logical error)\
INC AX, 2 -> inc does not take any source operand (syntax error)
## Task 2
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
## Task 3
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
## Task 4 Part 1
```asm
TITLE task.asm
INCLUDE Irvine32.inc

.data
	Val1 DWORD 25h
	Val2 BYTE 36o
	Val3 WORD 20d
.code
main PROC
	mov eax, 89
	add eax, 75fh
	sub eax, 46o
	sub eax, 28
	add eax, 1101b
	call writeint
exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/d24947bf-721e-40ba-b977-f01f77f4b725)

## Task 4 Part 2
```asm
TITLE task.asm
INCLUDE Irvine32.inc

.data
	Val1 DWORD 25h
	Val2 BYTE 36o
	Val3 WORD 20d
.code
main PROC
	mov eax, val1
	movzx ebx, val2
	add eax, ebx
	sub eax, 654h
	movzx ebx, val3
	add eax, ebx
	call writeint
exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/6d494c5d-ac2b-4ab8-9288-36a0e4142084)
## Task 5
```asm
TITLE task.asm
INCLUDE Irvine32.inc

.data
	SecondsInDay equ 24*60*60
.code
main PROC
	mov eax, SecondsInDay
	call writeint
exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/655b0ebe-327e-49ad-a3a4-ad824baf5902)
## Task 6
```asm
TITLE task.asm
INCLUDE Irvine32.inc

.data
	A DWORD 0FF10h
	B DWORD 0E10Bh
.code
main PROC
	mov eax, A
	mov ebx, B
	xchg eax, ebx
	call dumpregs
exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/32d613c4-f747-4c9a-af92-14216ed323b4)
## Task 7
```asm
TITLE task.asm
INCLUDE Irvine32.inc

.data
	val1 BYTE 10h
	val2 WORD 8000h
	val3 DWORD 0FFFFh
	val4 WORD 7FFFh

.code
main PROC
	inc val2
	mov eax, 1000h
	sub eax, val3
	mov dx, val4
	sub dx, val2
	movzx ebx, val1
	movzx ecx, val2
	movzx edx, val4
	call dumpregs
exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/000cb8f5-266c-463c-8ff9-a644620629ea)
