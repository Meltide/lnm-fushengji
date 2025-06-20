#pragma once
#include "afxdialogex.h"


// TopDlg 对话框

class TopDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TopDlg)

public:
	TopDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TopDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TOPLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	CListCtrl m_topList;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};

struct Member
{
	std::string name;
	std::string cash;
	std::string health;
	std::string fame;

	Member(
		std::string name,
		std::string cash,
		std::string health,
		std::string fame)
		: name(name), cash(cash), health(health), fame(fame)
	{}
};
