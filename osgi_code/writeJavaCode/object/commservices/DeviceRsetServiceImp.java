package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public class DeviceRsetServiceImp implements DeviceRsetService {

    static{
		System.loadLibrary("bundle");
	}

	public native int resetJni();

	public int reset(){
        return resetJni();
    }
}
