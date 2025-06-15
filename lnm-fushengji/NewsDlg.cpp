// NewsDlg.cpp: 实现文件
//

#include "pch.h"
#include "utils.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "NewsDlg.h"


// NewsDlg 对话框

IMPLEMENT_DYNAMIC(NewsDlg, CDialogEx)

NewsDlg::NewsDlg(CWnd* pParent /*=nullptr*/, CString msg)
	: CDialogEx(IDD_NEWS, pParent)
{
	m_msg = msg;
}

NewsDlg::~NewsDlg()
{
}

void NewsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL NewsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetDlgItemText(IDC_TEXT, m_msg);

	// 获取图片控件
	CStatic* pPictureControl = (CStatic*)GetDlgItem(IDC_NEWS); // 替换为你的图片控件 ID
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

	return TRUE;
}


BEGIN_MESSAGE_MAP(NewsDlg, CDialogEx)
END_MESSAGE_MAP()


// NewsDlg 消息处理程序

