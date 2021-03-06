// TestE2API.cs : Declares the DLL functions for C#.
// Generated by C:\work_bluesuite_2_5\p4\common\hosttools\bluesuite_2_5\prodtest\scripts\extract_tt_api.pl from TestE2.h;  at 03/02/14 - 11:36:28

using System;
using System.Runtime.InteropServices;
using System.Text;

namespace TestE2API
{
    public class TestE2
    {
#if PocketPC || WindowsCE
        const CharSet charset = CharSet.Auto;
        const CallingConvention calling_convention = CallingConvention.Winapi;
#else
        const CharSet charset = CharSet.Ansi;
        const CallingConvention calling_convention = CallingConvention.StdCall;
#endif

        [DllImport("TestE2.dll", EntryPoint="te2GetVersion",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern void te2GetVersion(StringBuilder versionStr);
        [DllImport("TestE2.dll", EntryPoint="te2GetVersion",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern void te2GetVersion(byte [] versionStr);

        [DllImport("TestE2.dll", EntryPoint="te2Open",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2Open(int transport, int port, int device);

        [DllImport("TestE2.dll", EntryPoint="te2OpenSpiUnlock",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2OpenSpiUnlock(int transport, int port, int device, String unlockKey);
        [DllImport("TestE2.dll", EntryPoint="te2OpenSpiUnlock",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2OpenSpiUnlock(int transport, int port, int device, byte [] unlockKey);

        [DllImport("TestE2.dll", EntryPoint="te2OpenTrans",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2OpenTrans(String trans);
        [DllImport("TestE2.dll", EntryPoint="te2OpenTrans",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2OpenTrans(byte [] trans);

        [DllImport("TestE2.dll", EntryPoint="te2OpenSpiUnlockTrans",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2OpenSpiUnlockTrans(String trans, String unlockKey);
        [DllImport("TestE2.dll", EntryPoint="te2OpenSpiUnlockTrans",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2OpenSpiUnlockTrans(byte [] trans, byte [] unlockKey);

        [DllImport("TestE2.dll", EntryPoint="te2Close",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern void te2Close();

        [DllImport("TestE2.dll", EntryPoint="te2GetDetectedDevices",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2GetDetectedDevices(out ushort devices);

        [DllImport("TestE2.dll", EntryPoint="te2GetFailedDevices",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2GetFailedDevices(out ushort devices);

        [DllImport("TestE2.dll", EntryPoint="te2IsBusy",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern byte te2IsBusy();

        [DllImport("TestE2.dll", EntryPoint="te2Program",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2Program(String filename, byte wait);
        [DllImport("TestE2.dll", EntryPoint="te2Program",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2Program(byte [] filename, byte wait);

        [DllImport("TestE2.dll", EntryPoint="te2ProgramBroad",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2ProgramBroad(String filename, ushort devices, byte wait);
        [DllImport("TestE2.dll", EntryPoint="te2ProgramBroad",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2ProgramBroad(byte [] filename, ushort devices, byte wait);

        [DllImport("TestE2.dll", EntryPoint="te2Fill",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2Fill(ushort value, byte wait);

        [DllImport("TestE2.dll", EntryPoint="te2FillBroad",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2FillBroad(ushort value, ushort devices, byte wait);

        [DllImport("TestE2.dll", EntryPoint="te2Dump",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2Dump(String filename, byte wait);
        [DllImport("TestE2.dll", EntryPoint="te2Dump",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2Dump(byte [] filename, byte wait);

        [DllImport("TestE2.dll", EntryPoint="te2GetSize",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2GetSize(out ushort size);

        [DllImport("TestE2.dll", EntryPoint="te2GetInfo",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2GetInfo(out ushort devSelect, out ushort byteAddr);

        [DllImport("TestE2.dll", EntryPoint="te2SetI2cPios",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2SetI2cPios(byte sda, byte scl, byte wp);

        [DllImport("TestE2.dll", EntryPoint="te2WriteBcHeader",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2WriteBcHeader();

        [DllImport("TestE2.dll", EntryPoint="te2GetResult",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2GetResult();

        [DllImport("TestE2.dll", EntryPoint="te2GetLastError",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern IntPtr te2GetLastError();

        [DllImport("TestE2.dll", EntryPoint="te2GetAvailableSpiPorts",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2GetAvailableSpiPorts(out ushort maxLen, StringBuilder ports, StringBuilder trans, out ushort count);
        [DllImport("TestE2.dll", EntryPoint="te2GetAvailableSpiPorts",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2GetAvailableSpiPorts(out ushort maxLen, byte [] ports, byte [] trans, out ushort count);

        [DllImport("TestE2.dll", EntryPoint="te2Verify",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2Verify(String filename, byte wait);
        [DllImport("TestE2.dll", EntryPoint="te2Verify",
                CharSet=charset, CallingConvention=calling_convention)]
        public static extern int te2Verify(byte [] filename, byte wait);

    }
}
