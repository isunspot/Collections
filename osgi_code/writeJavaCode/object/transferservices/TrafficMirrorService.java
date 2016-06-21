package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public interface TrafficMirrorService {
	int deleteMirrorRule(int ruleNum);
	String getMirroRuleInfo();
	int deleteAllMirrorRule();
	int addMirrorRule(String remoteAddress, String remotePort, String direction, String protocol, String hostMAC, String mirrorToIP, int mirrorToPort);
}
