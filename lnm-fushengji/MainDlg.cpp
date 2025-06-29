﻿// MainDlg.cpp: 实现文件
//

#include "pch.h"
#include "utils.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "MainDlg.h"

#include "BuyDlg.h"
#include "SellDlg.h"

#include "BankDlg.h"
#include "PostDlg.h"
#include "HospitalDlg.h"
#include "WangbaDlg.h"
#include "DiaryDlg.h"
#include "NewsDlg.h"
#include "IntopDlg.h"
#include "TopDlg.h"
#include "BossComeDlg.h"
#include "lnm-fushengjiDlg.h"
#include "AboutDlg.h"


Message gameMsgs[] = {
	{170, "砖家提议提高群友“强碱素质”，进口福瑞颇受欢迎!", 5, 2, 0, 0},
	{139, "有入自豪地说：饿了不用吃答辩，吃巧克力（剧毒）就可以!", 3, 3, 0, 0},
	{100, "医院的秘密报告：“《outice 艾草》功效甚过91短视频”!", 4, 5, 0, 0},
	{41, "文盲说：“黑神话悟空？呸！不如盗版Galaxy。”", 2, 4, 0, 0},
	{37, "《吉吉国经济小报》社论：“走私公交车大力推进汽车消费!”", 1, 3, 0, 0},
	{23, "《吉吉国真理报》社论：“提倡卢关，落到实处”，伪劣斐济杯大受欢迎!", 7, 4, 0, 0},
	{37, "91.com电子书店也不敢卖《outice艾草》，黑市一册可卖天价!", 4, 8, 0, 0},
	{15, "minqwq在阳光牢黏猫窝说：“我酷!我使用伪劣斐济杯!”，伪劣斐济杯供不应求!", 7, 7, 0, 0},
	{40, "牢黏猫窝有人狂吃美团巧克力，可以卖出天价!", 3, 7, 0, 0},
	{29, "牢黏猫窝的群友们开始找片，看片神器大受欢迎！!", 6, 7, 0, 0},
	{35, "大伊万疯狂地购买走私公交车！价格狂升!", 1, 8, 0, 0},
	{17, "市场上充斥着来自美团的走私和成天下!", 0, 0, 8, 0},
	{24, "牢黏猫窝的孩子们都忙于上网看片，进口福瑞没人愿意超。", 5, 0, 5, 0},
	{18, "盗版业十分兴旺，“吉吉国硅谷”全是卖盗版Galaxy Client的福瑞!", 2, 0, 8, 0},
	{160, "吉吉国的老壁灯资助俺两部走私公交车！发了！！", 1, 0, 0, 2},
	{45, "三次方扫荡后，俺在黑暗角落里发现了孙超丢失的进口和成天下。", 0, 0, 0, 6},
	{35, "沙发瑞回家前把一些美团巧克力（剧毒）给俺!", 3, 0, 0, 4},
	{140,"媒体报道：又有霓虹国出口到吉吉国的产品出事了! 出事后霓虹人死不认帐,拒绝赔偿。outice得知此消息，托人把他用的看片神器（无任何厂商标识）硬卖给您，收您2500元。",6,0,0,1},
};

BadEvent events[] = {
	{117, "大街上两个xxs打了俺!", 3},
	{157, "俺在过街地道被Graphic超了一顿! ", 20},
	{21, "BBC追俺超过三个胡同。 ",1},
	{100, "牢黏猫窝拥挤的交通让俺心焦! ",1},
	{35, "打斐济的打俺一耳光!",1},
	{313, "一群Graphic超了俺!", 10},
	{120, "附近胡同的一个小男娘砸俺一砖头!", 5},
	{29, "附近网吧一个候国玉用电棍电击俺!",3},
	{43, "牢黏猫窝臭黑的小河熏着我了! ",1},
	{45, "守服务器的孙承欢嘲笑俺没吉吉国户口!",1},
	{48, "牢黏猫窝高温114514度!俺热...",1},
	{33, "开服添了新风景，牢黏猫窝又来沙尘暴!",1},
};

StealEvent steals[] = {
	{60, "俺怜悯地铁口扮演成乞丐的大伊万。", 10},
	{125, "沙发瑞在街头拦住俺：“bro给点钱用!”。",10},
	{100, "一个福瑞碰了俺一下，说：“别超了!”。",40},
	{65, "三个带红袖章的洗头佬揪住俺：“你是美团人?罚款!”",20},
	{35, "两个猛0揪住俺：“兄弟你今天必须月我。”", 15},
	{27, "群主说：“办牢黏猫证?晚上不要去我家给我送钱哦。”", 10},
	{40, "牢黏猫窝空气污染得厉害,俺去氧吧吸氧...", 5},
};

// MainDlg 对话框

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	cash = 200000;
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

	DDX_Control(pDX, IDC_BUTTON_GO, m_go);
	DDX_Control(pDX, IDC_BUTTON_BOSS, m_boss);

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

	DDX_Control(pDX, IDC_BUTTON_BANK, m_bank);
	DDX_Control(pDX, IDC_BUTTON_HOSP, m_hosp);
	DDX_Control(pDX, IDC_BUTTON_POST, m_post);
	DDX_Control(pDX, IDC_BUTTON_HOUSE, m_house);
	DDX_Control(pDX, IDC_BUTTON_WANGBA, m_wangba);
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
		float scaleFactor = 0.35f; // 缩放因子，值越小图片越小
		int adjustedWidth = static_cast<int>(GetDpiAdjustedSize(rect.Width(), this->GetSafeHwnd()) * scaleFactor);
		int adjustedHeight = static_cast<int>(GetDpiAdjustedSize(rect.Height(), this->GetSafeHwnd()) * scaleFactor);

		// 设置控件的新大小
		pPictureControl->SetWindowPos(nullptr, rect.left, rect.top, adjustedWidth, adjustedHeight, SWP_NOZORDER | SWP_NOMOVE);
	}

    // 获取DPI缩放因子
    HDC hdc = ::GetDC(m_hWnd);
    int dpi = GetDeviceCaps(hdc, LOGPIXELSX);
    ::ReleaseDC(m_hWnd, hdc);
    float dpiScale = dpi / 96.0f;

    // 设置图标列表
    int iconSize = static_cast<int>(18 * dpiScale);
    m_imageList.Create(iconSize, iconSize, ILC_COLOR32 | ILC_MASK, 1, 1);
    m_imageList.Add(AfxGetApp()->LoadIcon(IDI_GOODS));
    m_market.SetImageList(&m_imageList, LVSIL_SMALL);
    m_coat.SetImageList(&m_imageList, LVSIL_SMALL);

    // 设置市场列表控件样式
    m_market.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | WS_HSCROLL);

	CRect rcMarket;
	m_market.GetClientRect(&rcMarket);
	int marketWidth = rcMarket.Width();

	// 动态调整黑市列表列宽
	m_market.InsertColumn(0, L"商品", LVCFMT_LEFT, marketWidth / 2); // 商品列占50%
	m_market.InsertColumn(1, L"黑市价格", LVCFMT_LEFT, marketWidth - marketWidth / 2); // 黑市价格列占50%

    // 初始化黑市货品
    GenGoods();

    // 设置出租屋列表控件样式
    m_coat.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | WS_HSCROLL);

	CRect rcCoat;
	m_coat.GetClientRect(&rcCoat);
	int coatWidth = rcCoat.Width();

	m_coat.InsertColumn(0, L"商品", LVCFMT_LEFT, coatWidth * 2 / 5); // 40%
	m_coat.InsertColumn(1, L"数量", LVCFMT_LEFT, coatWidth / 5);     // 20%
	m_coat.InsertColumn(2, L"买进价格", LVCFMT_LEFT, coatWidth * 2 / 5); // 40%

    // 动态调整字体大小
    int dpiAdjustedFontHeight = GetDpiAdjustedFontHeight(28, this->GetSafeHwnd());

    // 创建等宽字体
    LOGFONT lf = { 0 };
    lf.lfHeight = dpiAdjustedFontHeight; // 根据 DPI 调整字体高度
    lf.lfWeight = FW_BOLD;               // 粗体
    // 推荐 Consolas，若无则 Courier New
    wcscpy_s(lf.lfFaceName, L"Consolas");
    m_fontBold.DeleteObject();
    m_fontBold.CreateFontIndirect(&lf);

    // 应用字体到控件
    m_cash.SetFont(&m_fontBold);
    m_inBank.SetFont(&m_fontBold);
    m_debt.SetFont(&m_fontBold);
    m_health.SetFont(&m_fontBold);
    m_fame.SetFont(&m_fontBold);

    // 设置按钮字体
    lf.lfHeight = GetDpiAdjustedFontHeight(16, this->GetSafeHwnd());
    lf.lfWeight = FW_NORMAL;
    wcscpy_s(lf.lfFaceName, L"Microsoft YaHei UI");
    m_buttonFont.CreateFontIndirect(&lf);

    m_go.SetFont(&m_buttonFont);
    m_boss.SetFont(&m_buttonFont);

	// 设置按钮图片
	m_bank.ModifyStyle(0, BS_OWNERDRAW);
	m_hosp.ModifyStyle(0, BS_OWNERDRAW);
	m_post.ModifyStyle(0, BS_OWNERDRAW);
	m_house.ModifyStyle(0, BS_OWNERDRAW);
	m_wangba.ModifyStyle(0, BS_OWNERDRAW);

	m_bank.SetIconText(AfxGetApp()->LoadIcon(IDI_BANK), L"银 行");
	m_hosp.SetIconText(AfxGetApp()->LoadIcon(IDI_HOSPITAL), L"医 院");
	m_post.SetIconText(AfxGetApp()->LoadIcon(IDI_POST), L"邮 局");
	m_house.SetIconText(AfxGetApp()->LoadIcon(IDI_HOUSE), L"租房中介");
	m_wangba.SetIconText(AfxGetApp()->LoadIcon(IDI_WANGBA), L"网 吧");

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
	ON_COMMAND(ID_32772, &MainDlg::OnTop)
	ON_BN_CLICKED(IDC_BUTTON_BUY, &MainDlg::OnBnClickedButtonBuy)
	ON_BN_CLICKED(IDC_BUTTON_SELL, &MainDlg::OnBnClickedButtonSell)
	ON_BN_CLICKED(IDC_BUTTON_GO, &MainDlg::OnBnClickedButtonGo)
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
	int priceTable[8];
	priceTable[0] = 100 + RandomNum(350);
	priceTable[1] = 15000 + RandomNum(15000);
	priceTable[2] = 5 + RandomNum(50);
	priceTable[3] = 1000 + RandomNum(2500);
	priceTable[4] = 5000 + RandomNum(9000);
	priceTable[5] = 250 + RandomNum(600);
	priceTable[6] = 750 + RandomNum(750);
	priceTable[7] = 65 + RandomNum(180);

	// 随机去掉3个商品
	std::vector<int> indices{ 0,1,2,3,4,5,6,7 };
	std::vector<int> selectedIndices;
	for (int i = 0; i < 3; ++i) {
		int idx = RandomNum((int)indices.size());
		indices.erase(indices.begin() + idx);
	}
	selectedIndices = indices;

	m_market.DeleteAllItems();
	for (size_t i = 0; i < selectedIndices.size(); ++i) {
		int id = selectedIndices[i];
		CString price;
		price.Format(L"%d", priceTable[id]);
		m_market.InsertItem(LVIF_TEXT | LVIF_IMAGE, (int)i, goods[id], 0, 0, 0, 0);
		m_market.SetItemText((int)i, 1, price);
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

void MainDlg::TriggerRandomEvents()
{
	// 处理Message事件
	int msgCount = sizeof(gameMsgs) / sizeof(gameMsgs[0]);
	for (int i = 0; i < msgCount; ++i) {
		// 查找该物品是否在黑市
		int row = -1;
		for (int j = 0; j < m_market.GetItemCount(); ++j) {
			CString name = m_market.GetItemText(j, 0);
			if (name == goods[gameMsgs[i].drug]) {
				row = j;
				break;
			}
		}
		if (row == -1)
			continue; // 黑市没有该物品，事件无效

		if (!(RandomNum(950) % gameMsgs[i].freq)) {
			CString msg = CString(gameMsgs[i].msg);

			// 处理商品价格变化
			int price = _wtoi(m_market.GetItemText(row, 1));
			if (gameMsgs[i].plus > 0)
				price *= gameMsgs[i].plus;
			if (gameMsgs[i].minus > 0)
				price /= gameMsgs[i].minus;
			if (price < 1) price = 1;
			CString newPrice;
			newPrice.Format(L"%d", price);
			m_market.SetItemText(row, 1, newPrice);

			// 赠送商品
			if (gameMsgs[i].add > 0) {
				if (total + gameMsgs[i].add > coat) {
					CString warn;
					warn.Format(L"可惜!俺租的房子太小，只能放%d个物品。", coat);
					DiaryDlg diary(nullptr, warn);
					diary.DoModal();
				}
				else {
					int found = -1;
					for (int k = 0; k < m_coat.GetItemCount(); ++k) {
						if (m_coat.GetItemText(k, 0) == goods[gameMsgs[i].drug]) {
							found = k;
							break;
						}
					}
					if (found != -1) {
						int cnt = _wtoi(m_coat.GetItemText(found, 1));
						cnt += gameMsgs[i].add;
						CString cntStr;
						cntStr.Format(L"%d", cnt);
						m_coat.SetItemText(found, 1, cntStr);
					}
					else {
						int n = m_coat.InsertItem(0, goods[gameMsgs[i].drug]);
						CString cntStr;
						cntStr.Format(L"%d", gameMsgs[i].add);
						m_coat.SetItemText(n, 1, cntStr);
						m_coat.SetItemText(n, 2, L"0");
					}
					total += gameMsgs[i].add;
				}
			}

			// 特殊事件：收2500元
			if (i == msgCount - 1) {
				debt += 2500;
			}

			// 更新显示
			FlushDisplay();

			NewsDlg news(nullptr, msg);
			news.DoModal();
			break; // 只触发一个Message事件
		}
	}

	// 处理BadEvent事件
	int badCount = sizeof(events) / sizeof(events[0]);
	for (int i = 0; i < badCount; ++i) {
		if (!(RandomNum(1000) % events[i].freq)) {
			CString msg = CString(events[i].msg);
			health -= events[i].hunt;
			if (health < 0) health = 0;

			// 附加健康减少说明
			msg.AppendFormat(L"俺的健康减少了%d点。", events[i].hunt);

			// 更新显示
			FlushDisplay();

			DiaryDlg diary(nullptr, msg);
			diary.DoModal();
			break; // 只触发一个BadEvent
		}
	}

	// 处理StealEvent事件
	int stealCount = sizeof(steals) / sizeof(steals[0]);
	for (int i = 0; i < stealCount; ++i) {
		if (!(RandomNum(1000) % steals[i].freq)) {
			CString msg = CString(steals[i].msg);
			int oldCash = cash;
			cash = cash * (100 - steals[i].ratoi) / 100;

			// 附加现金减少说明
			int lost = oldCash - cash;
			msg.AppendFormat(L"俺的迷你币减少了%d元。", lost);

			// 更新显示
			FlushDisplay();

			DiaryDlg diary(nullptr, msg);
			diary.DoModal();
			break; // 只触发一个StealEvent
		}
	}
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

	if (debt > 100000)
	{
		DiaryDlg diary(nullptr, L"俺欠钱太多，村长叫一群老乡揍了俺一顿!");
		diary.DoModal();
		health -= 30;
		FlushDisplay();
	}

	if (inBank > 0)
	{
		inBank *= 1.01;
		FlushDisplay();
	}

	TriggerRandomEvents();

	if (health < 85 && leftDay < 37 && health > 0) {
		int delay_day = 1 + RandomNum(2);
		CString msg1, msg2, msg3;
		msg1.Format(L"好心的群友把你抬到医院，医生让你治疗%d天。", delay_day);
		msg2 = L"由于不注意身体，你被人发现昏迷在地铁站附近。";
		int load = delay_day * (1000 + RandomNum(8500));
		msg3.Format(L"群主让人为你垫付了住院费用%d元。", load);

		DiaryDlg dlg(nullptr, msg1 + L"\n" + msg2 + L"\n" + msg3);
		dlg.DoModal();
		debt += load;
		health += 10;
		if (health > 100) health = 100;
		leftDay += delay_day; // 住院消耗天数
		FlushDisplay();
		return;
	}
	if (health < 20 && health > 0) {
		DiaryDlg dlg(nullptr, L"你的健康……健康危机……快去医院……");
		dlg.DoModal();
	}
	if (health <= 0) {
		DiaryDlg dlg(nullptr, L"你倒在街头，身边日记本上写着：“牢黏猫窝，我将再来！”");
		dlg.DoModal();
		EndGame();
	}

	if (leftDay == 39)
	{
		DiaryDlg diary(nullptr, L"俺明天回家乡，快把全部货物卖掉。");
		diary.DoModal();
	}

	if (leftDay >= 40) // 检查是否达到游戏结束条件
	{
		DiaryDlg diary(nullptr, L"俺已经在北京40天了，该回去结婚去了。");
		diary.DoModal();

		// 自动卖出剩余货物
		if (m_coat.GetItemCount() > 0)
		{
			CString goods_left = L"系统替你卖了剩余货物：";
			long total_earn = 0;
			for (int i = 0; i < m_coat.GetItemCount(); ++i)
			{
				CString name = m_coat.GetItemText(i, 0);
				CString cntStr = m_coat.GetItemText(i, 1);
				int count = _wtoi(cntStr);
				int price = 0;
				// 查找黑市价格
				for (int j = 0; j < m_market.GetItemCount(); ++j)
				{
					if (m_market.GetItemText(j, 0) == name)
					{
						price = _wtoi(m_market.GetItemText(j, 1));
						break;
					}
				}
				if (count > 0 && price > 0)
				{
					goods_left += name + L"×" + cntStr + L" ";
					cash += count * price;
					total_earn += count * price;
				}
			}
			goods_left += L"。";
			DiaryDlg dlg(nullptr, goods_left);
			dlg.DoModal();
			FlushDisplay();
		}

		EndGame();
	}
}

void MainDlg::EndGame()
{
	// 计算分数
	long score = cash + inBank - debt;
	if (score > 0)
	{
		// 可弹窗输入姓名，简化为默认
		IntopDlg inTop(nullptr, this);
		int order = inTop.GetTopOrder(score);
		if (order != 100) {
			// 进入高手榜
			inTop.DoModal();
		}
	}
	else
	{
		NewsDlg newsDlg(nullptr, L"《牢黏猫游戏报》报道: 玩家“无名氏”在牢黏猫窝没挣着钱，被遣送回家。");
		newsDlg.DoModal();
	}

	int status = MessageBox(L"嗨，再玩一把吗？", L"游戏结束", MB_YESNO | MB_ICONINFORMATION);
	if (status == IDYES)
	{
		OnNewgame(); // 重新开始游戏
		return;
	}
	else if (status == IDNO)
	{
		EndDialog(IDOK);
	}
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
	FlushDisplay();
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
	if (m_nVisitWangba > 2)
	{
		DiaryDlg diary(nullptr, L"outice放出话来：你别总是在网吧里看片，快去做正经买卖!");
		diary.DoModal();
		return;
	}

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

	m_nVisitWangba++;

	FlushDisplay();
}

void MainDlg::OnBnClickedButtonGo()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_goStat)
	{
		m_goStat = false;
		SetDlgItemText(IDC_PLACEGROUP, L"牢黏猫窝地标示意图");
		m_go.SetWindowText(L"我要单杀群友");
		m_iceHome.SetWindowText(L"ice家");
		m_mcpeCity.SetWindowText(L"MCPECity");
		m_danCity.SetWindowText(L"淡城");
		m_meltCity.SetWindowText(L"融城");
		m_minCity.SetWindowText(L"MinCity");
		m_furryCs.SetWindowText(L"福瑞超市");
		m_code.SetWindowText(L"牢黏猫Code");
		m_minHome.SetWindowText(L"min家");
		m_galaxy.SetWindowText(L"Galaxy 2024");
		m_file.SetWindowText(L"牢黏猫文件");
	}
	else
	{
		m_goStat = true;
		SetDlgItemText(IDC_PLACEGROUP, L"群友IP示意图");
		m_go.SetWindowText(L"我要逛地标");
		m_iceHome.SetWindowText(L"台州");
		m_mcpeCity.SetWindowText(L"厦门");
		m_danCity.SetWindowText(L"淄博");
		m_meltCity.SetWindowText(L"烟台");
		m_minCity.SetWindowText(L"菏泽");
		m_furryCs.SetWindowText(L"桂林");
		m_code.SetWindowText(L"陕西");
		m_minHome.SetWindowText(L"新余");
		m_galaxy.SetWindowText(L"温州");
		m_file.SetWindowText(L"天津");
	}

	// 将焦点设置到其他控件，避免显示焦点边框
	GetDlgItem(IDC_STATIC)->SetFocus();
}

void MainDlg::OnBnClickedButtonBoss()
{
	// TODO: 在此添加控件通知处理程序代码
	BossComeDlg BossComeDlg;
	BossComeDlg.DoModal();

	// 将焦点设置到其他控件，避免显示焦点边框
	GetDlgItem(IDC_STATIC)->SetFocus();
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

void MainDlg::OnTop()
{
	// TODO: 在此添加命令处理程序代码
	TopDlg top;
	top.DoModal();
}

void MainDlg::OnBnClickedButtonBuy()
{
	// TODO: 在此添加控件通知处理程序代码
	BuyDlg buy(nullptr, this);
	buy.DoModal();
	FlushDisplay();
}

void MainDlg::OnBnClickedButtonSell()
{
	// TODO: 在此添加控件通知处理程序代码
	SellDlg sell(nullptr, this);
	sell.DoModal();
	FlushDisplay();
}
