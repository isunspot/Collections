#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_setHTTPUserPassword(const int* response, char* passwordStr)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_setHTTPUserPassword: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_setHTTPUserPassword: leave============>\n");

    return ret;
}
