// BossComeDlg.cpp: 实现文件
//

#include "pch.h"
#include "lnm-fushengji.h"
#include "afxdialogex.h"
#include "BossComeDlg.h"


// BossComeDlg 对话框

IMPLEMENT_DYNAMIC(BossComeDlg, CDialogEx)

BossComeDlg::BossComeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BOSS_COME, pParent)
{

}

BossComeDlg::~BossComeDlg()
{
}

void BossComeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL BossComeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str;
	str = "                              关于做好本月工作的一些具体想法  \r\n";
	str += "一、坚持做好本职工作，把业务和技术方面的协调任务进一步\r\n抓起来。工作要专注。\r\n";
	str += "二、虚心听取同事的意见。这一点很重要。\r\n";
	str += "三、我目前工作情况很好，但是要争取更好，无止境地提高自己的能力。\r\n";
	str += "四、主动、积极、制定计划、按时完成计划，每一天都要问自己：\r\n我工作得怎么样了？\r\n";
	str += "五、老板、经理非常有能力，而且对我很关心很照顾，我一定要认\r\n真工作,\r\n";
	str += "六、每天下班后，把自己的办公桌收拾干净，因为整洁有助于营造\r\n高效益的工作气氛，也能给人空气清香的感觉。\r\n";
	str += "七、每周六半夜，应把下一周该做的事情考虑好，并且最好把较容\r\n易的事放在周四下午，半个星期都干劲十足。 \r\n";
	str += "八、说话和做事不要自做主张，重要的事都要经理和老板指点，他们是\r\n绝对是正确的。\r\n";

	SetDlgItemText(IDC_WRITE, str);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_WRITE);
	pEdit->SetSel(-1, -1);
	pEdit->SetFocus();

	return FALSE;
}

BEGIN_MESSAGE_MAP(BossComeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK, &BossComeDlg::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_OK, &BossComeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// BossComeDlg 消息处理程序

void BossComeDlg::OnBnClickedCheck()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"拼写检查建议：“空气清香”改为“空气清新”\n“老板”改为“老板娘”。", L"拼写检查", MB_ICONINFORMATION);
}

void BossComeDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
