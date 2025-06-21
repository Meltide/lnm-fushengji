// SellDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "SellDlg.h"

#include "DiaryDlg.h"


// SellDlg 对话框

IMPLEMENT_DYNAMIC(SellDlg, CDialogEx)

SellDlg::SellDlg(CWnd* pParent /*=nullptr*/, MainDlg* main)
	: CDialogEx(IDD_SELL, pParent)
{
	m_nItem = main->m_coat.GetSelectionMark();
	
	m_main = main;
	m_goods = main->m_coat.GetItemText(m_nItem, 0).GetString();
	m_count = _wtoi(main->m_coat.GetItemText(m_nItem, 1).GetString());
	m_price = _wtoi(main->m_coat.GetItemText(m_nItem, 2).GetString());
}

SellDlg::~SellDlg()
{
}

void SellDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_SPIN, m_spin);
}

BOOL SellDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	if (m_nItem == -1) {
		EndDialog(IDCANCEL);
		DiaryDlg diary(nullptr, L"我还没有选定卖什么物品呢。");
		diary.DoModal();
		return FALSE;
	}

	// 检查黑市是否有收购该商品
	bool found = false;
	int nMarketCount = m_main->m_market.GetItemCount();
	for (int i = 0; i < nMarketCount; ++i)
	{
		CString marketName = m_main->m_market.GetItemText(i, 0);
		if (marketName == m_goods)
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		CString msg;
		msg.Format(L"哦？仿佛没有人在这里做%s生意。", m_goods);
		EndDialog(IDCANCEL);
		DiaryDlg diary(nullptr, msg);
		diary.DoModal();
		return FALSE;
	}

	m_spin.SetBuddy(GetDlgItem(IDC_COUNT));
	m_spin.SetRange(0, m_count);
	m_spin.SetPos(m_count);

	CString strAsk;
	strAsk.Format(L"您有%d个%s，想卖出多少？", m_count, m_goods);
	SetDlgItemText(IDC_ASK, strAsk);
	SetDlgItemText(IDC_COUNT, std::to_wstring(m_count).c_str());

	return TRUE;
}


BEGIN_MESSAGE_MAP(SellDlg, CDialogEx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN, &SellDlg::OnDeltaposSpin)
	ON_BN_CLICKED(IDC_OK, &SellDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CANCEL, &SellDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// SellDlg 消息处理程序

void SellDlg::OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult)
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
	SetDlgItemText(IDC_COUNT, strValue);

	*pResult = 0;
}

void SellDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strCount;
	GetDlgItemText(IDC_COUNT, strCount);

	if (strCount.IsEmpty())
	{
		MessageBox(L"请输入卖出数量！", L"提示", MB_ICONINFORMATION);
		return;
	}

	int count = _wtoi(strCount);
	if (count < 0 || count > m_count)
	{
		CString msg;
		msg.Format(L"请输入0到%d间的整数", m_count);
		MessageBox(msg, L"提示", MB_ICONINFORMATION);
		return;
	}

	// 检查黑市是否有收购该商品，并获取价格
	bool found = false;
	int nMarketCount = m_main->m_market.GetItemCount();
	int sellPrice = 0;
	for (int i = 0; i < nMarketCount; ++i)
	{
		CString marketName = m_main->m_market.GetItemText(i, 0);
		if (marketName == m_goods)
		{
			found = true;
			CString priceStr = m_main->m_market.GetItemText(i, 1);
			sellPrice = _wtoi(priceStr);
			break;
		}
	}
	if (!found)
	{
		CString msg;
		msg.Format(L"哦？仿佛没有人在这里做%s生意。", m_goods);
		DiaryDlg diary(nullptr, msg);
		diary.DoModal();
		return;
	}

	m_main->cash += count * sellPrice;
	m_main->total -= count;
	m_main->m_coat.DeleteItem(m_main->m_coat.GetSelectionMark());

	CDialogEx::OnOK();
}

void SellDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
