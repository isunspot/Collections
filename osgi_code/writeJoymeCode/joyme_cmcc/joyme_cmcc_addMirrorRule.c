#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_addMirrorRule(const int* response, char* remoteAddressStr, char* remotePortStr, char* directionStr, char* protocolStr, char* hostMACStr, char* mirrorToIPStr, int mirrorToPort)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_addMirrorRule: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_addMirrorRule: leave============>\n");

    return ret;
}
