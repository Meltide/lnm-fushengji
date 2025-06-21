#pragma once
#include "afxdialogex.h"

struct TopEntry {
	CString name;
	long score;
	int health;
	int fame;
};

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

	CListCtrl m_market;
	CListCtrl m_coat;

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
	void MainDlg::TriggerRandomEvents();
	void MainDlg::NextDay();
	void MainDlg::EndGame();

	static void LoadTopList(std::vector<TopEntry>& list);
	static void SaveTopList(const std::vector<TopEntry>& list);
	static int GetTopOrder(long score);
	static void InsertTop(const TopEntry& entry);
	static void ShowTopList(CWnd* pParent = nullptr);

	int m_nVisitWangba = 0;
	bool m_goStat = false;

	CStatic m_cash;
	CStatic m_inBank;
	CStatic m_debt;
	CStatic m_health;
	CStatic m_fame;

	CImageList m_imageList;

	CMFCButton m_go;
	CMFCButton m_boss;

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

	CIconBtn m_bank;
	CIconBtn m_hosp;
	CIconBtn m_post;
	CIconBtn m_house;
	CIconBtn m_wangba;

private:
	CFont m_fontBold;
	CFont m_buttonFont;

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
	afx_msg void OnBank();
	afx_msg void OnBnClickedButtonPost();
	afx_msg void OnPost();
	afx_msg void OnBnClickedButtonHosp();
	afx_msg void OnHosp();
	afx_msg void OnBnClickedButtonHouse();
	afx_msg void OnNewgame();
	afx_msg void OnTop();
	afx_msg void OnBnClickedButtonBuy();
	afx_msg void OnBnClickedButtonSell();
	afx_msg void OnBnClickedButtonGo();
};
