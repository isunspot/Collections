package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public class TrafficMirrorServiceImp implements TrafficMirrorService {

    static{
		System.loadLibrary("bundle");
	}

	public native int deleteMirrorRuleJni(int ruleNum);
	public native String getMirroRuleInfoJni();
	public native int deleteAllMirrorRuleJni();
	public native int addMirrorRuleJni(String remoteAddress, String remotePort, String direction, String protocol, String hostMAC, String mirrorToIP, int mirrorToPort);

	public int deleteMirrorRule(int ruleNum){
        return deleteMirrorRuleJni(ruleNum);
    }
	public String getMirroRuleInfo(){
        return getMirroRuleInfoJni();
    }
	public int deleteAllMirrorRule(){
        return deleteAllMirrorRuleJni();
    }
	public int addMirrorRule(String remoteAddress, String remotePort, String direction, String protocol, String hostMAC, String mirrorToIP, int mirrorToPort){
        return addMirrorRuleJni(remoteAddress, remotePort, direction, protocol, hostMAC, mirrorToIP, mirrorToPort);
    }
}
