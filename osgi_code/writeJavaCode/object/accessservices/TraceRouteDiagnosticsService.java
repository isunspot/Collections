package com.chinamobile.smartgateway.accessservices;

import org.osgi.framework.BundleContext;

public interface TraceRouteDiagnosticsService {
	int startTraceRouteDiagnostics(int wanIndex, String host, String traceRouterParameter);
	String getTraceRouteDiagnosticsResult();
}
