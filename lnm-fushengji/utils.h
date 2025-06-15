#pragma once
#include <windows.h>

// 获取当前 DPI 并计算字体高度
inline int GetDpiAdjustedFontHeight(int baseHeight, HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	int dpi = GetDeviceCaps(hdc, LOGPIXELSY); // 获取垂直方向的 DPI
	ReleaseDC(hwnd, hdc);
	return MulDiv(baseHeight, dpi, 96); // 96 是标准 DPI
}

// 获取 DPI 调整后的大小
inline int GetDpiAdjustedSize(int baseSize, HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	int dpi = GetDeviceCaps(hdc, LOGPIXELSY); // 获取垂直方向的 DPI
	ReleaseDC(hwnd, hdc);
	return MulDiv(baseSize, dpi, 96); // 96 是标准 DPI
}