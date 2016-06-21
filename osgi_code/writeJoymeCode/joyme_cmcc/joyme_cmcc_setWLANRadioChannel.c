#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_setWLANRadioChannel(const int* response, char* radioTypeStr, int channel)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_setWLANRadioChannel: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_setWLANRadioChannel: leave============>\n");

    return ret;
}
