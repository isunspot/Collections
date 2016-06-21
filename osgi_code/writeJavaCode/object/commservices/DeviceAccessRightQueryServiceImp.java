package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public class DeviceAccessRightQueryServiceImp implements DeviceAccessRightQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getSambaRightInfoJni();
	public native String getHTTPRightInfoJni();
	public native String getFTPRightInfoJni();

	public String getSambaRightInfo(){
        return getSambaRightInfoJni();
    }
	public String getHTTPRightInfo(){
        return getHTTPRightInfoJni();
    }
	public String getFTPRightInfo(){
        return getFTPRightInfoJni();
    }
}
