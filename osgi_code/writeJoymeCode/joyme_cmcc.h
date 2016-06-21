#ifndef _JOYME_CMCC_H_
#define _JOYME_CMCC_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/msg.h>
#include <sys/uio.h>
#include "json.h"
#include "joyme.h"
#include "libtcapi.h"
#include "json_helper.h"

int joyme_cmcc_getInternetWANIndex(const int*);
int joyme_cmcc_getWANIfList(const char*);
int joyme_cmcc_getPONIfUpTime(const int*);
int joyme_cmcc_getWANIfStats(const char*, int);
int joyme_cmcc_getWANIfInfo(const char*, int);
int joyme_cmcc_getWANIfStatus(const char*, int);
int joyme_cmcc_getWanIfBandwidth(const char*, int);
int joyme_cmcc_getPONIfPhyStatus(const char*);
int joyme_cmcc_getPONIfRegisterStatus(const char*);
int joyme_cmcc_getUplinkIfStats(const char*);
int joyme_cmcc_startTraceRouteDiagnostics(const int*, int, char*, char*);
int joyme_cmcc_getTraceRouteDiagnosticsResult(const char*);
int joyme_cmcc_getIPPingDiagnosticsResult(const char*);
int joyme_cmcc_startIPPingDiagnostics(const int*, int, char*, char*);
int joyme_cmcc_addWANIf(const int*, char*, char*, char*);
int joyme_cmcc_deleteWANIf(const int*, int);
int joyme_cmcc_setWANIf(const int*, int, char*);
int joyme_cmcc_getTrafficInfoByFlow(const char*, int);
int joyme_cmcc_addTrafficToFlow(const int*, char*, char*, int);
int joyme_cmcc_getStatsByFlow(const char*, int);
int joyme_cmcc_deleteAllTrafficFromFlow(const int*, int);
int joyme_cmcc_getSpeedLimitByFlow(const char*, int);
int joyme_cmcc_getSpeedByFlow(const char*, int);
int joyme_cmcc_deleteTrafficFromFlow(const int*, char*, char*, int);
int joyme_cmcc_getDSCPRemarkByFlow(const int*, int);
int joyme_cmcc_setSpeedLimitByFlow(const int*, int, int, int);
int joyme_cmcc_setDSCPRemarkByFlow(const int*, int, int);
int joyme_cmcc_deleteMirrorRule(const int*, int);
int joyme_cmcc_getMirroRuleInfo(const char*);
int joyme_cmcc_deleteAllMirrorRule(const int*);
int joyme_cmcc_addMirrorRule(const int*, char*, char*, char*, char*, char*, char*, int);
int joyme_cmcc_addHTTPTrafficProcessRule(const int*, char*, int, char*, char*, char*[], int, char*[], int, char*[], int, char*);
int joyme_cmcc_getHTTPTrafficProcessRuleInfo(const char*);
int joyme_cmcc_deleteHTTPTrafficProcessRule(const int*, int);
int joyme_cmcc_deleteAllHTTPTrafficProcessRule(const int*);
int joyme_cmcc_deleteForwardRule(const int*, int);
int joyme_cmcc_addForwardRule(const int*, char*, char*, char*, char*, char*, int);
int joyme_cmcc_getForwardRuleInfo(const char*);
int joyme_cmcc_deleteAllForwardRule(const int*);
int joyme_cmcc_getTrafficMonitoringDestAddressInfo(const char*);
int joyme_cmcc_addTrafficMonitoringDestAddress(const int*, char*[], int, char*);
int joyme_cmcc_deleteTrafficMonitoringDestAddress(const int*, char*[], int, char*);
int joyme_cmcc_setVLANBind(const int*, char*, char*);
int joyme_cmcc_clearVLANBind(const int*, char*);
int joyme_cmcc_getLayer3ForwardingCurrent(const char*);
int joyme_cmcc_getIPTVStatus(const char*);
int joyme_cmcc_getLayer3ForwardingStaticConfigInfo(const char*);
int joyme_cmcc_getVLANBindInfo(const char*);
int joyme_cmcc_getIPv6Layer3ForwardingCurrent(const char*);
int joyme_cmcc_getIPv6Layer3ForwardingStaticConfigInfo(const char*);
int joyme_cmcc_deleteLayer3ForwardingStatic(const int*, char*, char*, char*);
int joyme_cmcc_deleteIPv6Layer3ForwardingStatic(const int*, int);
int joyme_cmcc_addLayer3ForwardingStatic(const int*, char*, char*, char*, char*);
int joyme_cmcc_addIPv6Layer3ForwardingStatic(const int*, int);
int joyme_cmcc_subscribeVoIPEvent(const int*, char*, char*[], int);
int joyme_cmcc_unSubscribeVoIPEvent(const int*, char*, char*[], int);
int joyme_cmcc_getPOTSInfo(const char*);
int joyme_cmcc_getSambaRightInfo(const char*);
int joyme_cmcc_getHTTPRightInfo(const char*);
int joyme_cmcc_getFTPRightInfo(const char*);
int joyme_cmcc_reset(const int*);
int joyme_cmcc_usbClose(const int*, int);
int joyme_cmcc_usbUnlock(const int*, int);
int joyme_cmcc_usbWrite(const int*, int, void*, int, int);
int joyme_cmcc_usbRead(const int*, int, void*, int, int, int);
int joyme_cmcc_getStorageInfo(const char*);
int joyme_cmcc_usbSetSerial(const int*, int, int, int, int, int, int, int);
int joyme_cmcc_usbRegister(const int*, char*, int);
int joyme_cmcc_usbOpen(const int*, int);
int joyme_cmcc_usbLock(const int*, int);
int joyme_cmcc_usbUnregister(const int*, char*);
int joyme_cmcc_usbDataAvailable(const int*, int);
int joyme_cmcc_setLedSwitch(const int*, int);
int joyme_cmcc_getJVMInfo(const char*);
int joyme_cmcc_getCPUOccupancyRate(const int*);
int joyme_cmcc_getRAMOccupancyRate(const int*);
int joyme_cmcc_getAPIVersion(const char*);
int joyme_cmcc_getOSGiInfo(const char*);
int joyme_cmcc_getDeviceUpTime(const int*);
int joyme_cmcc_getDeviceInfo(const char*);
int joyme_cmcc_getDeviceMAC(const char*);
int joyme_cmcc_getDeviceSerialNumber(const char*);
int joyme_cmcc_getDeviceDefaultSSID1Name(const char*);
int joyme_cmcc_getDevicePassword(const char*);
int joyme_cmcc_getDeviceManufacturerOUI(const char*);
int joyme_cmcc_getDeviceDefaultWebPassword(const char*);
int joyme_cmcc_getDeviceDefaultSSID1Password(const char*);
int joyme_cmcc_addSambaAccount(const int*, char*, char*);
int joyme_cmcc_setHTTPRight(const int*, int);
int joyme_cmcc_setSambaRight(const int*, int, int);
int joyme_cmcc_deleteSambaAccount(const int*, char*);
int joyme_cmcc_deleteAllFTPAccount(const int*);
int joyme_cmcc_setHTTPUserPassword(const int*, char*);
int joyme_cmcc_setFTPRight(const int*, int, int);
int joyme_cmcc_deleteAllSambaAccount(const int*);
int joyme_cmcc_deleteFTPAccount(const int*, char*);
int joyme_cmcc_addFTPAccount(const int*, char*, char*);
int joyme_cmcc_getLANDHCPInfo(const char*);
int joyme_cmcc_getLANHostIP(const char*);
int joyme_cmcc_getPortMappingInfo(const char*);
int joyme_cmcc_addPortMapping(const int*, int, int, int, char*, char*);
int joyme_cmcc_setPortMappingSwitch(const int*, int, int, int);
int joyme_cmcc_deletePortMapping(const int*, int, int);
int joyme_cmcc_setLANHostIP(const int*, char*, char*);
int joyme_cmcc_setLANDHCPInfo(const int*, char*, char*, char*, int);
int joyme_cmcc_setLANEthernetDuplexMode(const int*, int, char*);
int joyme_cmcc_setLANEthernetEnable(const int*, int, int);
int joyme_cmcc_setLANEthernetMaxBitRate(const int*, int, char*);
int joyme_cmcc_getWLANNeighbor(const char*, char*);
int joyme_cmcc_getWLANSSIDStats(const char*, int);
int joyme_cmcc_getWLANRadioInfo(const char*, char*);
int joyme_cmcc_getWLANHostInfo(const char*, char*[], int);
int joyme_cmcc_getWLANSSIDInfo(const char*, int);
int joyme_cmcc_getGuestSSIDInfo(const char*);
int joyme_cmcc_getWLANWPSStatus(const int*, int);
int joyme_cmcc_getWLANHardwareSwitch(const int*, char*);
int joyme_cmcc_getLANHostInfoByInterface(const char*, char*);
int joyme_cmcc_getMacFilterMode(const int*);
int joyme_cmcc_getLANHostInfoByClass(const char*, char*);
int joyme_cmcc_getLANHostSpeedLimitInfo(const char*, char*[], int);
int joyme_cmcc_getLANHostInfoByMAC(const char*, char*[], int);
int joyme_cmcc_getGatewayName(const char*);
int joyme_cmcc_getLANHostStats(const char*, char*[], int);
int joyme_cmcc_setLANHostSpeedLimit(const int*, char*, int, int);
int joyme_cmcc_setWLANSSIDAdvertisement(const int*, int, int);
int joyme_cmcc_setWLANSSIDSecurity(const int*, int, char*, char*);
int joyme_cmcc_setWLANRadioFrequencyWidth(const int*, char*, char*);
int joyme_cmcc_setWLANStandard(const int*, char*, char*);
int joyme_cmcc_addWLANGuestSSID(const int*, int);
int joyme_cmcc_setWLANRadioPower(const int*, char*, int);
int joyme_cmcc_setWLANSSIDSwitch(const int*, int, int);
int joyme_cmcc_setWLANGuestPortIsolation(const int*, int, int);
int joyme_cmcc_startWLANWPS(const int*, int);
int joyme_cmcc_deleteWLANGuestSSID(const int*, int);
int joyme_cmcc_setWLANHardwareSwitch(const int*, char*, int);
int joyme_cmcc_setWLANGuestDuration(const int*, int, int);
int joyme_cmcc_stopWLANWPS(const int*, int);
int joyme_cmcc_setWLANRadioChannel(const int*, char*, int);
int joyme_cmcc_getLANEthernetStats(const char*, int);
int joyme_cmcc_getLANEthernetInfo(const char*, int);
int joyme_cmcc_getWLANSSIDPassword(const char*, int);
int joyme_cmcc_setGatewayName(const int*, char*);
int joyme_cmcc_setLANHostName(const int*, char*, char*);
int joyme_cmcc_getLANHostSpeed(const char*, char*);
int joyme_cmcc_addLANHostToStorageBlackList(const int*, char*);
int joyme_cmcc_deleteLANHostFromTrustList(const int*, char*[], int);
int joyme_cmcc_deleteLANHostFromStorageBlackList(const int*, char*[], int);
int joyme_cmcc_addLANHostToTrustList(const int*, char*[], int);
int joyme_cmcc_setMacFilterMode(const int*, int);
int joyme_cmcc_deleteLANHostFromBlackList(const int*, char*[], int);
int joyme_cmcc_addLANHostToBlackList(const int*, char*[], int);

#endif /* _JOYME_CMCC_H_ */