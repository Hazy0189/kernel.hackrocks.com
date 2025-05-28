gdb-pwndbg \
	-ex 'set arch i386:x86-64' \
    -ex 'target remote localhost:1234'\
	-ex 'file vmlinux' \
    -ex 'add-symbol-file mount/stagefour.ko 0xffffffffc0000000'\ 
