package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public interface LANHostsInfoQueryService {
	String getLANHostInfoByInterface(String ConnectInterface);
	int getMacFilterMode();
	String getLANHostInfoByClass(String hostClass);
	String getLANHostSpeedLimitInfo(String[] hostMAC);
	String getLANHostInfoByMAC(String[] hostMAC);
	String getGatewayName();
	String getLANHostStats(String[] hostMAC);
}
