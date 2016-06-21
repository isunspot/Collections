package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public class LanNetworkNameConfigServiceImp implements LanNetworkNameConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native int setGatewayNameJni(String name);
	public native int setLANHostNameJni(String hostMAC, String hostName);

	public int setGatewayName(String name){
        return setGatewayNameJni(name);
    }
	public int setLANHostName(String hostMAC, String hostName){
        return setLANHostNameJni(hostMAC, hostName);
    }
}
