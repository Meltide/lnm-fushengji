#pragma once
#include "afxdialogex.h"
#include "MainDlg.h"


// HospitalDlg 对话框

class HospitalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(HospitalDlg)

	MainDlg* m_main;
	CSpinButtonCtrl m_spin;

	unsigned int m_needPoint;

public:
	HospitalDlg(CWnd* pParent = nullptr, MainDlg* main = nullptr);   // 标准构造函数
	virtual ~HospitalDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOSPITAL };
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
