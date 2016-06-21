package com.chinamobile.smartgateway.voipservices;

import org.osgi.framework.BundleContext;

public class VoIPInfoSubscribeServiceImp implements VoIPInfoSubscribeService {

    static{
		System.loadLibrary("bundle");
	}

	public native int subscribeVoIPEventJni(BundleContext context, String[] Event);
	public native int unSubscribeVoIPEventJni(BundleContext context, String[] Event);

	public int subscribeVoIPEvent(BundleContext context, String[] Event){
        return subscribeVoIPEventJni(context, Event);
    }
	public int unSubscribeVoIPEvent(BundleContext context, String[] Event){
        return unSubscribeVoIPEventJni(context, Event);
    }
}
