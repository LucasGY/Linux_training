#! /bin/sh
# shell while,case,shift training

usage()
{
# $0 of usage() = $0
# $1 of usage() = $0 of "usage $0 $1"
# $2 of usage() = $1 of "usage $0 $1"
echo "This is help about $0 "
echo "the first parameter transmitted is $1"
echo "the second parameter transmitted is $2" 
exit
} 
# attention ";" before "do" 
while [ $# -gt 0 ]; do
  case $1 in
# --help and -h are all right cases
# usage is a function
    --help | -h) usage $0 $1 ;;
    --a) echo "1:$1 2:$2 3:$3 4:$4";shift; echo "1:$1 2:$2 3:$3 4:$4";shift; ;;
    --b) echo "1:$1 2:$2 3:$3 4:$4";shift; echo "1:$1 2:$2 3:$3 4:$4";shift; ;;
    *) echo "please listen to me"; shift; ;;
  esac
done
