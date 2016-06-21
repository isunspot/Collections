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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_commservices_DeviceAccessRightConfigServiceImp_addSambaAccountJni
(JNIEnv *env, jobject obj, jstring username, jstring password )
{
	int ret = 0;
	jint response = 0;
	const char* usernameStr = NULL;
	const char* passwordStr = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	usernameStr = (char*)(*env)->GetStringUTFChars(env, username, NULL);
	passwordStr = (char*)(*env)->GetStringUTFChars(env, password, NULL);

	ret = joyme_cmcc_addSambaAccount(&response, usernameStr, passwordStr);


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
