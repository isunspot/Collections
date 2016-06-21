package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public interface LanHostSpeedLimitService {
	int setLANHostSpeedLimit(String hostMAC, int upSpeed, int downSpeed);
}
