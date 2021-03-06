' TestE2API.vb : Declares the DLL functions for vb7.
' Generated by C:\work_bluesuite_2_5\p4\common\hosttools\bluesuite_2_5\prodtest\scripts\extract_tt_api.pl from TestE2.h;  at 03/02/14 - 11:36:28

Imports System.Text

Module TestE2
Declare Sub te2GetVersion Lib "TestE2.dll" (ByVal versionStr As StringBuilder)
Declare Function te2Open Lib "TestE2.dll" (ByVal transport As Integer, ByVal port As Integer, ByVal device As Integer) As Integer
Declare Function te2OpenSpiUnlock Lib "TestE2.dll" (ByVal transport As Integer, ByVal port As Integer, ByVal device As Integer, ByVal unlockKey As String) As Integer
Declare Function te2OpenTrans Lib "TestE2.dll" (ByVal trans As String) As Integer
Declare Function te2OpenSpiUnlockTrans Lib "TestE2.dll" (ByVal trans As String, ByVal unlockKey As String) As Integer
Declare Sub te2Close Lib "TestE2.dll" ()
Declare Function te2GetDetectedDevices Lib "TestE2.dll" (ByRef devices As Short) As Integer
Declare Function te2GetFailedDevices Lib "TestE2.dll" (ByRef devices As Short) As Integer
Declare Function te2IsBusy Lib "TestE2.dll" () As Byte
Declare Function te2Program Lib "TestE2.dll" (ByVal filename As String, ByVal wait As Byte) As Integer
Declare Function te2ProgramBroad Lib "TestE2.dll" (ByVal filename As String, ByVal devices As Short, ByVal wait As Byte) As Integer
Declare Function te2Fill Lib "TestE2.dll" (ByVal value As Short, ByVal wait As Byte) As Integer
Declare Function te2FillBroad Lib "TestE2.dll" (ByVal value As Short, ByVal devices As Short, ByVal wait As Byte) As Integer
Declare Function te2Dump Lib "TestE2.dll" (ByVal filename As String, ByVal wait As Byte) As Integer
Declare Function te2GetSize Lib "TestE2.dll" (ByRef size As Short) As Integer
Declare Function te2GetInfo Lib "TestE2.dll" (ByRef devSelect As Short, ByRef byteAddr As Short) As Integer
Declare Function te2SetI2cPios Lib "TestE2.dll" (ByVal sda As Byte, ByVal scl As Byte, ByVal wp As Byte) As Integer
Declare Function te2WriteBcHeader Lib "TestE2.dll" () As Integer
Declare Function te2GetResult Lib "TestE2.dll" () As Integer
Declare Function te2GetLastError Lib "TestE2.dll" () As IntPtr
Declare Function te2GetAvailableSpiPorts Lib "TestE2.dll" (ByRef maxLen As Short, ByVal ports As StringBuilder, ByVal trans As StringBuilder, ByRef count As Short) As Integer
Declare Function te2Verify Lib "TestE2.dll" (ByVal filename As String, ByVal wait As Byte) As Integer
End Module
