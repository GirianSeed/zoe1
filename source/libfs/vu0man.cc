#include <stddef.h>
#include <libdma.h>

static void *pcurProgDma = NULL;

void FS_UploadVu0Program( void *pDmaTag )
{
    sceDmaChan *pDmaVif0;

    if (pDmaTag != pcurProgDma)
    {
        pDmaVif0 = sceDmaGetChan( SCE_DMA_VIF0 );
        pDmaVif0->chcr.TTE = 1;

        sceDmaSend( pDmaVif0, pDmaTag );
        sceDmaSync( pDmaVif0, 0, 0 );
    }
}
