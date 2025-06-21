// BuyDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "BuyDlg.h"

#include "DiaryDlg.h"


// BuyDlg 对话框

IMPLEMENT_DYNAMIC(BuyDlg, CDialogEx)

BuyDlg::BuyDlg(CWnd* pParent /*=nullptr*/, MainDlg* main)
	: CDialogEx(IDD_BUY, pParent)
{
	m_nItem = main->m_market.GetSelectionMark();

	m_main = main;
	m_goods = main->m_market.GetItemText(m_nItem, 0).GetString();
	m_price = _wtoi(main->m_market.GetItemText(m_nItem, 1).GetString());
	m_remain = main->coat - main->total;
}

BuyDlg::~BuyDlg()
{
}

void BuyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_SPIN, m_spin);
}

BOOL BuyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	if (m_nItem == -1) {
		EndDialog(IDCANCEL);
		DiaryDlg diary(nullptr, L"我还没有选定买什么物品呢。");
		diary.DoModal();
	}
	else
		m_count = m_main->cash / m_price;
	if (m_count > m_remain)
		m_count = m_remain;

	if (m_price > m_main->cash)
	{
		EndDialog(IDCANCEL);
		CString msg;

		if (m_main->inBank > 0)
			msg = L"俺带的现金不够，去银行提点钱吧。";
		else
			msg = L"俺的现金不够，银行又没有存款，咋办哩?";
		
		DiaryDlg diary(nullptr, msg);
		diary.DoModal();
	}

	m_spin.SetBuddy(GetDlgItem(IDC_COUNT));
	m_spin.SetRange(0, m_count);
	m_spin.SetPos(m_count);

	CString strAsk;
	strAsk.Format(L"您的现金是%d迷你币，最多可以买%d个%s", m_main->cash, m_count, m_goods);
	SetDlgItemText(IDC_ASK, strAsk);
	SetDlgItemInt(IDC_COUNT, m_count);

	return TRUE;
}


BEGIN_MESSAGE_MAP(BuyDlg, CDialogEx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN, &BuyDlg::OnDeltaposSpin)
	ON_BN_CLICKED(IDC_OK, &BuyDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CANCEL, &BuyDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// BuyDlg 消息处理程序

void BuyDlg::OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult)
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

void BuyDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strCount;
	GetDlgItemText(IDC_COUNT, strCount);

	if (strCount.IsEmpty())
	{
		MessageBox(L"请输入购买数量！", L"提示", MB_ICONINFORMATION);
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

	m_main->cash -= count * m_price;
	m_main->total += count;

	if (count > 0)
	{
		// 查找是否已存在该商品
		int nItemCount = m_main->m_coat.GetItemCount();
		bool found = false;
		for (int i = 0; i < nItemCount; ++i)
		{
			CString existName = m_main->m_coat.GetItemText(i, 0);
			if (existName == m_goods)
			{
				CString oldCountStr = m_main->m_coat.GetItemText(i, 1);
				int oldCount = _wtoi(oldCountStr);
				int newCount = oldCount + count;
				CString newCountStr;
				newCountStr.Format(L"%d", newCount);
				m_main->m_coat.SetItemText(i, 1, newCountStr);

				found = true;
				break;
			}
		}
		if (!found)
		{
			// 不存在，插入新行
			int nNew = m_main->m_coat.InsertItem(LVIF_TEXT | LVIF_IMAGE, 0, m_goods, 0, 0, 0, 0);
			m_main->m_coat.SetItemText(nNew, 1, strCount);
			m_main->m_coat.SetItemText(nNew, 2, std::to_wstring(count * m_price).c_str());
		}
	}

	CDialogEx::OnOK();
}

void BuyDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
