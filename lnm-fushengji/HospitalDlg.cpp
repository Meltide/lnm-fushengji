// HospitalDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "HospitalDlg.h"


// HospitalDlg 对话框

IMPLEMENT_DYNAMIC(HospitalDlg, CDialogEx)

HospitalDlg::HospitalDlg(CWnd* pParent /*=nullptr*/, MainDlg* main)
	: CDialogEx(IDD_HOSPITAL, pParent)
{
	m_main = main;
	m_needPoint = 100 - m_main->health;
}

HospitalDlg::~HospitalDlg()
{
}

void HospitalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_SPIN, m_spin);
}

BOOL HospitalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString msg;
	msg.Format(L"大夫高兴地拍着手：“您的健康点数是%d，需要治疗的点数是%d。坚决抵制腐败！每个健康点数俺只收您3500元红包。”", m_main->health, m_needPoint);
	SetDlgItemText(IDC_MSG, msg);

	CString strPoint;
	strPoint.Format(L"%u", m_needPoint);
	SetDlgItemText(IDC_POINT, strPoint);

	m_spin.SetBuddy(GetDlgItem(IDC_POINT));
	m_spin.SetRange(0, m_needPoint);
	m_spin.SetPos(m_needPoint);

	return TRUE;
}


BEGIN_MESSAGE_MAP(HospitalDlg, CDialogEx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN, &HospitalDlg::OnDeltaposSpin)
	ON_BN_CLICKED(IDC_OK, &HospitalDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CANCEL, &HospitalDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// HospitalDlg 消息处理程序

void HospitalDlg::OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult)
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
	SetDlgItemText(IDC_POINT, strValue);

	*pResult = 0;
}

void HospitalDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strPoint;
	GetDlgItemText(IDC_POINT, strPoint);

	if (strPoint.IsEmpty())
	{
		MessageBox(L"请输入点数", L"提示", MB_ICONINFORMATION);
		return;
	}

	unsigned int point = _tstoi(strPoint);

	if (point * 3500 > m_main->cash)
	{
		CDialogEx::OnCancel();
		return;
	}

	m_main->health += point;
	m_main->cash -= point * 3500;

	CDialogEx::OnOK();
}

void HospitalDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
