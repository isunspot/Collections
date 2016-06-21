package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public interface StaticLayer3ForwardingConfigService {
	int deleteLayer3ForwardingStatic(String DestIPPrefix, String NextHop, String Interface);
	int deleteIPv6Layer3ForwardingStatic(int index);
	int addLayer3ForwardingStatic(String DestIPAddress, String DestSubnetMask, String GatewayIPAddress, String Interface);
	int addIPv6Layer3ForwardingStatic(int index);
}
