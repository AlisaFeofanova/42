*This project has been created as part of the 42 curriculum by alfeofan.*

# Born2beroot

## Description

**Born2beroot** is a system administration project from the **42 curriculum**.  
The goal of this project is to introduce students to the fundamentals of **Linux system administration, virtualization, and security**.

In this project, a virtual machine is created and configured from scratch using a Linux distribution. The system must follow strict security rules, including encrypted partitions, strong password policies, user management, firewall configuration, and automated monitoring scripts.

The main objectives of the project are:

- Learn how to create and manage a **virtual machine**
- Understand **Linux system architecture**
- Configure **secure system policies**
- Manage **users, groups, and permissions**
- Implement **disk partitioning with encryption**
- Configure **SSH access**
- Set up a **firewall**
- Automate system monitoring using **shell scripts**

By completing this project, students gain practical experience in **Linux administration and server security**, which are essential skills for system engineers, DevOps engineers, and backend developers.

---

# System Architecture

The system is built using the following components:

| Component | Description |
|--------|-------------|
| Virtual Machine | Created using a virtualization tool |
| Operating System | Debian or Rocky Linux |
| LVM | Logical Volume Management for flexible disk management |
| LUKS | Disk encryption for secure storage |
| SSH | Secure remote access |
| UFW / firewalld | Firewall configuration |
| Bash Script | System monitoring automation |

---

# Virtualization

The project requires creating a **virtual machine (VM)**.

A virtual machine is a software environment that simulates a physical computer. It allows multiple operating systems to run on the same hardware without interfering with each other.

Advantages of virtualization:

- Safe experimentation environment
- Isolation from the host system
- Easy backup and restoration
- Efficient resource usage

Common virtualization software:

- VirtualBox
- UTM
- VMware

The virtual machine must run **without a graphical interface (no GUI)**, using only the terminal.

---

# Operating System

The project can be implemented using one of the following Linux distributions:

- **Debian**
- **Rocky Linux**

These distributions are commonly used for servers because they are:

- Stable
- Secure
- Well documented
- Widely supported in enterprise environments

---

# Disk Partitioning and Encryption

The system must use **LVM (Logical Volume Management)** and **disk encryption**.

## LVM (Logical Volume Management)

LVM allows flexible disk management compared to traditional partitions.

Benefits:

- Easy resizing of partitions
- Dynamic disk allocation
- Logical grouping of disks

Typical structure:

















S0 — Orientation
L1 — What is Born2beRoot? (B2BR-S0-L1)
Feynman-style: you build a tiny Linux server VM (usually Debian) and harden it:

Proper disk layout with LVM (required).

Create your non-root user (your intra login) and never work as root.

Install and configure sudo, SSH (on port 4242), and a firewall (ufw).

Enforce password policy (complexity + ageing) using PAM and chage.

Write a monitoring script that prints system info to all users periodically (via wall).

Provide proof: configuration files, command outputs, your understanding in the audit.

Deliverable: a .vdi/.vmdk (or your VM) and your brain: you explain every choice and show the configs.

L2 — Glossary (quick) (B2BR-S0-L2)
VM/Hypervisor: Software that runs another OS as a guest (VirtualBox/UTM/Parallels).

Debian: The Linux distribution you’ll install.

LVM: Logical Volume Manager—flexible disk partitions (PV → VG → LV).

SSH: Secure remote shell (we’ll run it on 4242, not 22).

UFW: Uncomplicated Firewall—easy iptables wrapper.

PAM: Pluggable Authentication Modules—where password rules live.

sudo: Run commands as root temporarily; we configure logs & secure path.

cron: Scheduler to run scripts periodically.

S1 — VM & ISO prep
L1 — Choose hypervisor & get ISO (B2BR-S1-L1)
Pick one:

VirtualBox (Windows/Linux/macOS Intel)

UTM (macOS Apple Silicon, free)

Parallels (macOS Apple Silicon, paid)

Get Debian ISO:

Debian netinst ISO (stable). (Search “Debian netinst” and download for your arch: amd64 or arm64.)

Create a VM (VirtualBox example):

Name: login42 (replace with your 42 login)

Type: Linux, Debian (64-bit)

RAM: 1024–2048 MB

CPUs: 1–2

Disk: 20–30 GB (VDI, dynamically allocated)

Attach ISO to the VM’s optical drive.

Networking: NAT is fine for the project; (Optionally “Bridged” if your campus allows.)

Exercise (answer included)

Q: Why not use the root account directly for daily operations?
A: It’s unsafe; a single mistake can break the system. Born2beRoot enforces working via non-root user + sudo.

L2 — Disk layout plan (B2BR-S1-L2)
Subject expects LVM. A clean, audit-friendly layout:

/boot — standard partition (ext2/ext4), NOT in LVM, ~512 MB

LVM PV on the remaining disk:

Create VG: vg00

Create LVs (sizes are examples; adjust to disk):

lv_root → / (ext4) — 10–12 GB

lv_swap → swap — RAM size (1–2 GB)

lv_var → /var (ext4) — 3–6 GB

lv_home → /home (ext4) — 2–6 GB

(optional) lv_tmp → /tmp — 1–2 GB

Why split /var? Logs grow there; isolating it prevents log floods from breaking /.

Exercise (answer included)

Q: Why put /boot outside LVM?
A: The bootloader must access kernel/initramfs early; placing /boot outside LVM avoids bootloader limitations.

S2 — Install Debian (base system)
... (осталось: 883 строки)

BTBindepth research.txt
30 кб
﻿
Randy
randyk4893
error / 404
 
 
 
“We’re all mad here. Oh, you’re not? How…ordinary.”
"I know no greater life purpose than to perish in attempting the great and impossible." 
— Friedrich Nietzsche

S0 — Orientation
L1 — What is Born2beRoot? (B2BR-S0-L1)
Feynman-style: you build a tiny Linux server VM (usually Debian) and harden it:

Proper disk layout with LVM (required).

Create your non-root user (your intra login) and never work as root.

Install and configure sudo, SSH (on port 4242), and a firewall (ufw).

Enforce password policy (complexity + ageing) using PAM and chage.

Write a monitoring script that prints system info to all users periodically (via wall).

Provide proof: configuration files, command outputs, your understanding in the audit.

Deliverable: a .vdi/.vmdk (or your VM) and your brain: you explain every choice and show the configs.

L2 — Glossary (quick) (B2BR-S0-L2)
VM/Hypervisor: Software that runs another OS as a guest (VirtualBox/UTM/Parallels).

Debian: The Linux distribution you’ll install.

LVM: Logical Volume Manager—flexible disk partitions (PV → VG → LV).

SSH: Secure remote shell (we’ll run it on 4242, not 22).

UFW: Uncomplicated Firewall—easy iptables wrapper.

PAM: Pluggable Authentication Modules—where password rules live.

sudo: Run commands as root temporarily; we configure logs & secure path.

cron: Scheduler to run scripts periodically.

S1 — VM & ISO prep
L1 — Choose hypervisor & get ISO (B2BR-S1-L1)
Pick one:

VirtualBox (Windows/Linux/macOS Intel)

UTM (macOS Apple Silicon, free)

Parallels (macOS Apple Silicon, paid)

Get Debian ISO:

Debian netinst ISO (stable). (Search “Debian netinst” and download for your arch: amd64 or arm64.)

Create a VM (VirtualBox example):

Name: login42 (replace with your 42 login)

Type: Linux, Debian (64-bit)

RAM: 1024–2048 MB

CPUs: 1–2

Disk: 20–30 GB (VDI, dynamically allocated)

Attach ISO to the VM’s optical drive.

Networking: NAT is fine for the project; (Optionally “Bridged” if your campus allows.)

Exercise (answer included)

Q: Why not use the root account directly for daily operations?
A: It’s unsafe; a single mistake can break the system. Born2beRoot enforces working via non-root user + sudo.

L2 — Disk layout plan (B2BR-S1-L2)
Subject expects LVM. A clean, audit-friendly layout:

/boot — standard partition (ext2/ext4), NOT in LVM, ~512 MB

LVM PV on the remaining disk:

Create VG: vg00

Create LVs (sizes are examples; adjust to disk):

lv_root → / (ext4) — 10–12 GB

lv_swap → swap — RAM size (1–2 GB)

lv_var → /var (ext4) — 3–6 GB

lv_home → /home (ext4) — 2–6 GB

(optional) lv_tmp → /tmp — 1–2 GB

Why split /var? Logs grow there; isolating it prevents log floods from breaking /.

Exercise (answer included)

Q: Why put /boot outside LVM?
A: The bootloader must access kernel/initramfs early; placing /boot outside LVM avoids bootloader limitations.

S2 — Install Debian (base system)
L1 — Installer walkthrough (B2BR-S2-L1)
During installation:

Language/keyboard: choose as needed.

Hostname: must include your login (e.g., login42 or login42-42 per subject).

Domain: leave empty or 42 (not critical).

Root password: DO NOT SET (skip root password) → Debian creates a sudo-capable user flow OR if installer asks both, set root but we’ll disable root SSH later.

Create user: login42 (your intra login). Strong password (we’ll change policy later).

Partitioning: Guided — use entire disk with LVM (then manual adjust) or Manual from start:

Create /boot primary, ext4, ~512MB outside LVM.

Create 1 big partition as physical volume for LVM.

Inside LVM, create VG vg00, LVs as planned (root, swap, var, home, optional tmp).

Base system: Minimal installation (no GUI).

Package manager: Yes to security updates; mirrors OK.

Software selection: choose “standard system utilities” and “SSH server” if offered. (If SSH not offered, we’ll install later.)

Grub: install to the disk (e.g., /dev/sda).

Finish & reboot.

Exercise (answers included)

Q: Which filesystems do you choose for LVs?
A: ext4 (simple, stable). Swap gets swap type.

Q: Why minimal install (no GUI)?
A: Server project: less attack surface, fits subject.

L2 — Verify LVM & filesystems (B2BR-S2-L2)
After first boot, login as your user (not root).

Commands:

lsblk
sudo lvs
sudo vgs
sudo pvs
df -h
Expected:

lsblk shows sda → sda1 (boot), sda2 (LVM PV), then mapper/vg00-lv_* mounted at /, /home, /var, etc.

lvs/vgs/pvs show the VG/LV structure.

df -h shows mount points and sizes.

S3 — First boot hardening
L1 — Users, groups (B2BR-S3-L1)
Create (or ensure) your login user and add to sudo group:

# If your user isn't already present or needs sudo:
sudo adduser login42
sudo usermod -aG sudo login42
Create an additional user if your campus wants a “tester” or “user42”:

sudo adduser user42
Check groups:

id login42
Expected: groups=... sudo ...

Exercise (answer)

Q: Why -aG sudo and not -G sudo alone?
A: -aG appends to existing groups; -G alone overwrites them.

L2 — sudo install & basic hardening (B2BR-S3-L2)
If sudo isn’t installed:

sudo apt update
sudo apt install sudo -y
Sudo secure_path & logfile:
Open /etc/sudoers with visudo:

sudo visudo
Add (or ensure) these lines (leave other defaults intact):

Defaults    secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
Defaults    logfile="/var/log/sudo/sudo.log"
Create the log dir:

sudo mkdir -p /var/log/sudo
sudo touch /var/log/sudo/sudo.log
sudo chown root:root /var/log/sudo/sudo.log
sudo chmod 0600 /var/log/sudo/sudo.log
Exercise (answers)

Q: Where will sudo command logs be written now?
A: /var/log/sudo/sudo.log

Q: Why secure_path?
A: Prevents using unsafe PATH when running as root via sudo.

S4 — SSH + Firewall
L1 — OpenSSH on port 4242; disable root SSH (B2BR-S4-L1)
Install SSH server if not present:

sudo apt install openssh-server -y
Edit config:

sudo nano /etc/ssh/sshd_config
Set/ensure:

Port 4242
PermitRootLogin no
PasswordAuthentication yes   # (stick to subject; later you can switch to keys)
Reload SSH:

sudo systemctl enable ssh
sudo systemctl restart ssh
sudo systemctl status ssh --no-pager
Test from host:

ssh -p 4242 login42@<VM_IP>
(Find IP with ip a in VM. If NAT, you can also use port forwarding; or just test from within campus with bridged NIC.)

Exercise (answers)

Q: What happens if PermitRootLogin yes?
A: Root could login over SSH—disallowed by subject. We set no.

L2 — UFW basic firewall (B2BR-S4-L2)
Install and configure:

sudo apt install ufw -y
sudo ufw default deny incoming
sudo ufw default allow outgoing
sudo ufw allow 4242/tcp
sudo ufw enable
sudo ufw status verbose
Expected: 4242/tcp ALLOW.

Exercise (answers)

Q: Why allow 4242 specifically?
A: SSH listens on 4242 per subject, so we must open it.

S5 — Password policy (PAM)
L1 — Complexity rules (B2BR-S5-L1)
Install module:

sudo apt install libpam-pwquality -y
Edit /etc/pam.d/common-password (keep existing lines; adjust the pwquality line):

password  requisite  pam_pwquality.so retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
Meaning (short):

minlen=10 → at least 10 chars

ucredit/lcredit/dcredit=-1 → must have at least 1 upper, 1 lower, 1 digit

maxrepeat=3 → at most 3 same chars in a row

reject_username → can’t contain the username

difok=7 → at least 7 chars different from old password

retry=3 → prompt at most 3 times

enforce_for_root → even root must obey

Exercise (answers)

Try passwd with a weak password; expect rejection with pwquality messages.

L2 — Ageing & history (B2BR-S5-L2)
Set system-wide defaults in /etc/login.defs (ensure):

PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
Apply to your users:

sudo chage -M 30 -m 2 -W 7 login42
sudo chage -M 30 -m 2 -W 7 user42
Check:

chage -l login42
You should see Max 30, Min 2, Warn 7.

History (last passwords): On Debian, enable remember via pam_unix or use pam_pwhistory:
Add to /etc/pam.d/common-password (after pwquality line), for example:

password   required    pam_pwhistory.so remember=5 use_authtok
This keeps the last 5 passwords for each user to prevent reuse.

S6 — Monitoring script
L1 — monitoring.sh full script (B2BR-S6-L1)
Create /usr/local/bin/monitoring.sh:

#!/bin/bash

arch=$(uname -a)
phys_cpu=$(lscpu | awk '/^Socket\(s\)/{print $2}')
virt_cpu=$(nproc)
mem_total=$(free -m | awk '/Mem:/{print $2}')
mem_used=$(free -m | awk '/Mem:/{print $3}')
mem_usep=$(free | awk '/Mem:/{printf("%.2f"), $3/$2*100}')
disk_used=$(df -h --total | awk '/total/{print $3}')
disk_total=$(df -h --total | awk '/total/{print $2}')
disk_usep=$(df -h --total | awk '/total/{print $5}')
cpu_load=$(top -bn1 | awk '/Cpu\(s\)/{printf("%.2f"), 100-$8}')
last_boot=$(who -b | awk '{print $3" "$4}')
lvm_use=$(lsblk | grep -q "lvm" && echo yes || echo no)
tcp_count=$(ss -tan | awk 'NR>1 && $1 ~ /ESTAB/ {c++} END{print c+0}')
user_logins=$(users | wc -w)
ip_addr=$(hostname -I | awk '{print $1}')
mac_addr=$(ip link show | awk '/ether/{print $2; exit}')
sudo_count=$(grep -c "COMMAND=" /var/log/sudo/sudo.log 2>/dev/null || echo 0)

msg="\
#Architecture: $arch
#CPU physical: $phys_cpu
#vCPU: $virt_cpu
#Memory Usage: ${mem_used}/${mem_total}MB (${mem_usep}%)
#Disk Usage: ${disk_used}/${disk_total} (${disk_usep})
#CPU load: ${cpu_load}%
#Last boot: $last_boot
#LVM use: $lvm_use
#Conn TCP: $tcp_count ESTABLISHED
#User log: $user_logins
#Network: IP $ip_addr ($mac_addr)
#Sudo: $sudo_count cmd"

wall "$msg"
Make executable:

sudo chmod +x /usr/local/bin/monitoring.sh
What it prints (matches common audit asks):

Architecture (uname -a)

Physical & virtual CPUs

Memory (used/total and %)

Disk (used/total and %)

CPU load (user-friendly)

Last boot time

LVM usage (yes/no)

Active TCP connections

Logged-in users count

Network IP + MAC

Sudo command count from /var/log/sudo/sudo.log

Exercise (answers)

Run sudo /usr/local/bin/monitoring.sh → All logged-in terminals receive the summary (via wall).

L2 — Cron every 10 minutes (B2BR-S6-L2)
Open root’s crontab:

sudo crontab -e
Add:

*/10 * * * * /usr/local/bin/monitoring.sh
Check cron service:

sudo systemctl status cron --no-pager
You should see broadcasts every 10 minutes.

S7 — Audit rehearsal
L1 — Commands auditors ask (B2BR-S7-L1)
Show LVM: lsblk, lvs, vgs, pvs, df -h

Show hostname: hostnamectl

Show users & groups: getent passwd | grep login42, id login42, getent group sudo

sudo logs path: sudo tail /var/log/sudo/sudo.log

SSH config: sudo grep -E '^(Port|PermitRootLogin|PasswordAuthentication)' /etc/ssh/sshd_config

UFW: sudo ufw status verbose

PAM: grep -E "pam_pwquality|pam_pwhistory" /etc/pam.d/common-password

Ageing: chage -l login42

Cron: sudo crontab -l

Monitoring script: show file (cat /usr/local/bin/monitoring.sh) and run it.

Exercise (answers)

Q: Which port is SSH listening on?
A: 4242 (show via sudo ss -tlnp | grep 4242)

L2 — Self-checklist (B2BR-S7-L2)
 VM boots to Debian; hostname contains your login.

 /boot outside LVM; /, /var, /home inside LVM.

 Your user can sudo; root SSH login disabled.

 SSH listens on 4242; you can connect.

 UFW enabled; allow 4242/tcp only (optionally allow needed services).

 PAM complexity active; weak passwords rejected.

 Password aging: max 30, min 2, warn 7 (via chage -l).

 Password history remember=5 (pwhistory present).

 monitoring.sh exists, runs, and cron triggers every 10 minutes.

 Sudo logs present in /var/log/sudo/sudo.log.

 You can explain what LVM is and why SSH is on 4242.

Where to go next
We’ve covered S0 → S6 in slow, practical steps with exercises & expected results.
If you want, we can:

continue with deeper practice & audit mock (S7), or

I can generate a filled Musashi Template for a specific B2BR module (e.g., “SSH hardening” or “PAM policy”), or

jump straight into a mock audit Q&A where I ask and you answer (with the key commands shown after).

Tell me where to resume:

B2BR-S7-L1 (audit rehearsal Q&A),

or say a module like “Make the Musashi Template for PAM policy.”

You said:
(S7
ChatGPT said:
perfect—jumping to B2BR-S7 — Audit rehearsal
(if memory resets, say B2BR-S7 to get back here)

We’ll do two short lessons:

S7-L1: Mock audit Q&A — what the auditor asks, exact commands to run, and what good output looks like.

S7-L2: Final self-checklist + 5-minute pre-audit warmup.

I’ll keep it slow, practical, and include “expected/typical output shapes” so you don’t guess.

S7-L1 — Mock audit Q&A (commands + expected)
Tip: run every command without sudo first when possible. If permission denied or root-only, then add sudo.

1) Host basics
Q: Show the hostname and OS info.
A:

hostnamectl
Expect:

Static hostname: <your-login> or similar (e.g., login42)

Operating System: Debian GNU/Linux ...

Kernel: Linux ...

Q (variant): What’s your machine architecture?
A:

uname -a
Expect: x86_64 (Intel/AMD) or aarch64/arm64 (Apple Silicon), plus kernel version.

2) LVM & filesystem layout
Q: Prove /boot is outside LVM and the rest are LVM.
A:

lsblk
Expect (shape):

sda
├─sda1             /boot
└─sda2
  └─vg00-lv_root  /
  └─vg00-lv_var   /var
  └─vg00-lv_home  /home
  (└─vg00-lv_tmp  /tmp)   # if you created it
Q: Show PV/VG/LV.
A:

sudo pvs
sudo vgs
sudo lvs
Expect:

PVS: /dev/sda2 → VG vg00

VGS: vg00 with total/used size

LVS: lv_root, lv_var, lv_home (and lv_swap), with sizes.

Q (variant): Show mounts and free space.
A:

df -h
Expect: /, /var, /home present with expected sizes.

3) Users & groups
Q: Show your primary user and groups (must include sudo).
A:

id <your-login>
Expect: groups=... sudo ...

Q: List all users (system + humans).
A:

getent passwd | cut -d: -f1,3,7 | head -n 5   # (just to show format)
getent passwd | grep -E '(/bin/bash|/bin/zsh)'   # likely human users
Expect: Your login user visible with a shell.

Q: Show the sudo group members.
A:

getent group sudo
Expect: sudo:x:27:<your-login>[,others]

4) Sudo configuration & logs
Q: Where does sudo log commands? Prove it.
A:

sudo grep -n 'logfile=' /etc/sudoers
sudo tail -n 5 /var/log/sudo/sudo.log
Expect:

In sudoers, Defaults logfile="/var/log/sudo/sudo.log"

Log file exists and contains entries like USER=<your-login> ; COMMAND=/usr/bin/apt update

Q (variant): Show secure_path.
A:

sudo grep -n 'secure_path=' /etc/sudoers
Expect: The exact secure path string you set.

5) SSH hardening
Q: Show SSH is on port 4242 and root login is disabled.
A:

sudo grep -E '^(Port|PermitRootLogin|PasswordAuthentication)' /etc/ssh/sshd_config
sudo ss -tlnp | grep ':4242'
Expect:

Port 4242

PermitRootLogin no

A listening line like LISTEN 0 128 0.0.0.0:4242 ... sshd

Q (variant): Prove you can connect via 4242.
A (from host or another shell):

ssh -p 4242 <your-login>@<vm-ip>
Expect: Password prompt or login success.

6) Firewall (UFW)
Q: Show firewall rules.
A:

sudo ufw status verbose
Expect:

Status: active

4242/tcp ALLOW (and not much else)

Q (variant): What is the default policy?
A: “deny incoming, allow outgoing” (showed by status verbose).

7) Password policy (PAM) & ageing
Q: Show password complexity rules.
A:

grep -n 'pam_pwquality.so' /etc/pam.d/common-password
Expect (contains): minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root retry=3

Q: Show password age policy for your user.
A:

chage -l <your-login>
Expect:

Minimum number of days between password change : 2

Maximum number of days between password change : 30

Number of days of warning before password expires : 7

Q: Prove password history is enabled (no reuse last N).
A:

grep -n 'pam_pwhistory.so' /etc/pam.d/common-password
Expect: a line like pam_pwhistory.so remember=5 use_authtok

8) Monitoring script & cron
Q: Show the monitoring script and run it.
A:

sudo bash -n /usr/local/bin/monitoring.sh   # syntax check (no output on success)
sudo /usr/local/bin/monitoring.sh
Expect: wall broadcasts a block with:

Architecture, CPU phys/vCPU, Mem used/total %, Disk used/total %, CPU load

Last boot, LVM use, TCP established count, Logged users count

Network IP + MAC, Sudo command count

Q: Show it runs every 10 minutes.
A:

sudo crontab -l
Expect: */10 * * * * /usr/local/bin/monitoring.sh

Q (variant): Is cron active?
A:

systemctl is-active cron
Expect: active

9) Service status (ssh, ufw, cron)
Q: Prove services are enabled and running.
A:

systemctl is-enabled ssh ufw cron
systemctl is-active ssh ufw cron
Expect: enabled / active for each.

10) Why decisions? (short answers to “why”)
Why port 4242? Subject requirement; reduces default-port scans, shows you can change defaults.

Why disable SSH root login? Principle of least privilege; mitigate credential brute-force and privilege escalation risks.

Why LVM? Flexibility: resize/extend logical volumes and isolate /var to protect /.

Why UFW? Simple policy enforcement: explicit allow 4242, deny others.

Why PAM rules? Enforce strong passwords and rotation to reduce compromise risk.

Why sudo logfile & secure_path? Audit trail for privileged actions; control PATH when elevated.

S7-L2 — Final self-checklist + 5-minute warmup
✅ Self-checklist (do these before the audit starts)
 hostnamectl shows correct hostname.

 lsblk, lvs, vgs, pvs, df -h all match the planned LVM layout (/boot outside LVM).

 id <your-login> shows you in sudo.

 /etc/sudoers has logfile= and secure_path=; the log file exists and contains entries.

 sshd_config: Port 4242, PermitRootLogin no.

 ss -tlnp | grep 4242 shows sshd listening.

 ufw status verbose → active, allow 4242/tcp, deny incoming by default.

 common-password contains pwquality line with your rules and pwhistory with remember=5.

 chage -l shows min=2, max=30, warn=7.

 monitoring.sh runs; crontab -l shows */10.

 systemctl is-active ssh ufw cron → active.

 You can explain each decision in one sentence (use the Why list above).

⏱️ 5-minute warmup (copy/paste block)
Run this just before the auditor joins:

echo '# Host & kernel'; hostnamectl; echo
echo '# LVM'; lsblk; echo; sudo vgs; sudo lvs; echo
echo '# Mounts'; df -h | sed -n '1,8p'; echo
echo '# User & sudo'; id $USER; getent group sudo; echo
echo '# sudoers bits'; sudo grep -E 'logfile=|secure_path=' /etc/sudoers; sudo tail -n 3 /var/log/sudo/sudo.log; echo
echo '# SSH'; sudo grep -E '^(Port|PermitRootLogin|PasswordAuthentication)' /etc/ssh/sshd_config; sudo ss -tlnp | grep sshd || true; echo
echo '# Firewall'; sudo ufw status verbose | sed -n '1,10p'; echo
echo '# PAM policy'; grep -E "pam_pwquality|pam_pwhistory" /etc/pam.d/common-password; echo
echo '# Ageing'; chage -l $USER | sed -n '1,6p'; echo
echo '# Cron'; sudo crontab -l || true; echo
echo '# Monitoring (one shot)'; sudo /usr/local/bin/monitoring.sh
Scan the output: if anything’s off, fix it now.

Mini-exercises (answers included)
Show your SSH port and root login policy in one command.

sudo grep -E '^(Port|PermitRootLogin)' /etc/ssh/sshd_config
Answer shape: Port 4242, PermitRootLogin no.

Prove UFW allows SSH and denies other incoming connections by default.

sudo ufw status verbose
Answer shape: Status: active, Default: deny (incoming), 4242/tcp ALLOW.

Show your password ageing for user login42.

chage -l login42
Answer shape: Max 30, Min 2, Warn 7.

Show the last 3 sudo commands logged.

sudo tail -n 3 /var/log/sudo/sudo.log
Answer shape: Lines with COMMAND= entries.

Prove /boot is not an LV.

lsblk | sed -n '1,20p'
Answer shape: /boot on sda1 (plain partition), LVs under mapper/vg00-* for /, /var, /home.

Final mantra (say this calmly in the audit)
“This VM is a minimal Debian server with /boot outside LVM and /, /var, /home as LVs under vg00. SSH is on 4242, root SSH is disabled, and UFW allows only 4242 inbound. PAM enforces strong passwords and chage sets max 30, min 2, warn 7 days; password history prevents reuse. sudo uses a secure path and logs to /var/log/sudo/sudo.log. A monitoring script broadcasts system status every 10 minutes via cron. I can demonstrate any of these with commands right now.”

You’re ready.
Want a filled Musashi Template for a specific B2BR module (e.g., SSH hardening or PAM policy) you can print, or do you want me to rapid-fire mock audit questions while you answer?

You said:
rapid-fire mock audit questions
ChatGPT said:
awesome — let’s do a rapid-fire mock audit for Born2beRoot.
Format per item: Question → You run → Good answer (what to say + what output shape to show).
Skim the bold bits; copy/paste the commands when practicing.

A. Host, system, kernel (8)
What’s the hostname? Does it match your login?
Run: hostnamectl
Answer: “Hostname is login42.”
Show: Static hostname: login42

What architecture and kernel are you running?
Run: uname -a
Answer: “x86_64 (or aarch64) on Linux <version>.”

When was the system last booted?
Run: who -b
Answer: “Last boot: <YYYY-MM-DD HH:MM>.”
Show: system boot 2025-10-13 08:42

How many physical CPUs and vCPUs?
Run: lscpu | awk '/^Socket|^CPU\(s\)/'
Answer: “Sockets: 1, vCPUs: N (from CPU(s)).”

What’s your IP and MAC?
Run: hostname -I | awk '{print $1}' ; ip link | awk '/ether/{print $2; exit}'
Answer: “IP 10.x.x.x, MAC xx:xx:xx:xx:xx:xx.”

What services are enabled and active (ssh, ufw, cron)?
Run: systemctl is-enabled ssh ufw cron ; systemctl is-active ssh ufw cron
Answer: “All enabled and active.”

Show system time and timezone.
Run: timedatectl
Answer: “Time synchronized: yes; Time zone: <Region/City>.”

Show disk usage summary.
Run: df -h
Answer: “/, /var, /home mounted on LVs with expected sizes.”

B. Disks, LVM, filesystems (8)
Prove /boot is outside LVM; others are LVM.
Run: lsblk
Answer: “sda1 /boot (plain), mapper/vg00-lv_* for /, /var, /home.”
Show: tree with /boot directly under sda1.

Show PV/VG/LV structure.
Run: sudo pvs ; sudo vgs ; sudo lvs
Answer: “PV /dev/sda2 → VG vg00 → LVs lv_root, lv_var, lv_home (+ swap).”

Which filesystem type did you choose? Why?
Run: findmnt -T / /var /home
Answer: “ext4 for stability; swap LV for swap.”

How much free space remains in VG?
Run: sudo vgs
Answer: “VFree shows remaining space (e.g., 2.00g).”

What’s your swap configuration?
Run: swapon --show
Answer: “Swap LV vg00-lv_swap size ~RAM.”

Show fstab entries.
Run: cat /etc/fstab
Answer: “UUID mounts for /, /boot, /var, /home, and swap.”

Why isolate /var?
Answer: “Logs/apt/cache growth can’t fill /; containment.”

How would you extend /var if it fills up?
Answer (1-liner): “Increase LV, resize FS.”
Run (pattern): sudo lvextend -L +1G /dev/vg00/lv_var && sudo resize2fs /dev/vg00/lv_var

C. Users, groups, sudo (8)
Show your user and groups.
Run: id $USER
Answer: “I’m in sudo (… other groups).”

Who is in the sudo group?
Run: getent group sudo
Answer: “Shows sudo:x:27:<login42>[,others].”

Where do sudo commands get logged? Prove it.
Run: sudo grep -n logfile= /etc/sudoers ; sudo tail -n 3 /var/log/sudo/sudo.log
Answer: “/var/log/sudo/sudo.log; show last entries.”

What is secure_path and why?
Run: sudo grep -n secure_path= /etc/sudoers
Answer: “Controls PATH for sudo to safe binaries; mitigates PATH hijacking.”

Create a new user user42 with sudo rights.
Run:

sudo adduser user42
sudo usermod -aG sudo user42
id user42
Answer: “Now user42 is in sudo.”

Show all human users.
Run: getent passwd | awk -F: '$7 ~ /bash|zsh/ {print $1,$7}'
Answer: “Lists interactive users.”

What happens if you run sudo -l?
Run: sudo -l
Answer: “Shows allowed commands/policy via sudoers.”

Why no daily root logins?
Answer: “Least privilege; use sudo traceable elevation; safer.”

D. SSH & Firewall (8)
Show SSH listens on port 4242; root login disabled.
Run:

sudo grep -E '^(Port|PermitRootLogin|PasswordAuthentication)' /etc/ssh/sshd_config
sudo ss -tlnp | grep ':4242'
Answer: “Port 4242, PermitRootLogin no, and sshd LISTEN on 4242.”

Why 4242 instead of 22?
Answer: “Subject requirement; shows we can change defaults; reduces generic scans a bit.”

Connect via SSH from host (what command)?
Answer: ssh -p 4242 login42@<VM_IP>

Show your firewall rules.
Run: sudo ufw status verbose
Answer: “Status: active; default deny incoming; allow 4242/tcp.”

Enable UFW safely (what order)?
Answer: “Allow 4242 first, then enable:”
Run:

sudo ufw allow 4242/tcp
sudo ufw enable
How to delete a wrong UFW rule?
Run: sudo ufw status numbered ; sudo ufw delete <num>

Show SSH service status and enablement.
Run: systemctl status ssh --no-pager ; systemctl is-enabled ssh
Answer: “Active and enabled.”

What if you disable PasswordAuthentication?
Answer: “Then only keys work; for subject we keep passwords on (auditors need to log in).”

E. PAM, password policy, ageing (8)
Show PAM complexity rules.
Run: grep -n 'pam_pwquality.so' /etc/pam.d/common-password
Answer: “Contains minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root retry=3.”

Demonstrate rejection of a weak password (what happens)?
Run: passwd (try weak)
Answer: “pwquality rejects with reasons; accepts strong password.”

Show password history is enforced.
Run: grep -n 'pam_pwhistory.so' /etc/pam.d/common-password
Answer: “remember=5 use_authtok prevents reusing last 5 passwords.”

Show password ageing for your user.
Run: chage -l $USER
Answer: “Min 2, Max 30, Warn 7.”

How to set those ageing values for another user?
Run: sudo chage -M 30 -m 2 -W 7 user42
Answer: “Same policy applied.”

Why enforce for root too?
Answer: “enforce_for_root reduces weak credentials even for root.”

Where else do PAM modules live?
Run: ls /etc/pam.d/
Answer: “Stacked files (common-*), service-specific files (sshd, su, sudo, login).”

F. Monitoring script & cron (6)
Show the monitoring script path and run it.
Run:

ls -l /usr/local/bin/monitoring.sh
sudo bash -n /usr/local/bin/monitoring.sh
sudo /usr/local/bin/monitoring.sh
Answer: “Executable, syntax OK, broadcast via wall with system summary.”

Show the cron schedule (every 10 minutes).
Run: sudo crontab -l
Answer: “*/10 * * * * /usr/local/bin/monitoring.sh.”

Is cron active and enabled?
Run: systemctl is-active cron ; systemctl is-enabled cron
Answer: “Active and enabled.”

Where do sudo command counts in the script come from?
Run: sudo tail -n 3 /var/log/sudo/sudo.log
Answer: “We grep that logfile in the script.”

How to silence wall during audit temporarily?
Answer: “Comment cron line or sudo crontab -e remove; re-add later. Or sudo systemctl stop cron briefly (explain first).”

G. Classic trick questions (8)
Why not allow root SSH login if sudo exists?
Answer: “We avoid direct privileged sessions; sudo yields traceable, least-privilege escalation, with logs.”

What if UFW is enabled but you forgot to allow 4242?
Answer: “You’d lock yourself out. Always ufw allow 4242/tcp first.”

Show that only ssh(4242) is open.
Run: sudo ss -tuln
Answer: “Only :4242 is listening for sshd.”

How to verify PAM is actually applied for passwd changes?
Run: sudo pam-auth-update --list (or attempt passwd with weak passwords)
Answer: “pam_pwquality line is in common-password; observed rejection confirms enforcement.”

How would you rotate logs in /var/log/sudo?
Answer: “Via logrotate: add a /etc/logrotate.d/sudo entry with rotation policy.”

If /var fills, what breaks first and why is it isolated?
Answer: “Logs/apt writes fail, but / remains healthy; isolation prevents full system outage.”

How to change SSH port again?
Answer: “Edit sshd_config → Port NNNN, open it in UFW, systemctl restart ssh.”

What is difok=7?
Answer: “New password must differ by at least 7 chars from the old one.”

H. 60-second “fix-it” snippets (copy-able)
Open SSH 4242 & enable UFW:

sudo ufw allow 4242/tcp
sudo ufw enable
sudo ufw status verbose
Set SSH port + disable root login:

sudoed=/etc/ssh/sshd_config
sudo sed -i 's/^#\?Port .*/Port 4242/' $sudoed
sudo sed -i 's/^#\?PermitRootLogin .*/PermitRootLogin no/' $sudoed
sudo systemctl restart ssh
Set PAM complexity + history (append if missing):

sudo nano /etc/pam.d/common-password   # ensure pwquality line with your options
# add history line if missing:
# password required pam_pwhistory.so remember=5 use_authtok
Apply ageing to a user:

sudo chage -M 30 -m 2 -W 7 login42
Monitoring cron every 10 min:

sudo crontab -e   # add: */10 * * * * /usr/local/bin/monitoring.sh
Final 1-line mantra for the audit
“Debian server with /boot outside LVM and / /var /home in LVM; SSH on 4242, root SSH disabled, UFW allows only 4242; PAM enforces strong passwords + history; ageing is 30/2/7; sudo uses secure_path and logs to /var/log/sudo/sudo.log; monitoring broadcasts every 10 minutes via cron. I can show each with a command.”
