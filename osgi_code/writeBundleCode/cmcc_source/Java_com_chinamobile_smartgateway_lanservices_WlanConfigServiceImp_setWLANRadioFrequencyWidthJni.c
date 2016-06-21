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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_lanservices_WlanConfigServiceImp_setWLANRadioFrequencyWidthJni
(JNIEnv *env, jobject obj, jstring radioType, jstring frequencyWidth )
{
	int ret = 0;
	jint response = 0;
	const char* radioTypeStr = NULL;
	const char* frequencyWidthStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	radioTypeStr = (char*)(*env)->GetStringUTFChars(env, radioType, NULL);
	frequencyWidthStr = (char*)(*env)->GetStringUTFChars(env, frequencyWidth, NULL);

	ret = joyme_cmcc_setWLANRadioFrequencyWidth(&response, radioTypeStr, frequencyWidthStr);


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
