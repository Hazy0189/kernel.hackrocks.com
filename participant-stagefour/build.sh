#!/bin/bash

musl-gcc exploit.c -o exploit --static
mv exploit mount/
cd mount

rm initramfs.cpio
find . | cpio -o -H newc > initramfs.cpio
cd ..

