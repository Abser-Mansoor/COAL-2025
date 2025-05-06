## Task 1
```asm
; EAX * 21 where 21 = 16 + 4 + 1 = 2^4 + 2^2 + 2^0
mov ebx, eax    ; EBX = original value
shl eax, 4      ; EAX = value * 16 (2^4)
shl ebx, 2      ; EBX = value * 4 (2^2)
add eax, ebx    ; EAX = (value*16) + (value*4)
add eax, [original_value]  ; Add original value (value*1)
```

## Task 2
```asm
mov ax, -128     ; AX = -128 (0xFF80)

; Sign extend AX to EAX using shifts
movsx eax, ax    ; Most efficient way, but if we must use shifts:
; Alternative with shifts:
movzx eax, ax    ; First zero extend
test ax, ax      ; Check sign bit
jns positive
or eax, 0xFFFF0000  ; If negative, set upper 16 bits
positive:
```

## Task 3
```asm
mov cx, ax       ; Copy AX to CX
and cx, 1        ; Isolate lowest bit of AX
shl cx, 15       ; Move to highest bit position
shr bx, 1        ; Make room in BX
or bx, cx        ; Combine with BX
```

## Task 4
```asm
; val1 = (val2 / val3) * (val1 / val2);
; Assuming signed 32-bit integers

mov eax, [val2]   ; Load val2
cdq               ; Sign extend EAX to EDX:EAX
idiv dword [val3] ; EAX = val2 / val3
mov ebx, eax      ; Save result in EBX

mov eax, [val1]   ; Load val1
cdq               ; Sign extend
idiv dword [val2] ; EAX = val1 / val2

imul ebx          ; EAX = EBX * EAX
mov [val1], eax   ; Store result in val1
```

## Task 5
```asm
; Extended_Add procedure
; Input: Two 64-bit numbers in memory (num1 and num2)
; Output: 64-bit sum in EAX:EDX

Extended_Add:
    push ebp
    mov ebp, esp
    
    ; Load lower 32 bits
    mov eax, [ebp+8]    ; Lower part of num1
    mov edx, [ebp+12]   ; Lower part of num2
    add eax, edx        ; Add lower parts
    
    ; Load upper 32 bits with carry
    mov edx, [ebp+16]   ; Upper part of num1
    mov ecx, [ebp+20]   ; Upper part of num2
    adc edx, ecx        ; Add upper parts with carry
    
    ; Result is now in EDX:EAX
    
    pop ebp
    ret 16              ; Clean up stack (4 parameters * 4 bytes each)

; Example usage:
; push dword [num1_hi]
; push dword [num1_lo]
; push dword [num2_hi]
; push dword [num2_lo]
; call Extended_Add
```
