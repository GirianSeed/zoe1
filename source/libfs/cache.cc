#include "common.h"

#if 0
#include "libfs.h"

static FS_CACHEMEMBER mbNonRsdnt[128];
static FS_CACHEMEMBER mbResident[128];
static FS_CACHE chNonRsdnt;
static FS_CACHE chResident;

FS_CACHEMEMBER* FS_CACHE::Find( UINT32 u32Id )
{
    int mod;
    FS_CACHEMEMBER *pMb;
    int i;
    // todo: decompile
}

void FS_CACHE::Shift( FS_CACHEMEMBER *pMb )
{
    UINT32 mod;
    FS_CACHEMEMBER *pMbPre;
    // todo: decompile
}

void FS_CACHE::Init( FS_CACHEMEMBER *pMemberp, int sizep )
{
    FS_CACHEMEMBER *pMb;
    int i;
    // todo: decompile
}

void FS_CACHE::Set( UINT32 u32Id, void *pBuf )
{
    int mod;
    FS_CACHEMEMBER *pMb;
    int i;
    // todo: decompile
}

void *FS_CACHE::Get( UINT32 u32Id )
{
    FS_CACHEMEMBER *pMb;
    // todo: decompile
}

void FS_CACHE::Unset( UINT32 u32Id )
{
    FS_CACHEMEMBER *pMb;
    // todo: decompile
}

void FS_CACHE::Destroy()
{
    // todo: decompile
}

void FS_InitCacheSystem()
{
    chNonRsdnt.Init( &mbNonRsdnt, sizeof(mbNonRsdnt) );
    chResident.Init( &mbResident, sizeof(mbResident) );
}

void FS_SetCache( UINT32 u32Id, void *pBuf, UINT32 u32Mode )
{
    if (u32Mode != 0)
        chResident.Set( u32Id, pBuf );
    else
        chNonRsdnt.Set( u32Id, pBuf );
}

void *FS_GetCache( UINT32 u32Id )
{
    void *pBuf;
    // todo: decompile
}

void FS_UnsetCache( UINT32 u32Id )
{
    // todo: decompile
}

void FS_DestroyOldCache()
{
    chNonRsdnt.Destroy();
}
#endif // 0

//-----------------------------------------------------------------------------
//!
//! @brief      3rd-generation string-hashing function.
//!             Originally from "ZONE OF THE ENDERS" (2001).
//!
//! Returns a 32-bit hash of a given string, or "string code."
//! This algorithm is used for referencing various resoureces in place of
//! direct string comparisons, helping to optimize memory accesses.
//!
//! @param      str         NULL-terminated string.
//!
//! @retval     0           if @p string is empty.
//! @retval     non-zero    32-bit hash of @p string.
//!
UINT32 FS_StrCode( char *str )
{
    UINT32 c;
    INT32  n = 0;
    UINT32 id = 0;

    while (( c = *str++ ))
    {
        id += ((id << (c & 0x0f)) | ((id >> 3) + (c << (n & 0x0f)) + c));
        n++;
    }
    return id;
}
