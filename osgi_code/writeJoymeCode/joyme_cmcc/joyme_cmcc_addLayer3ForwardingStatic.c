#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_addLayer3ForwardingStatic(const int* response, char* DestIPAddressStr, char* DestSubnetMaskStr, char* GatewayIPAddressStr, char* InterfaceStr)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_addLayer3ForwardingStatic: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_addLayer3ForwardingStatic: leave============>\n");

    return ret;
}
