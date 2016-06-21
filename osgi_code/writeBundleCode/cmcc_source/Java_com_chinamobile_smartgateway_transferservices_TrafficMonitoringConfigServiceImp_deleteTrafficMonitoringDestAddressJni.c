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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_transferservices_TrafficMonitoringConfigServiceImp_deleteTrafficMonitoringDestAddressJni
(JNIEnv *env, jobject obj, jobjectArray destAddressList, jstring context )
{
	int ret = 0;
	jint response = 0;
	int i = 0;
	jstring str;
	const char *chars = NULL;
	int destAddressListNum = 0;
	char *destAddressListList[256] = {0};
	const char* contextStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	destAddressListNum = (*env)->GetArrayLength(env, destAddressList);
	for (i=0; i<destAddressListNum; i++)
    {
        destAddressListList[i] = malloc(256 * sizeof(char));
        str = (jstring)(*env)->GetObjectArrayElement(env, destAddressList, i);
        chars = (*env)->GetStringUTFChars(env, str, NULL);
        strncpy(destAddressListList[i], chars, sizeof(destAddressListList[i]));
        (*env)->ReleaseStringUTFChars(env, str, chars);
    }

	contextStr = (char*)(*env)->GetStringUTFChars(env, context, NULL);

	ret = joyme_cmcc_deleteTrafficMonitoringDestAddress(&response, destAddressListList, destAddressListNum, contextStr);

	for (i=0; i<destAddressListNum; i++)
    {
        free(destAddressListList[i]);
        destAddressListList[i] = NULL;
    }


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
