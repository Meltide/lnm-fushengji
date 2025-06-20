#pragma once
#include "afxdialogex.h"
#include "MainDlg.h"


// BuyDlg 对话框

class BuyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BuyDlg)

	MainDlg* m_main;
	CString m_goods;

	unsigned int m_count = 0;

public:
	BuyDlg(CWnd* pParent = nullptr, MainDlg* main = nullptr, CString goods = L"", int price);   // 标准构造函数
	virtual ~BuyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
};
