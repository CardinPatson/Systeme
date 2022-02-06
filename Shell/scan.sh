#!/bin/bash


#`ping -c1 192.168.1.30 | grep "64 bytes" |cut -f 4 -d " " | tr -d ":" > ip.txt`

#for i in `seq 1 255`;do
#	echo $i
#done

for i in `seq 1 254`;do
	ping -c1 $1.$i | grep "64 bytes" | cut -f 4 -d " " | tr -d ":" >>ip.txt
done

