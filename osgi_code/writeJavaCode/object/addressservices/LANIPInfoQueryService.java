package com.chinamobile.smartgateway.addressservices;

import org.osgi.framework.BundleContext;

public interface LANIPInfoQueryService {
	String getLANDHCPInfo();
	String getLANHostIP();
}
