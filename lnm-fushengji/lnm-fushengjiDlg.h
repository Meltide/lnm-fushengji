// lnm-fushengjiDlg.h: 头文件
//

#pragma once


// ClnmfushengjiDlg 对话框
class ClnmfushengjiDlg : public CDialogEx
{
// 构造
public:
	ClnmfushengjiDlg(CWnd* pParent = nullptr, bool story = false);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LNMFUSHENGJI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnUpdateLoadMsg(WPARAM, LPARAM);
	afx_msg LRESULT OnEnableButton(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()

private:
	CFont m_fontTitle;
	CFont m_fontLoad;

	bool m_story;
public:
	afx_msg void OnBnClickedButton1();
};
