#! /bin/sh
# Script to create SD card for DRA7xx evm.
#
# Author: Lucas Gou
#
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

dd if=/dev/zero of=$device bs=1024 count=1024

sync

cat << END | fdisk $device
n
p
1

+256M
n
p
2


t
1
c
a
1
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
    mkfs.vfat -F 32 -n "boot" ${PARTITION1}
else
    echo "Cant find boot partition in /dev"
fi

if [ -b ${PARITION2} ]; then
    mkfs.ext4 -L "rootfs" ${PARTITION2}
else
    echo "Cant find rootfs partition in /dev"
fi
}

COPY()
{
echo "just copy the boot files" 
echo "Copying filesystem on ${device}1,${device}2"
mkdir -p /tmp/sdk/$$/boot
mkdir -p /tmp/sdk/$$/rootfs
mount ${device}1 /tmp/sdk/$$/boot
mount ${device}2 /tmp/sdk/$$/rootfs

echo " Copy MLO,u-boot.img,dtb"
cp /home/gy/Desktop/beifen/MLO /tmp/sdk/$$/boot/
cp /home/gy/Desktop/beifen/u-boot.img /tmp/sdk/$$/boot/
cp /home/gy/Desktop/beifen/zImage /tmp/sdk/$$/boot/
cp /home/gy/Desktop/beifen/dra7-evm-infoadas.dtb /tmp/sdk/$$/boot/

echo "Extracting filesystem on ${device}2 ..."
root_fs=`ls -1 /home/gy/PROCESSOR_SDK_VISION_03_02_00_00/ti_components/os_tools/linux/targetfs/tisdk-rootfs-image-dra7xx-evm.tar.xz `
tar xf $root_fs -C /tmp/sdk/$$/rootfs

sync
echo "unmounting ${device}1,${device}2"
umount /tmp/sdk/$$/boot
umount /tmp/sdk/$$/rootfs

rm -rf /tmp/sdk/$$
echo "completed!"
}

version ()
{
  echo
  echo "`basename $1` version $VERSION"
  echo "Script to create bootable SD card for dra7xx-evm"
  echo

  exit 0
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
     y | Y) FORMAT; COPY; ;;
     n | N) COPY; ;;
 esac

exit





