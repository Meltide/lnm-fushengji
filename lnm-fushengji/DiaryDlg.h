#pragma once
#include "afxdialogex.h"


// DiaryDlg 对话框

class DiaryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DiaryDlg)

public:
	DiaryDlg(CWnd* pParent = nullptr, CString msg = L"");   // 标准构造函数
	virtual ~DiaryDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIARY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	CString msg;

	DECLARE_MESSAGE_MAP()
};
