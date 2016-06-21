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

JNIEXPORT jint JNICALL Java_com_chinamobile_smartgateway_commservices_UsbServiceImp_usbReadJni
(JNIEnv *env, jobject obj, jint handle, jbyteArray buf, jint offset, jint count, jint timeout )
{
	int ret = 0;
	jint response = 0;
	jbyte* bufByte = NULL;

	joyme_printf(JOYME_INFO, "addTrafficMonitoringDestAddressJni: enter============>\n");

	bufByte = (*env)->GetByteArrayElements(env, buf, NULL);

	ret = joyme_cmcc_usbRead(&response, handle, bufByte, offset, count, timeout);

	(*env)->ReleaseByteArrayElements(env, buf, bufByte, 0);


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
