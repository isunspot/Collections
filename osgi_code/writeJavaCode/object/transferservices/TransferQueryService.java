package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public interface TransferQueryService {
	String getLayer3ForwardingCurrent();
	String getIPTVStatus();
	String getLayer3ForwardingStaticConfigInfo();
	String getVLANBindInfo();
	String getIPv6Layer3ForwardingCurrent();
	String getIPv6Layer3ForwardingStaticConfigInfo();
}
