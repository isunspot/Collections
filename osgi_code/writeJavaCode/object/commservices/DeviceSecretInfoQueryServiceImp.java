package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public class DeviceSecretInfoQueryServiceImp implements DeviceSecretInfoQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getDeviceSerialNumberJni();
	public native String getDeviceDefaultSSID1NameJni();
	public native String getDevicePasswordJni();
	public native String getDeviceManufacturerOUIJni();
	public native String getDeviceDefaultWebPasswordJni();
	public native String getDeviceDefaultSSID1PasswordJni();

	public String getDeviceSerialNumber(){
        return getDeviceSerialNumberJni();
    }
	public String getDeviceDefaultSSID1Name(){
        return getDeviceDefaultSSID1NameJni();
    }
	public String getDevicePassword(){
        return getDevicePasswordJni();
    }
	public String getDeviceManufacturerOUI(){
        return getDeviceManufacturerOUIJni();
    }
	public String getDeviceDefaultWebPassword(){
        return getDeviceDefaultWebPasswordJni();
    }
	public String getDeviceDefaultSSID1Password(){
        return getDeviceDefaultSSID1PasswordJni();
    }
}
