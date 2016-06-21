package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public interface VLANBindConfigService {
	int setVLANBind(String lanInterface, String bind);
	int clearVLANBind(String lanInterface);
}
