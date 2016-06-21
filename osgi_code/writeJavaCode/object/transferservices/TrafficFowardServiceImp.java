package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public class TrafficFowardServiceImp implements TrafficFowardService {

    static{
		System.loadLibrary("bundle");
	}

	public native int deleteForwardRuleJni(int ruleNum);
	public native int addForwardRuleJni(String remoteAddress, String remotePort, String protocol, String hostMAC, String forwardToIP, int forwardToPort);
	public native String getForwardRuleInfoJni();
	public native int deleteAllForwardRuleJni();

	public int deleteForwardRule(int ruleNum){
        return deleteForwardRuleJni(ruleNum);
    }
	public int addForwardRule(String remoteAddress, String remotePort, String protocol, String hostMAC, String forwardToIP, int forwardToPort){
        return addForwardRuleJni(remoteAddress, remotePort, protocol, hostMAC, forwardToIP, forwardToPort);
    }
	public String getForwardRuleInfo(){
        return getForwardRuleInfoJni();
    }
	public int deleteAllForwardRule(){
        return deleteAllForwardRuleJni();
    }
}
