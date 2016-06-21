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

JNIEXPORT jstring JNICALL Java_com_chinamobile_smartgateway_lanservices_LANHostsInfoQueryServiceImp_getLANHostStatsJni
(JNIEnv *env, jobject obj, jobjectArray hostMAC )
{
	int ret = 0;
	jstring reply;
	char response[4096] = "";
	int i = 0;
	jstring str;
	const char *chars = NULL;
	int hostMACNum = 0;
	char *hostMACList[256] = {0};

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	hostMACNum = (*env)->GetArrayLength(env, hostMAC);
	for (i=0; i<hostMACNum; i++)
    {
        hostMACList[i] = malloc(256 * sizeof(char));
        str = (jstring)(*env)->GetObjectArrayElement(env, hostMAC, i);
        chars = (*env)->GetStringUTFChars(env, str, NULL);
        strncpy(hostMACList[i], chars, sizeof(hostMACList[i]));
        (*env)->ReleaseStringUTFChars(env, str, chars);
    }


	ret = joyme_cmcc_getLANHostStats(response, hostMACList, hostMACNum);

	for (i=0; i<hostMACNum; i++)
    {
        free(hostMACList[i]);
        hostMACList[i] = NULL;
    }


    if (0 == ret)
    {
        joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: leave============>OK\n");
    }
    else
    {
        joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: leave============>ERROR\n");
    }

	reply = (*env)->NewStringUTF(env, response);
	return reply;
}
