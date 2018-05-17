#! /bin/sh

# Script to create SD card for S32V234vb.
# Author: Lucas Gou
# Licensed under terms of GPLv2
# 格式化SD卡 
VERSION="0.1"

FORMAT()
{

echo "FORMAT"	

for i in `ls -1 $device?`; do

 echo "unmounting device '$i'"

 umount $i 2>/dev/null

done


sudo dd if=/dev/zero of=$device bs=1024 count=1024




sync



cat << END | fdisk $device
n
p
1

+255M
n
p
2


t
1
c
t
2
83
w
END

sync

# handle various device names.

PARTITION1=${device}1

PARTITION2=${device}2

echo "PARTITION1 = $PARTITION1, PARTITION2 = $PARTITION2"

# make partitions.

echo "Formating ${device}1 ..."

if [ -b ${PARTITION1} ]; then

    mkfs.vfat -n "boot" ${PARTITION1}

else

    echo "Cant find boot partition in /dev"

fi



if [ -b ${PARITION2} ]; then

    mkfs.ext3 -L "rootfs" ${PARTITION2}

else

    echo "Cant find rootfs partition in /dev"

fi

}

version ()

{

  echo

  echo "`basename $1` version $VERSION"

  echo "Script to create bootable SD card for dra7xx-evm"

  echo



  exit 0

}

COPY()

{

echo "just copy the boot files" 

echo "Copying filesystem on ${device}1,${device}2"

mkdir -p /tmp/sdk/$$/boot

mkdir -p /tmp/sdk/$$/rootfs

mount ${device}1 /tmp/sdk/$$/boot

mount ${device}2 /tmp/sdk/$$/rootfs

echo " dd u-boot.s32"
sudo dd if=/home/lucas/Desktop/share/u-boot/u-boot.s32 of=${device} bs=512 seek=8 conv=fsync && sync

echo " Copy Image,s32v234-evb.dtb"
cp /home/lucas/Desktop/share/linux/arch/arm64/boot/Image /tmp/sdk/$$/boot/
cp /home/lucas/Desktop/share/linux/arch/arm64/boot/dts/freescale/s32v234-evb.dtb /tmp/sdk/$$/boot/

echo "Extracting filesystem on ${device}2 ..."
#root_fs=`ls -1 /home/lucas/Downloads/yocto_auto_linux_bsp15.0/build_s32v234evb_release/tmp/deploy/images/s32v234evb/fsl-image-s32v2xx-s32v234evb-20180308110235.rootfs.tar.gz `
#tar xf $root_fs -C /tmp/sdk/$$/rootfs

#copy the new rootfs to SD card
TARGET_ROOTFS_DIR="target-rootfs"
sudo cp /home/lucas/Desktop/Debian_rootfs/sja1105_install.sh /home/lucas/Desktop/Debian_rootfs/$TARGET_ROOTFS_DIR/root
#sudo rm -rf /tmp/sdk/$$/rootfs*
sudo cp -rf /home/lucas/Desktop/Debian_rootfs/$TARGET_ROOTFS_DIR/* /tmp/sdk/$$/rootfs && sync



sync

echo "unmounting ${device}1,${device}2"

umount /tmp/sdk/$$/boot

umount /tmp/sdk/$$/rootfs



rm -rf /tmp/sdk/$$

echo "completed!"
sudo eject /dev/sdb

}

usage ()

{

  echo "

Usage: `basename $1` <options> [ files for install partition ]



Mandatory options:

  --device              SD block device node (e.g /dev/sdd)



Optional options:

  --version             Print version.

  --help                Print this help message.

"

  exit 1

}



check_if_main_drive ()

{

  mount | grep " on / type " > /dev/null

  if [ "$?" != "0" ]

  then

    echo "-- WARNING: not able to determine current filesystem device"

  else

    main_dev=`mount | grep " on / type " | awk '{print $1}'`

    echo "-- Main device is: $main_dev"

    echo $main_dev | grep "$device" > /dev/null

    [ "$?" = "0" ] && echo "++ ERROR: $device seems to be current main drive ++" && exit 1

  fi



}



user=`id -u`

[ "$user" != "0" ] && echo "++ Must be root/sudo ++" && exit   



#-gt是great then的意思

while [ $# -gt 0 ]; do                 

  case $1 in

    --help | -h) usage $0 ;;

    --device) shift; device=$1; echo "going to do something in $device";  ;;

    --version) version $0;;

    *) copy="$copy $1"; shift; ;;

  esac

done 



test -z $device && usage $0



if [ ! -b $device ]; then                        

   echo "ERROR: $device is not a block device file"

   exit 1;

fi

echo " Do you want to FORMAT your SD card FIRST ? [y/n]"

read input 

 case $input in 

     y | Y) FORMAT;COPY; ;;

     n | N) COPY; ;;

 esac



exit
