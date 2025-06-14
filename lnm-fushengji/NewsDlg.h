#pragma once
#include "afxdialogex.h"


// NewsDlg 对话框

class NewsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NewsDlg)

	CString m_msg;

public:
	NewsDlg(CWnd* pParent = nullptr, CString msg = L"");   // 标准构造函数
	virtual ~NewsDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEWS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
