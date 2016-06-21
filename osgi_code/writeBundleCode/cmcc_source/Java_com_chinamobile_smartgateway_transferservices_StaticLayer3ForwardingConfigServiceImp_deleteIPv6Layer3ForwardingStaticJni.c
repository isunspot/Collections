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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_transferservices_StaticLayer3ForwardingConfigServiceImp_deleteIPv6Layer3ForwardingStaticJni
(JNIEnv *env, jobject obj, jint index )
{
	int ret = 0;
	jint response = 0;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");


	ret = joyme_cmcc_deleteIPv6Layer3ForwardingStatic(&response, index);


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
