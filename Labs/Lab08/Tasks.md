## Task 1
```asm
TITLE Source
include irvine32.inc

.data
	nums DWORD 4 DUP(?)
	prompt BYTE "Enter a number: ", 0
	end1 BYTE "All nums are equal", 0
	end2 BYTE "Nums arent equal", 0
.code
main PROC
	mov ecx, 0
	mov ebx, 4
	mov edx, offset prompt
	mov esi, offset nums
	input_loop:
		inc ecx
		call writestring
		call readint
		mov [esi], eax
		add esi, 4
		cmp ecx, ebx
		jl input_loop
	mov esi, offset nums
	mov eax, [esi]
	cmp eax, [esi+4]
	jne not_equal
	add esi, 4
	mov eax, [esi]
	cmp eax, [esi+4]
	jne not_equal
	add esi, 4
	mov eax, [esi]
	cmp eax, [esi+4]
	jne not_equal
	mov edx, offset end1
	call writestring
	jmp end_code
	not_equal:
		mov edx, offset end2
		call writestring
	end_code:
main endp
end main
```
![image](https://github.com/user-attachments/assets/c73c751e-f8b6-4c7d-a9e4-675ba031ce9c)
![image](https://github.com/user-attachments/assets/856f4582-03f7-44ba-bbb0-b3ddc3ad82e6)

## Task 2
```asm
TITLE Source
include irvine32.inc

.data
	intArr SWORD 0,0,0,150,120,35,-12,66,4,0
	end1 BYTE "Non Zero Value found:  ", 0
	end2 BYTE "No non zero values in array.", 0
.code
main PROC
	mov esi, offset intArr
	mov ecx, lengthof intArr
	check_nums:
		mov ax, [esi]
		cmp ax, 0
		jg found
		add esi, 2
		loop check_nums
	jmp end_code
	found:
		mov edx, offset end1
		movsx eax, ax
		call writestring
		call writeint
	end_code:
main endp
end main
```
![image](https://github.com/user-attachments/assets/de2f058d-3439-44f0-b169-9593e4de15c4)

## Task 3
```asm
TITLE Source
include irvine32.inc

.data
	var DWORD 5
	x DWORD ?
.code
main PROC
	mov edx, var
	inc edx
	mov ecx, 10 ; lengthof array from task 2 used
	cmp var, ecx
	jge else_block
	cmp ecx, edx
	jl else_block
	mov x, 0
	jmp end_code
	else_block:
		mov x, 1
	end_code:
		mov eax, x
		call writedec
main endp
end main
```
![image](https://github.com/user-attachments/assets/f2d81011-3554-45fe-ab3d-d093b69aa31b)

## Task 4
```asm
TITLE Source
include irvine32.inc

.data
	var DWORD 0
	prompt1 BYTE "Hello", 0
	prompt2 BYTE "World", 0
.code
main PROC
	while_loop:
		mov eax, var
		cmp eax, 5
		jge else_block
		mov edx, offset prompt1
		call writestring
		inc eax
		mov var, eax
		cmp eax, 10
		jle while_loop
		else_block:
			mov edx, offset prompt2
			call writestring
		inc eax
		mov var, eax
		cmp eax, 10
		jle while_loop
	end_code:
main endp
end main
```
![image](https://github.com/user-attachments/assets/032c90b6-0d40-4a98-8529-062b61ec91f9)

## Task 5
```asm
TITLE Source
include irvine32.inc

.data
	arr WORD 10, 4, 7, 14, 299, 156, 3, 19, 29, 300, 20
	num DWORD ?
	prompt BYTE "Enter a number: ", 0
	end1 BYTE "Number Found.", 0
	end2 BYTE "Number Not Found", 0
.code
main PROC
	mov edx, offset prompt
	call writestring
	call readint
	mov ecx, lengthof arr
	mov esi, offset arr
	search_loop:
		mov ebx, [esi]
		cmp eax, ebx
		je found
		add esi, 2
		loop search_loop
	mov edx, offset end2
	call writestring
	jmp end_code
	found:
		mov edx, offset end1
		call writestring
	end_code:
main endp
end main
```
![image](https://github.com/user-attachments/assets/cb49b28e-7d37-441c-b058-819171eebd66)
![image](https://github.com/user-attachments/assets/8e6d46cc-d09d-4285-9636-5d076f8e88cf)

## Task 6
```asm
TITLE Source
include irvine32.inc

.data
	arr WORD 10, 4, 7, 14, 299, 156, 3, 19, 29, 300, 20
	prompt BYTE "Sorted array: ", 0
	curr_num DWORD 0
	outer_count DWORD 0
.code
main PROC
	mov esi, offset arr
	mov ecx, lengthof arr - 1
	outer_loop:
		mov ax, [esi]
		mov curr_num, esi
		dec ecx
		mov outer_count, ecx
		add esi, 2
		inner_loop:
			cmp ax, [esi]
			jl swap
			add esi, 2
			loop inner_loop
			swap:
				mov dx, [esi]
				mov [esi], ax
				mov [esi-2], dx
			loop inner_loop
		mov esi, curr_num
		mov ecx, outer_count
		loop outer_loop
	mov esi, offset arr
	mov ecx, lengthof arr
	mov edx, offset prompt
	call writestring
	print_loop:
		mov eax, [esi]
		add esi, 2
		call writedec
		loop print_loop
	end_code:
main endp
end main
```

## Task 7
```asm
TITLE Source
include irvine32.inc

.data
	weekdays BYTE "Monday",0,0,0,0,
    "Tuesday",0,0,0,
    "Wednesday",0,
    "Thursday",0,0,
    "Friday",0,0,0,0,
    "Saturday",0,0,
    "Sunday",0,0,0,0
	prompt BYTE "Enter a number: ", 0
.code
main PROC
	mov edx, offset prompt
	call writestring
	call ReadInt
	dec eax
	mov ebx, 10
	imul ebx

	mov esi, eax
	mov ecx, 10
print_word:
	movzx eax, weekdays[esi]
	call WriteChar
	inc esi
	loop print_word
  end_code:
main endp
end main
```
![image](https://github.com/user-attachments/assets/748e0e4f-b287-454b-a57b-3392fdf1e877)

## Task 8
```asm
TITLE Source
include irvine32.inc

.data
	prompt BYTE "Enter a character: ", 0
	end1 BYTE "It is a character.", 0
	end2 BYTE "It is not a character.", 0
.code
main PROC
	mov edx, offset prompt
	call writestring
	call readchar
	call writechar
	call crlf
	cmp al, 65
	jl not_an_alphabet
	cmp al, 95
	jle is_an_alphabet
	cmp al, 97
	jl not_an_alphabet
	cmp al, 122
	jg not_an_alphabet
	is_an_alphabet:
		mov edx, offset end1
		call writestring
		jmp end_code
	not_an_alphabet:
		mov edx, offset end2
		call writestring
	end_code:
	exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/5da6c3f0-c1ee-4140-9d50-a52f057c8daa)
![image](https://github.com/user-attachments/assets/74ab1da7-2379-4770-92d9-78513cdb83be)
