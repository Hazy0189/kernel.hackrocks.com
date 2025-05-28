#include "libpwn.h"
#include <linux/userfaultfd.h>

void stagefinal_kalloc(size_t idx, size_t size)
{
        param req;
        req.idx = idx;
        req.size = size;
        if (ioctl(fd, IOCTL_KALLOC, &req) == -1) error("KALCOC failed");
}

void stagefinal_kfree(size_t idx)
{
        param req;
        req.idx = idx;
        if (ioctl(fd, IOCTL_KFREE, &req) == -1) error("KFREE failed");
}

struct param stagefinal_read(size_t idx, char *buf)
{
        param req;
        req.idx = idx;
        req.buf = buf;
        if (ioctl(fd, IOCTL_READ, &req) != -1) return req;
        else error("READ failed");
}

void stagefinal_write(size_t idx, char *buf)
{
        param req;
        req.idx = idx;
        req.buf = buf;
        if (ioctl(fd, IOCTL_WRITE, &req) == -1) error("WRITE failed");
}

void stagefinal_migrates_src_to_dst(size_t idx_dst, size_t idx_src, size_t size_to_set)
{
        migrate_idx req;
        req.idx_src = idx_src;
        req.idx_dst = idx_dst;
        req.size_to_set = size_to_set;
        ioctl(fd, IOCTL_MIGRATES1, &req);
}

void stagefinal_migrates_dst_to_src(size_t idx_dst, size_t idx_src, size_t size_to_set)
{
        migrate_idx req;
        req.idx_src = idx_src;
        req.idx_dst = idx_dst;
        req.size_to_set = size_to_set;
        ioctl(fd, IOCTL_MIGRATES2, &req);
}