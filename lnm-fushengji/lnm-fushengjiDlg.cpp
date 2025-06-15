// lnm-fushengjiDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "utils.h"
#include "lnm-fushengji.h"
#include "lnm-fushengjiDlg.h"

#include "MainDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ClnmfushengjiDlg 对话框



ClnmfushengjiDlg::ClnmfushengjiDlg(CWnd* pParent /*=nullptr*/, bool story)
	: CDialogEx(IDD_LNMFUSHENGJI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_story = story;
}

void ClnmfushengjiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(ClnmfushengjiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_USER + 1, &ClnmfushengjiDlg::OnUpdateLoadMsg)
	ON_MESSAGE(WM_USER + 2, &ClnmfushengjiDlg::OnEnableButton)
	ON_BN_CLICKED(IDC_BUTTON1, &ClnmfushengjiDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// ClnmfushengjiDlg 消息处理程序

BOOL ClnmfushengjiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标
	SetIcon(m_hIcon, TRUE);  // 设置大图标
	SetIcon(m_hIcon, FALSE); // 设置小图标

	// TODO: 在此添加额外的初始化代码
	if (!m_story)
	{
		std::thread([this]() {
			CString msg[5] = {
				L"初始化BBC信息....",
				L"初始化Graphic信息.....",
				L"初始化黑市物品......",
				L"初始化随机事件......",
				L"加载吉吉国实时新闻...."
			};
			for (CString s : msg)
			{
				::SendMessage(this->GetSafeHwnd(), WM_USER + 1, 0, (LPARAM)new CString(s));
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
			}
			::SendMessage(this->GetSafeHwnd(), WM_USER + 1, 0, (LPARAM)new CString(L"游戏初始化完毕,准备进入牢黏猫窝..."));
			::SendMessage(this->GetSafeHwnd(), WM_USER + 2, 0, 0);
		}).detach();
	}
	else
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		SetDlgItemText(IDC_BUTTON1, L"继续游戏");
	}

	// 动态调整字体大小
	int dpiAdjustedTitleHeight = GetDpiAdjustedFontHeight(25, this->GetSafeHwnd());
	int dpiAdjustedLoadHeight = GetDpiAdjustedFontHeight(20, this->GetSafeHwnd());

	// 设置 IDC_TITLE 字体
	LOGFONT lfTitle = { 0 };
	lfTitle.lfHeight = dpiAdjustedTitleHeight; // 根据 DPI 调整字体高度
	lfTitle.lfWeight = FW_BOLD;               // 粗体
	wcscpy_s(lfTitle.lfFaceName, L"微软雅黑");
	m_fontTitle.CreateFontIndirect(&lfTitle);
	GetDlgItem(IDC_TITLE)->SetFont(&m_fontTitle);

	// 设置 IDC_LOAD 字体
	LOGFONT lfLoad = { 0 };
	lfLoad.lfHeight = dpiAdjustedLoadHeight; // 根据 DPI 调整字体高度
	lfLoad.lfWeight = FW_BOLD;              // 粗体
	wcscpy_s(lfLoad.lfFaceName, L"微软雅黑");
	m_fontLoad.CreateFontIndirect(&lfLoad);
	GetDlgItem(IDC_LOAD)->SetFont(&m_fontLoad);

	return TRUE; // 除非将焦点设置到控件，否则返回 TRUE
}

void ClnmfushengjiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ClnmfushengjiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR ClnmfushengjiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT ClnmfushengjiDlg::OnUpdateLoadMsg(WPARAM, LPARAM lParam)
{
	CString* pStr = (CString*)lParam;
	SetDlgItemText(IDC_LOAD, *pStr);
	delete pStr;
	return 0;
}

LRESULT ClnmfushengjiDlg::OnEnableButton(WPARAM, LPARAM)
{
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	return 0;
}


void ClnmfushengjiDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_story)
	{
		EndDialog(IDOK);
		MainDlg mainDlg;
		mainDlg.DoModal();
	}
	else
	{
		CDialogEx::OnOK();
	}
}
