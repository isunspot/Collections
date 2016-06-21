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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_addressservices_LANIPConfigServiceImp_setLANDHCPInfoJni
(JNIEnv *env, jobject obj, jstring enableDHCPServer, jstring DHCPStartIP, jstring DHCPEndIP, jint DHCPDuration )
{
	int ret = 0;
	jint response = 0;
	const char* enableDHCPServerStr = NULL;
	const char* DHCPStartIPStr = NULL;
	const char* DHCPEndIPStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	enableDHCPServerStr = (char*)(*env)->GetStringUTFChars(env, enableDHCPServer, NULL);
	DHCPStartIPStr = (char*)(*env)->GetStringUTFChars(env, DHCPStartIP, NULL);
	DHCPEndIPStr = (char*)(*env)->GetStringUTFChars(env, DHCPEndIP, NULL);

	ret = joyme_cmcc_setLANDHCPInfo(&response, enableDHCPServerStr, DHCPStartIPStr, DHCPEndIPStr, DHCPDuration);


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
