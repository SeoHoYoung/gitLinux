#!/bin/sh
who=`who | wc -l`

if [ $who -ne 0 ]
then
    echo "Current Login User : $who "
else
    echo "Error."
fi
