KVERS = $(shell uname -r)
KERNEL_DIR = /home/gy/kernel
COMPILE_DIR = /home/gy/PROCESSOR_SDK_VISION_03_02_00_00/ti_components/os_tools/linux/linaro/gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf/bin/
# Kernel modules
obj-m += gy.o

# Specify flags for the module compilation.
#EXTRA_CFLAGS=-g -O0



modules:
	make -C $(KERNEL_DIR) M=$(CURDIR) ARCH=arm CROSS_COMPILE=$(COMPILE_DIR)arm-linux-gnueabihf- modules

clean:
	make -C $(KERNEL_DIR) M=$(CURDIR) ARCH=arm CROSS_COMPILE=$(COMPILE_DIR)arm-linux-gnueabihf- clean
