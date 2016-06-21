package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public interface EthConfigService {
	int setLANEthernetDuplexMode(int portIndex, String duplexMode);
	int setLANEthernetEnable(int portIndex, boolean enable);
	int setLANEthernetMaxBitRate(int portIndex, String maxBitRate);
}
