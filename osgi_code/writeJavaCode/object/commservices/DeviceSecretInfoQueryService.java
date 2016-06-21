package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public interface DeviceSecretInfoQueryService {
	String getDeviceSerialNumber();
	String getDeviceDefaultSSID1Name();
	String getDevicePassword();
	String getDeviceManufacturerOUI();
	String getDeviceDefaultWebPassword();
	String getDeviceDefaultSSID1Password();
}
