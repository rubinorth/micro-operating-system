#!Makefile
#2018-01-28

#找到当前目录下所有.c结尾的文件
C_SOURCES = $(shell find . -name "*.c")

#给C_OBJECTS赋值，值为C_SOURCES中所有的文件名改为.o文件后 得到的文件名
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

S_SOURCES = $(shell find . -name "*.s")

S_OBJECTS = $(patsubst %.s, %.o, $(S_SOURCES))
