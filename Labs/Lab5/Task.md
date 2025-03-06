## Task 1
```asm
TITLE task
include irvine32.inc

.data
	arr BYTE 61,43,11,52,25
	newarr BYTE LENGTHOF arr DUP(?)

.code
main PROC
    mov esi, OFFSET arr

    mov al, [esi] 
    mov newarr[0], al
    inc esi

    mov al, [esi] 
    mov newarr[1], al
    inc esi

    mov al, [esi]  
    mov newarr[2], al
    inc esi

    mov al, [esi]  
    mov newarr[3], al
    inc esi

    mov al, [esi] 
    mov newarr[4], al

    mov esi, 0
    mov ecx, LENGTHOF newarr

printarr:
    movzx eax, newarr[esi*TYPE newarr]
    call WriteInt
    call Crlf ; for leaving lines for clean output
    inc esi
    loop printarr
; The above code is already generalised to account for separate data types therefore the only change needed for 
; WORD or DWORD operation is changing al to ax and eax respectively
    exit
main endp
end main
```
## Task 2
```asm
TITLE task
include irvine32.inc

.data
	arrayB BYTE 10, 20, 30 
    arrayW WORD 150, 250, 350 
    arrayD DWORD 600, 1200, 1800
    SUM1 DWORD ?
    SUM2 DWORD ?
    SUM3 DWORD ?

.code
main PROC
    mov esi, 0

    movzx ebx, arrayB[esi*TYPE arrayB]
    mov SUM1, ebx
    movzx ebx, arrayW[esi*TYPE arrayW]
    add SUM1, ebx
    mov ebx, arrayD[esi*TYPE arrayD]
    add SUM1, ebx
    inc esi

    movzx ebx, arrayB[esi*TYPE arrayB]
    mov SUM2, ebx
    movzx ebx, arrayW[esi*TYPE arrayW]
    add SUM2, ebx
    mov ebx, arrayD[esi*TYPE arrayD]
    add SUM2, ebx
    inc esi
    
    movzx ebx, arrayB[esi*TYPE arrayB]
    mov SUM3, ebx
    movzx ebx, arrayW[esi*TYPE arrayW]
    add SUM3, ebx
    mov ebx, arrayD[esi*TYPE arrayD]
    add SUM3, ebx
    inc esi

    mov eax, SUM1
    call writeint
    call crlf
    mov eax, SUM2
    call writeint
    call crlf
    mov eax, SUM3
    call writeint
    call crlf

    exit
main endp
end main
```
## Task 3
```asm

```
