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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_accessservices_WanConfigServiceImp_addWANIfJni
(JNIEnv *env, jobject obj, jstring VLANMode, jstring VLANIDMark, jstring ConnectionType )
{
	int ret = 0;
	jint response = 0;
	const char* VLANModeStr = NULL;
	const char* VLANIDMarkStr = NULL;
	const char* ConnectionTypeStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	VLANModeStr = (char*)(*env)->GetStringUTFChars(env, VLANMode, NULL);
	VLANIDMarkStr = (char*)(*env)->GetStringUTFChars(env, VLANIDMark, NULL);
	ConnectionTypeStr = (char*)(*env)->GetStringUTFChars(env, ConnectionType, NULL);

	ret = joyme_cmcc_addWANIf(&response, VLANModeStr, VLANIDMarkStr, ConnectionTypeStr);


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
