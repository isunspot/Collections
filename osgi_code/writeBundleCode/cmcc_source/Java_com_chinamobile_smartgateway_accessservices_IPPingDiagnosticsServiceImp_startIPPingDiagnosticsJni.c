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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_accessservices_IPPingDiagnosticsServiceImp_startIPPingDiagnosticsJni
(JNIEnv *env, jobject obj, jint wanIndex, jstring host, jstring pingParameter )
{
	int ret = 0;
	jint response = 0;
	const char* hostStr = NULL;
	const char* pingParameterStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	hostStr = (char*)(*env)->GetStringUTFChars(env, host, NULL);
	pingParameterStr = (char*)(*env)->GetStringUTFChars(env, pingParameter, NULL);

	ret = joyme_cmcc_startIPPingDiagnostics(&response, wanIndex, hostStr, pingParameterStr);


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
