package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public interface DeviceInfoQueryService {
	String getJVMInfo();
	int getCPUOccupancyRate();
	int getRAMOccupancyRate();
	String getAPIVersion();
	String getOSGiInfo();
	int getDeviceUpTime();
	String getDeviceInfo();
	String getDeviceMAC();
}
