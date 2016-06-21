#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_setVLANBind(const int* response, char* lanInterfaceStr, char* bindStr)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_setVLANBind: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_setVLANBind: leave============>\n");

    return ret;
}
