section .data
    format db 'Hello, Holberton', 0
    printf_format db '%s', 0

section .text
    global main
    extern printf

main:
    sub rsp, 8  ; align stack

    ; Call printf
    mov rdi, printf_format
    mov rsi, format
    xor rax, rax
    call printf

    add rsp, 8  ; restore stack

    xor eax, eax
    ret
