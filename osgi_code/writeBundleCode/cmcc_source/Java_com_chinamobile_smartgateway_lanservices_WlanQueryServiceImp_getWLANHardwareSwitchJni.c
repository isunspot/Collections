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

JNIEXPORT jboolean JNICALL Java_com_chinamobile_smartgateway_lanservices_WlanQueryServiceImp_getWLANHardwareSwitchJni
(JNIEnv *env, jobject obj, jstring radioType )
{
	int ret = 0;
	jboolean response = 0;
	const char* radioTypeStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	radioTypeStr = (char*)(*env)->GetStringUTFChars(env, radioType, NULL);

	ret = joyme_cmcc_getWLANHardwareSwitch(&response, radioTypeStr);


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
