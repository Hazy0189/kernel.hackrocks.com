#!/bin/bash

#
# launch
#
timeout --foreground 28800 /usr/bin/qemu-system-x86_64 \
	-kernel ./bzImage \
	-initrd ./mount/initramfs.cpio \
	-nographic \
	-monitor none \
	-no-reboot \
	-cpu kvm64,+smap,+smep\
	-append "console=ttyS0 kaslr kpti quiet panic=1 oops=panic" \
        -netdev user,id=net0,hostfwd=tcp::23947-:23947 \
        -s
