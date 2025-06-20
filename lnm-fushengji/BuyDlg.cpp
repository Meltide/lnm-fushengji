// BuyDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "BuyDlg.h"


// BuyDlg 对话框

IMPLEMENT_DYNAMIC(BuyDlg, CDialogEx)

BuyDlg::BuyDlg(CWnd* pParent /*=nullptr*/, MainDlg* main, CString goods, int price)
	: CDialogEx(IDD_BUY, pParent)
{
	m_main = main;
	m_goods = goods;

	m_count = main->cash / price;
	if (m_count > m_main->coat)
		m_count = m_main->coat;
}

BuyDlg::~BuyDlg()
{
}

void BuyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL BuyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString strAsk;
	strAsk.Format(L"您的现金是%d迷你币，最多可以买%d个%s", m_main->cash, m_count, m_goods);

	return TRUE;
}


BEGIN_MESSAGE_MAP(BuyDlg, CDialogEx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &BuyDlg::OnDeltaposSpin1)
END_MESSAGE_MAP()


// BuyDlg 消息处理程序

void BuyDlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
