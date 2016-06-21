package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public interface EthQueryService {
	String getLANEthernetStats(int portIndex);
	String getLANEthernetInfo(int portIndex);
}
