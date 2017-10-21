#!/bin/bash

echo -n "1st Number : "
read num1
echo -n "2nd Number : "
read num2
echo -n "3rd Number : "
read num3

echo "Num1. $num1, Num2. $num2, Num3. $num3"

if [ $num1 -gt $num2 -a $num1 -gt $num3 ];
then
    echo "Max Number : $num1"
    if [ $num2 -gt $num3 ];
    then
        echo "Min Number : $num3"
    else
        echo "Min Number : $num2"
    fi
elif [ $num2 -gt $num1 -a $num2 -gt $num3 ];
then
    echo "Max Number : $num2"
    if [ $num1 -gt $num3 ];
    then
        echo "Min Number : $num3"
    else
        echo "Min Number : $num1"
    fi

elif [ $num3 -gt $num1 -a $num3 -gt $num2 ];
then
    echo "Max Number : $num3"
    if [ $num1 -gt $num2 ];
    then
        echo "Min Number : $num2"
    else
        echo "Min Number : $num1"
    fi
fi
