package com.chinamobile.smartgateway.transferservices;

import org.osgi.framework.BundleContext;

public interface TrafficQoSService {
	String getTrafficInfoByFlow(int flow);
	int addTrafficToFlow(String remoteAddress, String remotePort, int flow);
	String getStatsByFlow(int flow);
	int deleteAllTrafficFromFlow(int flow);
	String getSpeedLimitByFlow(int flow);
	String getSpeedByFlow(int flow);
	int deleteTrafficFromFlow(String remoteAddress, String remotePort, int flow);
	int getDSCPRemarkByFlow(int flow);
	int setSpeedLimitByFlow(int flow, int upSpeed, int downSpeed);
	int setDSCPRemarkByFlow(int flow, int remarkDSCP);
}
