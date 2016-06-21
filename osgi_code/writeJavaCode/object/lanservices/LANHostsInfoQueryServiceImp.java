package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public class LANHostsInfoQueryServiceImp implements LANHostsInfoQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getLANHostInfoByInterfaceJni(String ConnectInterface);
	public native int getMacFilterModeJni();
	public native String getLANHostInfoByClassJni(String hostClass);
	public native String getLANHostSpeedLimitInfoJni(String[] hostMAC);
	public native String getLANHostInfoByMACJni(String[] hostMAC);
	public native String getGatewayNameJni();
	public native String getLANHostStatsJni(String[] hostMAC);

	public String getLANHostInfoByInterface(String ConnectInterface){
        return getLANHostInfoByInterfaceJni(ConnectInterface);
    }
	public int getMacFilterMode(){
        return getMacFilterModeJni();
    }
	public String getLANHostInfoByClass(String hostClass){
        return getLANHostInfoByClassJni(hostClass);
    }
	public String getLANHostSpeedLimitInfo(String[] hostMAC){
        return getLANHostSpeedLimitInfoJni(hostMAC);
    }
	public String getLANHostInfoByMAC(String[] hostMAC){
        return getLANHostInfoByMACJni(hostMAC);
    }
	public String getGatewayName(){
        return getGatewayNameJni();
    }
	public String getLANHostStats(String[] hostMAC){
        return getLANHostStatsJni(hostMAC);
    }
}
