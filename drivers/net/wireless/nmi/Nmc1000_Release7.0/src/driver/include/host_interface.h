/*!  
*  @file	host_interface.h
*  @brief	File containg host interface APIs
*  @author	zsalah
*  @sa		host_interface.c
*  @date	8 March 2012
*  @version	1.0
*/

#ifndef HOST_INT_H
#define HOST_INT_H

#include "CoreConfigurator.h"
#include "CoreConfigSimulator.h"
/*****************************************************************************/
/*								Macros                                       */
/*****************************************************************************/
#if 0
#define WID_BSS_TYPE				0x0000
#define WID_CURRENT_TX_RATE			0x0001
#define WID_CURRENT_CHANNEL			0x0002
#define WID_PREAMBLE				0x0003
#define WID_STATUS					0x0005
#define WID_SCAN_TYPE				0x0007
#define WID_KEY_ID					0x0009
#define	WID_DTIM_PERIOD				0x0010
#define	WID_POWER_MANAGEMENT		0x000B
#define WID_AUTH_TYPE				0x000D
#define WID_SITE_SURVEY				0x000E
#define WID_DTIM_PERIOD				0x0010
#define WID_DISCONNECT				0x0016
#define WID_SHORT_SLOT_ALLOWED		0x001A
#define WID_START_SCAN_REQ			0x001E
#define WID_RSSI					0x001F
#define WID_JOIN_REQ				0x0020
#define WID_11N_TXOP_PROT_DISABLE	0x00B0
#define WID_RTS_THRESHOLD			0x1000
#define WID_FRAG_THRESHOLD			0x1001
#define WID_SHORT_RETRY_LIMIT		0x1002
#define WID_LONG_RETRY_LIMIT		0x1003
#define WID_BEACON_INTERVAL			0x1006
#define WID_ACTIVE_SCAN_TIME		0x100C
#define WID_PASSIVE_SCAN_TIME		0x100D
#define WID_SITE_SURVEY_SCAN_TIME	0x100E
#define WID_AUTH_TIMEOUT			0x1010
#define WID_11I_PSK					0x3008
#define WID_SITE_SURVEY_RESULTS		0x3012
#define WID_ADD_PTK					0x301B
#define WID_ADD_RX_GTK				0x301C
#define WID_ADD_TX_GTK				0x301D
#define WID_ADD_WEP_KEY				0x3019
#define	WID_REMOVE_WEP_KEY			0x301A
#define WID_REMOVE_KEY				0x301E
#define WID_ASSOC_REQ_INFO			0x301F
#define WID_ASSOC_RES_INFO			0x3020
#define WID_PMKID_INFO				0x3082
#define WID_SCAN_CHANNEL_LIST		0x4084
#define WID_11I_MODE			    0x000C
#endif
#define FAIL		0x0000
#define SUCCESS		0x0001

#define BIT2                    ((NMI_Uint32)(1 << 2))
#define BIT1                    ((NMI_Uint32)(1 << 1))
#define BIT0                    ((NMI_Uint32)(1 << 0))

#define AP_MODE     	0x01
#define STATION_MODE	0x02


#define MAX_NUM_STA                           8
#define ACTIVE_SCAN_TIME			10
#define PASSIVE_SCAN_TIME			1200
#define MIN_SCAN_TIME				10
#define MAX_SCAN_TIME				1200
#define DEFAULT_SCAN				0
#define USER_SCAN					BIT0
#define OBSS_PERIODIC_SCAN			BIT1
#define OBSS_ONETIME_SCAN			BIT2
#define GTK_RX_KEY_BUFF_LEN			24
#define ADDKEY						0x1
#define REMOVEKEY					0x2
#define DEFAULTKEY					0x4
#define ADDKEY_AP					0x8
#define MAX_NUM_SCANNED_NETWORKS	100 //30		// rachel
#define MAX_NUM_SCANNED_NETWORKS_SHADOW	130
#define MAX_NUM_PROBED_SSID            10  /*One more than the number of scanned ssids*/
#define CHANNEL_SCAN_TIME 			250//250

#define TX_MIC_KEY_LEN				8
#define RX_MIC_KEY_LEN				8
#define PTK_KEY_LEN					16

#define TX_MIC_KEY_MSG_LEN			26
#define RX_MIC_KEY_MSG_LEN			48
#define PTK_KEY_MSG_LEN				39

#define PMKSA_KEY_LEN				22
#define ETH_ALEN  6
#define PMKID_LEN  					16
#define NMI_MAX_NUM_PMKIDS  16
#define NMI_SUPP_MCS_SET_SIZE	16
#define NMI_ADD_STA_LENGTH	40 /* Not including the rates field cause it has variable length*/
#define SCAN_EVENT_DONE_ABORTED 
/*****************************************************************************/
/* Data Types                                                                */
/*****************************************************************************/
//typedef unsigned char	uint8;
//typedef signed char     int8;
//typedef unsigned short	uint16;
//typedef unsigned long   uint32;
//typedef uint32   Bool;

#if 0
typedef enum {WID_CHAR  = 0,
              WID_SHORT = 1,
              WID_INT   = 2,
              WID_STR   = 3,
              WID_ADR   = 4,
              WID_BIN   = 5,
              WID_IP    = 6,
              WID_UNDEF = 7
} WID_TYPE_T;
#endif
typedef struct
{
    NMI_Uint16     cfg_wid;
    WID_TYPE_T	  cfg_type;
    NMI_Sint8     *pu8Para;
} cfg_param_t;



typedef enum
{
	HOST_IF_IDLE  					= 0,
	HOST_IF_SCANNING	  			= 1,
	HOST_IF_WAITING_CONN_REQ		= 2,
	HOST_IF_WAITING_CONN_RESP		= 3,
	HOST_IF_CONNECTED				= 4,
	HOST_IF_FORCE_32BIT  			= 0xFFFFFFFF
}tenuHostIFstate;

typedef struct _tstrHostIFpmkid
{
	NMI_Uint8 bssid[ETH_ALEN];
	NMI_Uint8 pmkid[PMKID_LEN];
}tstrHostIFpmkid;

typedef struct _tstrHostIFpmkidAttr
{
	NMI_Uint8 numpmkid;
	tstrHostIFpmkid pmkidlist[NMI_MAX_NUM_PMKIDS];
}tstrHostIFpmkidAttr;
#if 0
/* Scan type parameter for scan request */
typedef enum
{
	PASSIVE_SCAN = 0,
    ACTIVE_SCAN  = 1,
    NUM_SCANTYPE
} tenuScanType;

typedef enum {SITE_SURVEY_1CH    = 0,
              SITE_SURVEY_ALL_CH = 1,
              SITE_SURVEY_OFF    = 2
} SITE_SURVEY_T;
#endif
typedef enum{AUTORATE	= 0,
			 MBPS_1		= 1,
			 MBPS_2		= 2,
			 MBPS_5_5	= 5,
			 MBPS_11	= 11,
			 MBPS_6		= 6,
			 MBPS_9		= 9,
			 MBPS_12	= 12,
			 MBPS_18	= 18,
			 MBPS_24	= 24,
			 MBPS_36	= 36,
			 MBPS_48	= 48,
			 MBPS_54	= 54

}CURRENT_TX_RATE_T;

typedef struct
{
	NMI_Uint32 u32SetCfgFlag;
	NMI_Uint8 ht_enable;
	NMI_Uint8 bss_type;
	NMI_Uint8 auth_type;
	NMI_Uint16 auth_timeout;
	NMI_Uint8 power_mgmt_mode;
	NMI_Uint16 short_retry_limit;
	NMI_Uint16 long_retry_limit;
	NMI_Uint16 frag_threshold;
	NMI_Uint16 rts_threshold;
	NMI_Uint16 preamble_type;
	NMI_Uint8 short_slot_allowed;
	NMI_Uint8 txop_prot_disabled;
	NMI_Uint16 beacon_interval;
	NMI_Uint16 dtim_period;
	SITE_SURVEY_T site_survey_enabled;
	NMI_Uint16 site_survey_scan_time;
	NMI_Uint8 scan_source;
	NMI_Uint16 active_scan_time;
	NMI_Uint16 passive_scan_time;
	CURRENT_TX_RATE_T curr_tx_rate;

}tstrCfgParamVal;

typedef enum {
	RETRY_SHORT		= 1 << 0,
	RETRY_LONG		= 1 << 1,
	FRAG_THRESHOLD	= 1 << 2,
	RTS_THRESHOLD	= 1 << 3,
	BSS_TYPE  = 1 << 4,
	AUTH_TYPE = 1 << 5,
	AUTHEN_TIMEOUT = 1 << 6,
	POWER_MANAGEMENT = 1 << 7,
	PREAMBLE = 1 << 8,
	SHORT_SLOT_ALLOWED = 1 << 9,
	TXOP_PROT_DISABLE = 1 << 10,
	BEACON_INTERVAL = 1 << 11,
	DTIM_PERIOD = 1 << 12,
	SITE_SURVEY = 1 << 13,
	SITE_SURVEY_SCAN_TIME = 1 << 14,
	ACTIVE_SCANTIME = 1 << 15,
	PASSIVE_SCANTIME = 1 << 16,
	CURRENT_TX_RATE = 1 << 17,
	HT_ENABLE = 1 <<18,
}tenuCfgParam;

typedef struct
{
	NMI_Uint8 au8bssid[6];
}tstrFoundNetworkInfo;

typedef enum {SCAN_EVENT_NETWORK_FOUND  = 0,
SCAN_EVENT_DONE = 1,
SCAN_EVENT_ABORTED = 2,
SCAN_EVENT_FORCE_32BIT  = 0xFFFFFFFF
}tenuScanEvent;

typedef enum
{
	CONN_DISCONN_EVENT_CONN_RESP  		= 0,
	CONN_DISCONN_EVENT_DISCONN_NOTIF 	= 1,
       CONN_DISCONN_EVENT_FORCE_32BIT  	= 0xFFFFFFFF
}tenuConnDisconnEvent;

typedef enum
{
	WEP,
	WPARxGtk,
	//WPATxGtk,
	WPAPtk,
	PMKSA,
}tenuKeyType;


/*Scan callBack function definition*/
typedef void(*tNMIpfScanResult)(tenuScanEvent, tstrNetworkInfo*, void*);

/*Connect callBack function definition*/
typedef void(*tNMIpfConnectResult)(tenuConnDisconnEvent, 
									tstrConnectInfo*, 
									NMI_Uint8, 
									tstrDisconnectNotifInfo*, 
									void*);

#ifdef NMI_P2P
/*Receving mgmt frame callback function*/
typedef void(*tNMIpfRemainOnChan)(tstrRcvdMgmtFrame *,void*);

/*Remain on channel callback function*/
typedef void(*tNMIpfRemainOnChanExpired)(void*);
#endif

//typedef NMI_Uint32 NMI_WFIDrvHandle;
typedef struct
{
	NMI_Sint32 s32Dummy;
}
*NMI_WFIDrvHandle;

/*!
*  @struct 		tstrRcvdNetworkInfo
*  @brief		Structure to hold Received Asynchronous Network info
*  @details		
*  @todo		
*  @sa			
*  @author		Mostafa Abu Bakr
*  @date		25 March 2012
*  @version		1.0 
*/
typedef struct _tstrRcvdNetworkInfo
{
	NMI_Uint8* pu8Buffer;
	NMI_Uint32 u32Length;
} tstrRcvdNetworkInfo;

/*BugID_4156*/
typedef struct _tstrHiddenNetworkInfo
{
	NMI_Uint8  *pu8ssid;
	NMI_Uint8  u8ssidlen;
	
}tstrHiddenNetworkInfo;

typedef struct _tstrHiddenNetwork
{
  //MAX_SSID_LEN
	tstrHiddenNetworkInfo *pstrHiddenNetworkInfo;
  	NMI_Uint8  u8ssidnum;
	
} tstrHiddenNetwork;

typedef struct
{		
	/* Scan user call back function */
	tNMIpfScanResult	pfUserScanResult;

	/* User specific parameter to be delivered through the Scan User Callback function */
	void* u32UserScanPvoid;

	NMI_Uint32 u32RcvdChCount;
	tstrFoundNetworkInfo astrFoundNetworkInfo[MAX_NUM_SCANNED_NETWORKS];	
}tstrNMI_UsrScanReq;

typedef struct
{
	NMI_Uint8* pu8bssid;
	NMI_Uint8* pu8ssid;
	NMI_Uint8 u8security;
	AUTHTYPE_T tenuAuth_type;
	size_t ssidLen;
	NMI_Uint8* pu8ConnReqIEs;
	size_t ConnReqIEsLen;
	/* Connect user call back function */
	tNMIpfConnectResult	pfUserConnectResult;
	NMI_Bool	IsHTCapable;
	/* User specific parameter to be delivered through the Connect User Callback function */
	void* u32UserConnectPvoid;
}tstrNMI_UsrConnReq;

#ifdef NMI_P2P
typedef struct
{
	NMI_Uint16     channel;
	NMI_Uint32  u32duration;
	tNMIpfRemainOnChan  RxProbeReq;
	tNMIpfRemainOnChanExpired pRemainOnChanExpired;
	void *  pVoid;
}tstrHostIfRemainOnChan;
#endif

typedef struct
{
	/* Scan user structure */
	tstrNMI_UsrScanReq strNMI_UsrScanReq;
	
	/* Connect User structure */
	tstrNMI_UsrConnReq strNMI_UsrConnReq;

	#ifdef NMI_P2P
	/*Remain on channel struvture*/
	tstrHostIfRemainOnChan strHostIfRemainOnChan;
	#endif

	tenuHostIFstate enuHostIFstate;

	//NMI_Bool bPendingConnRequest;

	#ifndef CONNECT_DIRECT
	NMI_Uint32 u32SurveyResultsCount;
	wid_site_survey_reslts_s astrSurveyResults[MAX_NUM_SCANNED_NETWORKS];
	#endif
	
	NMI_Uint8 au8AssociatedBSSID[ETH_ALEN];
	tstrCfgParamVal strCfgValues;
}tstrNMI_WFIDrv;

/*!
*  @enum 		tenuNMI_StaFlag
*  @brief			Used to decode the station flag set and mask in tstrNMI_AddStaParam
*  @details		
*  @todo		
*  @sa			tstrNMI_AddStaParam, enum nl80211_sta_flags
*  @author		Enumeraion's creator
*  @date			12 July 2012
*  @version		1.0 Description
*/

typedef enum
{
	NMI_STA_FLAG_INVALID = 0,
	NMI_STA_FLAG_AUTHORIZED,			/*!<  station is authorized (802.1X)*/
	NMI_STA_FLAG_SHORT_PREAMBLE,	/*!< station is capable of receiving frames	with short barker preamble*/
	NMI_STA_FLAG_WME,				/*!< station is WME/QoS capable*/
	NMI_STA_FLAG_MFP,					/*!< station uses management frame protection*/
	NMI_STA_FLAG_AUTHENTICATED		/*!< station is authenticated*/
}tenuNMI_StaFlag;

typedef struct
{
	NMI_Uint8 au8BSSID[ETH_ALEN];
	NMI_Uint16 u16AssocID;
	NMI_Uint8 u8NumRates;
	NMI_Uint8* pu8Rates;
	NMI_Bool bIsHTSupported;
	NMI_Uint16 u16HTCapInfo;
	NMI_Uint8 u8AmpduParams;
	NMI_Uint8 au8SuppMCsSet[16];
	NMI_Uint16 u16HTExtParams;
	NMI_Uint32 u32TxBeamformingCap;
	NMI_Uint8 u8ASELCap;
	NMI_Uint16 u16FlagsMask;		/*<! Determines which of u16FlagsSet were changed>*/
	NMI_Uint16 u16FlagsSet;		/*<! Decoded according to tenuNMI_StaFlag */
}tstrNMI_AddStaParam;

//extern void CfgDisconnected(void* pUserVoid, NMI_Uint16 u16reason, NMI_Uint8 * ie, size_t ie_len);

/*****************************************************************************/
/*																			 */
/*							Host Interface API								 */
/*																			 */
/*****************************************************************************/

/**
*  @brief 		removes wpa/wpa2 keys
*  @details 	only in BSS STA mode if External Supplicant support is enabled. 
				removes all WPA/WPA2 station key entries from MAC hardware.
*  @param[in,out] handle to the wifi driver
*  @param[in] 	6 bytes of Station Adress in the station entry table
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_remove_key(NMI_WFIDrvHandle hWFIDrv,const NMI_Uint8* pu8StaAddress);
/**
*  @brief 		removes WEP key
*  @details 	valid only in BSS STA mode if External Supplicant support is enabled.
				remove a WEP key entry from MAC HW. 
				The BSS Station automatically finds the index of the entry using its 
				BSS ID and removes that entry from the MAC hardware.
*  @param[in,out] handle to the wifi driver
*  @param[in] 	6 bytes of Station Adress in the station entry table
*  @return 		Error code indicating success/failure
*  @note 		NO need for the STA add since it is not used for processing 
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_remove_wep_key(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8 u8Index);
/**
*  @brief 		sets WEP deafault key
*  @details 	Sets the index of the WEP encryption key in use, 
				in the key table	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	key index ( 0, 1, 2, 3)
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_set_WEPDefaultKeyID(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8 u8Index);

/**
*  @brief 		sets WEP deafault key
*  @details 	valid only in BSS STA mode if External Supplicant support is enabled. 
				sets WEP key entry into MAC hardware when it receives the 
				corresponding request from NDIS.
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing WEP Key in the following format
				|---------------------------------------|
				|Key ID Value | Key Length |	Key		|
				|-------------|------------|------------|
				|	1byte	  |		1byte  | Key Length	|
				|---------------------------------------|

*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_add_wep_key_bss_sta(NMI_WFIDrvHandle hWFIDrv, const NMI_Uint8* pu8WepKey, NMI_Uint8 u8WepKeylen, NMI_Uint8 u8Keyidx);
/**
*  @brief 		host_int_add_wep_key_bss_ap
*  @details 	valid only in AP mode if External Supplicant support is enabled. 
				sets WEP key entry into MAC hardware when it receives the 
				corresponding request from NDIS.
*  @param[in,out] handle to the wifi driver


*  @return 		Error code indicating success/failure
*  @note 		
*  @author		mdaftedar
*  @date		28 Feb 2013
*  @version		1.0
*/
NMI_Sint32 host_int_add_wep_key_bss_ap(NMI_WFIDrvHandle hWFIDrv, const NMI_Uint8* pu8WepKey, NMI_Uint8 u8WepKeylen, NMI_Uint8 u8Keyidx,NMI_Uint8 u8mode, AUTHTYPE_T tenuAuth_type);

/**
*  @brief 		adds ptk Key
*  @details 	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing PTK Key in the following format
|-------------------------------------------------------------------------|
|Sta Adress | Key Length |	Temporal Key | Rx Michael Key |Tx Michael Key |
|-----------|------------|---------------|----------------|---------------|
|	6 bytes |	1byte	 |   16 bytes	 |	  8 bytes	  |	   8 bytes	  |
|-------------------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_add_ptk(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8* pu8Ptk,NMI_Uint8 u8PtkKeylen,
	const NMI_Uint8* mac_addr,NMI_Uint8* pu8RxMic,NMI_Uint8* pu8TxMic,NMI_Uint8 mode,NMI_Uint8 u8Ciphermode,NMI_Uint8 u8Idx);

/**
*  @brief 		host_int_get_inactive_time
*  @details 	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing inactive time

*  @return 		Error code indicating success/failure
*  @note 		
*  @author		mdaftedar
*  @date		15 April 2013
*  @version		1.0
*/
NMI_Sint32 host_int_get_inactive_time(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8 * mac,NMI_Uint32* pu32InactiveTime);

/**
*  @brief 		adds Rx GTk Key
*  @details 	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing Rx GTK Key in the following format
|----------------------------------------------------------------------------|
|Sta Address | Key RSC | KeyID | Key Length | Temporal Key	| Rx Michael Key |
|------------|---------|-------|------------|---------------|----------------|
|	6 bytes	 | 8 byte  |1 byte |  1 byte	|   16 bytes	|	  8 bytes	 |
|----------------------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
	NMI_Sint32 host_int_add_rx_gtk(NMI_WFIDrvHandle hWFIDrv, NMI_Uint8* pu8RxGtk,NMI_Uint8 u8GtkKeylen,
			NMI_Uint8 u8KeyIdx,NMI_Uint32 u32KeyRSClen, NMI_Uint8* KeyRSC,
			NMI_Uint8* pu8RxMic,NMI_Uint8* pu8TxMic,NMI_Uint8 mode,NMI_Uint8 u8Ciphermode);


/**
*  @brief 		adds Tx GTk Key
*  @details 	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing Tx GTK Key in the following format
				|----------------------------------------------------|
				| KeyID | Key Length | Temporal Key	| Tx Michael Key |
				|-------|------------|--------------|----------------|
				|1 byte |  1 byte	 |   16 bytes	|	  8 bytes	 |
				|----------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_add_tx_gtk(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8 u8KeyLen,NMI_Uint8* pu8TxGtk,NMI_Uint8 u8KeyIdx);

/**
*  @brief 		caches the pmkid 
*  @details 	valid only in BSS STA mode if External Supplicant	 	
				support is enabled. This Function sets the PMKID in firmware 
				when host drivr receives the corresponding request from NDIS. 
				The firmware then includes theset PMKID in the appropriate 
				management frames		 	
*  @param[in,out] handle to the wifi driver
*  @param[in] 	message containing PMKID Info in the following format
|-----------------------------------------------------------------|
|NumEntries |	BSSID[1] | PMKID[1] |  ...	| BSSID[K] | PMKID[K] |
|-----------|------------|----------|-------|----------|----------|
|	   1	|		6	 |   16		|  ...	|	 6	   |	16	  |
|-----------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

NMI_Sint32 host_int_set_pmkid_info(NMI_WFIDrvHandle hWFIDrv, tstrHostIFpmkidAttr* pu8PmkidInfoArray);
/**
*  @brief 		gets the cached the pmkid info
*  @details 	valid only in BSS STA mode if External Supplicant	 	
				support is enabled. This Function sets the PMKID in firmware 
				when host drivr receives the corresponding request from NDIS. 
				The firmware then includes theset PMKID in the appropriate 
				management frames		 	
*  @param[in,out] handle to the wifi driver, 

				  message containing PMKID Info in the following format
		|-----------------------------------------------------------------|
		|NumEntries |	BSSID[1] | PMKID[1] |  ...	| BSSID[K] | PMKID[K] |
		|-----------|------------|----------|-------|----------|----------|
		|	   1	|		6	 |   16		|  ...	|	 6	   |	16	  |
		|-----------------------------------------------------------------|
*  @param[in] 	
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

NMI_Sint32 host_int_get_pmkid_info(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8* pu8PmkidInfoArray, 
									   NMI_Uint32 u32PmkidInfoLen);

/**
*  @brief 		sets the pass phrase
*  @details 	AP/STA mode. This function gives the pass phrase used to
				generate the Pre-Shared Key when WPA/WPA2 is enabled	
				The length of the field can vary from 8 to 64 bytes, 
				the lower layer should get the  	
*  @param[in,out] handle to the wifi driver, 	
*  @param[in] 	 String containing PSK 
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_set_RSNAConfigPSKPassPhrase(NMI_WFIDrvHandle hWFIDrv, NMI_Uint8* pu8PassPhrase, 
														  NMI_Uint8 u8Psklength);
/**
*  @brief 		gets the pass phrase
*  @details 	AP/STA mode. This function gets the pass phrase used to
				generate the Pre-Shared Key when WPA/WPA2 is enabled	
				The length of the field can vary from 8 to 64 bytes, 
				the lower layer should get the  	
*  @param[in,out] handle to the wifi driver, 
				  String containing PSK 
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_get_RSNAConfigPSKPassPhrase(NMI_WFIDrvHandle hWFIDrv,
												NMI_Uint8* pu8PassPhrase, NMI_Uint8 u8Psklength);

/**
*  @brief 		gets mac address
*  @details
*  @param[in,out] handle to the wifi driver,

*  @return 		Error code indicating success/failure
*  @note
*  @author		mdaftedar
*  @date		19 April 2012
*  @version		1.0
*/
NMI_Sint32 host_int_get_MacAddress(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8* pu8MacAddress);

/**
*  @brief 		sets mac address
*  @details
*  @param[in,out] handle to the wifi driver,

*  @return 		Error code indicating success/failure
*  @note
*  @author		mabubakr
*  @date		16 July 2012
*  @version		1.0
*/
NMI_Sint32 host_int_set_MacAddress(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8* pu8MacAddress);

/**
*  @brief 		gets the site survey results
*  @details 	  	
*  @param[in,out] handle to the wifi driver, 
				  Message containing  site survey results in the 
				  following formate 
|---------------------------------------------------|
| MsgLength | fragNo.	| MsgBodyLength	| MsgBody	|					
|-----------|-----------|---------------|-----------|
|	 1		|	  1		|		1		|	 1		|					
-----------------------------------------	 |  ----------------
										     |   						
						|---------------------------------------|
						| Network1 | Netweork2 | ... | Network5 |
						|---------------------------------------|
						|	44	   |	44	   | ... |	 44		|
-------------------------- | ---------------------------------------
							 |
|---------------------------------------------------------------------|
| SSID | BSS Type | Channel | Security Status| BSSID | RSSI |Reserved |
|------|----------|---------|----------------|-------|------|---------|
|  33  |	 1	  |	  1		|		1		 |	  6	 |	 1	|	 1	  |
|---------------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
#ifndef CONNECT_DIRECT
NMI_Sint32 host_int_get_site_survey_results(NMI_WFIDrvHandle hWFIDrv, 
											NMI_Uint8 ppu8RcvdSiteSurveyResults[][MAX_SURVEY_RESULT_FRAG_SIZE], 
											NMI_Uint32 u32MaxSiteSrvyFragLen);
#endif

/**
*  @brief 		sets a start scan request
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]	Scan Source one of the following values
				DEFAULT_SCAN        0									
				USER_SCAN           BIT0								
				OBSS_PERIODIC_SCAN  BIT1								
				OBSS_ONETIME_SCAN   BIT2	
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

NMI_Sint32 host_int_set_start_scan_req(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8 scanSource);
/**
*  @brief 		gets scan source of the last scan
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
				Scan Source one of the following values
				DEFAULT_SCAN        0									
				USER_SCAN           BIT0								
				OBSS_PERIODIC_SCAN  BIT1								
				OBSS_ONETIME_SCAN   BIT2	
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
 NMI_Sint32 host_int_get_start_scan_req(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8* pu8ScanSource);

/**
*  @brief 		sets a join request
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]	Index of the bss descriptor 	
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

NMI_Sint32 host_int_set_join_req(NMI_WFIDrvHandle hWFIDrv, NMI_Uint8* pu8bssid,
							     NMI_Uint8* pu8ssid, size_t ssidLen,
							     const NMI_Uint8* pu8IEs, size_t IEsLen,
							     tNMIpfConnectResult pfConnectResult, void* pvUserArg, 
							     NMI_Uint8 u8security, AUTHTYPE_T tenuAuth_type, 
							     NMI_Uint8 u8channel);

/**
*  @brief 		disconnects from the currently associated network
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]	Reason Code of the Disconnection
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_disconnect(NMI_WFIDrvHandle hWFIDrv, NMI_Uint16 u16ReasonCode);

/**
*  @brief 		disconnects a sta
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]	Association Id of the station to be disconnected	
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_disconnect_station(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8 assoc_id);
/**
*  @brief 		gets a Association request info
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
				Message containg assoc. req info in the following format
------------------------------------------------------------------------
|                        Management Frame Format                    |
|-------------------------------------------------------------------| 
|Frame Control|Duration|DA|SA|BSSID|Sequence Control|Frame Body|FCS |
|-------------|--------|--|--|-----|----------------|----------|----|
| 2           |2       |6 |6 |6    |		2       |0 - 2312  | 4  |
|-------------------------------------------------------------------|
|                                                                   |
|             Association Request Frame - Frame Body                |
|-------------------------------------------------------------------|
| Capability Information | Listen Interval | SSID | Supported Rates |
|------------------------|-----------------|------|-----------------|
|			2            |		 2         | 2-34 |		3-10        |
| ---------------------------------------------------------------------
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

NMI_Sint32 host_int_get_assoc_req_info(NMI_WFIDrvHandle hWFIDrv, NMI_Uint8* pu8AssocReqInfo, 
										    NMI_Uint32 u32AssocReqInfoLen);
/**
*  @brief 		gets a Association Response info
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
				Message containg assoc. resp info 
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/

NMI_Sint32 host_int_get_assoc_res_info(NMI_WFIDrvHandle hWFIDrv, NMI_Uint8* pu8AssocRespInfo, 
										    NMI_Uint32 u32MaxAssocRespInfoLen, NMI_Uint32* pu32RcvdAssocRespInfoLen);
/**
*  @brief 		gets a Association Response info
*  @details 	Valid only in STA mode. This function gives the RSSI	
				values observed in all the channels at the time of scanning.
				The length of the field is 1 greater that the total number of 
				channels supported. Byte 0 contains the number of channels while
				each of Byte N contains	the observed RSSI value for the channel index N.							
*  @param[in,out] handle to the wifi driver,
				array of scanned channels' RSSI 
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_get_rx_power_level(NMI_WFIDrvHandle hWFIDrv, NMI_Uint8* pu8RxPowerLevel, 
										   NMI_Uint32 u32RxPowerLevelLen);

/**
*  @brief 		sets a channel
*  @details 	 	
*  @param[in,out] handle to the wifi driver, 
*  @param[in]	Index of the channel to be set		
|-------------------------------------------------------------------| 
|          CHANNEL1      CHANNEL2 ....		             CHANNEL14	|
|  Input:         1             2					            14	|
|-------------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_set_mac_chnl_num(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8 u8ChNum);

/**
*  @brief 		gets the current channel index
*  @details 	 	
*  @param[in,out] handle to the wifi driver,
				current channel index
|-----------------------------------------------------------------------| 
|          CHANNEL1      CHANNEL2 ....                     CHANNEL14	|
|  Input:         1             2                                 14	|
|-----------------------------------------------------------------------|
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_get_host_chnl_num(NMI_WFIDrvHandle hWFIDrv, NMI_Uint8* pu8ChNo);
/**
*  @brief 		gets the sta rssi
*  @details 	gets the currently maintained RSSI value for the station. 
				The received signal strength value in dB. 
				The range of valid values is -128 to 0.
*  @param[in,out] handle to the wifi driver,
				rssi value in dB
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_get_rssi(NMI_WFIDrvHandle hWFIDrv, NMI_Sint8* ps8Rssi);
NMI_Sint32 host_int_get_link_speed(NMI_WFIDrvHandle hWFIDrv, NMI_Sint8* ps8lnkspd);
/**
*  @brief 		scans a set of channels
*  @details 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]		Scan source
				Scan Type	PASSIVE_SCAN = 0,							
							ACTIVE_SCAN  = 1
				Channels Array
				Channels Array length
				Scan Callback function
				User Argument to be delivered back through the Scan Cllback function
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_scan(NMI_WFIDrvHandle hWFIDrv, NMI_Uint8 u8ScanSource,
					     NMI_Uint8 u8ScanType, NMI_Uint8* pu8ChnlFreqList,
					     NMI_Uint8 u8ChnlListLen, const NMI_Uint8* pu8IEs,
					     size_t IEsLen, tNMIpfScanResult ScanResult,
					     void* pvUserArg,tstrHiddenNetwork  *pstrHiddenNetwork);
/**
*  @brief 		sets configuration wids values
*  @details 	
*  @param[in,out] handle to the wifi driver,
*  @param[in]	WID, WID value				
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 hif_set_cfg(NMI_WFIDrvHandle hWFIDrv, tstrCfgParamVal * pstrCfgParamVal);

/**
*  @brief 		gets configuration wids values
*  @details 	
*  @param[in,out] handle to the wifi driver, 
				WID value
*  @param[in]	WID, 				
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 hif_get_cfg(NMI_WFIDrvHandle hWFIDrv,NMI_Uint16 u16WID,NMI_Uint16* pu16WID_Value);
/*****************************************************************************/
/*							Notification Functions							 */
/*****************************************************************************/
/**
*  @brief 		notifies host with join and leave requests
*  @details 	This function prepares an Information frame having the
				information about a joining/leaving station.
*  @param[in,out] handle to the wifi driver,
*  @param[in]	6 byte Sta Adress
				Join or leave flag:
				Join = 1,
				Leave =0
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
void host_int_send_join_leave_info_to_host
						(NMI_Uint16 assocId, NMI_Uint8* stationAddr, NMI_Bool joining);

/**
*  @brief 		notifies host with stations found in scan
*  @details 	sends the beacon/probe response from scan
*  @param[in,out] handle to the wifi driver,
*  @param[in]	Sta Address,
				Frame length,
				Rssi of the Station found
*  @return 		Error code indicating success/failure
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
void host_int_send_network_info_to_host
			(NMI_Uint8 *macStartAddress,NMI_Uint16 u16RxFrameLen, NMI_Sint8 s8Rssi);

/**
*  @brief 		host interface initialization function
*  @details 	
*  @param[in,out] handle to the wifi driver,
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_init(NMI_WFIDrvHandle* phWFIDrv);

/**
*  @brief 		host interface initialization function
*  @details 	
*  @param[in,out] handle to the wifi driver,
*  @note 		
*  @author		zsalah
*  @date		8 March 2012
*  @version		1.0
*/
NMI_Sint32 host_int_deinit(NMI_WFIDrvHandle hWFIDrv);


/*!
 *  @fn		NMI_Sint32 host_int_add_beacon(NMI_WFIDrvHandle hWFIDrv,NMI_Uint8 u8Index)
 *  @brief		Sends a beacon to the firmware to be transmitted over the air
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	u32Interval	Beacon Interval. Period between two successive beacons on air
 *  @param[in]	u32DTIMPeriod DTIM Period. Indicates how many Beacon frames
 * 		(including the current frame) appear before the next DTIM	 
 *  @param[in]	u32Headlen	Length of the head buffer in bytes
 *  @param[in]	pu8Head		Pointer to the beacon's head buffer. Beacon's head
 *		is the part from the beacon's start till the TIM element, NOT including the TIM
 *  @param[in]	u32Taillen	Length of the tail buffer in bytes
 *  @param[in]	pu8Tail		Pointer to the beacon's tail buffer. Beacon's tail
 *		starts just after the TIM inormation element
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		10 Julys 2012
 *  @version		1.0 Description

 */
NMI_Sint32 host_int_add_beacon(NMI_WFIDrvHandle hWFIDrv, NMI_Uint32 u32Interval,
									 NMI_Uint32 u32DTIMPeriod,
									 NMI_Uint32 u32HeadLen, NMI_Uint8* pu8Head,
									 NMI_Uint32 u32TailLen, NMI_Uint8* pu8tail);


/*!
 *  @fn		NMI_Sint32 host_int_del_beacon(NMI_WFIDrvHandle hWFIDrv)
 *  @brief		Removes the beacon and stops tranmitting it over the air
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		10 Julys 2012
 *  @version		1.0 Description
 */
NMI_Sint32 host_int_del_beacon(NMI_WFIDrvHandle hWFIDrv);

/*!
 *  @fn		NMI_Sint32 host_int_add_station(NMI_WFIDrvHandle hWFIDrv, tstrNMI_AddStaParam strStaParams)
 *  @brief		Notifies the firmware with a new associated stations
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	pstrStaParams	Station's parameters
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		12 July 2012
 *  @version		1.0 Description
 */
NMI_Sint32 host_int_add_station(NMI_WFIDrvHandle hWFIDrv, tstrNMI_AddStaParam* pstrStaParams);


/*!
 *  @fn		NMI_Sint32 host_int_del_station(NMI_WFIDrvHandle hWFIDrv, NMI_Uint8* pu8MacAddr)
 *  @brief		Notifies the firmware with a new deleted station
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	pu8MacAddr	Station's mac address
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		15 July 2012
 *  @version		1.0 Description
 */
NMI_Sint32 host_int_del_station(NMI_WFIDrvHandle hWFIDrv, NMI_Uint8* pu8MacAddr);

/*!
 *  @fn		NMI_Sint32 host_int_edit_station(NMI_WFIDrvHandle hWFIDrv, tstrNMI_AddStaParam strStaParams)
 *  @brief		Notifies the firmware with new parameters of an already associated station
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	pstrStaParams	Station's parameters
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		15 July 2012
 *  @version		1.0 Description
 */
NMI_Sint32 host_int_edit_station(NMI_WFIDrvHandle hWFIDrv, tstrNMI_AddStaParam* pstrStaParams);

/*!
 *  @fn		NMI_Sint32 host_int_set_power_mgmt(NMI_WFIDrvHandle hWFIDrv, NMI_Bool bIsEnabled, NMI_Uint32 u32Timeout)
 *  @brief		Set the power management mode to enabled or disabled
 *  @details	
 *  @param[in,out]	hWFIDrv		handle to the wifi driver
 *  @param[in]	bIsEnabled	TRUE if enabled, FALSE otherwise
 *  @param[in]	u32Timeout	A timeout value of -1 allows the driver to adjust
 *							the dynamic ps timeout value
 *  @return	0 for Success, error otherwise
 *  @todo
 *  @sa
 *  @author		Adham Abozaeid
 *  @date		24 November 2012
 *  @version		1.0 Description
 */
NMI_Sint32 host_int_set_power_mgmt(NMI_WFIDrvHandle hWFIDrv, NMI_Bool bIsEnabled, NMI_Uint32 u32Timeout);

#ifdef NMI_P2P
/**
*  @brief           host_int_remain_on_channel
*  @details 	   Remaining on specific channel required by wpas
*  @param[in]    
*  @return 	    Error code.
*  @author	Mai Daftedar
*  @date	
*  @version	1.0
*/
NMI_Sint32 host_int_remain_on_channel(NMI_WFIDrvHandle hWFIDrv, NMI_Uint32 u32duration,NMI_Uint16 chan, tNMIpfRemainOnChan RxMgmt,tNMIpfRemainOnChanExpired RemainOnChanExpired,void* pvUserArg);
#endif

static NMI_Sint32 Handle_ScanDone(tenuScanEvent enuEvent);

static int host_int_addBASession(char* pBSSID,char TID,short int BufferSize,
	short int SessionTimeout);


/*****************************************************************************/
/*																			 */
/*									EOF										 */
/*																			 */
/*****************************************************************************/
#endif 
