## Task 1
```asm
TITLE Source
include irvine32.inc

.data
	prev DWORD 1
	curr DWORD 1

.code
main PROC
	mov ecx, 10
	fib:
		mov eax, curr
		call writeint
		add eax, prev
		mov ebx, curr
		mov curr, eax
		mov prev, ebx
		call crlf
	loop fib
main endp
end main
```

## Task 2
```asm
TITLE Source
include irvine32.inc

.data
	inner_counter DWORD 1
.code
main PROC
	mov ecx, 4
	mov eax, '1'
	outer:
		mov ebx, ecx
		mov ecx, inner_counter
		inner:
			call writechar
		loop inner
		mov ecx, ebx
		inc inner_counter
		call crlf
	loop outer
main endp
end main
```
![image](https://github.com/user-attachments/assets/386d504c-da3c-46bf-808d-7ef229fc34ce)

```asm
TITLE Source
include irvine32.inc

.data
	inner_counter DWORD 1
.code
main PROC
	mov ecx, 4
	mov inner_counter, ecx
	mov eax, '1'
	outer:
		mov ebx, ecx
		inner:
			call writechar
		loop inner
		mov ecx, ebx
		dec inner_counter
		call crlf
	loop outer
main endp
end main
```
![image](https://github.com/user-attachments/assets/7c38f917-8e80-4b4d-9f97-ce1e7b95f630)

```asm
TITLE Source
include irvine32.inc

.data
	inner_counter DWORD 1
	numbers BYTE "1","2","3","4"
.code
main PROC
	mov ecx, 4
	mov inner_counter, ecx
	mov eax, '1'
	outer:
		mov ebx, ecx
		mov edx, lengthof numbers - 1
		inner:
			movzx eax, numbers[edx]
			call writechar
			dec edx
		loop inner
		mov ecx, ebx
		dec inner_counter
		call crlf
	loop outer
main endp
end main
```
![image](https://github.com/user-attachments/assets/de12dd6e-81ca-4e1b-8703-8265522e0476)

```asm
TITLE Source
include irvine32.inc

.data
	inner_counter DWORD 1
	numbers BYTE "1","2","3","4"
.code
main PROC
	mov ecx, 4
	mov inner_counter, ecx
	mov eax, '1'
	outer:
		mov ebx, ecx
		mov edx, 0
		inner:
			movzx eax, numbers[edx]
			call writechar
			inc edx
		loop inner
		mov ecx, ebx
		dec inner_counter
		call crlf
	loop outer
main endp
end main
```
![image](https://github.com/user-attachments/assets/bf80ff16-e45b-4327-8044-ce7636387178)

## Task 3
```asm

```
