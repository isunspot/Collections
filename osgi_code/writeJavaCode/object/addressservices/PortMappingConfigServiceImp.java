package com.chinamobile.smartgateway.addressservices;

import org.osgi.framework.BundleContext;

public class PortMappingConfigServiceImp implements PortMappingConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native int addPortMappingJni(int wanIndex, int externalPort, int internalPort, String portMappingProtocol, String internalClient);
	public native int setPortMappingSwitchJni(int wanIndex, int portMappingIndex, boolean Switch);
	public native int deletePortMappingJni(int wanIndex, int portMappingIndex);

	public int addPortMapping(int wanIndex, int externalPort, int internalPort, String portMappingProtocol, String internalClient){
        return addPortMappingJni(wanIndex, externalPort, internalPort, portMappingProtocol, internalClient);
    }
	public int setPortMappingSwitch(int wanIndex, int portMappingIndex, boolean Switch){
        return setPortMappingSwitchJni(wanIndex, portMappingIndex, Switch);
    }
	public int deletePortMapping(int wanIndex, int portMappingIndex){
        return deletePortMappingJni(wanIndex, portMappingIndex);
    }
}
