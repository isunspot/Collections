package com.chinamobile.smartgateway.commservices;

import org.osgi.framework.BundleContext;

public class DeviceAccessRightConfigServiceImp implements DeviceAccessRightConfigService {

    static{
		System.loadLibrary("bundle");
	}

	public native int addSambaAccountJni(String username, String password);
	public native int setHTTPRightJni(int right);
	public native int setSambaRightJni(int right, boolean anonymous);
	public native int deleteSambaAccountJni(String username);
	public native int deleteAllFTPAccountJni();
	public native int setHTTPUserPasswordJni(String password);
	public native int setFTPRightJni(int right, boolean anonymous);
	public native int deleteAllSambaAccountJni();
	public native int deleteFTPAccountJni(String username);
	public native int addFTPAccountJni(String username, String password);

	public int addSambaAccount(String username, String password){
        return addSambaAccountJni(username, password);
    }
	public int setHTTPRight(int right){
        return setHTTPRightJni(right);
    }
	public int setSambaRight(int right, boolean anonymous){
        return setSambaRightJni(right, anonymous);
    }
	public int deleteSambaAccount(String username){
        return deleteSambaAccountJni(username);
    }
	public int deleteAllFTPAccount(){
        return deleteAllFTPAccountJni();
    }
	public int setHTTPUserPassword(String password){
        return setHTTPUserPasswordJni(password);
    }
	public int setFTPRight(int right, boolean anonymous){
        return setFTPRightJni(right, anonymous);
    }
	public int deleteAllSambaAccount(){
        return deleteAllSambaAccountJni();
    }
	public int deleteFTPAccount(String username){
        return deleteFTPAccountJni(username);
    }
	public int addFTPAccount(String username, String password){
        return addFTPAccountJni(username, password);
    }
}
