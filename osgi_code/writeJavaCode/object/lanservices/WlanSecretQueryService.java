package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public interface WlanSecretQueryService {
	String getWLANSSIDPassword(int ssidIndex);
}
