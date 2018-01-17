#! /bin/sh
#attention the different between character string and number
user1=`id -u`
[ "$user1" = "0" ] && echo "++ userid1 = $user1 ++" 
user2=`id -u`
[ $user2 -eq 0 ] && echo "++ userid2 = $user2 ++" && exit
