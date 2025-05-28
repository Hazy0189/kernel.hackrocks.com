#!/bin/bash

gcc -static exploit2.c -o exploit
mv exploit mount/
cd mount

rm initramfs.cpio
find . | cpio -o -H newc > initramfs.cpio
cd ..

