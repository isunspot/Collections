package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public class TransferQueryServiceImp implements TransferQueryService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getLayer3ForwardingCurrentJni();
	public native String getIPTVStatusJni();
	public native String getLayer3ForwardingStaticConfigInfoJni();
	public native String getVLANBindInfoJni();
	public native String getIPv6Layer3ForwardingCurrentJni();
	public native String getIPv6Layer3ForwardingStaticConfigInfoJni();

	public String getLayer3ForwardingCurrent(){
        return getLayer3ForwardingCurrentJni();
    }
	public String getIPTVStatus(){
        return getIPTVStatusJni();
    }
	public String getLayer3ForwardingStaticConfigInfo(){
        return getLayer3ForwardingStaticConfigInfoJni();
    }
	public String getVLANBindInfo(){
        return getVLANBindInfoJni();
    }
	public String getIPv6Layer3ForwardingCurrent(){
        return getIPv6Layer3ForwardingCurrentJni();
    }
	public String getIPv6Layer3ForwardingStaticConfigInfo(){
        return getIPv6Layer3ForwardingStaticConfigInfoJni();
    }
}
