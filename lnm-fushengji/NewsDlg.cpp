// NewsDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "NewsDlg.h"


// NewsDlg 对话框

IMPLEMENT_DYNAMIC(NewsDlg, CDialogEx)

NewsDlg::NewsDlg(CWnd* pParent /*=nullptr*/, CString msg)
	: CDialogEx(IDD_NEWS, pParent)
{
	m_msg = msg;
}

NewsDlg::~NewsDlg()
{
}

void NewsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL NewsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetDlgItemText(IDC_TEXT, m_msg);

	return TRUE;
}


BEGIN_MESSAGE_MAP(NewsDlg, CDialogEx)
END_MESSAGE_MAP()


// NewsDlg 消息处理程序

