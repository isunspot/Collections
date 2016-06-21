package com.chinamobile.smartgateway.accessservices;

import org.osgi.framework.BundleContext;

public interface WanConfigService {
	int addWANIf(String VLANMode, String VLANIDMark, String ConnectionType);
	int deleteWANIf(int wanIndex);
	int setWANIf(int wanIndex, String setParameter);
}
