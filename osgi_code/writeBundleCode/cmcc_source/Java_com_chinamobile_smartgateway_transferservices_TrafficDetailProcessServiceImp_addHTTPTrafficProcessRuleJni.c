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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_transferservices_TrafficDetailProcessServiceImp_addHTTPTrafficProcessRuleJni
(JNIEnv *env, jobject obj, jstring remoteAddress, jint remotePort, jstring direction, jstring hostMAC, jobjectArray methodList, jobjectArray statuscodeList, jobjectArray headerList, jstring context )
{
	int ret = 0;
	jint response = 0;
	const char* remoteAddressStr = NULL;
	const char* directionStr = NULL;
	const char* hostMACStr = NULL;
	int i = 0;
	jstring str;
	const char *chars = NULL;
	int methodListNum = 0;
	char *methodListList[256] = {0};
	int statuscodeListNum = 0;
	char *statuscodeListList[256] = {0};
	int headerListNum = 0;
	char *headerListList[256] = {0};
	const char* contextStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	remoteAddressStr = (char*)(*env)->GetStringUTFChars(env, remoteAddress, NULL);
	directionStr = (char*)(*env)->GetStringUTFChars(env, direction, NULL);
	hostMACStr = (char*)(*env)->GetStringUTFChars(env, hostMAC, NULL);
	methodListNum = (*env)->GetArrayLength(env, methodList);
	for (i=0; i<methodListNum; i++)
    {
        methodListList[i] = malloc(256 * sizeof(char));
        str = (jstring)(*env)->GetObjectArrayElement(env, methodList, i);
        chars = (*env)->GetStringUTFChars(env, str, NULL);
        strncpy(methodListList[i], chars, sizeof(methodListList[i]));
        (*env)->ReleaseStringUTFChars(env, str, chars);
    }

	statuscodeListNum = (*env)->GetArrayLength(env, statuscodeList);
	for (i=0; i<statuscodeListNum; i++)
    {
        statuscodeListList[i] = malloc(256 * sizeof(char));
        str = (jstring)(*env)->GetObjectArrayElement(env, statuscodeList, i);
        chars = (*env)->GetStringUTFChars(env, str, NULL);
        strncpy(statuscodeListList[i], chars, sizeof(statuscodeListList[i]));
        (*env)->ReleaseStringUTFChars(env, str, chars);
    }

	headerListNum = (*env)->GetArrayLength(env, headerList);
	for (i=0; i<headerListNum; i++)
    {
        headerListList[i] = malloc(256 * sizeof(char));
        str = (jstring)(*env)->GetObjectArrayElement(env, headerList, i);
        chars = (*env)->GetStringUTFChars(env, str, NULL);
        strncpy(headerListList[i], chars, sizeof(headerListList[i]));
        (*env)->ReleaseStringUTFChars(env, str, chars);
    }

	contextStr = (char*)(*env)->GetStringUTFChars(env, context, NULL);

	ret = joyme_cmcc_addHTTPTrafficProcessRule(&response, remoteAddressStr, remotePort, directionStr, hostMACStr, methodListList, methodListNum, statuscodeListList, statuscodeListNum, headerListList, headerListNum, contextStr);

	for (i=0; i<methodListNum; i++)
    {
        free(methodListList[i]);
        methodListList[i] = NULL;
    }

	for (i=0; i<statuscodeListNum; i++)
    {
        free(statuscodeListList[i]);
        statuscodeListList[i] = NULL;
    }

	for (i=0; i<headerListNum; i++)
    {
        free(headerListList[i]);
        headerListList[i] = NULL;
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
