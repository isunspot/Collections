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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_addressservices_LANIPConfigServiceImp_setLANHostIPJni
(JNIEnv *env, jobject obj, jstring localIP, jstring submask )
{
	int ret = 0;
	jint response = 0;
	const char* localIPStr = NULL;
	const char* submaskStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	localIPStr = (char*)(*env)->GetStringUTFChars(env, localIP, NULL);
	submaskStr = (char*)(*env)->GetStringUTFChars(env, submask, NULL);

	ret = joyme_cmcc_setLANHostIP(&response, localIPStr, submaskStr);


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
