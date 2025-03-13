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
