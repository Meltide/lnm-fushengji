// IntopDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "IntopDlg.h"

#include "TopDlg.h"


// IntopDlg 对话框

IMPLEMENT_DYNAMIC(IntopDlg, CDialogEx)

IntopDlg::IntopDlg(CWnd* pParent /*=nullptr*/, MainDlg* main)
	: CDialogEx(IDD_INTOP, pParent)
{
	m_main = main;
	m_money = main->cash + main->inBank;
}

IntopDlg::~IntopDlg()
{
}

void IntopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL IntopDlg::OnInitDialog()
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


BEGIN_MESSAGE_MAP(IntopDlg, CDialogEx)
END_MESSAGE_MAP()


void IntopDlg::LoadTopList(std::vector<TopEntry>& list)
{
	list.clear();
	std::ifstream fin("score.txt");
	if (!fin.is_open()) return;
	for (int i = 0; i < 10; ++i) {
		std::string name, score, health, fame;
		if (!std::getline(fin, name)) break;
		if (!std::getline(fin, score)) break;
		if (!std::getline(fin, health)) break;
		if (!std::getline(fin, fame)) break;
		list.emplace_back(CString(name.c_str()), atol(score.c_str()), atoi(health.c_str()), atoi(fame.c_str()));
	}
	fin.close();
}

void IntopDlg::SaveTopList(const std::vector<TopEntry>& list)
{
	std::ofstream fout("score.txt", std::ios::trunc);
	for (const auto& entry : list) {
		fout << CT2A(entry.name) << "\n"
			<< entry.score << "\n"
			<< entry.health << "\n"
			<< entry.fame << "\n";
	}
	fout.close();
}

int IntopDlg::GetTopOrder(long score)
{
	std::vector<TopEntry> list;
	LoadTopList(list);
	for (int i = 0; i < list.size(); ++i) {
		if (score > list[i].score)
			return i;
	}
	return (list.size() < 10) ? (int)list.size() : 100;
}

void IntopDlg::InsertTop(const TopEntry& entry)
{
	std::vector<TopEntry> list;
	LoadTopList(list);
	int pos = GetTopOrder(entry.score);
	if (pos == 100 && list.size() >= 10) return;
	list.insert(list.begin() + pos, entry);
	if (list.size() > 10) list.resize(10);
	SaveTopList(list);
}

void IntopDlg::ShowTopList(CWnd* pParent)
{
	TopDlg dlg(pParent);
	dlg.DoModal();
}

// IntopDlg 消息处理程序
