#pragma once
#include "afxdialogex.h"


// BossComeDlg 对话框

class BossComeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BossComeDlg)

public:
	BossComeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BossComeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOSS_COME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck();
	afx_msg void OnBnClickedOk();
};
