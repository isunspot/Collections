#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_deleteWANIf(const int* response, int wanIndex)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_deleteWANIf: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_deleteWANIf: leave============>\n");

    return ret;
}
