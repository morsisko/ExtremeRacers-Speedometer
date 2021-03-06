// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include "Structures.h"
#include "SerialPort.h"

const char* portName = "\\\\.\\COM5";

DWORD WINAPI DllStart(LPVOID unused)
{
	SerialPort arduino((char*)portName);

	DWORD baseModule = (DWORD)GetModuleHandleA("gamex86.dll");
	float angleScale = 1.428f;
	
	while (true)
	{
		Car* car = *(Car**)(baseModule + 0x14B68);
		int speed = car->GetSpeed();
		int angle = round(speed / angleScale);
		arduino.writeSerialPort((char*)&angle, 1);
		Sleep(50);
	}

	return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, DllStart, 0, 0, 0);
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

