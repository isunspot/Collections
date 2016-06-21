#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_setWLANGuestDuration(const int* response, int guestSsidIndex, int duration)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_setWLANGuestDuration: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_setWLANGuestDuration: leave============>\n");

    return ret;
}
