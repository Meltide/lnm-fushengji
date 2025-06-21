#include "pch.h"
#include "IconBtn.h"
#include "utils.h"

CIconBtn::CIconBtn() : m_hIcon(nullptr), m_bHover(false), m_bPressed(false), m_bTracking(false) {}

void CIconBtn::SetIconText(HICON hIcon, const CString& strText)
{
    m_hIcon = hIcon;
    m_strText = strText;
    Invalidate();
}

void CIconBtn::TrackMouse()
{
    if (!m_bTracking)
    {
        TRACKMOUSEEVENT tme = { sizeof(TRACKMOUSEEVENT), TME_LEAVE, m_hWnd, 0 };
        ::TrackMouseEvent(&tme);
        m_bTracking = true;
    }
}

void CIconBtn::OnMouseMove(UINT nFlags, CPoint point)
{
    TrackMouse();
    if (!m_bHover)
    {
        m_bHover = true;
        Invalidate();
    }
    CButton::OnMouseMove(nFlags, point);
}

void CIconBtn::OnMouseLeave()
{
    m_bHover = false;
    m_bTracking = false;
    Invalidate();
    CButton::OnMouseLeave();
}

void CIconBtn::OnLButtonDown(UINT nFlags, CPoint point)
{
    m_bPressed = true;
    Invalidate();
    CButton::OnLButtonDown(nFlags, point);
}

void CIconBtn::OnLButtonUp(UINT nFlags, CPoint point)
{
    m_bPressed = false;
    Invalidate();
    CButton::OnLButtonUp(nFlags, point);
}

void CIconBtn::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rc = lpDrawItemStruct->rcItem;

    // 背景色
    COLORREF bgColor = ::GetSysColor(COLOR_BTNFACE);
    if (m_bPressed)
        bgColor = RGB(200, 220, 255);
    else if (m_bHover)
        bgColor = RGB(220, 235, 255);

    pDC->FillSolidRect(&rc, bgColor);

    // 边框
    if (m_bPressed)
        pDC->Draw3dRect(&rc, RGB(100, 120, 180), RGB(100, 120, 180));
    else if (m_bHover)
        pDC->Draw3dRect(&rc, RGB(120, 160, 220), RGB(120, 160, 220));
    else
        pDC->Draw3dRect(&rc, RGB(180, 180, 180), RGB(180, 180, 180));

    // 动态根据按钮高度自适应iconSize
    int iconSize = min(rc.Height() - 6, GetDpiAdjustedSize(20, m_hWnd));
    int iconLeftMargin = 6;
    int spacing = GetDpiAdjustedSize(8, m_hWnd);
    int iconX = rc.left + iconLeftMargin;
    int iconY = rc.top + (rc.Height() - iconSize) / 2;

    // 绘制图标
    if (m_hIcon)
        ::DrawIconEx(pDC->GetSafeHdc(), iconX, iconY, m_hIcon, iconSize, iconSize, 0, NULL, DI_NORMAL);

    // 文字参数
    CFont* pOldFont = pDC->SelectObject(GetFont());
    pDC->SetBkMode(TRANSPARENT);
    pDC->SetTextColor(RGB(40, 40, 40));
    CSize textSize = pDC->GetTextExtent(m_strText);

    // 文字区域
    int textRightMargin = GetDpiAdjustedSize(12, m_hWnd);
    int textLeft = iconX + iconSize + spacing;
    int textRight = rc.right - textRightMargin;
    if (textRight <= textLeft)
        textRight = textLeft + 10;
    CRect textRect(textLeft, rc.top, textRight, rc.bottom);

    // 绘制文字
    pDC->DrawText(m_strText, &textRect, DT_RIGHT | DT_VCENTER | DT_SINGLELINE | DT_NOPREFIX);

    pDC->SelectObject(pOldFont);
}

BEGIN_MESSAGE_MAP(CIconBtn, CButton)
    ON_WM_MOUSEMOVE()
    ON_WM_MOUSELEAVE()
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
END_MESSAGE_MAP()