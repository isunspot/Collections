package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public class UsbServiceImp implements UsbService {

    static{
		System.loadLibrary("bundle");
	}

	public native int usbCloseJni(int handle);
	public native int usbUnlockJni(int devId);
	public native int usbWriteJni(int handle, byte[] buf, int offset, int count);
	public native int usbReadJni(int handle, byte[] buf, int offset, int count, int timeout);
	public native String getStorageInfoJni();
	public native int usbSetSerialJni(int handle, int bandRate, int parity, int dataBits, int stopBits, boolean hwFlowCtrl, boolean swFlowCtl);
	public native int usbRegisterJni(BundleContext context, int devTypes);
	public native int usbOpenJni(int devId);
	public native int usbLockJni(int devId);
	public native int usbUnregisterJni(BundleContext context);
	public native int usbDataAvailableJni(int handle);

	public int usbClose(int handle){
        return usbCloseJni(handle);
    }
	public int usbUnlock(int devId){
        return usbUnlockJni(devId);
    }
	public int usbWrite(int handle, byte[] buf, int offset, int count){
        return usbWriteJni(handle, buf, offset, count);
    }
	public int usbRead(int handle, byte[] buf, int offset, int count, int timeout){
        return usbReadJni(handle, buf, offset, count, timeout);
    }
	public String getStorageInfo(){
        return getStorageInfoJni();
    }
	public int usbSetSerial(int handle, int bandRate, int parity, int dataBits, int stopBits, boolean hwFlowCtrl, boolean swFlowCtl){
        return usbSetSerialJni(handle, bandRate, parity, dataBits, stopBits, hwFlowCtrl, swFlowCtl);
    }
	public int usbRegister(BundleContext context, int devTypes){
        return usbRegisterJni(context, devTypes);
    }
	public int usbOpen(int devId){
        return usbOpenJni(devId);
    }
	public int usbLock(int devId){
        return usbLockJni(devId);
    }
	public int usbUnregister(BundleContext context){
        return usbUnregisterJni(context);
    }
	public int usbDataAvailable(int handle){
        return usbDataAvailableJni(handle);
    }
}
