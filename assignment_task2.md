```asm
TITLE Recursive Array Search (Search.asm)
INCLUDE Irvine32.inc

.data
array DWORD 1,2,3,4,5,6,7,8,9
input_message BYTE "Enter a number to search: ", 0
found_message BYTE "The value was found.",0
fail_message BYTE "Value could not be found.",0

.code
; Forward declaration for INVOKE
recursiveSearch PROTO,
    curr_idx:DWORD,
    arr_size:DWORD,
    target:DWORD

main PROC
    mov edx, OFFSET input_message
    call WriteString
    call ReadInt
    
    INVOKE recursiveSearch, 0, LENGTHOF array, eax
    
    cmp eax, 1
    jne not_found
    mov edx, OFFSET found_message
    jmp display
    
not_found:
    mov edx, OFFSET fail_message
    
display:
    call WriteString
    call Crlf
    exit
main ENDP

;---------------------------------------------------------
recursiveSearch PROC USES ebx,
    curr_idx:DWORD,
    arr_size:DWORD,
    target:DWORD
    
    mov ebx, curr_idx
    cmp ebx, arr_size
    jge not_found
    
    mov ecx, array[ebx*4]
    cmp ecx, target
    je found
    
    inc ebx
    INVOKE recursiveSearch, ebx, arr_size, target
    ret
    
found:
    mov eax, 1
    ret
    
not_found:
    mov eax, 0
    ret
recursiveSearch ENDP

END main
```
