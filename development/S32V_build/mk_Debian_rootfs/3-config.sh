#Directory contains the target rootfs
TARGET_ROOTFS_DIR="target-rootfs"
sudo cp /usr/bin/qemu-aarch64-static $TARGET_ROOTFS_DIR/usr/bin
sudo mount -o bind /dev/ $TARGET_ROOTFS_DIR/dev/
sudo LC_ALL=C LANGUAGE=C LANG=C chroot $TARGET_ROOTFS_DIR dpkg --configure -a

#Board hostname
filename=$TARGET_ROOTFS_DIR/etc/hostname
echo s32v234evb > $filename

#Default name servers
filename=$TARGET_ROOTFS_DIR/etc/resolv.conf
echo nameserver 8.8.8.8 > $filename
echo nameserver 8.8.4.4 >> $filename

#Default name servers
filename=$TARGET_ROOTFS_DIR/etc/resolv.conf
echo nameserver 192.168.2.1 > $filename

#Set the the debug port
filename=$TARGET_ROOTFS_DIR/etc/inittab
echo T0:2345:respawn:/sbin/getty -L ttyLF0 115200 vt100 >> $filename

#Set passwd for the target
sudo chattr -i $TARGET_ROOTFS_DIR/etc/shadow
sudo chattr -i $TARGET_ROOTFS_DIR/etc/passwd
sudo chmod 0777 -R *
sudo chroot $TARGET_ROOTFS_DIR/ passwd
sudo chattr +i $TARGET_ROOTFS_DIR/etc/shadow
sudo chattr +i $TARGET_ROOTFS_DIR/etc/passwd

#rename the securetty
sudo chmod 0777 -R ./$TARGET_ROOTFS_DIR
mv /home/lucas/Desktop/Debian_rootfs/target-rootfs/etc/securetty /home/lucas/Desktop/Debian_rootfs/target-rootfs/etc/securetty1

#umount
sudo umount /home/lucas/Desktop/Debian_rootfs/target-rootfs/dev
