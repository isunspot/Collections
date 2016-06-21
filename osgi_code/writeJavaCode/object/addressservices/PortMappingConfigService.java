package com.chinamobile.smartgateway.addressservices;

import org.osgi.framework.BundleContext;

public interface PortMappingConfigService {
	int addPortMapping(int wanIndex, int externalPort, int internalPort, String portMappingProtocol, String internalClient);
	int setPortMappingSwitch(int wanIndex, int portMappingIndex, boolean Switch);
	int deletePortMapping(int wanIndex, int portMappingIndex);
}
