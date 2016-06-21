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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_voipservices_VoIPInfoSubscribeServiceImp_subscribeVoIPEventJni
(JNIEnv *env, jobject obj, jstring context, jobjectArray Event )
{
	int ret = 0;
	jint response = 0;
	const char* contextStr = NULL;
	int i = 0;
	jstring str;
	const char *chars = NULL;
	int EventNum = 0;
	char *EventList[256] = {0};

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	contextStr = (char*)(*env)->GetStringUTFChars(env, context, NULL);
	EventNum = (*env)->GetArrayLength(env, Event);
	for (i=0; i<EventNum; i++)
    {
        EventList[i] = malloc(256 * sizeof(char));
        str = (jstring)(*env)->GetObjectArrayElement(env, Event, i);
        chars = (*env)->GetStringUTFChars(env, str, NULL);
        strncpy(EventList[i], chars, sizeof(EventList[i]));
        (*env)->ReleaseStringUTFChars(env, str, chars);
    }


	ret = joyme_cmcc_subscribeVoIPEvent(&response, contextStr, EventList, EventNum);

	for (i=0; i<EventNum; i++)
    {
        free(EventList[i]);
        EventList[i] = NULL;
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
