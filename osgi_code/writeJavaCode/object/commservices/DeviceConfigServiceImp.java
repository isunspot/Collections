package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public class DeviceConfigServiceImp implements DeviceConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native int setLedSwitchJni(boolean enableState);

	public int setLedSwitch(boolean enableState){
        return setLedSwitchJni(enableState);
    }
}
