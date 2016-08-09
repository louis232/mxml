#######################################################
#本文件用于指定编译规则，在每个Makefile中都会包含该文件
#######################################################

#指定编译器
CC=gcc

#指定归档程序，用于制作静态库
AR=ar

#指定头文件路径
INCDIR=$(ROOT)/include

#指定库文件路径
LDDIR=$(ROOT)/lib

#指定库名
LIB=common

#指定编译选项
CFLAGS=-Wall -I$(INCDIR)

#指定链接选项
LDFLAGS=-L$(LDDIR) -l$(LIB)

#编译生成的中间文件，用于make clean操作
TEMPFILES=core core.* *.o temp.* *.out