package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public interface TrafficFowardService {
	int deleteForwardRule(int ruleNum);
	int addForwardRule(String remoteAddress, String remotePort, String protocol, String hostMAC, String forwardToIP, int forwardToPort);
	String getForwardRuleInfo();
	int deleteAllForwardRule();
}
