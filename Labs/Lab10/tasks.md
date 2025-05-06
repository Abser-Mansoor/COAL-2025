## Task 1
```asm
section .text
global _start

_start:
    ; Push three numbers onto the stack
    push dword 5
    push dword 7
    push dword 3
    
    call ThreeProd
    
    ; Exit program
    mov eax, 1
    mov ebx, 0
    int 0x80

ThreeProd:
    ; Prologue
    push ebp
    mov ebp, esp
    
    ; Get parameters from stack
    mov eax, [ebp+8]   ; First parameter (3)
    mov ebx, [ebp+12]  ; Second parameter (7)
    imul eax, ebx      ; Multiply first two
    mov ebx, [ebp+16]  ; Third parameter (5)
    imul eax, ebx      ; Multiply result with third
    
    ; Display the result (simple version - just store in eax for demonstration)
    ; In a real program, you'd convert to string and print
    
    ; Epilogue
    mov esp, ebp
    pop ebp
    ret 12             ; Clean up stack (3 params * 4 bytes each)
```

## Task 2
```asm
section .data
    array dd 12, 45, 3, 78, 23, 56, 89, 34, 67, 90, 1, 45, 78, 23, 56, 89, 34, 67, 90, 100
    array_size equ 20

section .text
global _start

_start:
    ; Pass array by reference
    push array
    call MinMaxArray
    
    ; Exit program
    mov eax, 1
    mov ebx, 0
    int 0x80

MinMaxArray:
    ; Prologue
    push ebp
    mov ebp, esp
    push ebx           ; Save registers
    push esi
    
    ; Get array address
    mov esi, [ebp+8]   ; Array address
    
    ; Initialize min and max with first element
    mov eax, [esi]     ; min
    mov ebx, [esi]     ; max
    
    ; Loop through array
    mov ecx, 1         ; Start from second element
    .loop:
        cmp ecx, array_size
        jge .done
        
        mov edx, [esi + ecx*4]  ; Get current element
        
        ; Check for min
        cmp edx, eax
        jge .not_min
        mov eax, edx
        .not_min:
        
        ; Check for max
        cmp edx, ebx
        jle .not_max
        mov ebx, edx
        .not_max:
        
        inc ecx
        jmp .loop
    
    .done:
    ; eax contains min, ebx contains max
    ; In a real program, you'd display these values
    
    ; Epilogue
    pop esi
    pop ebx
    mov esp, ebp
    pop ebp
    ret 4              ; Clean up stack (1 param)
```

## Task 3
```asm
section .data
    prompt db "Enter a number: ", 0
    fmt db "%d", 0
    result_msg db "The square is: %d", 10, 0

section .text
global main
extern scanf, printf

main:
    call LocalSquare
    ret

LocalSquare:
    ; Prologue with space for local variable
    enter 4, 0        ; Allocate 4 bytes for local variable
    
    ; Prompt user
    push prompt
    call printf
    add esp, 4
    
    ; Read input into local variable
    lea eax, [ebp-4]  ; Address of local variable
    push eax
    push fmt
    call scanf
    add esp, 8
    
    ; Calculate square
    mov eax, [ebp-4]
    imul eax, eax
    
    ; Display result
    push eax
    push result_msg
    call printf
    add esp, 8
    
    ; Epilogue
    leave
    ret
```

## Task 4
```asm
section .data
    prompt db "Enter a number: ", 0
    fmt db "%d", 0
    prime_msg db "%d is prime", 10, 0
    not_prime_msg db "%d is not prime", 10, 0
    largest_msg db "The largest prime is: %d", 10, 0
    numbers times 4 dd 0

section .text
global main
extern scanf, printf

main:
    ; Read 4 numbers from user
    mov ecx, 4
    mov edi, numbers
    .read_loop:
        push ecx
        push edi
        
        ; Prompt
        push prompt
        call printf
        add esp, 4
        
        ; Read number
        push edi
        push fmt
        call scanf
        add esp, 8
        
        pop edi
        pop ecx
        add edi, 4
        loop .read_loop
    
    ; Check if all numbers are prime
    mov ecx, 4
    mov esi, numbers
    mov ebx, 1         ; Flag for all primes (1 = true)
    .check_all_primes:
        push ecx
        push ebx
        push esi
        
        push dword [esi]
        call CheckPrime
        add esp, 4
        
        pop esi
        pop ebx
        pop ecx
        
        ; If any number is not prime, set flag to 0
        cmp eax, 0
        jne .is_prime
        mov ebx, 0
        .is_prime:
        
        add esi, 4
        loop .check_all_primes
    
    ; If all primes, find largest
    cmp ebx, 1
    jne .exit
    
    push numbers
    call LargestPrime
    add esp, 4
    
    .exit:
    ret

CheckPrime:
    ; Prologue
    push ebp
    mov ebp, esp
    push ebx
    
    mov eax, [ebp+8]   ; Get the number
    cmp eax, 1
    jle .not_prime     ; Numbers <= 1 are not prime
    
    mov ebx, 2         ; Start divisor at 2
    .test_loop:
        mov edx, 0
        div ebx        ; Divide number by divisor
        
        cmp edx, 0     ; Check remainder
        je .not_prime
        
        ; Next divisor
        inc ebx
        mov eax, [ebp+8]
        cmp ebx, eax   ; Only need to test up to sqrt(n), but this is simpler
        jl .test_loop
    
    ; If we get here, it's prime
    mov eax, 1
    jmp .done
    
    .not_prime:
    mov eax, 0
    
    .done:
    ; Display result
    push eax
    push dword [ebp+8]
    cmp eax, 1
    jne .show_not_prime
    push prime_msg
    jmp .show_msg
    .show_not_prime:
    push not_prime_msg
    .show_msg:
    call printf
    add esp, 12
    
    pop ebx
    mov esp, ebp
    pop ebp
    ret

LargestPrime:
    ; Prologue
    push ebp
    mov ebp, esp
    
    mov esi, [ebp+8]   ; Array address
    mov eax, [esi]     ; Initialize with first number
    
    ; Compare with remaining numbers
    mov ecx, 1
    .find_largest:
        cmp ecx, 4
        jge .done
        
        mov ebx, [esi + ecx*4]
        cmp ebx, eax
        jle .not_larger
        mov eax, ebx
        .not_larger:
        
        inc ecx
        jmp .find_largest
    
    .done:
    ; Display largest
    push eax
    push largest_msg
    call printf
    add esp, 8
    
    mov esp, ebp
    pop ebp
    ret
```

## Task 5
```asm
section .data
    array dd 12, 45, 3, 78, 23, 56, 89, 34, 67, 90
    array_size equ 10

section .text
global _start

_start:
    ; Pass array and size
    push array_size
    push array
    call BubbleSort
    
    ; Exit program
    mov eax, 1
    mov ebx, 0
    int 0x80

BubbleSort:
    ; Prologue
    push ebp
    mov ebp, esp
    push ebx
    push esi
    push edi
    
    ; Get parameters
    mov esi, [ebp+8]   ; Array address
    mov ecx, [ebp+12]  ; Array size
    
    dec ecx            ; Outer loop counter (n-1)
    .outer_loop:
        mov edx, ecx   ; Inner loop counter
        mov edi, esi   ; Pointer to current element
        
        .inner_loop:
            mov eax, [edi]      ; Current element
            mov ebx, [edi+4]   ; Next element
            
            cmp eax, ebx
            jle .no_swap
            
            ; Swap elements
            mov [edi], ebx
            mov [edi+4], eax
            
            .no_swap:
            add edi, 4
            dec edx
            jnz .inner_loop
        
        loop .outer_loop
    
    ; Epilogue
    pop edi
    pop esi
    pop ebx
    mov esp, ebp
    pop ebp
    ret 8              ; Clean up stack (2 params * 4 bytes each)
```
