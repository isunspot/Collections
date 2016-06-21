package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public interface WlanConfigService {
	int setWLANSSIDAdvertisement(int ssidIndex, boolean SSIDAdvertisementEnabled);
	int setWLANSSIDSecurity(int ssidIndex, String encryptionMode, String password);
	int setWLANRadioFrequencyWidth(String radioType, String frequencyWidth);
	int setWLANStandard(String radioType, String standard);
	int addWLANGuestSSID(int guestSsidIndex);
	int setWLANRadioPower(String radioType, int transmitPower);
	int setWLANSSIDSwitch(int ssidIndex, boolean enable);
	int setWLANGuestPortIsolation(int guestSsidIndex, boolean portIsolation);
	int startWLANWPS(int ssidIndex);
	int deleteWLANGuestSSID(int guestSsidIndex);
	int setWLANHardwareSwitch(String radioType, boolean Switch);
	int setWLANGuestDuration(int guestSsidIndex, int duration);
	int stopWLANWPS(int ssidIndex);
	int setWLANRadioChannel(String radioType, int channel);
}
