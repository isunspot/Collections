#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_usbWrite(const int* response, int handle, void* bufByte, int offset, int count)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_usbWrite: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_usbWrite: leave============>\n");

    return ret;
}
