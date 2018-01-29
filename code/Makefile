#!Makefile
#
# --------------------------------------------------------
#
#	2018-01-28
#   内核的 Makefile
#   默认的内核名字是hx_kernel
#   默认使用的C语言编译器是 GCC、汇编语言编译器是 nasm
#
# --------------------------------------------------------


#找到当前目录下所有.c结尾的文件
C_SOURCES = $(shell find . -name "*.c")
#给C_OBJECTS赋值，patsubst 处理所有在 C_SOURCES 字列中的字（一列文件名），如果它的 结尾是 '.c'，就用 '.o' 把 '.c' 取代
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))
S_SOURCES = $(shell find . -name "*.s")
S_OBJECTS = $(patsubst %.s, %.o, $(S_SOURCES))

CC = gcc
LD = ld
ASM = nasm

C_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-builtin -fno-stack-protector -I include
LD_FLAGS = -T scripts/kernel.ld -m elf_i386 -nostdlib
ASM_FLAGS = -f elf -g -F stabs

#make开始执行的地方
#all是一个伪目标，但放在开头，就相当于默认目标，相当于main函数
#all是伪目标，所以不生成文件
all: $(S_OBJECTS) $(C_OBJECTS) link update_image
#这里省略了.PHONY:all

#.c.o相当于%.o:%.c，表明所有.o是目标文件，所有.c是依赖目标
#$@，当前目标的名称，这里应该是%.o
#$<，比当前目标更新的已修改的当前依赖性名称，这里应该是%.c
.c.o:
	@echo 编译代码文件 $< ...
	$(CC) $(C_FLAGS) $< -o $@
	
.s.o:
	@echo 编译汇编文件 $< ...
	$(ASM) $(ASM_FLAGS) $<
	
link:
	@echo 链接内核文件...
	$(LD) $(LD_FLAGS) $(S_OBJECTS) $(C_OBJECTS) -o hx_kernel

#.PHONY:clean表明clean是一个伪目标
#命令行只打make是不运行的，只有打make clean才运行
.PHONY:clean
clean:
	$(RM) $(S_OBJECTS) $(C_OBJECTS) hx_kernel

.PHONY:update_image
update_image:
	sudo mount floppy.img /mnt/kernel
	sudo cp hx_kernel /mnt/kernel/hx_kernel
	sleep 1
	sudo umount /mnt/kernel

.PHONY:mount_image
mount_image:
	sudo mount floppy.img /mnt/kernel

.PHONY:umount_image
umount_image:
	sudo umount /mnt/kernel

.PHONY:qemu
qemu:
	qemu -fda floppy.img -boot a

.PHONY:bochs
bochs:
	bochs -f scripts/bochsrc.txt

.PHONY:debug
debug:
	qemu -S -s -fda floppy.img -boot a &
	sleep 1
	cgdb -x scripts/gdbinit