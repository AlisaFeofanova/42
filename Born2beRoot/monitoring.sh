#!/bin/bash


#ARCH
#The architecture of your operating system and its kernel version
# uname -a to get CPU architecture
# prints all information, except if the CPU is unknown or the platform hardware.
arch=$(uname -a)


#CPU PHYSICAL
#The number of phisical processors
# file /proc/cpuinfo, gives  information about the CPU: its type, brand, model, performance, etc.
# grep command looking inside the file for phisical id 
# wc -l count the lines of the grep output
cpuf=$(grep "phisical id" /proc/cpuinfo | wc -l) 



#CPU VIRTUAL
#The number of virtual processors
# grep processor /proc/cpuinfo | wc -l to get number of virtual cores
# grep command looking inside the file for processor 
# wc -l count the lines of the grep output
cpuv=$(grep "processor" /porc/cpuinfo | wc -l)



#RAM
#The current available RAM on your server and its utilization rate as a percentage
# the free command provides real-time information about RAM usage, free space, and resources reserved for other purposes
# free --mega to display memory metrics in megabytes
# awk to process the output text files
# $1 first column / {print $3}  execute action if condition is true / $2 second column total memory / $3 third column used memory

# free --mega | awk $1 == Mem: {print $3} to get number mb of used memoir
# free --mega | awk $1 == Mem: {print $2} to get number of total mb memoire
# free --mega | awk $1 == Mem: {printf((%.2f), $3/$2*100)} to get pourcent of used memory
#
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_used=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')


