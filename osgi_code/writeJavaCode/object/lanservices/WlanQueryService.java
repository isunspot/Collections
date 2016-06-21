package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public interface WlanQueryService {
	String getWLANNeighbor(String radioType);
	String getWLANSSIDStats(int ssidIndex);
	String getWLANRadioInfo(String radioType);
	String getWLANHostInfo(String[] hostMAC);
	String getWLANSSIDInfo(int ssidIndex);
	String getGuestSSIDInfo();
	int getWLANWPSStatus(int ssidIndex);
	boolean getWLANHardwareSwitch(String radioType);
}
