#ifndef __ZOE_COMMON_H__
#define __ZOE_COMMON_H__

#include <stddef.h>
#include <sys/types.h>
#include <eetypes.h>

/*---------------------------------------------------------------------------*/
// https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html

#if defined(__GNUC__)
#if defined(__GNUC_PATCHLEVEL__) // GCC 3.0
#  define GCC_VERSION ((__GNUC__       * 10000)\
                      +(__GNUC_MINOR__ *   100)\
                      +(__GNUC_PATCHLEVEL__))
#else
#  define GCC_VERSION ((__GNUC__       * 10000)\
                      +(__GNUC_MINOR__ *   100))
#endif // __GNUC_PATCHLEVEL__
#else
#  define GCC_VERSION 0
#endif // __GNUC__

/* Macro to test version of GCC.  Returns 0 for non-GCC or too old GCC. */
#ifndef __GNUC_PREREQ
#  if defined(__GNUC__) && defined(__GNUC_MINOR__)
#    define __GNUC_PREREQ(maj, min) \
        ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#  else
#    define __GNUC_PREREQ(maj, min) 0
#  endif
#endif
/* Version with trailing underscores for BSD compatibility. */
#ifndef __GNUC_PREREQ__
#define __GNUC_PREREQ__(maj, min) __GNUC_PREREQ(maj, min)
#endif

/*---------------------------------------------------------------------------*/

#ifndef MIN
#define MIN(x, y)       (((x) < (y)) ? (x) : (y))
#endif
#ifndef MAX
#define MAX(x, y)       (((x) > (y)) ? (x) : (y))
#endif
#ifndef ABS
#define ABS(x)          (((x) >= 0) ? (x) : -(x))
#endif

#ifndef CLAMP
#define CLAMP(x, min, max) (MAX(MIN(x, max), min))
#endif

#ifndef _countof
#define _countof(array) (sizeof(array)/sizeof(array[0]))
#endif
#define countof(array)  _countof(array)
#define COUNTOF(array)  _countof(array)

#define PACKED          __attribute__((packed))
#define ALIGN(_x)       __attribute__((aligned(_x)))
#define ALIGN8          ALIGN(8)
#define ALIGN16         ALIGN(16)
#define ALIGN64         ALIGN(64)
#define ALIGN128        ALIGN(128)

/*---------------------------------------------------------------------------*/

#define HANGUP()        (*(int *)1 = 0)

#if 0
#define ASSERT(cond)                                            \
    if (!(cond)) {                                              \
        printf("Assertion failed: file %s, line %d\n", __FILE__, __LINE__); \
        MTS_Panic();                                            \
        /* todo: decompile (C++ stuff?) */                      \
    }
#else
#define ASSERT(cond, _file, _line)                              \
    if (!(cond)) {                                              \
        printf("Assertion failed: file %s, line %d\n", _file, _line); \
        MTS_Panic();                                            \
        /* todo: decompile (C++ stuff?) */                      \
    }
#endif

/*---------------------------------------------------------------------------*/
// https://en.cppreference.com/w/c/language/arithmetic_types#Boolean_type
// NOTE: (bool)0.5 evaluates to true, whereas (int)0.5 evaluates to 0.

typedef int             BOOL;

#ifndef FALSE
#define FALSE           (0)
#endif
#ifndef TRUE
#define TRUE            (!FALSE)
#endif

/*---------------------------------------------------------------------------*/

typedef signed char     INT8;           //  8-bit signed integer
typedef signed short    INT16;          // 16-bit signed integer
typedef signed int      INT32;          // 32-bit signed integer
typedef signed long     INT64;          // 64-bit signed integer

typedef unsigned char   UINT8;          //  8-bit unsigned integer
typedef unsigned short  UINT16;         // 16-bit unsigned integer
typedef unsigned int    UINT32;         // 32-bit unsigned integer
typedef unsigned long   UINT64;         // 64-bit unsigned integer

// https://gcc.gnu.org/onlinedocs/gcc/_005f_005fint128.html
// https://gcc.gnu.org/onlinedocs/gccint/Machine-Modes.html

typedef long128         INT128;         // 128-bit signed integer
typedef u_long128       UINT128;        // 128-bit unsigned integer

/*---------------------------------------------------------------------------*/

typedef union DAT64 {
    UINT64  u64;        // 64-bit unsigned integer
    UINT32  u32[2];     // 32-bit unsigned integer
    UINT16  u16[4];     // 16-bit unsigned integer
    UINT8   u8[8];      //  8-bit unsigned integer
    float   f[2];       // 32-bit floating point
} ALIGN8 DAT64;

typedef union DAT128 {
    UINT128 u128;       // 128-bit unsigned integer
    UINT64  u64[2];     //  64-bit unsigned integer
    UINT32  u32[4];     //  32-bit unsigned integer
    UINT16  u16[8];     //  16-bit unsigned integer
    UINT8   u8[16];     //   8-bit unsigned integer
    float   f[4];       //  32-bit floating point
} ALIGN16 DAT128;

typedef struct FVECTOR {
    float vx;
    float vy;
    float vz;
    float vw;
} ALIGN16 FVECTOR;

typedef struct FMATRIX {
    float m[4][4];
} ALIGN16 FMATRIX;

#endif // {{{ END OF FILE }}}
