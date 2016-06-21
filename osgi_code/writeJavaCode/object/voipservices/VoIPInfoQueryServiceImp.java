package com.chinamobile.smartgateway.voipservices;

import org.osgi.framework.BundleContext;

public class VoIPInfoQueryServiceImp implements VoIPInfoQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getPOTSInfoJni();

	public String getPOTSInfo(){
        return getPOTSInfoJni();
    }
}
