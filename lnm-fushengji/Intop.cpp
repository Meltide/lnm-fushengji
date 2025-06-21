// Intop.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "Intop.h"


// Intop 对话框

IMPLEMENT_DYNAMIC(Intop, CDialogEx)

Intop::Intop(CWnd* pParent /*=nullptr*/, MainDlg* main)
	: CDialogEx(IDD_INTOP, pParent)
{
	m_main = main;
	m_money = main->cash + main->inBank;
}

Intop::~Intop()
{
}

void Intop::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL Intop::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str[5] = {
		L"牢黏猫窝优秀圈钱员",
		L"牢黏猫窝十大杰出小青年",
		L"牢黏猫最酷倒卖手",
		L"牢黏猫圈钱大师",
		L"牢黏猫第一金手指"
	};
	SetDlgItemText(IDC_FAME, str[rand() % 5]);

	return TRUE;
}


BEGIN_MESSAGE_MAP(Intop, CDialogEx)
END_MESSAGE_MAP()


// Intop 消息处理程序
