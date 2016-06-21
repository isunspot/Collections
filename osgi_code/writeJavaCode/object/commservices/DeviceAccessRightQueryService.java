package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public interface DeviceAccessRightQueryService {
	String getSambaRightInfo();
	String getHTTPRightInfo();
	String getFTPRightInfo();
}
