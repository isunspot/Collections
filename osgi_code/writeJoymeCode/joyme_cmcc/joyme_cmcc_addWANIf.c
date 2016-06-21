#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_addWANIf(const int* response, char* VLANModeStr, char* VLANIDMarkStr, char* ConnectionTypeStr)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_addWANIf: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_addWANIf: leave============>\n");

    return ret;
}
