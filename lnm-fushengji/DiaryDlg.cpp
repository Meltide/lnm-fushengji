// DiaryDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "DiaryDlg.h"

extern CString globalMsg; // 全局变量，用于存储消息内容

// DiaryDlg 对话框

IMPLEMENT_DYNAMIC(DiaryDlg, CDialogEx)

DiaryDlg::DiaryDlg(CWnd* pParent /*=nullptr*/, CString msg)
	: CDialogEx(IDD_DIARY, pParent)
{
	this->msg = msg;
}

DiaryDlg::~DiaryDlg()
{
}

void DiaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL DiaryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 在对话框初始化时使用 msg
	SetDlgItemText(IDC_TEXT, msg);

	return TRUE;  // return TRUE unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(DiaryDlg, CDialogEx)
END_MESSAGE_MAP()


// DiaryDlg 消息处理程序
