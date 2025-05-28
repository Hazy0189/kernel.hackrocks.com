# Kernel hackr0cks

This my solve script for [Linux Kernel Exploitation Challenges](https://kernel.hackrocks.com/) 

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Stage One | pwn | `kernel` `stack` `www2exec` `modprobe_path` | since there is no kaslr, we can just overwrite modprobe_path and get the flag |
| Stage Two | pwn | `kernel` `stack` `commit_creds` | just a simple bof then do ret2user |
| Stage Three | pwn | `kernel` `stack` `commit_creds` `rop` | same with the previous one but we have to do rop chain since userland is not allowed |
| Stage Four | pwn | `kernel` `heap` `seq_op` `commit_creds` | by opening /proc/self/stat to leak kernel base then overwrite and trigger with read the /proc/self/stat to get shell |
| Stage Five | pwn | `kernel` `heap` `timer_tfd` `modprobe_path` `slub poison` | using timer_tfd to leak kernel address then do slub poisoning overwrite the next pointer to modprobe to be overwrite and abuse modprobing to get the flag |