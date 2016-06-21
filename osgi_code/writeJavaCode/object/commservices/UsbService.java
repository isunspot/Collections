package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public interface UsbService {
	int usbClose(int handle);
	int usbUnlock(int devId);
	int usbWrite(int handle, byte[] buf, int offset, int count);
	int usbRead(int handle, byte[] buf, int offset, int count, int timeout);
	String getStorageInfo();
	int usbSetSerial(int handle, int bandRate, int parity, int dataBits, int stopBits, boolean hwFlowCtrl, boolean swFlowCtl);
	int usbRegister(BundleContext context, int devTypes);
	int usbOpen(int devId);
	int usbLock(int devId);
	int usbUnregister(BundleContext context);
	int usbDataAvailable(int handle);
}
