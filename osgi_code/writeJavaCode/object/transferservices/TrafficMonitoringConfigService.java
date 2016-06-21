package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public interface TrafficMonitoringConfigService {
	String getTrafficMonitoringDestAddressInfo();
	int addTrafficMonitoringDestAddress(String[] destAddressList, BundleContext context);
	int deleteTrafficMonitoringDestAddress(String[] destAddressList, BundleContext context);
}
