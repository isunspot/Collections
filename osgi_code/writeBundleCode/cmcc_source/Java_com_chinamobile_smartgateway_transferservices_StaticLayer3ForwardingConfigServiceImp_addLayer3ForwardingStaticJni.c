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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_transferservices_StaticLayer3ForwardingConfigServiceImp_addLayer3ForwardingStaticJni
(JNIEnv *env, jobject obj, jstring DestIPAddress, jstring DestSubnetMask, jstring GatewayIPAddress, jstring Interface )
{
	int ret = 0;
	jint response = 0;
	const char* DestIPAddressStr = NULL;
	const char* DestSubnetMaskStr = NULL;
	const char* GatewayIPAddressStr = NULL;
	const char* InterfaceStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	DestIPAddressStr = (char*)(*env)->GetStringUTFChars(env, DestIPAddress, NULL);
	DestSubnetMaskStr = (char*)(*env)->GetStringUTFChars(env, DestSubnetMask, NULL);
	GatewayIPAddressStr = (char*)(*env)->GetStringUTFChars(env, GatewayIPAddress, NULL);
	InterfaceStr = (char*)(*env)->GetStringUTFChars(env, Interface, NULL);

	ret = joyme_cmcc_addLayer3ForwardingStatic(&response, DestIPAddressStr, DestSubnetMaskStr, GatewayIPAddressStr, InterfaceStr);


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
