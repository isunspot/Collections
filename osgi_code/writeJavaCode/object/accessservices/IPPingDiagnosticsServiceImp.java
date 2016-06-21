package com.chinamobile.smartgateway.accessservices;

import org.osgi.framework.BundleContext;

public class IPPingDiagnosticsServiceImp implements IPPingDiagnosticsService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getIPPingDiagnosticsResultJni();
	public native int startIPPingDiagnosticsJni(int wanIndex, String host, String pingParameter);

	public String getIPPingDiagnosticsResult(){
        return getIPPingDiagnosticsResultJni();
    }
	public int startIPPingDiagnostics(int wanIndex, String host, String pingParameter){
        return startIPPingDiagnosticsJni(wanIndex, host, pingParameter);
    }
}
