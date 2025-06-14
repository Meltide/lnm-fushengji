// BankJyDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "BankJyDlg.h"


// BankJyDlg 对话框

IMPLEMENT_DYNAMIC(BankJyDlg, CDialogEx)

BankJyDlg::BankJyDlg(CWnd* pParent /*=nullptr*/, MainDlg* main, bool mode)
	: CDialogEx(IDD_BANK_JY, pParent)
{
	m_main = main;
	m_mode = mode;
}

BankJyDlg::~BankJyDlg()
{
}

void BankJyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_SPIN, m_spin);
}

BOOL BankJyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_spin.SetBuddy(GetDlgItem(IDC_MONEY));
	if (m_mode) {
		m_spin.SetRange(1, 1000000);
		m_spin.SetPos(10000);
	} else {
		m_spin.SetRange(1, 100000);
		m_spin.SetPos(1000);

	return TRUE;
}

BEGIN_MESSAGE_MAP(BankJyDlg, CDialogEx)
END_MESSAGE_MAP()


// BankJyDlg 消息处理程序
