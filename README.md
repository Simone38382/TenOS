# TenOS
OS in c :)

compile with
```
nasm -f elf32 boot.asm -o boot.o
gcc -m32 -c kernel.c -o kernel.o -ffreestanding -nostdlib -lgcc
ld -m elf_i386 -Ttext 0x100000 -o kernel.bin --oformat binary boot.o kernel.o
```
and
```
mkdir -p iso/boot/grub
cp kernel.bin iso/boot/
cp grub.cfg iso/boot/grub/
grub-mkrescue -o TenOS.iso iso
```
and then you can run on qemu,virtualbox,bochs,etc.
```
qemu-system-x86_64 -cdrom TenOS.iso
```
