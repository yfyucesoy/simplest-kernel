# simplest-kernel
simplest kernel which can be loaded with the GRUB bootloader on an x86 system
*to build*
```
nasm -f elf32 furkanoskernel.asm -o furkanosasm.o
gcc -m32 -c furkanoskernel.c -o furkanosc.o
ld -m elf_i386 -T furkanoslink.ld -o furkanoskernel furkanosasm.o furkanosc.o
``

