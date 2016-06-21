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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_lanservices_LanNetworkNameConfigServiceImp_setLANHostNameJni
(JNIEnv *env, jobject obj, jstring hostMAC, jstring hostName )
{
	int ret = 0;
	jint response = 0;
	const char* hostMACStr = NULL;
	const char* hostNameStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	hostMACStr = (char*)(*env)->GetStringUTFChars(env, hostMAC, NULL);
	hostNameStr = (char*)(*env)->GetStringUTFChars(env, hostName, NULL);

	ret = joyme_cmcc_setLANHostName(&response, hostMACStr, hostNameStr);


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
