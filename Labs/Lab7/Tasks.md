## Task 1
```asm
TITLE Task1
INCLUDE irvine32.inc

.data
	
	array WORD 1,2,3,4,5,6,7,8,9,10
	destination WORD 10 DUP(?)
.code
main PROC
	mov ecx, 10
	mov esi, 0
	push_to_stack:
		mov ax, array[esi]
		PUSH ax
		inc esi
		inc esi
		loop push_to_stack
	mov ecx, 10
	mov esi, 0
	pop_to_dest:
		POP ax
		mov destination[esi], ax
		inc esi
		inc esi
		loop pop_to_dest
	mov ecx, 10
	mov esi, 0
	print_array:
		movzx eax, destination[esi]
		call writeint
		inc esi
		inc esi
		loop print_array
	exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/d16996c4-32ea-4823-832e-3442a95b7375)

## Task 2
```asm
TITLE Task2
INCLUDE irvine32.inc

.data
	
	int1 DWORD 7
	int2 DWORD 13
	int3 DWORD 9
.code
main PROC
	mov eax, int1
	push eax
	mov eax, int2
	push eax
	mov eax, int3
	push eax
	pop eax
	pop ebx
	pop ecx
	add eax, ebx
	add eax, ecx
	call writedec
	exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/97eb11b4-e4da-4773-a851-11bd6321bc78)

## Task 3
