package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public class WlanSecretQueryServiceImp implements WlanSecretQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getWLANSSIDPasswordJni(int ssidIndex);

	public String getWLANSSIDPassword(int ssidIndex){
        return getWLANSSIDPasswordJni(ssidIndex);
    }
}
