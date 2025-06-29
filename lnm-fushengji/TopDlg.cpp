﻿// TopDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "TopDlg.h"


// TopDlg 对话框

IMPLEMENT_DYNAMIC(TopDlg, CDialogEx)

TopDlg::TopDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TOPLIST, pParent)
{

}

TopDlg::~TopDlg()
{
}

void TopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST1, m_topList);
}

BOOL TopDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_topList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | WS_HSCROLL);

	// 获取DPI缩放因子
	HDC hdc = ::GetDC(m_hWnd);
	int dpi = GetDeviceCaps(hdc, LOGPIXELSX);
	::ReleaseDC(m_hWnd, hdc);
	float dpiScale = dpi / 96.0f;

	// 获取列表控件客户区宽度
	CRect rcList;
	m_topList.GetClientRect(&rcList);
	int listWidth = rcList.Width();

	// 按比例分配列宽
	int col0 = static_cast<int>(listWidth * 0.10f); // 序号
	int col1 = static_cast<int>(listWidth * 0.28f); // 姓名
	int col2 = static_cast<int>(listWidth * 0.22f); // 金钱
	int col3 = static_cast<int>(listWidth * 0.22f); // 健康
	int col4 = listWidth - (col0 + col1 + col2 + col3); // 名声，剩余全部

	m_topList.InsertColumn(0, L"", LVCFMT_LEFT, col0);
	m_topList.InsertColumn(1, L"姓名", LVCFMT_LEFT, col1);
	m_topList.InsertColumn(2, L"金钱", LVCFMT_LEFT, col2);
	m_topList.InsertColumn(3, L"健康程度", LVCFMT_LEFT, col3);
	m_topList.InsertColumn(4, L"名声", LVCFMT_LEFT, col4);

	std::ifstream file("score.txt");
	if (!file.is_open())
	{
		MessageBox(L"未找到score.txt文件", L"错误", MB_ICONERROR);
		EndDialog(IDCANCEL);
	}

	std::string name, cash, health, fame;
	std::vector<Member> list;

	for (int i = 0; i < 10; i++)
	{
		std::getline(file, name);
		std::getline(file, cash);
		std::getline(file, health);
		std::getline(file, fame);
		list.emplace_back(name, cash, health, fame);
	}

	for (int i = 0; i < list.size(); i++)
	{
		CString strIndex;
		strIndex.Format(L"%d", i + 1);

		int index = m_topList.InsertItem(m_topList.GetItemCount(), strIndex);
		m_topList.SetItemText(index, 1, CString(list[i].name.c_str()));
		m_topList.SetItemText(index, 2, CString(list[i].cash.c_str()));
		m_topList.SetItemText(index, 3, CString(list[i].health.c_str()));
		m_topList.SetItemText(index, 4, CString(list[i].fame.c_str()));
	}

	file.close();
	return TRUE;
}


BEGIN_MESSAGE_MAP(TopDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TopDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// TopDlg 消息处理程序

void TopDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK(); // 关闭对话框
}
