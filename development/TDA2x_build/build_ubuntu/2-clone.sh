#!/bin/sh
# This installs some basic required setup for building visionsdk
# This is one time setup only.
# This is built on ti baseline and user can add more things depending on user linux OS baseline

echo "-----------------------Clone linux---------------------------------------------"
export INSTALL_DIR=/home/gy/PROCESSOR_SDK_VISION_03_02_00_00
cd $INSTALL_DIR/vision_sdk/build
./hlos/scripts/linux/setup_linux.sh
#cp /home/gy/Downloads/codec_engine_3_24_00_08.tar.gz $INSTALL_DIR/ti_components/codecs
#cd $INSTALL_DIR/ti_components/codecs
#tar -xvzf codec_engine_3_24_00_08.tar.gz


echo "-----------------------Download and untar file system---------------------------------------------"
cp /home/gy/Downloads/tisdk-rootfs-image-dra7xx-evm.tar.xz $INSTALL_DIR/ti_components/os_tools/linux/targetfs
cd $INSTALL_DIR/ti_components/os_tools/linux/targetfs
#####################  Note : useless  ############################
chmod 777 ../targetfs
tar xf tisdk-rootfs-image-dra7xx-evm.tar.xz
exit
#cp $INSTALL_DIR/ti_components/os_tools/linux/kernel/linux-kernel-addon/fs-patches/opencl_fs_patches.tar.gz $INSTALL_DIR/ti_components/os_tools/linux/targetfs
#cd $INSTALL_DIR/ti_components/os_tools/linux/targetfs
#tar -xvzf opencl_fs_patches.tar.gz
#cd $INSTALL_DIR
#chmod -R 777 $INSTALL_DIR











#read -p "Press Enter to continue" REPLY

#echo
#$cmd

