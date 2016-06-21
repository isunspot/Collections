package com.chinamobile.smartgateway.voipservices;

import org.osgi.framework.BundleContext;

public interface VoIPInfoSubscribeService {
	int subscribeVoIPEvent(BundleContext context, String[] Event);
	int unSubscribeVoIPEvent(BundleContext context, String[] Event);
}
