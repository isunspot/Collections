#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_setLANDHCPInfo(const int* response, char* enableDHCPServerStr, char* DHCPStartIPStr, char* DHCPEndIPStr, int DHCPDuration)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_setLANDHCPInfo: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_setLANDHCPInfo: leave============>\n");

    return ret;
}
