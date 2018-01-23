#!/bin/sh
# This installs some basic required setup for building visionsdk
# This is one time setup only.
# This is built on ti baseline and user can add more things depending on user linux OS baseline
echo "-----------------------install VSDK---------------------------------------------"
cd /home/gy/Downloads
chmod +x PROCESSOR_SDK_VISION_03_02_00_00_setuplinux.bin
echo " ###########Please attention the install path###########"
./PROCESSOR_SDK_VISION_03_02_00_00_setuplinux.bin
cd /home/gy/PROCESSOR_SDK_VISION_03_02_00_00
export INSTALL_DIR=/home/gy/PROCESSOR_SDK_VISION_03_02_00_00
echo "-----------------------A15 Compiler, Linker-------------------------------------"
cp /home/gy/Downloads/gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf.tar.xz $INSTALL_DIR/ti_components/os_tools/linux/linaro
echo " ###########Please wait###########"
echo " ###########Please wait###########"
echo " ###########Please wait###########"
echo " ###########Please wait###########"
cd $INSTALL_DIR/ti_components/os_tools/linux/linaro
tar -xvf gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf.tar.xz
sudo apt-get install lib32stdc++6 lib32z1-dev lib32z1 lib32ncurses5 lib32bz2-1.0 
sudo apt-get install ia32-libs 
cd $INSTALL_DIR/vision_sdk/build/hlos/scripts/linux
./setup-linux-build-env.sh
sudo apt-get install  dos2unix dtrx mono-complete git
sudo apt-get install uname sed mkimage
echo "-----------------------Edit .gitconfig---------------------------------------------"
vi  /home/gy/.gitconfig
echo "-----------------------Create git-proxy.sh---------------------------------------------"
cp /home/gy/Downloads/git-proxy.sh /home/gy
echo " ###########ture response###########"
echo " ###########core.gitproxy=none for ti.com###########"
echo " ###########core.gitproxy=/home/gy/git–proxy.sh###########"
git config --list
su 












#read -p "Press Enter to continue" REPLY

#echo
#$cmd

