package com.chinamobile.smartgateway.accessservices;

import org.osgi.framework.BundleContext;

public interface IPPingDiagnosticsService {
	String getIPPingDiagnosticsResult();
	int startIPPingDiagnostics(int wanIndex, String host, String pingParameter);
}
