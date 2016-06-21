package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public interface LanNetworkAccessConfigService {
	int addLANHostToStorageBlackList(String hostMAC);
	int deleteLANHostFromTrustList(String[] hostMAC);
	int deleteLANHostFromStorageBlackList(String[] hostMAC);
	int addLANHostToTrustList(String[] hostMAC);
	int setMacFilterMode(int mode);
	int deleteLANHostFromBlackList(String[] hostMAC);
	int addLANHostToBlackList(String[] hostMAC);
}
