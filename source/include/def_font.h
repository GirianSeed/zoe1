#ifndef __ZOE_DEF_FONT_H__
#define __ZOE_DEF_FONT_H__

#include "common.h"

typedef struct _DEF_HANKAKU_PROP {
    UINT16  u16width;       // +0x00
    UINT16  u16index;       // +0x02
} DEF_HANKAKU_PROP;

// Copied from "ZONE OF THE ENDERS HD EDITION" (PSN ver.)
// USRDIR/ZoE1/stage/title/ExtractSpacingInfo.rb
//
// Comments were (badly) machine-translated from Japanese.
// Should we translate these back?

// clang-format off
typedef struct _DEF_FONT_TABLE {
    UINT16  u16nTex;            // 00-01:The_number_of_Fontotekusuchadeta
    UINT16  u16SizeTex;         // 02-03:1Sentence_texture_data_size_characters
    UINT8   u8width;            // 04-04:Sumi_Tamotsu_width
    UINT8   u8height;
    UINT16  u16Kind;            // 06-07:Font_Type
    void*   pTexTop;            // 08-11:Top_Fontotekusuchadeta

    UINT16*             ptabIndex;          // 12-15:EUC -> Table_Index
    DEF_HANKAKU_PROP*   pHankakuPropTop;    // 16-19:The_top_half_of_the_property_data
    UINT32              pad1,pad2,pad3;     // 20-31:

    UINT32              u32ColClut[16];     // 32-96:CLUT Column_colors_(from_lowRGBA)
} DEF_FONT_TABLE ALIGN16;
// clang-format on

// STATIC_ASSERT(sizeof(DEF_HANKAKU_PROP) == 0x04);
// STATIC_ASSERT(sizeof(DEF_FONT_TABLE) == 0x60);

#endif // {{{ END OF FILE }}}
