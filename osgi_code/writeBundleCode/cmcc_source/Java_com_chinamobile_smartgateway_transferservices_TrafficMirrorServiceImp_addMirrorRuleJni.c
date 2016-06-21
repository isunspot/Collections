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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_transferservices_TrafficMirrorServiceImp_addMirrorRuleJni
(JNIEnv *env, jobject obj, jstring remoteAddress, jstring remotePort, jstring direction, jstring protocol, jstring hostMAC, jstring mirrorToIP, jint mirrorToPort )
{
	int ret = 0;
	jint response = 0;
	const char* remoteAddressStr = NULL;
	const char* remotePortStr = NULL;
	const char* directionStr = NULL;
	const char* protocolStr = NULL;
	const char* hostMACStr = NULL;
	const char* mirrorToIPStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	remoteAddressStr = (char*)(*env)->GetStringUTFChars(env, remoteAddress, NULL);
	remotePortStr = (char*)(*env)->GetStringUTFChars(env, remotePort, NULL);
	directionStr = (char*)(*env)->GetStringUTFChars(env, direction, NULL);
	protocolStr = (char*)(*env)->GetStringUTFChars(env, protocol, NULL);
	hostMACStr = (char*)(*env)->GetStringUTFChars(env, hostMAC, NULL);
	mirrorToIPStr = (char*)(*env)->GetStringUTFChars(env, mirrorToIP, NULL);

	ret = joyme_cmcc_addMirrorRule(&response, remoteAddressStr, remotePortStr, directionStr, protocolStr, hostMACStr, mirrorToIPStr, mirrorToPort);


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
