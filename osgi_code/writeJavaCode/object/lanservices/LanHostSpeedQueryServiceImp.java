package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public class LanHostSpeedQueryServiceImp implements LanHostSpeedQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getLANHostSpeedJni(String hostMAC);

	public String getLANHostSpeed(String hostMAC){
        return getLANHostSpeedJni(hostMAC);
    }
}
