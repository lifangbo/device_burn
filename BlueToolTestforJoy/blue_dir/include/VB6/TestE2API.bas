' TestE2API.bas : Declares the DLL functions for vb6.
' Generated by C:\work_bluesuite_2_5\p4\common\hosttools\bluesuite_2_5\prodtest\scripts\extract_tt_api.pl from TestE2.h;  at 03/02/14 - 11:36:28

Declare Sub te2GetVersion Lib "TestE2.dll" (ByVal versionStr As String)
Declare Function te2Open Lib "TestE2.dll" (ByVal transport As Long, ByVal port As Long, ByVal device As Long) As Long
Declare Function te2OpenSpiUnlock Lib "TestE2.dll" (ByVal transport As Long, ByVal port As Long, ByVal device As Long, ByVal unlockKey As String) As Long
Declare Function te2OpenTrans Lib "TestE2.dll" (ByVal trans As String) As Long
Declare Function te2OpenSpiUnlockTrans Lib "TestE2.dll" (ByVal trans As String, ByVal unlockKey As String) As Long
Declare Sub te2Close Lib "TestE2.dll" ()
Declare Function te2GetDetectedDevices Lib "TestE2.dll" (ByRef devices As Integer) As Long
Declare Function te2GetFailedDevices Lib "TestE2.dll" (ByRef devices As Integer) As Long
Declare Function te2IsBusy Lib "TestE2.dll" () As Byte
Declare Function te2Program Lib "TestE2.dll" (ByVal filename As String, ByVal wait As Byte) As Long
Declare Function te2ProgramBroad Lib "TestE2.dll" (ByVal filename As String, ByVal devices As Integer, ByVal wait As Byte) As Long
Declare Function te2Fill Lib "TestE2.dll" (ByVal value As Integer, ByVal wait As Byte) As Long
Declare Function te2FillBroad Lib "TestE2.dll" (ByVal value As Integer, ByVal devices As Integer, ByVal wait As Byte) As Long
Declare Function te2Dump Lib "TestE2.dll" (ByVal filename As String, ByVal wait As Byte) As Long
Declare Function te2GetSize Lib "TestE2.dll" (ByRef size As Integer) As Long
Declare Function te2GetInfo Lib "TestE2.dll" (ByRef devSelect As Integer, ByRef byteAddr As Integer) As Long
Declare Function te2SetI2cPios Lib "TestE2.dll" (ByVal sda As Byte, ByVal scl As Byte, ByVal wp As Byte) As Long
Declare Function te2WriteBcHeader Lib "TestE2.dll" () As Long
Declare Function te2GetResult Lib "TestE2.dll" () As Long
Declare Function te2GetLastError Lib "TestE2.dll" () As String
Declare Function te2GetAvailableSpiPorts Lib "TestE2.dll" (ByRef maxLen As Integer, ByVal ports As String, ByVal trans As String, ByRef count As Integer) As Long
Declare Function te2Verify Lib "TestE2.dll" (ByVal filename As String, ByVal wait As Byte) As Long
