export ARCH=arm64
export CROSS_COMPILE=/home/lucas/Desktop/build/gcc-linaro-4.9-2015.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
make s32v234_defconfig
make  -j4
