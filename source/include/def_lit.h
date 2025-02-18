#ifndef __ZOE_DEF_LIT_H__
#define __ZOE_DEF_LIT_H__

#include "common.h"
#include "../libdg/libdg.h"

class DEF_LIGHT
{
public:
    INT32       nLight;     // +0x00
    UINT32      pad0;       // +0x04
    UINT32      pad1;       // +0x08
    UINT32      pad2;       // +0x0C
    DG_LIGHT    lit[];      // +0x10

public:
    DEF_LIGHT()
    {
        // TODO: decompile
    }
    ~DEF_LIGHT()
    {
        // TODO: decompile
    }

    DEF_LIGHT& operator = ( const DEF_LIGHT& ref )
    {
        // TODO: decompile
    }
};

// STATIC_ASSERT(sizeof(DEF_LIGHT) == 0x10);

#endif // {{{ END OF FILE }}}
