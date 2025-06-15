#pragma once
#include "afxdialogex.h"
#include "MainDlg.h"


// PostDlg 对话框

class PostDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PostDlg)

	MainDlg* m_main;
	CSpinButtonCtrl m_spin;

public:
	PostDlg(CWnd* pParent = nullptr, MainDlg* main = nullptr);   // 标准构造函数
	virtual ~PostDlg();

	long back;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
