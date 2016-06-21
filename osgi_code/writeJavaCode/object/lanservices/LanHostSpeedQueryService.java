package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public interface LanHostSpeedQueryService {
	String getLANHostSpeed(String hostMAC);
}
