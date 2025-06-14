#pragma once
#include "afxdialogex.h"
#include "MainDlg.h"


// BankJyDlg 对话框

class BankJyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BankJyDlg)

	MainDlg* m_main;
	bool m_mode;

public:
	BankJyDlg(CWnd* pParent = nullptr, MainDlg* main = nullptr, bool mode = true);   // 标准构造函数
	virtual ~BankJyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BANK_JY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	CSpinButtonCtrl m_spin;

	DECLARE_MESSAGE_MAP()
};
