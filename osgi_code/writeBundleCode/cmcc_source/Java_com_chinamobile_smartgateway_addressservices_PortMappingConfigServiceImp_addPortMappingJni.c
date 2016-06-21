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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_addressservices_PortMappingConfigServiceImp_addPortMappingJni
(JNIEnv *env, jobject obj, jint wanIndex, jint externalPort, jint internalPort, jstring portMappingProtocol, jstring internalClient )
{
	int ret = 0;
	jint response = 0;
	const char* portMappingProtocolStr = NULL;
	const char* internalClientStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	portMappingProtocolStr = (char*)(*env)->GetStringUTFChars(env, portMappingProtocol, NULL);
	internalClientStr = (char*)(*env)->GetStringUTFChars(env, internalClient, NULL);

	ret = joyme_cmcc_addPortMapping(&response, wanIndex, externalPort, internalPort, portMappingProtocolStr, internalClientStr);


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
