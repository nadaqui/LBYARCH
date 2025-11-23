; extern void acc(int y, float *arr, int *res);
; Arguments: RCX = y, RDX = arr, R8 = res

section .data
const dd 0.27777777777 ; 1000M/H / 3600s

section .text
default rel
bits 64

global asmacc
asmacc:
    xor rbx, rbx            ; rbx = 0
    
.loop:
    cmp ebx, ecx            ; if (i >= count) break
    jge .done

    lea r9, [rbx + rbx*2]   ; r9 = rbx * 3
    shl r9, 2               ; r9 = rbx * 12

    ; load Vi, Vf, t
    movss xmm0, [rdx + r9 + 0]   ; Vi
    movss xmm1, [rdx + r9 + 4]   ; Vf
    movss xmm2, [rdx + r9 + 8]   ; t

    ; compute formula    
    subss xmm1, xmm0        ; Vf - Vi
    mulss xmm1, [const]     ; convert km/h to m/s
    divss xmm1, xmm2        ; (Vf - Vi) / t
    
    ; convert float to int
    cvtss2si eax, xmm1         

    ; store result
    mov [r8 + rbx*4], eax   ; int is 4 bytes

    inc rbx
    jmp .loop
    
.done:
    ret