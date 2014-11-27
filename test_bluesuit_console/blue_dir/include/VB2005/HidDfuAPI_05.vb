' HidDfuAPI_05.vb : Declares the DLL functions for vb2005.
' Generated by C:\work_bluesuite_2_5\p4\common\hosttools\bluesuite_2_5\prodtest\scripts\extract_tt_api.pl from HidDfu.h;  at 03/02/14 - 11:13:42

Imports System.Text
Imports System.Runtime.InteropServices

Module HidDfu
    Public Const HIDDFU_ERROR_NONE As Integer = 0
    Public Const HIDDFU_ERROR_SEQUENCE As Integer = -1
    Public Const HIDDFU_ERROR_CONNECTION As Integer = -2
    Public Const HIDDFU_ERROR_FILE_OPEN_FAILED As Integer = -3
    Public Const HIDDFU_ERROR_FILE_WRITE_FAILED As Integer = -4
    Public Const HIDDFU_ERROR_FILE_INVALID_FORMAT As Integer = -5
    Public Const HIDDFU_ERROR_FILE_CRC_INCORRECT As Integer = -6
    Public Const HIDDFU_ERROR_FILE_READ_FAILED As Integer = -7
    Public Const HIDDFU_ERROR_UPGRADE_FAILED As Integer = -8
    Public Const HIDDFU_ERROR_RESET_FAILED As Integer = -9
    Public Const HIDDFU_ERROR_OUT_OF_MEM As Integer = -10
    Public Const HIDDFU_ERROR_INVALID_PARAMETER As Integer = -11
    Public Const HIDDFU_ERROR_DRIVER_INTERFACE_FAILURE As Integer = -12
    Public Const HIDDFU_ERROR_OPERATION_FAILED_TO_START As Integer = -13
    Public Const HIDDFU_ERROR_BUSY As Integer = -14
    Public Const HIDDFU_ERROR_CLEAR_STATUS_FAILED As Integer = -15
    Public Const HIDDFU_ERROR_DEVICE_FIRMWARE As Integer = -16
    Public Const HIDDFU_ERROR_UNKNOWN As Integer = -20
    <DllImport("HidDfu.dll", EntryPoint:="hidDfuGetVersion", _
    CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Function hidDfuGetVersion (ByRef major As UShort, ByRef minor As UShort, ByRef release As UShort, ByRef build As UShort) As Integer
    End Function
    <DllImport("HidDfu.dll", EntryPoint:="hidDfuConnect", _
    CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Function hidDfuConnect (ByVal vid As UShort, ByVal pid As UShort, ByVal usage As UShort, ByVal usagePage As UShort) As Integer
    End Function
    <DllImport("HidDfu.dll", EntryPoint:="hidDfuDisconnect", _
    CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Function hidDfuDisconnect () As Integer
    End Function
    <DllImport("HidDfu.dll", EntryPoint:="hidDfuBackup", _
    CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Function hidDfuBackup (ByVal fileName As String) As Integer
    End Function
    <DllImport("HidDfu.dll", EntryPoint:="hidDfuUpgrade", _
    CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Function hidDfuUpgrade (ByVal fileName As String) As Integer
    End Function
    <DllImport("HidDfu.dll", EntryPoint:="hidDfuResetDevice", _
    CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Function hidDfuResetDevice () As Integer
    End Function
    <DllImport("HidDfu.dll", EntryPoint:="hidDfuGetProgress", _
    CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Function hidDfuGetProgress () As Byte
    End Function
    <DllImport("HidDfu.dll", EntryPoint:="hidDfuGetResult", _
    CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Function hidDfuGetResult () As Integer
    End Function
    <DllImport("HidDfu.dll", EntryPoint:="hidDfuGetLastError", _
    CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Function hidDfuGetLastError () As IntPtr
    End Function
    <DllImport("HidDfu.dll", EntryPoint:="hidDfuSendCommand", _
    CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Function hidDfuSendCommand (ByRef data As Byte, ByVal length As UInteger) As Integer
    End Function
End Module
