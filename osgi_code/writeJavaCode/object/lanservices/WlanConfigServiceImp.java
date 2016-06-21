package com.chinamobile.smartgateway.lanservices;

import org.osgi.framework.BundleContext;

public class WlanConfigServiceImp implements WlanConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native int setWLANSSIDAdvertisementJni(int ssidIndex, boolean SSIDAdvertisementEnabled);
	public native int setWLANSSIDSecurityJni(int ssidIndex, String encryptionMode, String password);
	public native int setWLANRadioFrequencyWidthJni(String radioType, String frequencyWidth);
	public native int setWLANStandardJni(String radioType, String standard);
	public native int addWLANGuestSSIDJni(int guestSsidIndex);
	public native int setWLANRadioPowerJni(String radioType, int transmitPower);
	public native int setWLANSSIDSwitchJni(int ssidIndex, boolean enable);
	public native int setWLANGuestPortIsolationJni(int guestSsidIndex, boolean portIsolation);
	public native int startWLANWPSJni(int ssidIndex);
	public native int deleteWLANGuestSSIDJni(int guestSsidIndex);
	public native int setWLANHardwareSwitchJni(String radioType, boolean Switch);
	public native int setWLANGuestDurationJni(int guestSsidIndex, int duration);
	public native int stopWLANWPSJni(int ssidIndex);
	public native int setWLANRadioChannelJni(String radioType, int channel);

	public int setWLANSSIDAdvertisement(int ssidIndex, boolean SSIDAdvertisementEnabled){
        return setWLANSSIDAdvertisementJni(ssidIndex, SSIDAdvertisementEnabled);
    }
	public int setWLANSSIDSecurity(int ssidIndex, String encryptionMode, String password){
        return setWLANSSIDSecurityJni(ssidIndex, encryptionMode, password);
    }
	public int setWLANRadioFrequencyWidth(String radioType, String frequencyWidth){
        return setWLANRadioFrequencyWidthJni(radioType, frequencyWidth);
    }
	public int setWLANStandard(String radioType, String standard){
        return setWLANStandardJni(radioType, standard);
    }
	public int addWLANGuestSSID(int guestSsidIndex){
        return addWLANGuestSSIDJni(guestSsidIndex);
    }
	public int setWLANRadioPower(String radioType, int transmitPower){
        return setWLANRadioPowerJni(radioType, transmitPower);
    }
	public int setWLANSSIDSwitch(int ssidIndex, boolean enable){
        return setWLANSSIDSwitchJni(ssidIndex, enable);
    }
	public int setWLANGuestPortIsolation(int guestSsidIndex, boolean portIsolation){
        return setWLANGuestPortIsolationJni(guestSsidIndex, portIsolation);
    }
	public int startWLANWPS(int ssidIndex){
        return startWLANWPSJni(ssidIndex);
    }
	public int deleteWLANGuestSSID(int guestSsidIndex){
        return deleteWLANGuestSSIDJni(guestSsidIndex);
    }
	public int setWLANHardwareSwitch(String radioType, boolean Switch){
        return setWLANHardwareSwitchJni(radioType, Switch);
    }
	public int setWLANGuestDuration(int guestSsidIndex, int duration){
        return setWLANGuestDurationJni(guestSsidIndex, duration);
    }
	public int stopWLANWPS(int ssidIndex){
        return stopWLANWPSJni(ssidIndex);
    }
	public int setWLANRadioChannel(String radioType, int channel){
        return setWLANRadioChannelJni(radioType, channel);
    }
}
