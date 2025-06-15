// PostDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "PostDlg.h"


// PostDlg 对话框

IMPLEMENT_DYNAMIC(PostDlg, CDialogEx)

PostDlg::PostDlg(CWnd* pParent /*=nullptr*/, MainDlg* main)
	: CDialogEx(IDD_POST, pParent)
{
	m_main = main;
	back = 0;
}

PostDlg::~PostDlg()
{
}

void PostDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	DDX_Control(pDX, IDC_SPIN, m_spin);
}

BOOL PostDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString msg;
	msg.Format(L"outice在电话中说道：“bro你欠俺%ld元，快还！”", m_main->debt);
	SetDlgItemText(IDC_MSG, msg);

	m_spin.SetBuddy(GetDlgItem(IDC_BACK));

	if (m_main->debt >= m_main->cash)
	{
		CString money;
		money.Format(L"%ld", m_main->cash);
		SetDlgItemText(IDC_BACK, money);

		m_spin.SetRange(1, m_main->cash);
		m_spin.SetPos(m_main->cash);
	}
	else
	{
		CString money;
		money.Format(L"%ld", m_main->debt);
		SetDlgItemText(IDC_BACK, money);

		m_spin.SetRange(1, m_main->debt);
		m_spin.SetPos(m_main->debt);
	}

	return TRUE;
}


BEGIN_MESSAGE_MAP(PostDlg, CDialogEx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN, &PostDlg::OnDeltaposSpin)
	ON_BN_CLICKED(IDC_OK, &PostDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CANCEL, &PostDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// PostDlg 消息处理程序

void PostDlg::OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult)
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
	SetDlgItemText(IDC_BACK, strValue);

	*pResult = 0;
}

void PostDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strBack;
	GetDlgItemText(IDC_BACK, strBack);

	if (strBack.IsEmpty()) {
		MessageBox(L"请输入金额", L"提示", MB_ICONINFORMATION);
		return;
	}

	back = _tstol(strBack);

	if (m_main->debt >= m_main->cash)
	{
		if (!(back >= 0 && back <= m_main->cash)) {
			CString msg;
			msg.Format(L"请输入0到%ld之间的整数", m_main->cash);
			MessageBox(msg, L"提示", MB_ICONINFORMATION);
			return;
		}
	}
	else
	{
		if (!(back >= 0 && back <= m_main->debt)) {
			CString msg;
			msg.Format(L"请输入0到%ld之间的整数", m_main->debt);
			MessageBox(msg, L"提示", MB_ICONINFORMATION);
			return;
		}
	}

	m_main->cash -= back;
	m_main->debt -= back;

	CDialogEx::OnOK();
}

void PostDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
