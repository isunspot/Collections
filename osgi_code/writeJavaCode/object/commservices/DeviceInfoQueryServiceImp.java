package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public class DeviceInfoQueryServiceImp implements DeviceInfoQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getJVMInfoJni();
	public native int getCPUOccupancyRateJni();
	public native int getRAMOccupancyRateJni();
	public native String getAPIVersionJni();
	public native String getOSGiInfoJni();
	public native int getDeviceUpTimeJni();
	public native String getDeviceInfoJni();
	public native String getDeviceMACJni();

	public String getJVMInfo(){
        return getJVMInfoJni();
    }
	public int getCPUOccupancyRate(){
        return getCPUOccupancyRateJni();
    }
	public int getRAMOccupancyRate(){
        return getRAMOccupancyRateJni();
    }
	public String getAPIVersion(){
        return getAPIVersionJni();
    }
	public String getOSGiInfo(){
        return getOSGiInfoJni();
    }
	public int getDeviceUpTime(){
        return getDeviceUpTimeJni();
    }
	public String getDeviceInfo(){
        return getDeviceInfoJni();
    }
	public String getDeviceMAC(){
        return getDeviceMACJni();
    }
}
