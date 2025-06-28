#pragma once
#include "afxdialogex.h"

#include "MainDlg.h"


struct TopEntry {
	CString name;
	long score;
	int health;
	int fame;

	TopEntry() : name(L""), score(0), health(0), fame(0) {}

	TopEntry(
		CString name,
		long score,
		int health,
		int fame
	) : name(name), score(score), health(health), fame(fame)
	{
	}
};

// IntopDlg 对话框

class IntopDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IntopDlg)

	MainDlg* m_main;
	long m_money;

public:
	IntopDlg(CWnd* pParent = nullptr, MainDlg* main = nullptr);   // 标准构造函数
	virtual ~IntopDlg();

	void LoadTopList(std::vector<TopEntry>& list);
	void IntopDlg::SaveTopList(const std::vector<TopEntry>& list);
	int IntopDlg::GetTopOrder(long score);
	void IntopDlg::InsertTop(const TopEntry& entry);
	void IntopDlg::ShowTopList(CWnd* pParent);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IntopDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
