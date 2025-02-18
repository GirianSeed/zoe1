#include <stddef.h>
#include <libdma.h>

// CXXFLAGS = -G0 -O2 -fno-exceptions

static void *pcurProgDma = NULL;

void FS_UploadVu0Program( void *pDmaTag )
{
    sceDmaChan *pDmaVif0;

    if (pcurProgDma != pDmaTag)
    {
        pDmaVif0 = sceDmaGetChan( SCE_DMA_VIF0 );
        pDmaVif0->chcr.TTE = 1;

        sceDmaSend( pDmaVif0, pDmaTag );
        sceDmaSync( pDmaVif0, 0, 0 );
    }
}
