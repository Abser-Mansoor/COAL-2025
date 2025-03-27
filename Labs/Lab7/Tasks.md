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
```asm
TITLE Task3
INCLUDE irvine32.inc

.data
    arr1 DWORD 1,2,3,4,5
    arr2 DWORD 6,7,8,9,10
    sum1 DWORD ?
    sum2 DWORD ?
    final_sum DWORD ?  ; Added to store the final result

.code

sum_arr1 PROC
    mov ecx, lengthof arr1 
    mov esi, 0              
    mov ebx, 0             

sum_array1:
    mov eax, arr1[esi * TYPE arr1] 
    add ebx, eax             
    inc esi                     
    loop sum_array1            

    mov sum1, ebx   ; Store sum1
    ret
sum_arr1 ENDP

sum_arr2 PROC
    mov ecx, lengthof arr2  
    mov esi, 0              
    mov ebx, 0              

sum_array2:
    mov eax, arr2[esi * TYPE arr2] 
    add ebx, eax                  
    inc esi                        
    loop sum_array2                

    mov sum2, ebx   ; Store sum2
    ret
sum_arr2 ENDP

sum_results PROC
    mov eax, sum1
    add eax, sum2
    mov final_sum, eax 
    ret
sum_results ENDP

main PROC
    call sum_arr1
    call sum_arr2
    call sum_results
    mov eax, final_sum
    call writeint                
    exit
main ENDP
END main
```
![image](https://github.com/user-attachments/assets/746afa79-f005-4c13-9481-d02037c041a0)

## Task 4
```asm
TITLE Task4
INCLUDE irvine32.inc

.data
	
	levels DWORD 5
	gap DWORD ' '
.code
main PROC
	mov ecx, 0 ; starting at lvl 0
	print_pattern:
		mov ebx, ecx
		print_gaps:
			mov eax, gap
			call writechar
			inc ebx
			cmp ebx, levels
			jl print_gaps
		mov ebx, ecx
		inc ebx
		print_stars:
			mov eax, '*'
			call writechar
			dec ebx
			cmp ebx, 0
			jg print_stars
		call crlf
		inc ecx 
		cmp ecx, levels
		jl print_pattern
	done:
		exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/8e00f8dd-d321-4fbc-b611-31f0e61a78db)
