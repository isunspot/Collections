package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public class TrafficDetailProcessServiceImp implements TrafficDetailProcessService {

    static{
		System.loadLibrary("bundle");
	}

	public native int addHTTPTrafficProcessRuleJni(String remoteAddress, int remotePort, String direction, String hostMAC, String[] methodList, String[] statuscodeList, String[] headerList, BundleContext context);
	public native String getHTTPTrafficProcessRuleInfoJni();
	public native int deleteHTTPTrafficProcessRuleJni(int ruleNum);
	public native int deleteAllHTTPTrafficProcessRuleJni();

	public int addHTTPTrafficProcessRule(String remoteAddress, int remotePort, String direction, String hostMAC, String[] methodList, String[] statuscodeList, String[] headerList, BundleContext context){
        return addHTTPTrafficProcessRuleJni(remoteAddress, remotePort, direction, hostMAC, methodList, statuscodeList, headerList, context);
    }
	public String getHTTPTrafficProcessRuleInfo(){
        return getHTTPTrafficProcessRuleInfoJni();
    }
	public int deleteHTTPTrafficProcessRule(int ruleNum){
        return deleteHTTPTrafficProcessRuleJni(ruleNum);
    }
	public int deleteAllHTTPTrafficProcessRule(){
        return deleteAllHTTPTrafficProcessRuleJni();
    }
}
