package com.chinamobile.smartgateway.addressservices;

import org.osgi.framework.BundleContext;

public class PortMappingQueryServiceImp implements PortMappingQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getPortMappingInfoJni();

	public String getPortMappingInfo(){
        return getPortMappingInfoJni();
    }
}
