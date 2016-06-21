package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public class TrafficQoSServiceImp implements TrafficQoSService {

    static{
		System.loadLibrary("bundle");
	}

	public native String getTrafficInfoByFlowJni(int flow);
	public native int addTrafficToFlowJni(String remoteAddress, String remotePort, int flow);
	public native String getStatsByFlowJni(int flow);
	public native int deleteAllTrafficFromFlowJni(int flow);
	public native String getSpeedLimitByFlowJni(int flow);
	public native String getSpeedByFlowJni(int flow);
	public native int deleteTrafficFromFlowJni(String remoteAddress, String remotePort, int flow);
	public native int getDSCPRemarkByFlowJni(int flow);
	public native int setSpeedLimitByFlowJni(int flow, int upSpeed, int downSpeed);
	public native int setDSCPRemarkByFlowJni(int flow, int remarkDSCP);

	public String getTrafficInfoByFlow(int flow){
        return getTrafficInfoByFlowJni(flow);
    }
	public int addTrafficToFlow(String remoteAddress, String remotePort, int flow){
        return addTrafficToFlowJni(remoteAddress, remotePort, flow);
    }
	public String getStatsByFlow(int flow){
        return getStatsByFlowJni(flow);
    }
	public int deleteAllTrafficFromFlow(int flow){
        return deleteAllTrafficFromFlowJni(flow);
    }
	public String getSpeedLimitByFlow(int flow){
        return getSpeedLimitByFlowJni(flow);
    }
	public String getSpeedByFlow(int flow){
        return getSpeedByFlowJni(flow);
    }
	public int deleteTrafficFromFlow(String remoteAddress, String remotePort, int flow){
        return deleteTrafficFromFlowJni(remoteAddress, remotePort, flow);
    }
	public int getDSCPRemarkByFlow(int flow){
        return getDSCPRemarkByFlowJni(flow);
    }
	public int setSpeedLimitByFlow(int flow, int upSpeed, int downSpeed){
        return setSpeedLimitByFlowJni(flow, upSpeed, downSpeed);
    }
	public int setDSCPRemarkByFlow(int flow, int remarkDSCP){
        return setDSCPRemarkByFlowJni(flow, remarkDSCP);
    }
}
