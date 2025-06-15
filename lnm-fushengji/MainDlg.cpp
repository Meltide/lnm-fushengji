// MainDlg.cpp: 实现文件
//

#include "pch.h"
#include "utils.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "MainDlg.h"

#include "BankDlg.h"
#include "PostDlg.h"
#include "HospitalDlg.h"
#include "WangbaDlg.h"
#include "DiaryDlg.h"
#include "NewsDlg.h"
#include "BossComeDlg.h"
#include "lnm-fushengjiDlg.h"
#include "AboutDlg.h"


// MainDlg 对话框

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	cash = 2000;
	inBank = 0;
	debt = 5500;
	health = 100;
	fame = 100;

	total = 0;
	coat = 100;

	leftDay = 0;

	goods[0] = L"进口和成天下";
	goods[1] = L"走私公交车";
	goods[2] = L"盗版Galaxy";
	goods[3] = L"巧克力（剧毒）";
	goods[4] = L"《outice艾草》（禁书）";
	goods[5] = L"进口福瑞";
	goods[6] = L"看片神器";
	goods[7] = L"伪劣飞机杯";
}

MainDlg::~MainDlg()
{
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_CASH, m_cash);
	DDX_Control(pDX, IDC_INBANK, m_inBank);
	DDX_Control(pDX, IDC_DEBT, m_debt);
	DDX_Control(pDX, IDC_HEALTH, m_health);
	DDX_Control(pDX, IDC_FAME, m_fame);

	DDX_Control(pDX, IDC_LIST_MARKET, m_market);
	DDX_Control(pDX, IDC_LIST_COAT, m_coat);

	DDX_Control(pDX, IDC_BUTTON_ICEHOME, m_iceHome);
	DDX_Control(pDX, IDC_BUTTON_MCPECITY, m_mcpeCity);
	DDX_Control(pDX, IDC_BUTTON_DANCITY, m_danCity);
	DDX_Control(pDX, IDC_BUTTON_MELTCITY, m_meltCity);
	DDX_Control(pDX, IDC_BUTTON_MINCITY, m_minCity);
	DDX_Control(pDX, IDC_BUTTON_FURRYCS, m_furryCs);
	DDX_Control(pDX, IDC_BUTTON_CODE, m_code);
	DDX_Control(pDX, IDC_BUTTON_MINHOME, m_minHome);
	DDX_Control(pDX, IDC_BUTTON_GALAXY, m_galaxy);
	DDX_Control(pDX, IDC_BUTTON_FILE, m_file);
}

BOOL MainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);  // 设置大图标
	SetIcon(m_hIcon, FALSE); // 设置小图标

	// 禁用关闭按钮
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		pSysMenu->EnableMenuItem(SC_CLOSE, MF_BYCOMMAND | MF_GRAYED); // 灰化关闭按钮
	}

	CString title;
	title.Format(L"牢黏猫浮生 (%u/40天)", leftDay);
	SetWindowText(title);

	// 获取图片控件
	CStatic* pPictureControl = (CStatic*)GetDlgItem(IDC_SUBWAY); // 替换为你的图片控件 ID
	if (pPictureControl)
	{
		// 获取控件的当前大小
		CRect rect;
		pPictureControl->GetWindowRect(&rect);
		ScreenToClient(&rect);

		// 根据 DPI 调整大小，并加入缩放因子
		float scaleFactor = 0.52f; // 缩放因子，值越小图片越小
		int adjustedWidth = static_cast<int>(GetDpiAdjustedSize(rect.Width(), this->GetSafeHwnd()) * scaleFactor);
		int adjustedHeight = static_cast<int>(GetDpiAdjustedSize(rect.Height(), this->GetSafeHwnd()) * scaleFactor);

		// 设置控件的新大小
		pPictureControl->SetWindowPos(nullptr, rect.left, rect.top, adjustedWidth, adjustedHeight, SWP_NOZORDER | SWP_NOMOVE);
	}

	// 设置出租屋标题
	CString coatTitle;
	coatTitle.Format(L"您的出租屋 (%u/%u)", total, coat);
	SetDlgItemText(IDC_STATIC_COAT, coatTitle);

	// 设置市场列表控件样式
	m_market.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | WS_HSCROLL);
	m_market.InsertColumn(0, L"商品", LVCFMT_LEFT, 150);
	m_market.InsertColumn(1, L"黑市价格", LVCFMT_LEFT, 150);

	// 初始化黑市货品
	GenGoods();

	// 设置出租屋列表控件样式
	m_coat.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | WS_HSCROLL);
	m_coat.InsertColumn(0, L"商品", LVCFMT_LEFT, 150);
	m_coat.InsertColumn(1, L"买进价格", LVCFMT_LEFT, 150);

	// 动态调整字体大小
	int dpiAdjustedFontHeight = GetDpiAdjustedFontHeight(28, this->GetSafeHwnd());

	// 创建自定义字体
	LOGFONT lf = { 0 };
	lf.lfHeight = dpiAdjustedFontHeight; // 根据 DPI 调整字体高度
	lf.lfWeight = FW_BOLD;              // 粗体
	wcscpy_s(lf.lfFaceName, L"微软雅黑"); // 字体名称
	m_fontBold.CreateFontIndirect(&lf);

	// 应用字体到控件
	m_cash.SetFont(&m_fontBold);
	m_inBank.SetFont(&m_fontBold);
	m_debt.SetFont(&m_fontBold);
	m_health.SetFont(&m_fontBold);
	m_fame.SetFont(&m_fontBold);

	// 设置每个控件的文本
	CString strCash;
	strCash.Format(L"%ld", cash);
	m_cash.SetWindowText(strCash);

	CString strInBank;
	strInBank.Format(L"%ld", inBank);
	m_inBank.SetWindowText(strInBank);

	CString strDebt;
	strDebt.Format(L"%ld", debt);
	m_debt.SetWindowText(strDebt);

	CString strHealth;
	strHealth.Format(L"%ld", health);
	m_health.SetWindowText(strHealth);

	CString strFame;
	strFame.Format(L"%ld", fame);
	m_fame.SetWindowText(strFame);

	return TRUE;  // return TRUE unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)
    ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_ICEHOME, &MainDlg::OnBnClickedButtonIcehome)
	ON_BN_CLICKED(IDC_BUTTON_MCPECITY, &MainDlg::OnBnClickedButtonMcpecity)
	ON_BN_CLICKED(IDC_BUTTON_DANCITY, &MainDlg::OnBnClickedButtonDancity)
	ON_BN_CLICKED(IDC_BUTTON_MELTCITY, &MainDlg::OnBnClickedButtonMeltcity)
	ON_BN_CLICKED(IDC_BUTTON_MINCITY, &MainDlg::OnBnClickedButtonMincity)
	ON_BN_CLICKED(IDC_BUTTON_FURRYCS, &MainDlg::OnBnClickedButtonFurrycs)
	ON_BN_CLICKED(IDC_BUTTON_CODE, &MainDlg::OnBnClickedButtonCode)
	ON_BN_CLICKED(IDC_BUTTON_MINHOME, &MainDlg::OnBnClickedButtonMinhome)
	ON_BN_CLICKED(IDC_BUTTON_GALAXY, &MainDlg::OnBnClickedButtonGalaxy)
	ON_BN_CLICKED(IDC_BUTTON_FILE, &MainDlg::OnBnClickedButtonFile)
	ON_BN_CLICKED(IDC_BUTTON_WANGBA, &MainDlg::OnBnClickedButtonWangba)
	ON_BN_CLICKED(IDC_BUTTON_BOSS, &MainDlg::OnBnClickedButtonBoss)
	ON_COMMAND(ID_32780, &MainDlg::OnStory)
	ON_COMMAND(ID_32781, &MainDlg::OnAbout)
	ON_COMMAND(ID_32779, &MainDlg::OnWangba)
	ON_COMMAND(ID_32774, &MainDlg::OnExit)
	ON_BN_CLICKED(IDC_BUTTON_BANK, &MainDlg::OnBnClickedButtonBank)
	ON_COMMAND(ID_32775, &MainDlg::OnBank)
	ON_BN_CLICKED(IDC_BUTTON_POST, &MainDlg::OnBnClickedButtonPost)
	ON_COMMAND(ID_32776, &MainDlg::OnPost)
	ON_BN_CLICKED(IDC_BUTTON_HOSP, &MainDlg::OnBnClickedButtonHosp)
	ON_COMMAND(ID_32777, &MainDlg::OnHosp)
	ON_BN_CLICKED(IDC_BUTTON_HOUSE, &MainDlg::OnBnClickedButtonHouse)
	ON_COMMAND(ID_32771, &MainDlg::OnNewgame)
END_MESSAGE_MAP()

HBRUSH MainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    // 检查控件 ID
    int nID = pWnd->GetDlgCtrlID();
    if (nID == IDC_CASH || nID == IDC_INBANK || nID == IDC_HEALTH || nID == IDC_FAME)
    {
        // 设置背景为黑色
        pDC->SetBkColor(RGB(0, 0, 0));
        pDC->SetTextColor(RGB(0, 221, 0)); // 设置文本为绿色
        static HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
        return hBrush;
    }
	else if (nID == IDC_DEBT)
	{
		// 设置背景为黑色
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(217, 0, 0)); // 设置文本为红色
		static HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
		return hBrush;
	}

    return CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
}

void MainDlg::GenGoods()
{
	// 初始化黑市货品
	srand((unsigned)time(nullptr)); // 设置随机种子
	int goodsCount = sizeof(goods) / sizeof(goods[0]); // 获取货品总数
	const int randomCount = 5; // 随机选择五个货品
	std::vector<int> selectedIndices; // 用于存储已选择的货品索引

	for (int i = 0; i < randomCount; ++i)
	{
		int randomIndex;
		do
		{
			randomIndex = rand() % goodsCount; // 随机选择货品索引
		} while (std::find(selectedIndices.begin(), selectedIndices.end(), randomIndex) != selectedIndices.end()); // 确保不重复

		selectedIndices.push_back(randomIndex); // 记录已选择的索引

		CString price;
		price.Format(L"%d", rand() % 1000 + 100); // 随机生成价格
		m_market.InsertItem(i, goods[randomIndex]); // 插入货品名称
		m_market.SetItemText(i, 1, price); // 插入货品价格
	}
}

void MainDlg::FlushBtn()
{
	m_iceHome.EnableWindow(TRUE);
	m_mcpeCity.EnableWindow(TRUE);
	m_danCity.EnableWindow(TRUE);
	m_meltCity.EnableWindow(TRUE);
	m_minCity.EnableWindow(TRUE);
	m_furryCs.EnableWindow(TRUE);
	m_code.EnableWindow(TRUE);
	m_minHome.EnableWindow(TRUE);
	m_galaxy.EnableWindow(TRUE);
	m_file.EnableWindow(TRUE);

	m_iceHome.SetState(FALSE);
	m_mcpeCity.SetState(FALSE);
	m_danCity.SetState(FALSE);
	m_meltCity.SetState(FALSE);
	m_minCity.SetState(FALSE);
	m_furryCs.SetState(FALSE);
	m_code.SetState(FALSE);
	m_minHome.SetState(FALSE);
	m_galaxy.SetState(FALSE);
	m_file.SetState(FALSE);
}

void MainDlg::Clicked(CButton& btn)
{
	FlushBtn();
	btn.EnableWindow(FALSE);
	btn.SetState(TRUE);

	// 将焦点设置到其他控件，避免显示焦点边框
	GetDlgItem(IDC_STATIC)->SetFocus();

	btn.Invalidate();
}

void MainDlg::FlushDisplay()
{
	CString strCash;
	strCash.Format(L"%ld", cash);
	m_cash.SetWindowText(strCash); // 更新现金显示

	CString strInBank;
	strInBank.Format(L"%ld", inBank);
	m_inBank.SetWindowText(strInBank); // 更新银行存款显示

	CString strDebt;
	strDebt.Format(L"%ld", debt);
	m_debt.SetWindowText(strDebt); // 更新债务显示

	CString strHealth;
	strHealth.Format(L"%ld", health);
	m_health.SetWindowText(strHealth); // 更新健康值显示

	CString strFame;
	strFame.Format(L"%ld", fame);
	m_fame.SetWindowText(strFame); // 更新名声值显示

	// 设置出租屋标题
	CString coatTitle;
	coatTitle.Format(L"您的出租屋 (%u/%u)", total, coat);
	SetDlgItemText(IDC_STATIC_COAT, coatTitle);
}

void MainDlg::NextDay()
{
	m_market.DeleteAllItems(); // 清空黑市货品列表
	GenGoods(); // 重新生成黑市货品

	leftDay++; // 增加一天
	CString title;
	title.Format(L"牢黏猫浮生 (%u/40天)", leftDay);
	SetWindowText(title); // 更新窗口标题

	if (debt > 0)
	{
		debt *= 1.1; // 债务增加10%
		FlushDisplay();
	}

	if (inBank > 0)
	{
		inBank *= 1.01;
		FlushDisplay();
	}

	if (leftDay == 39)
	{
		DiaryDlg diary(nullptr, L"俺明天回家乡，快把全部货物卖掉。");
		diary.DoModal();
	}

	if (leftDay >= 40) // 检查是否达到游戏结束条件
		EndGame();
}

void MainDlg::EndGame()
{

}

// MainDlg 消息处理程序

void MainDlg::OnBnClickedButtonIcehome()
{
	// TODO: 在此添加控件通知处理程序代码
	Clicked(m_iceHome);
	NextDay();
}

void MainDlg::OnBnClickedButtonMcpecity()
{
	// TODO: 在此添加控件通知处理程序代码
	Clicked(m_mcpeCity);
	NextDay();
}

void MainDlg::OnBnClickedButtonDancity()
{
	// TODO: 在此添加控件通知处理程序代码
	Clicked(m_danCity);
	NextDay();
}

void MainDlg::OnBnClickedButtonMeltcity()
{
	// TODO: 在此添加控件通知处理程序代码
	Clicked(m_meltCity);
	NextDay();
}

void MainDlg::OnBnClickedButtonMincity()
{
	// TODO: 在此添加控件通知处理程序代码
	Clicked(m_minCity);
	NextDay();
}

void MainDlg::OnBnClickedButtonFurrycs()
{
	// TODO: 在此添加控件通知处理程序代码
	Clicked(m_furryCs);
	NextDay();
}

void MainDlg::OnBnClickedButtonCode()
{
	// TODO: 在此添加控件通知处理程序代码
	Clicked(m_code);
	NextDay();
}

void MainDlg::OnBnClickedButtonMinhome()
{
	// TODO: 在此添加控件通知处理程序代码
	Clicked(m_minHome);
	NextDay();
}

void MainDlg::OnBnClickedButtonGalaxy()
{
	// TODO: 在此添加控件通知处理程序代码
	Clicked(m_galaxy);
	NextDay();
}

void MainDlg::OnBnClickedButtonFile()
{
	// TODO: 在此添加控件通知处理程序代码
	Clicked(m_file);
	NextDay();
}


void MainDlg::OnNewgame()
{
	// TODO: 在此添加命令处理程序代码
	if (40 - leftDay >= 3)
		if (MessageBox(L"您正在玩一个游戏，要放弃它并开始新的吗?", L"注意", MB_YESNO | MB_ICONWARNING) == IDNO)
			return;
	
	cash = 2000;
	inBank = 0;
	debt = 5500;
	health = 100;
	fame = 100;

	total = 0;
	coat = 100;

	leftDay = 0;

	CString title;
	title.Format(L"牢黏猫浮生 (%u/40天)", leftDay);
	SetWindowText(title); // 更新窗口标题

	m_market.DeleteAllItems();
	m_coat.DeleteAllItems();
	GenGoods();
	FlushBtn();
	FlushDisplay();
}

void MainDlg::OnExit()
{
	// TODO: 在此添加命令处理程序代码
	NewsDlg newsDlg(nullptr, L"《牢黏猫游戏报》报道: 玩家“无名氏”在牢黏猫窝没挣着钱，被遣送回家。");
	newsDlg.DoModal();
	EndDialog(IDOK);
}

void MainDlg::OnBnClickedButtonBank()
{
	// TODO: 在此添加控件通知处理程序代码
	BankDlg bankDlg(nullptr, this);
	bankDlg.DoModal();
}

void MainDlg::OnBnClickedButtonHosp()
{
	// TODO: 在此添加控件通知处理程序代码
	if (health == 100)
	{
		DiaryDlg diary(nullptr, L"min笑咪咪地望着俺：“大哥！神经科这边挂号.”");
		diary.DoModal();
		return;
	}

	HospitalDlg hosp(nullptr, this);
	if (hosp.DoModal() == IDCANCEL)
	{
		DiaryDlg diary(nullptr, L"医生说，“钱不够哎! 拒绝治疗。”");
		diary.DoModal();
	}

	FlushDisplay();
}

void MainDlg::OnBnClickedButtonPost()
{
	// TODO: 在此添加控件通知处理程序代码
	if (debt == 0)
	{
		if (cash + inBank < 1000)
		{
			DiaryDlg diary(nullptr, L"outice嘿嘿笑道：“你没钱,有神经病!”");
			diary.DoModal();
		}
		else if (cash + inBank < 100000 && cash + inBank>1000)
		{
			DiaryDlg diary(nullptr, L"outice朝俺点头：“bro想支援家乡1000迷你币吗？”");
			diary.DoModal();
		}
		else if (cash + inBank < 10000000 && cash + inBank>100000)
		{
			DiaryDlg diary(nullptr, L"outice在电话中朝俺鞠躬：“富哥!我想把我星怒嫁给您.”");
			diary.DoModal();
		}
		else if (cash + inBank > 10000000)
		{
			DiaryDlg diary(nullptr, L"outice在电话中朝俺下跪，说：“您简直是我跌！”");
			diary.DoModal();
		}
		else
		{
			DiaryDlg diary(nullptr, L"outice说：“您是赛博黏氢入的典范！”");
			diary.DoModal();
		}

		return;
	}

	PostDlg post(nullptr, this);
	post.DoModal();

	if (post.back == 0)
	{
		DiaryDlg diary(nullptr, L"outice老婆狂吞“和成天下”，冷笑道：“你还得起吗?”");
		diary.DoModal();
	}

	FlushDisplay();
}

void MainDlg::OnBnClickedButtonHouse()
{
	// TODO: 在此添加控件通知处理程序代码
	if (coat == 140)
	{
		DiaryDlg diary(nullptr, L"中介说，您的房子比群主的还大!还租房?");
		diary.DoModal();
		return;
	}

	if (cash < 30000)
	{
		DiaryDlg diary(nullptr, L"中介说，您没有三万现金就想租房? 一边凉快去!");
		diary.DoModal();
		return;
	}
}

void MainDlg::OnBnClickedButtonWangba()
{
	// TODO: 在此添加控件通知处理程序代码
	if (cash < 15)
	{
		DiaryDlg diary(nullptr, L"进网吧至少身上要带15迷你币，呵呵，取钱再来。");
		diary.DoModal();
		return;
	}

	WangbaDlg wangba;
	wangba.DoModal();
	
	CString msg;
	srand((unsigned)time(nullptr));
	unsigned int money = rand() % 10 + 1;
	cash += money;

	msg.Format(L"感谢Graphic改革，可以免费看片! 还挣了91短视频广告费%d元，嘿嘿!", money);
	DiaryDlg diary(nullptr, msg);
	diary.DoModal();

	FlushDisplay();
}

void MainDlg::OnBnClickedButtonBoss()
{
	// TODO: 在此添加控件通知处理程序代码
	BossComeDlg BossComeDlg;
	BossComeDlg.DoModal();
}

void MainDlg::OnBank()
{
	// TODO: 在此添加命令处理程序代码
	BankDlg bankDlg(nullptr, this);
	bankDlg.DoModal();

	FlushDisplay();
}

void MainDlg::OnHosp()
{
	// TODO: 在此添加命令处理程序代码
	if (health == 100)
	{
		DiaryDlg diary(nullptr, L"min笑咪咪地望着俺：“大哥！神经科这边挂号.”");
		diary.DoModal();
		return;
	}

	HospitalDlg hosp(nullptr, this);
	if (hosp.DoModal() == IDCANCEL)
	{
		DiaryDlg diary(nullptr, L"医生说，“钱不够哎! 拒绝治疗。”");
		diary.DoModal();
	}

	FlushDisplay();
}

void MainDlg::OnPost()
{
	// TODO: 在此添加命令处理程序代码
	PostDlg post(nullptr, this);
	post.DoModal();

	if (post.back == 0)
	{
		DiaryDlg diary(nullptr, L"outice老婆狂吞“和成天下”，冷笑道：“你还得起吗?”");
		diary.DoModal();
	}

	FlushDisplay();
}

void MainDlg::OnWangba()
{
	// TODO: 在此添加命令处理程序代码
	if (cash < 15)
	{
		DiaryDlg diary(nullptr, L"进网吧至少身上要带15迷你币，呵呵，取钱再来。");
		diary.DoModal();
		return;
	}

	WangbaDlg wangbaDlg;
	wangbaDlg.DoModal();

	CString msg;
	srand((unsigned)time(nullptr));
	unsigned int money = rand() % 10 + 1;
	cash += money;

	msg.Format(L"感谢Graphic改革，可以免费看片! 还挣了91短视频广告费%d元，嘿嘿!", money);
	DiaryDlg diary(nullptr, msg);
	diary.DoModal();
}

void MainDlg::OnStory()
{
	// TODO: 在此添加命令处理程序代码
	ClnmfushengjiDlg storyDlg(nullptr, true);
	storyDlg.DoModal();
}

void MainDlg::OnAbout()
{
	// TODO: 在此添加命令处理程序代码
	AboutDlg about;
	about.DoModal();
}
