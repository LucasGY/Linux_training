#! /bin/sh
#shell "for" training
for i in `ls -1 /dev/sda?`; do
 echo "device1 is '$i'"
done
for x in `ls /dev/sda?`; do
 echo "device2 is  '$x'"
done
for y in ls -1 /dev/sda?; do
 echo "device3 is  '$y'"
done
