#本次编译是外部编译，使用的内核源码是Ubuntu的源代码，而非开发板所用linux内核源码，运行平台为X86
KVERS = $(shell uname -r)
 
# Kernel modules
obj-m += hello.o
 
# Specify flags for the module compilation.
EXTRA_CFLAGS=-g -O0
#-Wall 是打开警告开关,-O代表默认优化,可选：-O0不优化,-O1低级优化,-O2中级优化,-O3高级优化,-Os代码空间优化
#-g是生成调试信息,生成的可执行文件具有和源代码关联的可调试的信息,可以以C语言源代码的形式查看变量、单步运行 

build: kernel_modules
  
kernel_modules:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) modules
clean:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) clean

