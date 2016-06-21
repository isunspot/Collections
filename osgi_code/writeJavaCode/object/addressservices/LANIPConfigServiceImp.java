package com.chinamobile.smartgateway.addressservices;

import org.osgi.framework.BundleContext;

public class LANIPConfigServiceImp implements LANIPConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native int setLANHostIPJni(String localIP, String submask);
	public native int setLANDHCPInfoJni(String enableDHCPServer, String DHCPStartIP, String DHCPEndIP, int DHCPDuration);

	public int setLANHostIP(String localIP, String submask){
        return setLANHostIPJni(localIP, submask);
    }
	public int setLANDHCPInfo(String enableDHCPServer, String DHCPStartIP, String DHCPEndIP, int DHCPDuration){
        return setLANDHCPInfoJni(enableDHCPServer, DHCPStartIP, DHCPEndIP, DHCPDuration);
    }
}
