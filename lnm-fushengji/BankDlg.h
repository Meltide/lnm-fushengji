#pragma once
#include "afxdialogex.h"
#include "MainDlg.h"


// BankDlg 对话框

class BankDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BankDlg)

	MainDlg* m_main;

public:
	BankDlg(CWnd* pParent = nullptr, MainDlg* main = nullptr);   // 标准构造函数
	virtual ~BankDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BANK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedGet();
	afx_msg void OnBnClickedLeft();
};
