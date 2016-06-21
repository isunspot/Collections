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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_accessservices_TraceRouteDiagnosticsServiceImp_startTraceRouteDiagnosticsJni
(JNIEnv *env, jobject obj, jint wanIndex, jstring host, jstring traceRouterParameter )
{
	int ret = 0;
	jint response = 0;
	const char* hostStr = NULL;
	const char* traceRouterParameterStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	hostStr = (char*)(*env)->GetStringUTFChars(env, host, NULL);
	traceRouterParameterStr = (char*)(*env)->GetStringUTFChars(env, traceRouterParameter, NULL);

	ret = joyme_cmcc_startTraceRouteDiagnostics(&response, wanIndex, hostStr, traceRouterParameterStr);


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
