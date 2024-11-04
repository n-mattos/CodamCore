# **OS**
```
uname -a
```


# **SSH**
SSH status
```
sudo systemctl status ssh
```

SSH restart
```
sudo systemctl restart ssh
```

Check port
```
sudo grep Port /etc/ssh/sshd_config
```

Connect to SSH
```
ssh username@127.0.0.1 -p 4242
```

# **UFW**
Check ufw:
```
sudo ufw status numbered
```

Allow incoming traffic:
```
sudo ufw allow <port>
```

Delete
```
sudo ufw delete <number>
```


# **PWQUALITY**
password quality
```
sudo vim /etc/pam.d/common-password
```

password expiration
```
sudo vim /etc/login.defs
```

# **GROUPS**
Groups
```
sudo groupadd <groupname>
```

check group
```
getent group
```

all users
```
cut -d: -f1 /etc/passwd
```

create user
```
sudo adduser <username>
```

assign user
```
sudo usermod -aG <groupname> <username>
```

check if in group
```
groups <username>
```

check pw rules
```
chage -l <username>
```


# **SUDOERS**
sudoers
```
sudo visudo
```

# **HOSTNAME**
hostname
```
hostnamectl
```

change hostname
```
sudo hostnamectl set-hostname <newhostname>
```

change hostname in file
```
sudo vim /etc/hostname
```


# **CRON**
cron
```
crontab -u root -e
```


# **DPKG**
check installed packages
```
dpkg -l
```