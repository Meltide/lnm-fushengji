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
		CString strCash;
		strCash.Format(L"%d", m_main->cash);

		SetDlgItemText(IDC_TEXT, L"您存多少钱？");
		SetDlgItemText(IDC_MONEY, strCash);

		m_spin.SetRange(1, m_main->cash);
		m_spin.SetPos(m_main->cash);
	}
	else {
		CString strInBank;
		strInBank.Format(L"%d", m_main->inBank);

		SetDlgItemText(IDC_TEXT, L"您取多少钱？");
		SetDlgItemText(IDC_MONEY, strInBank);

		m_spin.SetRange(1, m_main->inBank);
		m_spin.SetPos(m_main->inBank);
	}

	return TRUE;
}

BEGIN_MESSAGE_MAP(BankJyDlg, CDialogEx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN, &BankJyDlg::OnDeltaposSpin)
	ON_BN_CLICKED(IDC_CANCEL, &BankJyDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_OK, &BankJyDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// BankJyDlg 消息处理程序

void BankJyDlg::OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	int nPos = pNMUpDown->iPos + pNMUpDown->iDelta;

	// 获取当前范围
	int nMin, nMax;
	m_spin.GetRange(nMin, nMax);

	// 边界检查
	if (nPos < nMin) nPos = nMin;
	if (nPos > nMax) nPos = nMax;

	CString strValue;
	strValue.Format(L"%d", nPos);
	SetDlgItemText(IDC_MONEY, strValue);

	*pResult = 0;
}


void BankJyDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strVarCash;
	GetDlgItemText(IDC_MONEY, strVarCash);

	if (strVarCash.IsEmpty()) {
		MessageBox(L"请输入金额", L"提示", MB_ICONINFORMATION);
		return;
	}

	long varCash = _tstol(strVarCash);

	if (m_mode)
	{
		m_main->cash -= varCash;
		m_main->inBank += varCash;
	}
	else
	{
		m_main->cash += varCash;
		m_main->inBank -= varCash;
	}

	CDialogEx::OnOK();
}

void BankJyDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
