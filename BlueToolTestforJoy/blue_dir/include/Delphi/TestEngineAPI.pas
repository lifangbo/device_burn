{ TestEngineAPI.pas : Declares the DLL functions for Delpi. }
{ Generated by C:\work_bluesuite_2_5\p4\common\hosttools\bluesuite_2_5\prodtest\scripts\extract_tt_api.pl from TestEngine.h;  at 03/02/14 - 11:36:54 }

unit TestEngineAPI;

interface

function teGetVersion( versionStr: PChar): Integer; stdcall; external 'TestEngine.dll' ;
function openTestEngine( transport: Integer;  transportDevice: PChar;  dataRate: Cardinal;  retryTimeOut: Integer;  usbTimeOut: Integer): Cardinal; stdcall; external 'TestEngine.dll' ;
function openTestEngineSpi( port: Integer;  multi: Integer;  transport: Integer): Cardinal; stdcall; external 'TestEngine.dll' ;
function openTestEngineSpiUnlock( port: Integer;  multi: Integer;  transport: Integer;  unlockKey: PChar): Cardinal; stdcall; external 'TestEngine.dll' ;
function openTestEngineSpiTrans( trans: PChar;  multi: Integer): Cardinal; stdcall; external 'TestEngine.dll' ;
function openTestEngineSpiUnlockTrans( trans: PChar;  multi: Integer;  unlockKey: PChar): Cardinal; stdcall; external 'TestEngine.dll' ;
function closeTestEngine( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function teGetLastError( handle: Cardinal): Cardinal; stdcall; external 'TestEngine.dll' ;
function bccmdSetColdReset( handle: Cardinal;  usbTimeout: Integer): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetWarmReset( handle: Cardinal;  usbTimeout: Integer): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestPause( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestDeepSleep( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestPcmExtLb( handle: Cardinal;  pcm_mode: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestPcmExtLbIf( handle: Cardinal;  pcm_mode: Word;  pcm_if: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestPcmLb( handle: Cardinal;  pcm_mode: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestPcmLbIf( handle: Cardinal;  pcm_mode: Word;  pcm_if: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestPcmTimingIn( handle: Cardinal;  pio_out: Word;  pcm_in: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestPcmTimingInIf( handle: Cardinal;  pio_out: Word;  pcm_in: Word;  pcm_if: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestPcmTone( handle: Cardinal;  freq: Word;  ampl: Word;  dc: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestPcmToneIf( handle: Cardinal;  freq: Word;  ampl: Word;  dc: Word;  pcm_if: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestPcmToneStereo( handle: Cardinal;  freq: Word;  ampl: Word;  dc: Word;  channel: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCtsRtsLb( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestRadioStatus( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hqGetRadioStatus( handle: Cardinal;  r: Word;  timeout: Integer): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestRadioStatusArray( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hqGetRadioStatusArray( handle: Cardinal;  r: Word;  timeout: Integer): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdMemoryGet( handle: Cardinal;  baseAddr: Word;  dataLength: Word;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdMemorySet( handle: Cardinal;  baseAddr: Word;  dataLength: Word;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetBuildId( handle: Cardinal; var buildid: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdBuildName( handle: Cardinal;  name: PChar;  max_len: Word; var length: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetChipVersion( handle: Cardinal; var chipver: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetChipRevision( handle: Cardinal; var chiprev: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetChipAnaVer( handle: Cardinal; var major: Byte; var minor: Byte; var vari: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdRouteClock( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdRssiAcl( handle: Cardinal;  connectionHandle: Word; var rssi: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetPio( handle: Cardinal;  mask: Word;  port: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetPio( handle: Cardinal; var mask: Word; var port: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdMapPio32( handle: Cardinal;  mask: Cardinal;  pios: Cardinal; var errLines: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetPio32( handle: Cardinal;  mask: Cardinal;  direction: Cardinal;  value: Cardinal; var errLines: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetPio32( handle: Cardinal; var direction: Cardinal; var value: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetAdc( handle: Cardinal;  adc: Word; var result: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetAio( handle: Cardinal;  aio: Word; var result: Word; var numBits: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdBC5MMGetBatteryVoltage( handle: Cardinal; var voltage: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetFirmwareCheckMask( handle: Cardinal; var mask: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetFirmwareCheck( handle: Cardinal; var check: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetExternalClockPeriod( handle: Cardinal; var period: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdEnableDeviceConnect( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdEnableDeviceUnderTestMode( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestStereoCodecLB( handle: Cardinal;  sampleRate: Word;  reroute: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestTxstart( handle: Cardinal;  frequency: Word;  intPA: Word;  extPA: Word;  modulation: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestTxdata1( handle: Cardinal;  frequency: Word;  intPA: Word;  extPA: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestTxdata2( handle: Cardinal;  countrycode: Word;  intPA: Word;  extPA: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestTxdata3( handle: Cardinal;  frequency: Word;  intPA: Word;  extPA: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestTxdata4( handle: Cardinal;  frequency: Word;  intPA: Word;  extPA: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgTxPower( handle: Cardinal;  power: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestRxstart1( handle: Cardinal;  frequency: Word;  hiside: Byte;  rx_attenuation: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestRxstart2( handle: Cardinal;  frequency: Word;  hiside: Byte;  rx_attenuation: Word;  sample_size: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hqGetRssi( handle: Cardinal;  timeout: Integer;  max_size: Word;  r: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestBer1( handle: Cardinal;  frequency: Word;  hiside: Byte;  rx_attenuation: Word;  sampleSize: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestBer2( handle: Cardinal;  country_code: Word;  hiside: Byte;  rx_attenuation: Word;  sampleSize: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestBerLoopback( handle: Cardinal;  frequency: Word;  intPA: Word;  extPA: Word;  sampleSize: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestRxLoopback( handle: Cardinal;  frequency: Word;  intPA: Word;  extPA: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestLoopback( handle: Cardinal;  frequency: Word;  intPA: Word;  extPA: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hqGetBer( handle: Cardinal;  timeout: Integer;  r: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestRxdata1( handle: Cardinal;  frequency: Word;  hiside: Byte;  rx_attenuation: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestRxdata2( handle: Cardinal;  countrycode: Word;  hiside: Byte;  rx_attenuation: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hqGetRxdata( handle: Cardinal;  timeout: Integer;  r: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgFreq( handle: Cardinal;  txrxinterval: Word;  loopback: Word;  report: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgFreqMs( handle: Cardinal;  txrxinterval: Word;  loopback: Word;  report: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgPkt( handle: Cardinal;  aType: Word;  size: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgBitError( handle: Cardinal;  sampleSize: Cardinal;  reset: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgTxPaAtten( handle: Cardinal;  atten: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgXtalFtrim( handle: Cardinal;  ftrim: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCalcXtalOffset( nominalFreqMhz: Double;  actualFreqMhz: Double; var offset: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgUapLap( handle: Cardinal;  uap: Word;  lap: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgIqTrim( handle: Cardinal;  trim: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgTxIf( handle: Cardinal;  offset: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgTxTrim( handle: Cardinal;  am_addr: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgLoLvl( handle: Cardinal;  lo_lvl: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestCfgHoppingSeq( handle: Cardinal;  channels: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestSettle( handle: Cardinal;  start: Word;  aEnd: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hqGetSettle( handle: Cardinal;  r: Word): Integer; stdcall; external 'TestEngine.dll' ;
function get_freq_offset( handle: Cardinal; var offset: Double;  sample_size: Integer): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetEeprom( handle: Cardinal;  log2bytes: Word;  addrMask: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psReadBdAddr( handle: Cardinal; var lap: Cardinal; var uap: Byte; var nap: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psRead( handle: Cardinal;  psKey: Word;  store: Word;  arrayLen: Word;  data: Word; var aLen: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psClear( handle: Cardinal;  psKey: Word;  store: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psClearAll( handle: Cardinal;  store: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psFactorySet( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function psFactoryRestoreAll( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function psFactoryRestore( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function psSize( handle: Cardinal;  psKey: Word;  store: Word; var size: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWrite( handle: Cardinal;  psKey: Word;  store: Word;  length: Word;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteVerify( handle: Cardinal;  psKey: Word;  store: Word;  length: Word;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteBdAddr( handle: Cardinal;  lap: Cardinal;  uap: Cardinal;  nap: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function psReadModuleId( handle: Cardinal; var moduleId: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function psReadXtalFtrim( handle: Cardinal; var fTrim: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteXtalFtrim( handle: Cardinal;  fTrim: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psReadXtalOffset( handle: Cardinal; var offset: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteXtalOffset( handle: Cardinal;  offset: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteModuleSecurityCode( handle: Cardinal;  code: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteModuleId( handle: Cardinal;  moduleId: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteBaudrate( handle: Cardinal;  value: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteRadiotestFirstTrimTime( handle: Cardinal;  time: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function psReadRadiotestFirstTrimTime( handle: Cardinal; var time: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteRadiotestLoLvlTrimEnable( handle: Cardinal;  state: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psReadRadiotestLoLvlTrimEnable( handle: Cardinal; var state: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteRadiotestSubsequentTrimTime( handle: Cardinal;  time: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function psReadRadiotestSubsequentTrimTime( handle: Cardinal; var time: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteHostInterface( handle: Cardinal;  transport: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psReadHostInterface( handle: Cardinal; var transport: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteUsbAttributes( handle: Cardinal;  bmAttributes: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteDPlusPullup( handle: Cardinal;  pioPin: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteUsbMaxPower( handle: Cardinal;  maxPower: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWritePioProtectMask( handle: Cardinal;  mask: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psReadPioProtectMask( handle: Cardinal; var mask: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteTxOffsetHalfMhz( handle: Cardinal;  offset: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function psReadTxOffsetHalfMhz( handle: Cardinal; var offset: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteUsrValue( handle: Cardinal;  userNo: Word;  length: Word;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psReadUsrValue( handle: Cardinal;  userNo: Word;  maxLen: Word; var length: Word;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function psWritePowerTable( handle: Cardinal;  numEntries: Word;  intPA: Byte;  extPA: Byte;  power: Integer): Integer; stdcall; external 'TestEngine.dll' ;
function psReadPowerTable( handle: Cardinal;  maxSize: Integer; var numEntries: Integer;  intPA: Byte;  extPA: Byte;  power: Integer): Integer; stdcall; external 'TestEngine.dll' ;
function psWriteVmDisable( handle: Cardinal;  vmDisable: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function psReadVmDisable( handle: Cardinal; var vmDisable: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function psMergeFromFile( handle: Cardinal;  filePath: PChar): Integer; stdcall; external 'TestEngine.dll' ;
function hciSlave( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hciSetAfhHostChannelClass( handle: Cardinal;  cClass: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function hciReadAfhChannelMap( handle: Cardinal;  aclHandle: Word; var mode: Byte;  cMap: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function hciSetEventFilterAutoacceptConnection( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hciWriteInquiryScanActivity( handle: Cardinal;  inquiryscan_interval: Word;  inquiryscan_window: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciWritePageScanActivity( handle: Cardinal;  pagescan_interval: Word;  pagescan_window: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciWriteScanEnable( handle: Cardinal;  scan_enable: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function hciInquiry( handle: Cardinal;  inquiryLength: Byte;  numResponses: Byte;  lap: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hciGetInquiryResults( handle: Cardinal;  lap: Cardinal;  uap: Byte;  nap: Word;  clockOffset: Word;  maxLen: Cardinal; var aLen: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hciInquiryCancel( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hciCreateConnection( handle: Cardinal;  lap: Cardinal;  uap: Byte;  nap: Word;  pkt_type: Word; var connectionHandle: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciCreateConnectionNoInquiry( handle: Cardinal;  lap: Cardinal;  uap: Byte;  nap: Word;  pkt_type: Word;  page_scan_rep_mode: Byte;  page_scan_mode: Byte;  clock_offset: Word;  allow_role_switch: Byte; var connectionHandle: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciCreateScoConnection( handle: Cardinal;  aclConnectionHandle: Word;  pkt_type: Word; var scoConnectionHandle: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciSetupScoConnection( handle: Cardinal;  aclConnectionHandle: Word;  txBandwidth: Cardinal;  rxBandwidth: Cardinal;  maxLatency: Word;  voiceSetting: Word;  retransEffort: Byte;  pktType: Word; var scoConnectionHandle: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciReadVoiceSetting( handle: Cardinal; var voiceSetting: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciWriteVoiceSetting( handle: Cardinal;  voiceSetting: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciWriteLinkPolicySettings( handle: Cardinal;  connection_handle: Word;  link_policy_settings: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciSendAclFile( handle: Cardinal;  connHandle: Word;  fileName: PChar): Integer; stdcall; external 'TestEngine.dll' ;
function hciSendAclData( handle: Cardinal;  connHandle: Word;  data: Byte;  length: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciGetAclData( handle: Cardinal;  data: Byte; var numBytes: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hciGetAclBytesRead( handle: Cardinal; var numBytes: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hciGetAclFileName( handle: Cardinal;  fileName: PChar; var length: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hciGetAclState( handle: Cardinal; var state: Integer): Integer; stdcall; external 'TestEngine.dll' ;
function hciResetAclState( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hciReset( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetAnaXtalFtrim( handle: Cardinal; var ftrim: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetAnaXtalFtrim( handle: Cardinal;  ftrim: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciSniffMode( handle: Cardinal;  connection_handle: Word;  sniff_max_interval: Word;  sniff_min_interval: Word;  sniff_attempt: Word;  sniff_timeout: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciExitSniff( handle: Cardinal;  connection_handle: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciDisconnect( handle: Cardinal;  connection_handle: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciGetConnectionHandle( handle: Cardinal;  lap: Cardinal;  uap: Byte;  nap: Word; var connectionHandle: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciConnectionStatus( handle: Cardinal;  connection_handle: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciEnableDeviceUnderTestMode( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hciGetLinkQuality( handle: Cardinal;  connection_handle: Word; var quality: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function hciReadRemoteVersionInformation( handle: Cardinal;  connection_handle: Word;  r: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function hciReadRemoteNameRequest( handle: Cardinal;  lap: Cardinal;  uap: Byte;  nap: Word;  page_scan_repetition_mode: Byte;  page_scan_offset: Byte;  clock_offset: Word;  r: PChar): Integer; stdcall; external 'TestEngine.dll' ;
function dmRegisterReq( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function dmSlave( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function dmEnableDeviceUnderTestMode( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function dmWritePageScanActivity( handle: Cardinal;  pagescan_interval: Word;  pagescan_window: Word): Integer; stdcall; external 'TestEngine.dll' ;
function dmWriteInquiryScanActivity( handle: Cardinal;  inquiryscan_interval: Word;  inquiryscan_window: Word): Integer; stdcall; external 'TestEngine.dll' ;
function dmWriteScanEnable( handle: Cardinal;  scan_enable: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function dmSetEventFilterAutoacceptConnection( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdBc3PsuTrim( handle: Cardinal;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdChargerPsuTrim( handle: Cardinal;  trim: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdBc3BuckReg( handle: Cardinal;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdPsuSmpsEnable( handle: Cardinal;  reg: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdBc3MicEn( handle: Cardinal;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdPsuHvLinearEnable( handle: Cardinal;  reg: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdBc3Led0( handle: Cardinal;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdLedEnable( handle: Cardinal;  led: Word;  state: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdLed0Enable( handle: Cardinal;  state: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdBc3Led1( handle: Cardinal;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdLed1Enable( handle: Cardinal;  state: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdChargerStatus( handle: Cardinal; var state: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdChargerDisable( handle: Cardinal;  state: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdChargerSuppressLed0( handle: Cardinal;  state: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciCreateConnectionNoWait( handle: Cardinal;  lap: Cardinal;  uap: Byte;  nap: Word;  pktType: Word;  pageScanRepMode: Byte;  pageScanMode: Byte;  clockOffset: Word;  allowRoleSwitch: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function hciWriteAuthenticationEnable( handle: Cardinal;  enable: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function hciLinkKeyRequestNegativeReply( handle: Cardinal;  lap: Cardinal;  uap: Byte;  nap: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciWaitForConnectionComplete( handle: Cardinal; var connHandle: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciWaitForLinkKeyRequest( handle: Cardinal; var lap: Cardinal; var uap: Byte; var nap: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciWaitForPinCodeRequest( handle: Cardinal; var lap: Cardinal; var uap: Byte; var nap: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hciWaitForEncryptionChange( handle: Cardinal; var enable: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function hciPinCodeRequestReply( handle: Cardinal;  lap: Cardinal;  uap: Byte;  nap: Word;  pinCodeLength: Byte;  pinCode: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function hciSetConnectionEncryption( handle: Cardinal;  connHandle: Word;  enable: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function vmWrite( handle: Cardinal;  data: Word): Integer; stdcall; external 'TestEngine.dll' ;
function vmRead( handle: Cardinal;  data: Word;  timeout: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetSingleChan( handle: Cardinal;  channel: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetHoppingOn( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmSwitchPower( handle: Cardinal;  powerOn: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmSetFreq( handle: Cardinal;  freqKHz: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmGetRssi( handle: Cardinal; var rssi: ShortInt): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmGetSnr( handle: Cardinal; var snr: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmGetIfOffset( handle: Cardinal; var offset: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmGetStatus( handle: Cardinal; var status: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmSetupAudio( handle: Cardinal;  route: Byte;  gain: Byte;  channel: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmVerifyRDSPi( handle: Cardinal;  pi: Word;  timeoutMs: Word; var matched: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmTxSwitchPower( handle: Cardinal;  powerOn: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmTxSetFreq( handle: Cardinal;  freqKHz: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmTxSetPowerLevel( handle: Cardinal;  powerLevel: SmallInt): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdFmTxSetupAudio( handle: Cardinal;  route: Byte;  audioGain: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdDisconnectAudio( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdDirectChargerPsuTrim( handle: Cardinal;  trim: Word): Integer; stdcall; external 'TestEngine.dll' ;
function teSupportsHq( handle: Cardinal; var hqSupported: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetAuxDac( handle: Cardinal;  enable: Byte;  level: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetMicBiasIf( handle: Cardinal;  instance: Byte;  enable: Byte;  voltage: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetMicBias( handle: Cardinal;  enable: Byte;  voltage: Byte;  current: Byte;  enableLowPowerMode: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function teGetAvailableSpiPorts(var maxLen: Word;  ports: PChar;  trans: PChar; var count: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdProvokeFault( handle: Cardinal;  faultCode: Word): Integer; stdcall; external 'TestEngine.dll' ;
function hqGetFaultReports( handle: Cardinal;  maxReports: Word;  codes: Word;  timestamps: Cardinal;  repeats: Word; var numReports: Word;  timeout: Integer): Integer; stdcall; external 'TestEngine.dll' ;
function teGetFaultDesc( handle: Cardinal;  faultCode: Word;  desc: PChar): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetMapScoPcm( handle: Cardinal;  enable: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetVrefConstant( handle: Cardinal; var vref: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetVrefAdc( handle: Cardinal; var result: Word; var numBits: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdBC5FMGetI2CState( handle: Cardinal; var sda: Byte; var scl: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function refEpGetRssiDbm( handle: Cardinal;  freqMHz: Word;  rssiChip: Double; var rssiDbm: Double): Integer; stdcall; external 'TestEngine.dll' ;
function refEpGetPaLevel( handle: Cardinal;  freqMHz: Word;  targetPowerDbm: Double; var intPa: Word; var powerDbm: Double): Integer; stdcall; external 'TestEngine.dll' ;
function refEpWriteCalDataFile( handle: Cardinal;  filePath: PChar): Integer; stdcall; external 'TestEngine.dll' ;
function refEpLoadCalDataFile( handle: Cardinal;  filePath: PChar): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetVmStatus( handle: Cardinal; var status: Word; var exitCode: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdI2CTransfer( handle: Cardinal;  slaveAddr: Word;  txOctets: Word;  rxOctets: Word;  restart: Byte;  data: Byte; var octets: Word): Integer; stdcall; external 'TestEngine.dll' ;
function radiotestBle( handle: Cardinal;  command: Word;  channel: Byte;  txLength: Byte;  txPayload: Byte): Integer; stdcall; external 'TestEngine.dll' ;
function hqGetBleRxPktCount( handle: Cardinal;  timeout: Integer; var pktCount: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetChargerTrims( handle: Cardinal; var chgRefTrim: Word; var hVrefTrim: Word; var rTrim: Word; var iTrim: Word; var iExtTrim: Word; var iTermTrim: Word; var vFastTrim: Word; var hystTrim: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdCapSenseRead( handle: Cardinal;  mask: Word;  values: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSetSpiLockCustomerKey( handle: Cardinal;  custKey: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdGetSpiLockStatus( handle: Cardinal; var status: Word): Integer; stdcall; external 'TestEngine.dll' ;
function bccmdSpiLockInitiateLock( handle: Cardinal): Integer; stdcall; external 'TestEngine.dll' ;
function teGetChipDisplayName( handle: Cardinal;  maxLen: Cardinal;  name: PChar): Integer; stdcall; external 'TestEngine.dll' ;

{ DEPRECATED FUNCTIONS }

function bccmdPsuBuckReg( handle: Cardinal;  reg: Word): Integer; stdcall; external 'TestEngine.dll' name 'bccmdPsuSmpsEnable';
function bccmdPsuMicEn( handle: Cardinal;  reg: Word): Integer; stdcall; external 'TestEngine.dll' name 'bccmdPsuHvLinearEnable';
function bccmdLed0( handle: Cardinal;  state: Word): Integer; stdcall; external 'TestEngine.dll' name 'bccmdLed0Enable';
function bccmdLed1( handle: Cardinal;  state: Word): Integer; stdcall; external 'TestEngine.dll' name 'bccmdLed1Enable';
function bccmdChargerSupressLed0( handle: Cardinal;  state: Word): Integer; stdcall; external 'TestEngine.dll' name 'bccmdChargerSuppressLed0';

implementation

end.
