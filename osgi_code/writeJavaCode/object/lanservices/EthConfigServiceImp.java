package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public class EthConfigServiceImp implements EthConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native int setLANEthernetDuplexModeJni(int portIndex, String duplexMode);
	public native int setLANEthernetEnableJni(int portIndex, boolean enable);
	public native int setLANEthernetMaxBitRateJni(int portIndex, String maxBitRate);

	public int setLANEthernetDuplexMode(int portIndex, String duplexMode){
        return setLANEthernetDuplexModeJni(portIndex, duplexMode);
    }
	public int setLANEthernetEnable(int portIndex, boolean enable){
        return setLANEthernetEnableJni(portIndex, enable);
    }
	public int setLANEthernetMaxBitRate(int portIndex, String maxBitRate){
        return setLANEthernetMaxBitRateJni(portIndex, maxBitRate);
    }
}
