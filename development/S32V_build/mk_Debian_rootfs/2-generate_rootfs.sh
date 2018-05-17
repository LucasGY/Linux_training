TARGET_ROOTFS_DIR="target-rootfs"
mkdir $TARGET_ROOTFS_DIR
multistrap -a arm64 -d $TARGET_ROOTFS_DIR -f debian.conf

