[BITS 32]
[ORG 0x100000]

; Multiboot header
ALIGN 4
mb_header:
    dd 0x1BADB002                ; Magic number
    dd 0x00                      ; Flags
    dd - (0x1BADB002 + 0x00)     ; Checksum

; Set up protected mode
mov eax, cr0
or eax, 0x1
mov cr0, eax

; Call the kernel entry point
extern kernel_main
call kernel_main

; Hang
cli
hlt

times 510 - ($-$$) db 0
dw 0xAA55
