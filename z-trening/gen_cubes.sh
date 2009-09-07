#!/bin/bash
echo $1
for((i=0;i<$1;++i)); do
		echo $(($RANDOM*10000000 + $RANDOM)); 
done 