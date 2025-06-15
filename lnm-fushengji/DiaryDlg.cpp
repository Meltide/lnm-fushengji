// DiaryDlg.cpp: 实现文件
//

#include "pch.h"
#include "utils.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "DiaryDlg.h"

extern CString globalMsg; // 全局变量，用于存储消息内容

// DiaryDlg 对话框

IMPLEMENT_DYNAMIC(DiaryDlg, CDialogEx)

DiaryDlg::DiaryDlg(CWnd* pParent /*=nullptr*/, CString msg)
	: CDialogEx(IDD_DIARY, pParent)
{
	this->msg = msg;
}

DiaryDlg::~DiaryDlg()
{
}

void DiaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL DiaryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 在对话框初始化时使用 msg
	SetDlgItemText(IDC_TEXT, msg);

	// 获取图片控件
	CStatic* pPictureControl = (CStatic*)GetDlgItem(IDC_DIARY); // 替换为你的图片控件 ID
	if (pPictureControl)
	{
		// 获取控件的当前大小
		CRect rect;
		pPictureControl->GetWindowRect(&rect);
		ScreenToClient(&rect);

		// 根据 DPI 调整大小
		int adjustedWidth = static_cast<int>(GetDpiAdjustedSize(rect.Width(), this->GetSafeHwnd()));
		int adjustedHeight = static_cast<int>(GetDpiAdjustedSize(rect.Height(), this->GetSafeHwnd()));

		// 设置控件的新大小
		pPictureControl->SetWindowPos(nullptr, rect.left, rect.top, adjustedWidth, adjustedHeight, SWP_NOZORDER | SWP_NOMOVE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(DiaryDlg, CDialogEx)
END_MESSAGE_MAP()


// DiaryDlg 消息处理程序
