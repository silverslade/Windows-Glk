/////////////////////////////////////////////////////////////////////////////
//
// Windows MFC Glk Libraries
//
// GlkMainWnd
// Main window of the Glk application
//
/////////////////////////////////////////////////////////////////////////////

#ifndef WINGLK_MAINWND_H_
#define WINGLK_MAINWND_H_

#include "GlkGraphic.h"
#include "MenuBar.h"
#include "TextOutput.h"
#include "Resource.h"

/////////////////////////////////////////////////////////////////////////////
// CToolBarEx control window, derived from CToolBar
/////////////////////////////////////////////////////////////////////////////

class CToolBarEx : public CToolBar
{
public:
  CToolBarEx() {}

  BOOL LoadToolBar(UINT nIDResource);
  BOOL LoadToolBar(LPCTSTR lpszResourceName);
  BOOL LoadBitmap(LPCTSTR lpszResourceName);
  BOOL SetBitmap(HBITMAP hbmImageWell);

  CBitmap& GetBitmap(void);

private:
  CBitmap m_bitmap;
};

/////////////////////////////////////////////////////////////////////////////
// CWinGlkViewWnd window, derived from the base CWnd class
/////////////////////////////////////////////////////////////////////////////

class CWinGlkViewWnd : public CWnd
{
public:
  CWinGlkViewWnd() {}

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CWinGlkViewWnd)
  //}}AFX_VIRTUAL

// Implementation
public:
  virtual ~CWinGlkViewWnd() {}

// Generated message map functions
protected:
  //{{AFX_MSG(CWinGlkViewWnd)
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg void OnPaint();
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()

public:
  void SizeWindows(void);
};

/////////////////////////////////////////////////////////////////////////////
// CWinGlkMainWnd frame window, derived from the menu bar frame class
/////////////////////////////////////////////////////////////////////////////

class CWinGlkMainWnd : public MenuBarFrameWnd
{
public:
  CWinGlkMainWnd();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CWinGlkMainWnd)
  public:
  virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
  protected:
  virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
  //}}AFX_VIRTUAL

// Implementation
public:
  virtual ~CWinGlkMainWnd();

  bool Create(bool bFrame);

  void StartTimer(int iMilliSecs);
  void SetBorders(bool bBorders);
  void SetGUI(bool bGUI);
  void EnableScrollback(bool bEnable);

  CWinGlkViewWnd* GetView(void) { return &m_View; }
  UINT GetCodePage(void) { return m_CodePage; }
  virtual void GetMessageString(UINT nID, CString& rMessage) const;

  void SetWindowMask(CWinGlkGraphic* pGraphic);

  TextOutput& GetTextOut(void) { return m_TextOut; }

// Generated message map functions
protected:
  //{{AFX_MSG(CWinGlkMainWnd)
  afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
  afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
  afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
  afx_msg void OnDestroy();
  afx_msg void OnTimer(UINT nIDEvent);
  afx_msg void OnScrollback();
  afx_msg void OnUpdateScrollback(CCmdUI* pCmdUI);
  afx_msg void OnFontProportional();
  afx_msg void OnFontFixed();
  afx_msg void OnOptions();
  afx_msg void OnAbout();
  afx_msg void OnAboutGame();
  afx_msg void OnEditPaste();
  afx_msg void OnFullscreen();
  //}}AFX_MSG
  afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
  afx_msg BOOL OnToolTipText(UINT nID, NMHDR* pNMHDR, LRESULT* pResult);
  afx_msg LRESULT OnSetMessageString(WPARAM wParam, LPARAM lParam);
  afx_msg LRESULT OnInputLangChange(WPARAM wParam, LPARAM lParam);
  afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
  DECLARE_MESSAGE_MAP()

protected:
  enum Timer
  {
    PulseTimer = 1,
    GlkTimer
  };

  void ChangeFont(bool bFixed);
  bool CheckMorePending(void);
  CRect GetDefaultSize(void);

protected:
  CWinGlkViewWnd m_View;
  CMenu m_FontMenu;
  CStatusBar m_StatusBar;
  CToolBarEx m_GlkToolBar;
  CToolBarEx m_UserToolBar;
  CRgn m_Mask;
  UINT m_CodePage;
  TextOutput m_TextOut;
  CRect m_NormalSize;
};

#endif // WINGLK_MAINWND_H_