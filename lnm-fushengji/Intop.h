#pragma once
#include "afxdialogex.h"

#include "MainDlg.h"


// Intop 对话框

class Intop : public CDialogEx
{
	DECLARE_DYNAMIC(Intop)

	MainDlg* m_main;
	long m_money;

public:
	Intop(CWnd* pParent = nullptr, MainDlg* main = nullptr);   // 标准构造函数
	virtual ~Intop();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INTOP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
