#pragma once
#include "afxdialogex.h"


// WangbaDlg 对话框

class WangbaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(WangbaDlg)

public:
	WangbaDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~WangbaDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WANGBA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
