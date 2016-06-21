#include "joyme_cmcc.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;


int joyme_cmcc_usbSetSerial(const int* response, int handle, int bandRate, int parity, int dataBits, int stopBits, int hwFlowCtrl, int swFlowCtl)
{
    int ret = 0;

    joyme_printf(JOYME_INFO, "joy_cmcc_usbSetSerial: enter============>\n");


    // please erasure this line and write someting.


    joyme_printf(JOYME_INFO, "joy_cmcc_usbSetSerial: leave============>\n");

    return ret;
}
