# Copyright 2017 NXP

cp -vf /home/lucas/Desktop/share/sja1105x/drivers/modules/sja1105.ko /home/lucas/Desktop/Debian_rootfs/target-rootfs
mkdir /home/lucas/Desktop/Debian_rootfs/target-rootfs/lib/firmware
sudo chmod 0777 /home/lucas/Desktop/Debian_rootfs/target-rootfs/lib/firmware
cp -vf /home/lucas/Desktop/share/sja1105x/tools/firmware_generation/sja1105_cfg_mra2lt* /home/lucas/Desktop/Debian_rootfs/target-rootfs/lib/firmware
cp -vfr /home/lucas/Desktop/Debian_rootfs/target-rootfs/lib/firmware /media/lucas/rootfs/lib/
