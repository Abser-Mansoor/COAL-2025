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

    mov al, [esi+2] 
    mov newarr[0], al

    mov al, [esi+4] 
    mov newarr[1], al

    mov al, [esi+1]  
    mov newarr[2], al

    mov al, [esi+3]  
    mov newarr[3], al

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
![image](https://github.com/user-attachments/assets/6d13a632-5f9d-4641-9b3c-768c6949bb75)

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
![image](https://github.com/user-attachments/assets/8d8ddeee-0426-4183-9583-23c115eab68b)

## Task 3
```asm
TITLE task
include irvine32.inc

.data
	array1 BYTE 10, 20, 30, 40
    array2 BYTE 4 DUP (?)

.code
main PROC
    mov esi, OFFSET array1
    add esi, LENGTHOF array1-1
    mov edi, OFFSET array2

    mov al, [esi]
    mov [edi], al
    inc edi
    dec esi

    mov al, [esi]
    mov [edi], al
    inc edi
    dec esi

    mov al, [esi]
    mov [edi], al
    inc edi
    dec esi

    mov al, [esi]
    mov [edi], al
    inc edi
    dec esi

    mov ecx, LENGTHOF array2
    mov esi, 0
    printarr:
        movzx eax, array2[esi]
        inc esi
        call writeint
        call crlf
    loop printarr
    exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/a9f46e41-743d-4525-8b40-80d17765a17e)

## Task 4
```asm
TITLE task
include irvine32.inc

.data
	array DWORD 500, 600, 1000, 5000, 400

.code
main PROC
    mov esi, OFFSET array
    mov eax, [esi]
    
    add esi, 4
    sub eax, [esi]

    add esi, 4
    sub eax, [esi]

    add esi, 4
    sub eax, [esi]

    add esi, 4
    sub eax, [esi]
    call writeint

    exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/ead84162-3707-4c9c-ac77-695f1ff0016b)

## Task 5
```asm
TITLE task
include irvine32.inc

.data
	arrayB BYTE 60, 70, 80
    arrayW WORD 150, 250, 350
    arrayD DWORD 600, 1200, 1800

.code
main PROC
    
    mov esi, 0
    mov al, arrayB[esi * TYPE arrayB]
    add esi, LENGTHOF arrayB-1
    add al, arrayB[esi * TYPE arrayB]
    movzx eax, al
    call writeint
    call crlf

    mov esi, 0
    mov ax, arrayW[esi * TYPE arrayW]
    add esi, LENGTHOF arrayW-1
    add ax, arrayW[esi * TYPE arrayW]
    movzx eax, ax
    call writeint
    call crlf

    mov esi, 0
    mov eax, arrayD[esi * TYPE arrayD]
    add esi, LENGTHOF arrayD-1
    add eax, arrayD[esi * TYPE arrayD]
    call writeint
    call crlf

    exit
main endp
end main
```
![image](https://github.com/user-attachments/assets/85627b0e-f30b-4aaa-976f-5fa0d46aa56b)
