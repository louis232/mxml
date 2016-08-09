#
# 编译库文件的Makefile
#

#顶层路径
ROOT = $(firstword $(subst mxml, mxml ,$(PWD)))/mxml

#包含编译规则
include $(ROOT)/Rules.make

#编译最终目标
target = libcommon.a

#依赖的目标文件名
OBJS = error.o


all:$(OBJS)
	$(AR) -crvs $(target) $^
	
%.o:%.c
	$(CC) $(CFLAGS) $< -c -o $@
	
clean:
	rm -f *.o a.out core temp.* $(target)

