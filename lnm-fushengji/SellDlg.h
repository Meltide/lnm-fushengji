#pragma once
#include "afxdialogex.h"
#include "MainDlg.h"


// SellDlg 对话框

class SellDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SellDlg)

	MainDlg* m_main;

	int m_nItem;
	CString m_goods;
	int m_count;
	int m_price;

	bool badFame1 = false;
	bool badFame2 = false;

public:
	SellDlg(CWnd* pParent = nullptr, MainDlg* main = nullptr);   // 标准构造函数
	virtual ~SellDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELL };
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
