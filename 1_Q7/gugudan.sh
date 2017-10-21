#!/bin/sh

i=1
j=1

while [ $i -le 9 ]
do
    echo "Current gugudan number : $i"
    while [ $j -le 9 ]
    do
        gop=`expr $i \* $j`
        echo "$i X $j = $gop"
        j=$((j+1))
    done
    j=1
    i=$((i+1))
done
