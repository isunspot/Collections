#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_deleteForwardRule(const int* response, int ruleNum)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_deleteForwardRule: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_deleteForwardRule: leave============>\n");

    return ret;
}
