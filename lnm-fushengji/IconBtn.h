#pragma once
#include <afxwin.h>

class CIconBtn : public CButton
{
public:
    HICON m_hIcon;
    CString m_strText;

    CIconBtn();

    void SetIconText(HICON hIcon, const CString& strText);

protected:
    bool m_bHover;
    bool m_bPressed;
    bool m_bTracking;

    void TrackMouse();

    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnMouseLeave();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

    DECLARE_MESSAGE_MAP()
};