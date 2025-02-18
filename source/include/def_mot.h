#ifndef __ZOE_DEF_MOT_H__
#define __ZOE_DEF_MOT_H__

#include "common.h"

typedef struct _DEF_MOTION {
    float       fFrame;     // +0x00
    UINT32      nbNode;     // +0x04
    UINT32      pad1;       // +0x08
    UINT32      pad2;       // +0x0C
} DEF_MOTION;

typedef struct _DEF_MOTION_LIST {
    UINT32      nbMotion;   // +0x00
} DEF_MOTION_LIST;

typedef struct _DEF_MOTION_NODE {
    UINT16      u16Flag;    // +0x00
    UINT16      u16nbElm;   // +0x02
    UINT32      nbData;     // +0x04
    UINT16*     pKeyData;   // +0x08
    INT16*      pMotData;   // +0x0C
} DEF_MOTION_NODE;

// STATIC_ASSERT(sizeof(DEF_MOTION) == 0x10);
// STATIC_ASSERT(sizeof(DEF_MOTION_LIST) == 0x04);
// STATIC_ASSERT(sizeof(DEF_MOTION_NODE) == 0x10);

#endif // {{{ END OF FILE }}}
