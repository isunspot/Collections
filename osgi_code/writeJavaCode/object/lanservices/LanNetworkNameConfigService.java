package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public interface LanNetworkNameConfigService {
	int setGatewayName(String name);
	int setLANHostName(String hostMAC, String hostName);
}
