#!/bin/bash

i=1
j=1
MAX=1000

while [ $i -le $MAX ]
do
    k=`expr $i + $j`
    echo -n "$i $j $k "
    i=`expr $k + $j`
    j=`expr $i + $k`
done
echo ""
