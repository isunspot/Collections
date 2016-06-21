#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jni.h"
#include "joyme.h"
#include "joyme_cmcc.h"
#include "cmcc_include.h"

typedef enum {
	JOYME_NONE = 0,
	JOYME_ERR,
	JOYME_INFO,
	JOYME_DEBUG,
	JOYME_ALL
} DebugLevel;

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_lanservices_LanHostSpeedLimitServiceImp_setLANHostSpeedLimitJni
(JNIEnv *env, jobject obj, jstring hostMAC, jint upSpeed, jint downSpeed )
{
	int ret = 0;
	jint response = 0;
	const char* hostMACStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	hostMACStr = (char*)(*env)->GetStringUTFChars(env, hostMAC, NULL);

	ret = joyme_cmcc_setLANHostSpeedLimit(&response, hostMACStr, upSpeed, downSpeed);


    if (0 == ret)
    {
        joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: leave============>OK\n");
    }
    else
    {
        joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: leave============>ERROR\n");
    }

	return response;
}
