package com.chinamobile.smartgateway.accessservices;

import org.osgi.framework.BundleContext;

public class AccessInfoQueryServiceImp implements AccessInfoQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native int getInternetWANIndexJni();
	public native String getWANIfListJni();
	public native int getPONIfUpTimeJni();
	public native String getWANIfStatsJni(int wanIndex);
	public native String getWANIfInfoJni(int wanIndex);
	public native String getWANIfStatusJni(int wanIndex);
	public native String getWanIfBandwidthJni(int wanIndex);
	public native String getPONIfPhyStatusJni();
	public native String getPONIfRegisterStatusJni();
	public native String getUplinkIfStatsJni();

	public int getInternetWANIndex(){
        return getInternetWANIndexJni();
    }
	public String getWANIfList(){
        return getWANIfListJni();
    }
	public int getPONIfUpTime(){
        return getPONIfUpTimeJni();
    }
	public String getWANIfStats(int wanIndex){
        return getWANIfStatsJni(wanIndex);
    }
	public String getWANIfInfo(int wanIndex){
        return getWANIfInfoJni(wanIndex);
    }
	public String getWANIfStatus(int wanIndex){
        return getWANIfStatusJni(wanIndex);
    }
	public String getWanIfBandwidth(int wanIndex){
        return getWanIfBandwidthJni(wanIndex);
    }
	public String getPONIfPhyStatus(){
        return getPONIfPhyStatusJni();
    }
	public String getPONIfRegisterStatus(){
        return getPONIfRegisterStatusJni();
    }
	public String getUplinkIfStats(){
        return getUplinkIfStatsJni();
    }
}
