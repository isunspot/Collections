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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_transferservices_StaticLayer3ForwardingConfigServiceImp_deleteLayer3ForwardingStaticJni
(JNIEnv *env, jobject obj, jstring DestIPPrefix, jstring NextHop, jstring Interface )
{
	int ret = 0;
	jint response = 0;
	const char* DestIPPrefixStr = NULL;
	const char* NextHopStr = NULL;
	const char* InterfaceStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	DestIPPrefixStr = (char*)(*env)->GetStringUTFChars(env, DestIPPrefix, NULL);
	NextHopStr = (char*)(*env)->GetStringUTFChars(env, NextHop, NULL);
	InterfaceStr = (char*)(*env)->GetStringUTFChars(env, Interface, NULL);

	ret = joyme_cmcc_deleteLayer3ForwardingStatic(&response, DestIPPrefixStr, NextHopStr, InterfaceStr);


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
