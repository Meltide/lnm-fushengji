// BankDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "BankDlg.h"


// BankDlg 对话框

IMPLEMENT_DYNAMIC(BankDlg, CDialogEx)

BankDlg::BankDlg(CWnd* pParent /*=nullptr*/, MainDlg* main)
	: CDialogEx(IDD_BANK, pParent)
{
	m_main = main;
}

BankDlg::~BankDlg()
{
}

void BankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL BankDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str;
	str.Format(L"客户您好! 您的迷你币是%d, 您的存款是%d. 请问您要...", m_main->cash, m_main->inBank);
	SetDlgItemText(IDC_STATIC, str);

	return TRUE;
}

BEGIN_MESSAGE_MAP(BankDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SAVE, &BankDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_GET, &BankDlg::OnBnClickedGet)
	ON_BN_CLICKED(IDC_LEFT, &BankDlg::OnBnClickedLeft)
END_MESSAGE_MAP()


// BankDlg 消息处理程序

void BankDlg::OnBnClickedSave()
{
	// TODO: 在此添加控件通知处理程序代码
}

void BankDlg::OnBnClickedGet()
{
	// TODO: 在此添加控件通知处理程序代码
}

void BankDlg::OnBnClickedLeft()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
