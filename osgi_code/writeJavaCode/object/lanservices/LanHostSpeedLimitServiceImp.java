package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public class LanHostSpeedLimitServiceImp implements LanHostSpeedLimitService {

    static{
		System.loadLibrary("bundle");
	}

	public native int setLANHostSpeedLimitJni(String hostMAC, int upSpeed, int downSpeed);

	public int setLANHostSpeedLimit(String hostMAC, int upSpeed, int downSpeed){
        return setLANHostSpeedLimitJni(hostMAC, upSpeed, downSpeed);
    }
}
