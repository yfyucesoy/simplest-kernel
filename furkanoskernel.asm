bits 32                                 ;nasm 32 bit komutu
section .text                           ;code section
        ;multiboot spec                 ;GRUB kernelimizi sadece multiboot spec ozelligiyle derlenmisse yukleyecektir.
        align 4
        dd 0x1BADB002              	;magic
        dd 0x00                    	;flags
        dd - (0x1BADB002 + 0x00)   	;checksum. m+f+c should be zero

global start
extern kmain 				;c dosyasinda tanimlanmis fonksiyon

start:
	cli 				;interruptlari blok etmek icin (clear-interrupts)
	mov esp, stack_space		;stack pointer set edilir
	call kmain                      ;k main fonksiyonu cagirilir
	hlt 				;halt the CPU

section .bss
resb 8192				;bss sectiondan stack icin 8 KB alan tahsisi
stack_space:
