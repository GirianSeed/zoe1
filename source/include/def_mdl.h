#ifndef __ZOE_DEF_MDL_H__
#define __ZOE_DEF_MDL_H__

#include "common.h"
#include "def_tex.h"    // for DEF_TEXLIST
#include "libalg.h"     // for ALG_VECTOR

typedef struct _DEF_TEXLIST DEF_TEXLIST; // in def_tex.h
typedef struct _DG_MATERIAL DG_MATERIAL; // in libdg.h

typedef struct _DEF_OBJ {
    UINT32          u32Flag;    // +0x00
    UINT16          u16nMdl;    // +0x04
    UINT16          u16szMdl;   // +0x06
    float           lx,ly,lz;   // +0x08 +0x0C +0x10
    float           ux,uy,uz;   // +0x14 +0x18 +0x1C
    void*           pBuf;       // +0x20
    UINT32          u32size;    // +0x24
    DEF_TEXLIST*    pTlst;      // +0x28
    float           fScale;     // +0x2C
} DEF_OBJ;

typedef struct _DEF_STRIP {
    DG_MATERIAL*    pmtr;       // +0x00
    UINT16          u16Flag;    // +0x04
    UINT16          u16nVert;   // +0x06
    INT16*          ps16Vert;   // +0x08
    INT16           s16Clut;    // +0x0C
    UINT16          u16TBP0;    // +0x0E
    void*           pTag;       // +0x10
    UINT32          u32pad0;    // +0x14
    UINT8           u8EnvFlag;  // +0x18
    UINT8           u8pad1;     // +0x19
    INT16           s16Clut2;   // +0x1A
    INT16           s16Clut3;   // +0x1C
    UINT16          u16pad2;    // +0x1E
} DEF_STRIP;

typedef struct _DEF_MDL {
    FMATRIX     matLocal;       // +0x00
    float       lx,ly,lz;       // +0x40 +0x44 +0x48
    float       ux,uy,uz;       // +0x4C +0x50 +0x54
    UINT16      u16Flag;        // +0x58
    INT16       s16Parent;      // +0x5A
    INT16       s16Child;       // +0x5C
    INT16       s16Sibling;     // +0x5E
    UINT16      u16nStrip;      // +0x60
    UINT16      u16szStrip;     // +0x62
    DEF_STRIP*  pStrip;         // +0x64
    UINT8       u8Env1;         // +0x68
    UINT8       u8Env2;         // +0x69
    UINT8       u8spType;       // +0x6A
    UINT8       u8Env3;         // +0x6B
} DEF_MDL;

typedef struct _DEF_MDL_ENVMAP {
    char*       pName;      // +0x00
    UINT32      pad0;       // +0x04
    UINT32      pad1;       // +0x08
    UINT32      pad2;       // +0x0C
} DEF_MDL_ENVMAP;

typedef struct _DEF_MDL_FLOWLINE {
    ALG_VECTOR  vecStart;   // +0x00
    ALG_VECTOR  vecEnd;     // +0x10
    ALG_VECTOR  vecSide;    // +0x20

public:
    _DEF_MDL_FLOWLINE()
    {
        // TODO: decompile
    }

    _DEF_MDL_FLOWLINE& operator = ( const _DEF_MDL_FLOWLINE& ref )
    {
        // TODO: decompile
    }

} DEF_MDL_FLOWLINE;

// STATIC_ASSERT(sizeof(DEF_OBJ)          == 0x30);
// STATIC_ASSERT(sizeof(DEF_STRIP)        == 0x20);
// STATIC_ASSERT(sizeof(DEF_MDL)          == 0x6C); // or 0x70?
// STATIC_ASSERT(sizeof(DEF_MDL_ENVMAP)   == 0x10);
// STATIC_ASSERT(sizeof(DEF_MDL_FLOWLINE) == 0x30);

#endif // {{{ END OF FILE }}}
