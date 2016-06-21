package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public interface TrafficDetailProcessService {
	int addHTTPTrafficProcessRule(String remoteAddress, int remotePort, String direction, String hostMAC, String[] methodList, String[] statuscodeList, String[] headerList, BundleContext context);
	String getHTTPTrafficProcessRuleInfo();
	int deleteHTTPTrafficProcessRule(int ruleNum);
	int deleteAllHTTPTrafficProcessRule();
}
