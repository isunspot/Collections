#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_setFTPRight(const int* response, int right, int anonymous)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_setFTPRight: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_setFTPRight: leave============>\n");

    return ret;
}
