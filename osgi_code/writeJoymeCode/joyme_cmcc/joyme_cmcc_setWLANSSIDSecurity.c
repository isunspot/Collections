#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_setWLANSSIDSecurity(const int* response, int ssidIndex, char* encryptionModeStr, char* passwordStr)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_setWLANSSIDSecurity: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_setWLANSSIDSecurity: leave============>\n");

    return ret;
}
