package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public class VLANBindConfigServiceImp implements VLANBindConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native int setVLANBindJni(String lanInterface, String bind);
	public native int clearVLANBindJni(String lanInterface);

	public int setVLANBind(String lanInterface, String bind){
        return setVLANBindJni(lanInterface, bind);
    }
	public int clearVLANBind(String lanInterface){
        return clearVLANBindJni(lanInterface);
    }
}
