package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public class LanNetworkAccessConfigServiceImp implements LanNetworkAccessConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native int addLANHostToStorageBlackListJni(String hostMAC);
	public native int deleteLANHostFromTrustListJni(String[] hostMAC);
	public native int deleteLANHostFromStorageBlackListJni(String[] hostMAC);
	public native int addLANHostToTrustListJni(String[] hostMAC);
	public native int setMacFilterModeJni(int mode);
	public native int deleteLANHostFromBlackListJni(String[] hostMAC);
	public native int addLANHostToBlackListJni(String[] hostMAC);

	public int addLANHostToStorageBlackList(String hostMAC){
        return addLANHostToStorageBlackListJni(hostMAC);
    }
	public int deleteLANHostFromTrustList(String[] hostMAC){
        return deleteLANHostFromTrustListJni(hostMAC);
    }
	public int deleteLANHostFromStorageBlackList(String[] hostMAC){
        return deleteLANHostFromStorageBlackListJni(hostMAC);
    }
	public int addLANHostToTrustList(String[] hostMAC){
        return addLANHostToTrustListJni(hostMAC);
    }
	public int setMacFilterMode(int mode){
        return setMacFilterModeJni(mode);
    }
	public int deleteLANHostFromBlackList(String[] hostMAC){
        return deleteLANHostFromBlackListJni(hostMAC);
    }
	public int addLANHostToBlackList(String[] hostMAC){
        return addLANHostToBlackListJni(hostMAC);
    }
}
