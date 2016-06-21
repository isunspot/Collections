package com.chinamobile.smartgateway.accessservices;

import org.osgi.framework.BundleContext;

public class WanConfigServiceImp implements WanConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native int addWANIfJni(String VLANMode, String VLANIDMark, String ConnectionType);
	public native int deleteWANIfJni(int wanIndex);
	public native int setWANIfJni(int wanIndex, String setParameter);

	public int addWANIf(String VLANMode, String VLANIDMark, String ConnectionType){
        return addWANIfJni(VLANMode, VLANIDMark, ConnectionType);
    }
	public int deleteWANIf(int wanIndex){
        return deleteWANIfJni(wanIndex);
    }
	public int setWANIf(int wanIndex, String setParameter){
        return setWANIfJni(wanIndex, setParameter);
    }
}
