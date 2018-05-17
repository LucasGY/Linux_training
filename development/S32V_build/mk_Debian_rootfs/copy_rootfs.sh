#copy the new rootfs to SD card
TARGET_ROOTFS_DIR="target-rootfs"
sudo cp ./sja1105_install.sh $TARGET_ROOTFS_DIR/root
sudo rm -rf /media/lucas/rootfs/*
sudo cp -rf $TARGET_ROOTFS_DIR/* /media/lucas/rootfs/ && sync
sudo eject /dev/sdb
