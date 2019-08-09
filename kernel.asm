;;kernel.asm

;nasm directive - 32 bit
bits 32
section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002            
        dd 0x00                  
        dd - (0x1BADB002 + 0x00)

global start
extern main	        

start:
  cli
  mov esp, stack_space	;set stack pointer
  call main
  hlt

section .bss
resb 8192		;8KB stack
stack_space: