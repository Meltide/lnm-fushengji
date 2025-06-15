#pragma once
#include <windows.h>

// ��ȡ��ǰ DPI ����������߶�
inline int GetDpiAdjustedFontHeight(int baseHeight, HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	int dpi = GetDeviceCaps(hdc, LOGPIXELSY); // ��ȡ��ֱ����� DPI
	ReleaseDC(hwnd, hdc);
	return MulDiv(baseHeight, dpi, 96); // 96 �Ǳ�׼ DPI
}

// ��ȡ DPI ������Ĵ�С
inline int GetDpiAdjustedSize(int baseSize, HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	int dpi = GetDeviceCaps(hdc, LOGPIXELSY); // ��ȡ��ֱ����� DPI
	ReleaseDC(hwnd, hdc);
	return MulDiv(baseSize, dpi, 96); // 96 �Ǳ�׼ DPI
}