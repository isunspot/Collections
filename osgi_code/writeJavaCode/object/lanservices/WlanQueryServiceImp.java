package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public class WlanQueryServiceImp implements WlanQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getWLANNeighborJni(String radioType);
	public native String getWLANSSIDStatsJni(int ssidIndex);
	public native String getWLANRadioInfoJni(String radioType);
	public native String getWLANHostInfoJni(String[] hostMAC);
	public native String getWLANSSIDInfoJni(int ssidIndex);
	public native String getGuestSSIDInfoJni();
	public native int getWLANWPSStatusJni(int ssidIndex);
	public native boolean getWLANHardwareSwitchJni(String radioType);

	public String getWLANNeighbor(String radioType){
        return getWLANNeighborJni(radioType);
    }
	public String getWLANSSIDStats(int ssidIndex){
        return getWLANSSIDStatsJni(ssidIndex);
    }
	public String getWLANRadioInfo(String radioType){
        return getWLANRadioInfoJni(radioType);
    }
	public String getWLANHostInfo(String[] hostMAC){
        return getWLANHostInfoJni(hostMAC);
    }
	public String getWLANSSIDInfo(int ssidIndex){
        return getWLANSSIDInfoJni(ssidIndex);
    }
	public String getGuestSSIDInfo(){
        return getGuestSSIDInfoJni();
    }
	public int getWLANWPSStatus(int ssidIndex){
        return getWLANWPSStatusJni(ssidIndex);
    }
	public boolean getWLANHardwareSwitch(String radioType){
        return getWLANHardwareSwitchJni(radioType);
    }
}
