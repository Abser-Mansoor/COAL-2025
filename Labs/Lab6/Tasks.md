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
TITLE Equation 1 (Test.asm)
INCLUDE Irvine32.inc

.Data
    id_prompt BYTE "Please Enter Your Employee ID", 0
    name_prompt BYTE  "Please Enter Your Name", 0
    dob_prompt BYTE  "Please Enter Your Date Of Birth", 0
    salary_prompt BYTE  "Please Enter Your Annual Salary", 0
    total_salary_message BYTE "The Total Salary Is: ", 0
    ids DWORD 5 DUP(20 DUP(?))
    names DWORD 5 DUP(?)
    dobs DWORD 5 DUP(?)
    salaries DWORD 5 DUP(?)
    total_salary DWORD ?

.code
main PROC
    mov esi, 0
    input_loop:
        
        ; Reading id
        mov edx, offset id_prompt
        mov eax, [edx]
        call writestring
        call crlf
        call readint
        mov ids[esi*4], eax

        ; Reading name
        mov edx, offset name_prompt
        mov eax, [edx]
        call writestring
        call crlf
        mov edx, offset names
        mov edi, esi
        imul edi, 20
        add edx, edi
        call readstring

        ; Reading dob
        mov edx, offset dob_prompt
        mov eax, [edx]
        call writestring
        call crlf
        call readint
        mov dobs[esi*4], eax

        ; Reading salary
        mov edx, offset salary_prompt
        mov eax, [edx]
        call writestring
        call crlf
        call readint
        mov salaries[esi*4], eax

        inc esi
        cmp esi, 5
        jl input_loop

    mov esi, 1
    mov eax, 0
    mov eax, salaries[0]

    cumulative_salary:
        add eax, salaries[esi*4]
        inc esi
        cmp esi, 5
        jl cumulative_salary
    
    mov total_salary, eax
    mov edx, offset total_salary_message
    mov eax, [edx]
    call writestring
    mov eax, total_salary
    call writeint

    exit
main ENDP

END main
```
![image](https://github.com/user-attachments/assets/e992146a-9acd-4008-a2e4-16a56f6932b4)

## Task 4
```asm
TITLE Equation 1 (Test.asm)
INCLUDE Irvine32.inc

.Data
    source BYTE "Hello World!", 0
    target BYTE lengthof source DUP(?)

.code
main PROC
    
    mov esi, offset source
    mov edi, offset target
    copy_string:
        mov al, [esi]
        mov [edi], al
        inc esi
        inc edi
        cmp al, 0
        je done
        jmp copy_string
    done:
    mov edx, offset target
    call writestring
    exit
main ENDP

END main
```
![image](https://github.com/user-attachments/assets/5598bfc9-4170-4f11-9fbf-b02694d90e10)

## Task 5
```asm
TITLE Source
include irvine32.inc

.data
	array DWORD 1,2,3,4,5,6,7,8,9
.code
main PROC
	mov ecx, lengthof array/2
	mov esi, 0
	mov edi, lengthof array-1
	outer:
		mov eax, array[esi * type array]
		xchg eax, array[edi * type array]
		mov array[esi * type array], eax
		inc esi
		dec edi
	loop outer
	mov esi, 0
	mov ecx, lengthof array
	print:
		mov eax, array[esi * type array]
		call writeint
		inc esi
	loop print
main endp
end main
```
![image](https://github.com/user-attachments/assets/17936019-0da8-46ad-be39-19255da881a4)
