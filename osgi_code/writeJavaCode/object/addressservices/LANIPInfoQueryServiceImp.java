package com.chinamobile.smartgateway.addressservices;

import org.osgi.framework.BundleContext;

public class LANIPInfoQueryServiceImp implements LANIPInfoQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getLANDHCPInfoJni();
	public native String getLANHostIPJni();

	public String getLANDHCPInfo(){
        return getLANDHCPInfoJni();
    }
	public String getLANHostIP(){
        return getLANHostIPJni();
    }
}
