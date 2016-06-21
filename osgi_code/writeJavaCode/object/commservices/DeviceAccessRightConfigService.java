package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public interface DeviceAccessRightConfigService {
	int addSambaAccount(String username, String password);
	int setHTTPRight(int right);
	int setSambaRight(int right, boolean anonymous);
	int deleteSambaAccount(String username);
	int deleteAllFTPAccount();
	int setHTTPUserPassword(String password);
	int setFTPRight(int right, boolean anonymous);
	int deleteAllSambaAccount();
	int deleteFTPAccount(String username);
	int addFTPAccount(String username, String password);
}
