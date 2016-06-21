package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public class TrafficMonitoringConfigServiceImp implements TrafficMonitoringConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getTrafficMonitoringDestAddressInfoJni();
	public native int addTrafficMonitoringDestAddressJni(String[] destAddressList, BundleContext context);
	public native int deleteTrafficMonitoringDestAddressJni(String[] destAddressList, BundleContext context);

	public String getTrafficMonitoringDestAddressInfo(){
        return getTrafficMonitoringDestAddressInfoJni();
    }
	public int addTrafficMonitoringDestAddress(String[] destAddressList, BundleContext context){
        return addTrafficMonitoringDestAddressJni(destAddressList, context);
    }
	public int deleteTrafficMonitoringDestAddress(String[] destAddressList, BundleContext context){
        return deleteTrafficMonitoringDestAddressJni(destAddressList, context);
    }
}
