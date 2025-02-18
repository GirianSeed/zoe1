#ifndef __ZOE_DEF_TEX_H__
#define __ZOE_DEF_TEX_H__

#include <eestruct.h>
#include "common.h"

typedef struct _DEF_TEXTURE {
    sceGsTex0   regTex;     // +0x00
    UINT16      rw;         // +0x08
    UINT16      rh;         // +0x0A
    void*       pData;      // +0x0C
} DEF_TEXTURE;

typedef struct _DEF_CLUT {
    sceGsTex0       regClut;        // +0x00
    DEF_TEXTURE*    pTex;           // +0x08
    void*           pData;          // +0x0C
    sceGsClamp      regClamp;       // +0x10
    UINT8           u8AlphaABCD;    // +0x18
    UINT8           u8AlphaFIX;     // +0x19
    UINT16          u16Flag;        // +0x1A
    UINT32          pad1;           // +0x1C
} DEF_CLUT;

typedef struct _DEF_TEXLIST {
    UINT16          u16nTex;    // +0x00
    UINT16          u16Flag;    // +0x02
    DEF_TEXTURE*    pTex;       // +0x04
    UINT32          nClut;      // +0x08
    DEF_CLUT*       pClut;      // +0x0C
} DEF_TEXLIST;

// STATIC_ASSERT(sizeof(DEF_TEXTURE) == 0x10);
// STATIC_ASSERT(sizeof(DEF_CLUT)    == 0x20);
// STATIC_ASSERT(sizeof(DEF_TEXLIST) == 0x10);

#endif // {{{ END OF FILE }}}
