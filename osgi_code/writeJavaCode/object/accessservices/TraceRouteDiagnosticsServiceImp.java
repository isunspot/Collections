package com.chinamobile.smartgateway.accessservices;

import org.osgi.framework.BundleContext;

public class TraceRouteDiagnosticsServiceImp implements TraceRouteDiagnosticsService {

    static{
		System.loadLibrary("bundle");
	}

	public native int startTraceRouteDiagnosticsJni(int wanIndex, String host, String traceRouterParameter);
	public native String getTraceRouteDiagnosticsResultJni();

	public int startTraceRouteDiagnostics(int wanIndex, String host, String traceRouterParameter){
        return startTraceRouteDiagnosticsJni(wanIndex, host, traceRouterParameter);
    }
	public String getTraceRouteDiagnosticsResult(){
        return getTraceRouteDiagnosticsResultJni();
    }
}
