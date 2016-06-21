package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public class EthQueryServiceImp implements EthQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getLANEthernetStatsJni(int portIndex);
	public native String getLANEthernetInfoJni(int portIndex);

	public String getLANEthernetStats(int portIndex){
        return getLANEthernetStatsJni(portIndex);
    }
	public String getLANEthernetInfo(int portIndex){
        return getLANEthernetInfoJni(portIndex);
    }
}
