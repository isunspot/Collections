package com.chinamobile.smartgateway.accessservices;

import org.osgi.framework.BundleContext;

public interface AccessInfoQueryService {
	int getInternetWANIndex();
	String getWANIfList();
	int getPONIfUpTime();
	String getWANIfStats(int wanIndex);
	String getWANIfInfo(int wanIndex);
	String getWANIfStatus(int wanIndex);
	String getWanIfBandwidth(int wanIndex);
	String getPONIfPhyStatus();
	String getPONIfRegisterStatus();
	String getUplinkIfStats();
}
