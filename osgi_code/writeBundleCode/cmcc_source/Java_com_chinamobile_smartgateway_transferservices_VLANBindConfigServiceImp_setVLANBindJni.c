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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_transferservices_VLANBindConfigServiceImp_setVLANBindJni
(JNIEnv *env, jobject obj, jstring lanInterface, jstring bind )
{
	int ret = 0;
	jint response = 0;
	const char* lanInterfaceStr = NULL;
	const char* bindStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	lanInterfaceStr = (char*)(*env)->GetStringUTFChars(env, lanInterface, NULL);
	bindStr = (char*)(*env)->GetStringUTFChars(env, bind, NULL);

	ret = joyme_cmcc_setVLANBind(&response, lanInterfaceStr, bindStr);


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
