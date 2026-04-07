#!/bin/bash

# $()       - run command and store result
# grep      - filter text
# -v        - exclude lines
# awk       - process text
# df        - shows disk usage (disk filesystem)
# -m        -  display values in megabytes (MB)
# END       - run at end


#ARCH
#The architecture of your operating system and its kernel version
#
# uname -a to get CPU architecture
# prints all information, except if the CPU is unknown or the platform hardware.
#
arch=$(uname -a)


#CPU PHYSICAL
#The number of phisical processors
#
# file /proc/cpuinfo, gives  information about the CPU: its type, brand, model, performance, etc.
# grep command looking inside the file for phisical id 
# wc -l count the lines of the grep output
#
cpuf=$(grep "phisical id" /proc/cpuinfo | wc -l) 


#CPU VIRTUAL
#The number of virtual processors
#
# grep processor /proc/cpuinfo | wc -l to get number of virtual cores
# grep command looking inside the file for processor
# wc -l count the lines of the grep output
#
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)


#RAM
#The current available RAM on your server and its utilization rate as a percentage
#
# the free command provides real-time information about RAM usage, free space, and resources reserved for other purposes
# free --mega to display memory metrics in megabytes
# awk to process the output text files
# $1 - first column, {print $3} -  execute action if condition is true, $2 - second column total memory, $3 - third column used memory
#
# free --mega | awk $1 == Mem: {print $3} to get number mb of used memoir
# free --mega | awk $1 == Mem: {print $2} to get number of total mb memoire
# free --mega | awk $1 == Mem: {printf((%.2f), $3/$2*100)} to get pourcent of used memory
#
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_used=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')


#DISK
#The currently available storage on your server and its utilization rate as a percent-age.
#
# df - shows disk usage (disk filesystem), -m -  display values in megabytes (MB)
# grep /dev/ - filters lines containing /dev/ and selects real disk partitions
# -v - exclude lines, removes /boot partition from results (Often /boot is small and not included in total disk calculation)
# END - runs after all lines are processed
#
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf("%.1f"),  disk_t/1024}')
disk_used=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}') 
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t += $2} END {printf("%d"), disk_u/disk_t*100}') 


#CPU LOAD
#The current CPU utilization rate as a percentage.
#
# vmstat - system statistics (memory usage, CPU activity, system status, etc)
# 1 - refresh every 1 second, 4 - run 4 times
# tail -1  - allow to produce the output only on the last line
# $15 - 15th column from vmstat
# vmstat 1 4 | tail -1 | awk {print $15} -  displays the available memory usage
# expr - perform mathematical calculations
# Subtract the value obtained from 100 to determine the CPU usage percentage
#
cpul=$(vmstat 1 4 | tail -1 | awk '{printf $15}')
cpu_usage=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f", $cpu_op)


#LAST BOOT
#The date and time of the last reboot.
#
# who - shows logged-in users and system info
# -b  - shows last boot time
# $3  - date, $4 -  time, " " -  space between them
#
lboot=$(who -b | awk '$1 == "system" {print $3 " " $4}')


#LVM USE
#Whether LVM is active or not.
#
# lsblk - lists all block devices (disks, partitions, LVM, etc.)
# grep lvm - Filters only lines containing lvm
# -gt  “greater than”
# echo - print text or variables to the terminal
#
lvm_use=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)


#TCP CONNEXIONS
#The number of active connections.
#
# ss - “socket statistics,” shows network connections
# -t - show TCP connections only
# -a - show all sockets (listening + established)
# grep ESTAB - filter lines containing ESTAB (established connections)
#
tcp_conn=$(ss -ta | grep ESTAB | wc -l)


#USER LOG
#The number of users using the server.
# wc -w - counts the number of words
#
user_log=$(users | wc -w)


#NETWORK
#The IPv4 address of your server and its MAC (Media Access Control) address.
#
# hostname - command to show system host information
# -I -  option to display all IP addresses of the host (except the loopback 127.0.0.1)
# ip link - shows network interfaces and their details
# grep link/ether - filters lines containing MAC addresses
# $2 - the MAC address
#
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')


#SUDO
#The number of commands executed with the sudo program.
#
# journalctl - shows logs from systemd journal
# _COMM=sudo - filter only logs from the sudo command
#
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)


wall "  Architecture: $arch
        Physical CPU: $cpuf
        vCPU: $cpuv
        Memory Usage: $ram_used/${ram_total}MB ($ram_percent%)
        Disk Usage: $disk_used/${disk_total}GB ($disk_percent%)
        CPU load: $cpu_fin
        Last boot: $lboot
        LVM use: $lvm_use
        TCP Connection: $tcp_conn ESTABLISHED
        User log: $user_log
        Network: IP $ip ($mac)
        Sudo: $cmnd cmd "

