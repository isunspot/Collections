#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_usbRegister(const int* response, char* contextStr, int devTypes)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_usbRegister: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_usbRegister: leave============>\n");

    return ret;
}
