#include <stdio.h>
#include <kernel.h>

int pcInit(void)
{
    return 0;
}

int pcOpen(char *filename, int flag)
{
    return open(filename, flag);
}

int pcClose(int fd)
{
    return close(fd);
}

int pcRead(int fd, void *buf, long nbyte)
{
    return read(fd, buf, nbyte);
}

int pcWrite(int fd, void *buf, long nbyte)
{
    return write(fd, buf, nbyte);
}

long pcLseek(int fd, long offset, int whence)
{
    return lseek(fd, offset, whence);
}

int start()
{
    extern libhead usbfs_entry;

    if (RegisterLibraryEntries(&usbfs_entry) != 0) {
        return NO_RESIDENT_END;
    }
    printf("USB FILE DO NOT USE\n");
    return RESIDENT_END;
}
