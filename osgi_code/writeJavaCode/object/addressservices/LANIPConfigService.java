package com.chinamobile.smartgateway.addressservices;

import org.osgi.framework.BundleContext;

public interface LANIPConfigService {
	int setLANHostIP(String localIP, String submask);
	int setLANDHCPInfo(String enableDHCPServer, String DHCPStartIP, String DHCPEndIP, int DHCPDuration);
}
