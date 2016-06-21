package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public class StaticLayer3ForwardingConfigServiceImp implements StaticLayer3ForwardingConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native int deleteLayer3ForwardingStaticJni(String DestIPPrefix, String NextHop, String Interface);
	public native int deleteIPv6Layer3ForwardingStaticJni(int index);
	public native int addLayer3ForwardingStaticJni(String DestIPAddress, String DestSubnetMask, String GatewayIPAddress, String Interface);
	public native int addIPv6Layer3ForwardingStaticJni(int index);

	public int deleteLayer3ForwardingStatic(String DestIPPrefix, String NextHop, String Interface){
        return deleteLayer3ForwardingStaticJni(DestIPPrefix, NextHop, Interface);
    }
	public int deleteIPv6Layer3ForwardingStatic(int index){
        return deleteIPv6Layer3ForwardingStaticJni(index);
    }
	public int addLayer3ForwardingStatic(String DestIPAddress, String DestSubnetMask, String GatewayIPAddress, String Interface){
        return addLayer3ForwardingStaticJni(DestIPAddress, DestSubnetMask, GatewayIPAddress, Interface);
    }
	public int addIPv6Layer3ForwardingStatic(int index){
        return addIPv6Layer3ForwardingStaticJni(index);
    }
}
