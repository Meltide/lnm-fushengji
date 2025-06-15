#pragma once
#include "afxdialogex.h"

#include <vector>


// MainDlg 对话框

class MainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MainDlg)

public:
	MainDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MainDlg();

	long cash;
	long inBank;
	long debt;
	int health;
	int fame;

	unsigned int total;
	unsigned int coat;

	unsigned int leftDay;

	CString goods[8];

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	HBRUSH MainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void MainDlg::GenGoods();
	void MainDlg::FlushBtn();
	void MainDlg::Clicked(CButton& btn);
	void FlushDisplay();
	void MainDlg::NextDay();
	void MainDlg::EndGame();

	CStatic m_cash;
	CStatic m_inBank;
	CStatic m_debt;
	CStatic m_health;
	CStatic m_fame;

	CListCtrl m_market;
	CListCtrl m_coat;

	CButton m_iceHome;
	CButton m_mcpeCity;
	CButton m_danCity;
	CButton m_meltCity;
	CButton m_minCity;
	CButton m_furryCs;
	CButton m_code;
	CButton m_minHome;
	CButton m_galaxy;
	CButton m_file;

private:
	CFont m_fontBold;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonIcehome();
	afx_msg void OnBnClickedButtonMcpecity();
	afx_msg void OnBnClickedButtonDancity();
	afx_msg void OnBnClickedButtonMeltcity();
	afx_msg void OnBnClickedButtonMincity();
	afx_msg void OnBnClickedButtonFurrycs();
	afx_msg void OnBnClickedButtonCode();
	afx_msg void OnBnClickedButtonMinhome();
	afx_msg void OnBnClickedButtonGalaxy();
	afx_msg void OnBnClickedButtonFile();
	afx_msg void OnBnClickedButtonWangba();
	afx_msg void OnBnClickedButtonBoss();
	afx_msg void OnStory();
	afx_msg void OnAbout();
	afx_msg void OnWangba();
	afx_msg void OnExit();
	afx_msg void OnBnClickedButtonBank();
};
