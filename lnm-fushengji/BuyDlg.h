﻿#pragma once
#include "afxdialogex.h"
#include "MainDlg.h"


// BuyDlg 对话框

class BuyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BuyDlg)

	MainDlg* m_main;
	CString m_goods;

	int m_nItem;
	int m_count = 0;
	int m_remain = 0;
	int m_price = 0;

public:
	BuyDlg(CWnd* pParent = nullptr, MainDlg* main = nullptr);   // 标准构造函数
	virtual ~BuyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	CSpinButtonCtrl m_spin;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
