#ifndef __KCEJ_NOUSBFS_H__
#define __KCEJ_NOUSBFS_H__

#include <sys/file.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int pcInit(void);
extern int pcOpen(char *filename, int flag);
extern int pcClose(int fd);
extern int pcRead(int fd, void *buf, long nbyte);
extern int pcWrite(int fd, void *buf, long nbyte);
extern long pcLseek(int fd, long offset, int whence);

#ifdef __cplusplus
}
#endif
#endif // {{{ END OF FILE }}}
