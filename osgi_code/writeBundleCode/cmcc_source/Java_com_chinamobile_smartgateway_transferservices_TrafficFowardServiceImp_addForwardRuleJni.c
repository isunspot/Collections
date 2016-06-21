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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_transferservices_TrafficFowardServiceImp_addForwardRuleJni
(JNIEnv *env, jobject obj, jstring remoteAddress, jstring remotePort, jstring protocol, jstring hostMAC, jstring forwardToIP, jint forwardToPort )
{
	int ret = 0;
	jint response = 0;
	const char* remoteAddressStr = NULL;
	const char* remotePortStr = NULL;
	const char* protocolStr = NULL;
	const char* hostMACStr = NULL;
	const char* forwardToIPStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	remoteAddressStr = (char*)(*env)->GetStringUTFChars(env, remoteAddress, NULL);
	remotePortStr = (char*)(*env)->GetStringUTFChars(env, remotePort, NULL);
	protocolStr = (char*)(*env)->GetStringUTFChars(env, protocol, NULL);
	hostMACStr = (char*)(*env)->GetStringUTFChars(env, hostMAC, NULL);
	forwardToIPStr = (char*)(*env)->GetStringUTFChars(env, forwardToIP, NULL);

	ret = joyme_cmcc_addForwardRule(&response, remoteAddressStr, remotePortStr, protocolStr, hostMACStr, forwardToIPStr, forwardToPort);


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
