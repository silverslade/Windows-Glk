/////////////////////////////////////////////////////////////////////////////
//
// Windows MFC Glk Libraries
//
// GlkMainWnd
// Main window of the Glk application
//
/////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "GlkDll.h"
#include "GlkMainWnd.h"
#include "GlkDialogs.h"
#include "GlkSndChannel.h"
#include "GlkSound.h"
#include "GlkTalk.h"
#include "GlkWindowGfx.h"
#include "GlkWindowTextBuffer.h"
#include "WinGlk.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolBarEx control window, derived from CToolBar
/////////////////////////////////////////////////////////////////////////////

// Internal CToolBar data structure
struct CToolBarData
{
  WORD wVersion;
  WORD wWidth;
  WORD wHeight;
  WORD wItemCount;

  WORD* items()
  {
    return (WORD*)(this+1);
  }
};

BOOL CToolBarEx::LoadToolBar(UINT nIDResource)
{
  return LoadToolBar(MAKEINTRESOURCE(nIDResource));
}

BOOL CToolBarEx::LoadToolBar(LPCTSTR lpszResourceName)
{
  ASSERT_VALID(this);
  ASSERT(lpszResourceName != NULL);

  HINSTANCE hInst = AfxFindResourceHandle(lpszResourceName,RT_TOOLBAR);
  HRSRC hRsrc = ::FindResource(hInst,lpszResourceName,RT_TOOLBAR);
  if (hRsrc == NULL)
  {
    hInst = NULL;
    hRsrc = ::FindResource(hInst,lpszResourceName,RT_TOOLBAR);
  }
  if (hRsrc == NULL)
    return FALSE;

  HGLOBAL hGlobal = LoadResource(hInst,hRsrc);
  if (hGlobal == NULL)
    return FALSE;

  CToolBarData* pData = (CToolBarData*)LockResource(hGlobal);
  if (pData == NULL)
    return FALSE;
  ASSERT(pData->wVersion == 1);

  UINT* pItems = new UINT[pData->wItemCount];
  for (int i = 0; i < pData->wItemCount; i++)
    pItems[i] = pData->items()[i];
  BOOL bResult = SetButtons(pItems,pData->wItemCount);
  delete[] pItems;

  if (bResult)
  {
    CSize sizeImage(pData->wWidth,pData->wHeight);
    CSize sizeButton(pData->wWidth + 7,pData->wHeight + 7);
    SetSizes(sizeButton,sizeImage);

    bResult = LoadBitmap(lpszResourceName);
  }

  UnlockResource(hGlobal);
  FreeResource(hGlobal);
  return bResult;
}

BOOL CToolBarEx::LoadBitmap(LPCTSTR lpszResourceName)
{
  ASSERT_VALID(this);
  ASSERT(lpszResourceName != NULL);

  HINSTANCE hInstImageWell = AfxFindResourceHandle(lpszResourceName,RT_BITMAP);
  HRSRC hRsrcImageWell = ::FindResource(hInstImageWell,lpszResourceName,RT_BITMAP);
  if (hRsrcImageWell == NULL)
  {
    hInstImageWell = NULL;
    hRsrcImageWell = ::FindResource(hInstImageWell,lpszResourceName,RT_BITMAP);
  }
  if (hRsrcImageWell == NULL)
    return FALSE;

  HBITMAP hbmImageWell;
  hbmImageWell = AfxLoadSysColorBitmap(hInstImageWell,hRsrcImageWell);

  if (!AddReplaceBitmap(hbmImageWell))
    return FALSE;

  if (m_bitmap.GetSafeHandle() != 0)
    m_bitmap.DeleteObject();
  m_bitmap.Attach(::LoadBitmap((hInstImageWell != 0) ?
    hInstImageWell : ::GetModuleHandle(NULL),lpszResourceName));

  m_hInstImageWell = hInstImageWell;
  m_hRsrcImageWell = hRsrcImageWell;
  return TRUE;
}

BOOL CToolBarEx::SetBitmap(HBITMAP hbmImageWell)
{
  if (CToolBar::SetBitmap(hbmImageWell))
  {
    if (m_bitmap.GetSafeHandle() != 0)
      m_bitmap.DeleteObject();
    m_bitmap.Attach(hbmImageWell);
    return TRUE;
  }
  return FALSE;
}

CBitmap& CToolBarEx::GetBitmap(void)
{
  return m_bitmap;
}

/////////////////////////////////////////////////////////////////////////////
// CWinGlkViewWnd window, derived from the base CWnd class
/////////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CWinGlkViewWnd, CWnd)
  //{{AFX_MSG_MAP(CWinGlkViewWnd)
  ON_WM_SIZE()
  ON_WM_PAINT()
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CWinGlkViewWnd::OnSize(UINT nType, int cx, int cy) 
{
  CWnd::OnSize(nType,cx,cy);
  SizeWindows();
  Invalidate();
}

void CWinGlkViewWnd::OnPaint() 
{
  // Must always be present here so that ::BeginPaint() and
  // ::EndPaint() get called in the constructor and destructor
  CPaintDC dc(this);

  if (CWinGlkWnd::GetMainWindow() == NULL)
  {
    CRect Client;
    GetClientRect(Client);
    dc.FillSolidRect(Client,::GetSysColor(COLOR_WINDOW));
  }
}

void CWinGlkViewWnd::SizeWindows(void)
{
  if (CWinGlkWnd::GetMainWindow())
  {
    CRect ClientRect;
    GetClientRect(ClientRect);

    CWinGlkWnd::GetMainWindow()->SizeWindow(&ClientRect);
    ((CGlkApp*)AfxGetApp())->AddEvent(evtype_Arrange,0,0,0);
  }  
}

/////////////////////////////////////////////////////////////////////////////
// CWinGlkMainWnd frame window, derived from the menu bar frame class
/////////////////////////////////////////////////////////////////////////////

static glsi32 ColourToGlk(COLORREF Colour)
{
  CGlkApp* pApp = (CGlkApp*)AfxGetApp();
  int iColour = 0;

  if (Colour == ::GetSysColor(COLOR_WINDOWTEXT))
    iColour = 0xFFFFFFFF;
  else if (Colour == ::GetSysColor(COLOR_WINDOW))
    iColour = 0xFFFFFFFE;
  else
  {
    int r = GetRValue(Colour);
    int g = GetGValue(Colour);
    int b = GetBValue(Colour);

    iColour = (r<<16) | (g<<8) | b;
  }
  return iColour;
}

static COLORREF GlkToColour(glsi32 iColour)
{
  COLORREF Colour;
  switch (iColour)
  {
  case 0xFFFFFFFF:
    Colour = ::GetSysColor(COLOR_WINDOWTEXT);
    break;
  case 0xFFFFFFFE:
    Colour = ::GetSysColor(COLOR_WINDOW);
    break;
  default:
    {
      BYTE r = (BYTE)((iColour & 0x00FF0000) >> 16);
      BYTE g = (BYTE)((iColour & 0x0000FF00) >> 8);
      BYTE b = (BYTE)((iColour & 0x000000FF));
      Colour = RGB(r,g,b);
    }
    break;
  }
  return Colour;
}

static UINT Indicators[] =
{
  ID_SEPARATOR,
  ID_INDICATOR_CAPS,
  ID_INDICATOR_NUM,
};

CWinGlkMainWnd::CWinGlkMainWnd() : m_CodePage(CP_ACP)
{
  m_menuBar.SetUseF10(false);
}

CWinGlkMainWnd::~CWinGlkMainWnd()
{
}

BEGIN_MESSAGE_MAP(CWinGlkMainWnd, MenuBarFrameWnd)
  //{{AFX_MSG_MAP(CWinGlkMainWnd)
  ON_WM_CHAR()
  ON_WM_KEYDOWN()
  ON_WM_SYSKEYDOWN()
  ON_WM_DESTROY()
  ON_WM_SYSCOMMAND()
  ON_WM_TIMER()
  ON_WM_GETMINMAXINFO()
  ON_COMMAND(IDM_SYS_SCROLLBACK, OnScrollback)
  ON_UPDATE_COMMAND_UI(IDM_SYS_SCROLLBACK, OnUpdateScrollback)
  ON_COMMAND(IDM_FONT_PROPORTIONAL, OnFontProportional)
  ON_COMMAND(IDM_FONT_FIXED, OnFontFixed)
  ON_COMMAND(IDM_SYS_OPTIONS, OnOptions)
  ON_COMMAND(IDM_SYS_HELP, OnHelpFinder)
  ON_COMMAND(IDM_SYS_ABOUT, OnAbout)
  ON_COMMAND(IDM_SYS_ABOUT_GAME, OnAboutGame)
  ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
  ON_COMMAND(ID_FULLSCREEN, OnFullscreen)
  //}}AFX_MSG_MAP
  ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW,0,0xFFFF,OnToolTipText)
  ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA,0,0xFFFF,OnToolTipText)
  ON_MESSAGE(WM_SETMESSAGESTRING, OnSetMessageString)
  ON_MESSAGE(WM_INPUTLANGCHANGE, OnInputLangChange)
END_MESSAGE_MAP()

bool CWinGlkMainWnd::Create(bool bFrame)
{
  CGlkApp* pApp = (CGlkApp*)AfxGetApp();
  CRect rInner(pApp->GetInnerRect());
  CRect rPlace(pApp->GetWindowRect());
  if (rPlace.Width() == 0)
    rPlace = GetDefaultSize();

  // Get the title for the frame
  CString strTitle = pApp->GetGameInfo().title;
  if (strTitle.GetLength() > 0)
    strTitle += " - ";
  strTitle += pApp->GetAppTitle();

  // Create the frame
  DWORD dwStyle = bFrame ? WS_OVERLAPPEDWINDOW : WS_POPUP;
  if (CreateEx(0,AfxRegisterWndClass(0),strTitle,dwStyle,rPlace,NULL,0,NULL) == FALSE)
    return FALSE;

  // Set the mask for the frame, if any
  int iMaskID = pApp->GetMaskID();
  if ((iMaskID != -1) && (bFrame == false))
  {
    CWinGlkGraphic* pGraphic = pApp->LoadGraphic(iMaskID,TRUE,FALSE);
    if (pGraphic)
    {
      SetWindowMask(pGraphic);
      delete pGraphic;
    }
  }
  SetWindowRgn(m_Mask,FALSE);

  CRect InitRect;
  GetClientRect(InitRect);

  DWORD dwExStyle = WS_EX_CLIENTEDGE;
  if (pApp->GetWindowBorders() || (bFrame == false))
    dwExStyle = 0;

  // Create the view, which contains all the Glk windows
  if (m_View.CreateEx(dwExStyle,
    AfxRegisterWndClass(0,pApp->LoadStandardCursor(IDC_ARROW)),
    NULL,WS_CHILD|WS_VISIBLE,InitRect,this,AFX_IDW_PANE_FIRST,NULL) == FALSE)
  {
    return FALSE;
  }

  // Set up the system menu
  CString strMenuItem;
  m_FontMenu.LoadMenu(IDR_FONTS);
  CMenu* pSysMenu = GetSystemMenu(FALSE);
  if (pSysMenu)
  {
    int SysMenuPos = 6;

    strMenuItem.LoadString(IDS_MENU_SCROLLBACK);
    pSysMenu->InsertMenu(SysMenuPos++,MF_BYPOSITION|MF_STRING,IDM_SYS_SCROLLBACK,
      strMenuItem);
    strMenuItem.LoadString(IDS_MENU_FONTS);
    pSysMenu->InsertMenu(SysMenuPos++,MF_BYPOSITION|MF_STRING|MF_POPUP,
      (UINT)m_FontMenu.GetSafeHmenu(),strMenuItem);
    strMenuItem.LoadString(IDS_MENU_OPTIONS);
    pSysMenu->InsertMenu(SysMenuPos++,MF_BYPOSITION|MF_STRING,IDM_SYS_OPTIONS,
      strMenuItem);

    if (pApp->HasHelpFile())
    {
      strMenuItem.LoadString(IDS_MENU_HELP);
      pSysMenu->InsertMenu(SysMenuPos++,MF_BYPOSITION|MF_STRING,IDM_SYS_HELP,
        strMenuItem);
    }

    if (pApp->GetGameInfo().ifid.IsEmpty() == FALSE)
    {
      strMenuItem.LoadString(IDS_MENU_ABOUT_GAME);
      pSysMenu->InsertMenu(SysMenuPos++,MF_BYPOSITION|MF_STRING,IDM_SYS_ABOUT_GAME,
        strMenuItem);
    }

    strMenuItem.LoadString(IDS_MENU_ABOUT);
    pApp->AddMenuName(strMenuItem);
    pSysMenu->InsertMenu(SysMenuPos++,MF_BYPOSITION|MF_STRING,IDM_SYS_ABOUT,
      strMenuItem);
    pSysMenu->InsertMenu(SysMenuPos++,MF_BYPOSITION|MF_SEPARATOR);
  }

  // Set up the main menu
  CMenu Menus;
  UINT MenuID = pApp->GetUserGuiID();
  if (MenuID != 0)
    Menus.Attach(::LoadMenu(::GetModuleHandle(NULL),MAKEINTRESOURCE(MenuID)));

  // If no menu has been loaded, create a blank menu bar
  if (Menus.GetSafeHmenu() == 0)
    Menus.CreateMenu();

  CMenu GlkMenu, GlkFontMenu;
  GlkMenu.CreateMenu();
  GlkFontMenu.CreateMenu();

  strMenuItem.LoadString(IDS_MENU_SCROLLBACK);
  GlkMenu.AppendMenu(MF_STRING,IDM_SYS_SCROLLBACK,strMenuItem);

  strMenuItem.LoadString(IDS_MENU_PROPFONT);
  GlkFontMenu.AppendMenu(MF_STRING,IDM_FONT_PROPORTIONAL,strMenuItem);
  strMenuItem.LoadString(IDS_MENU_FIXEDFONT);
  GlkFontMenu.AppendMenu(MF_STRING,IDM_FONT_FIXED,strMenuItem);
  strMenuItem.LoadString(IDS_MENU_FONTS);
  GlkMenu.AppendMenu(MF_STRING|MF_POPUP,(UINT_PTR)GlkFontMenu.Detach(),strMenuItem);

  strMenuItem.LoadString(IDS_MENU_OPTIONS);
  GlkMenu.AppendMenu(MF_STRING,IDM_SYS_OPTIONS,strMenuItem);

  if (pApp->HasHelpFile())
  {
    strMenuItem.LoadString(IDS_MENU_HELP);
    GlkMenu.AppendMenu(MF_STRING,IDM_SYS_HELP,strMenuItem);
  }

  if (pApp->GetGameInfo().ifid.IsEmpty() == FALSE)
  {
    strMenuItem.LoadString(IDS_MENU_ABOUT_GAME);
    GlkMenu.AppendMenu(MF_STRING,IDM_SYS_ABOUT_GAME,strMenuItem);
  }

  strMenuItem.LoadString(IDS_MENU_ABOUT);
  pApp->AddMenuName(strMenuItem);
  GlkMenu.AppendMenu(MF_STRING,IDM_SYS_ABOUT,strMenuItem);
  strMenuItem.LoadString(IDS_MENU_EXIT);
  GlkMenu.AppendMenu(MF_SEPARATOR,0,(LPCSTR)NULL);
  GlkMenu.AppendMenu(MF_STRING,ID_APP_EXIT,strMenuItem);

  Menus.AppendMenu(MF_STRING|MF_POPUP,(UINT_PTR)GlkMenu.Detach(),pApp->GetMenuName());

  // Set up the status bar
  if ((m_StatusBar.Create(this,WS_CHILD|CBRS_BOTTOM) == FALSE) ||
    (m_StatusBar.SetIndicators(Indicators,sizeof(Indicators)/sizeof(UINT)) == FALSE))
  {
    return FALSE;
  }

  // Load the user toolbar
  DWORD BarStyle = WS_CHILD|WS_VISIBLE|CBRS_ALIGN_TOP|CBRS_TOOLTIPS|CBRS_FLYBY;
  UINT ToolbarID = pApp->GetUserGuiID();
  if (ToolbarID != 0)
  {
    if (m_UserToolBar.CreateEx(this,TBSTYLE_FLAT|TBSTYLE_TRANSPARENT,BarStyle))
    {
      if (m_UserToolBar.LoadToolBar(ToolbarID) == FALSE)
        m_UserToolBar.DestroyWindow();
    }
  }

  // Load the standard Glk toolbar
  if (m_GlkToolBar.CreateEx(this,TBSTYLE_FLAT|TBSTYLE_TRANSPARENT,BarStyle) == FALSE)
    return FALSE;
  if (m_GlkToolBar.LoadToolBar(IDR_GLK) == FALSE)
    return FALSE;
  if (IsHighColour())
  {
    CBitmap bitmap;
    bitmap.Attach(::LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_TOOLBAR32)));
    if (m_GlkToolBar.SetBitmap((HBITMAP)bitmap.Detach()) == FALSE)
      return FALSE;
  }

  // Hide the help button, if help is not available
  if (pApp->HasHelpFile() == false)
    m_GlkToolBar.GetToolBarCtrl().SetState(IDM_SYS_HELP,TBSTATE_HIDDEN);

  // Create the menu bar and attach the menus to it, or fall back to ordinary
  // Windows menus if the menu bar was not created
  if (CreateMenuBar((UINT)-1,&Menus) == FALSE)
    return FALSE;
  if (m_menuBar.GetSafeHwnd() == 0)
  {
    SetMenu(&Menus);
    Menus.Detach();
  }

  // Add the tool bars
  DWORD addStyle = RBBS_NOGRIPPER|RBBS_BREAK;
  if (m_UserToolBar.GetSafeHwnd())
  {
    if (m_coolBar.AddBar(&m_UserToolBar,NULL,NULL,addStyle) == FALSE)
      return FALSE;
    addStyle = RBBS_NOGRIPPER;
  }
  if (m_coolBar.AddBar(&m_GlkToolBar,NULL,NULL,addStyle) == FALSE)
    return FALSE;
  if (m_UserToolBar.GetSafeHwnd() != 0)
    m_coolBar.GetReBarCtrl().MinimizeBand((m_menuBar.GetSafeHwnd() != 0) ? 1 : 0);

  // Add the bitmaps from the toolbars to the menus
  if (m_menuBar.GetSafeHwnd() != 0)
  {
    if (m_UserToolBar.GetSafeHwnd() != 0)
      m_menuBar.LoadBitmaps(m_UserToolBar.GetBitmap(),m_UserToolBar.GetToolBarCtrl(),CSize(16,15),false);
    m_menuBar.LoadBitmaps(m_GlkToolBar.GetBitmap(),m_GlkToolBar.GetToolBarCtrl(),CSize(16,15),IsHighColour());
    m_menuBar.Update();
  }

  // Load the icon
  SetIcon(pApp->GetIcon(),TRUE);

  // Load the accelerators
  LoadAccelTable(MAKEINTRESOURCE(IDR_GLK));

  // Enable or disable GUI elements
  SetGUI(pApp->GetEnableGUI());

  // If the inner size of the window is set, resize
  if (rInner.Width() > 0)
  {
    CRect InnerNow;
    m_View.GetClientRect(InnerNow);

    // Get the style for a test window
    DWORD dwExStyle = 0;
    if (((CGlkApp*)AfxGetApp())->GetWindowBorders())
      dwExStyle = WS_EX_CLIENTEDGE;

    // Create, measure and destroy the test window
    CWnd TestWnd;
    TestWnd.CreateEx(dwExStyle,AfxRegisterWndClass(0,NULL),NULL,
      WS_CHILD,InnerNow,&m_View,0,NULL);
    TestWnd.GetClientRect(InnerNow);
    TestWnd.DestroyWindow();

    rPlace.right += (rInner.Width() - InnerNow.Width());
    rPlace.bottom += (rInner.Height() - InnerNow.Height());
    MoveWindow(rPlace,FALSE);
  }

  // Move the frame window, if necessary
  if (pApp->GetStartFullScreen())
  {
    CRect r;
    m_View.GetClientRect(r);
    m_View.ClientToScreen(r);
    rPlace.OffsetRect(-r.left,-r.top);
    MoveWindow(rPlace,FALSE);

    m_View.GetWindowRect(r);
    MoveWindow(rPlace,FALSE);
  }
  else if ((pApp->GetWindowRect().Width() == 0) || (rInner.Width() > 0) || (bFrame == false))
    CenterWindow();

  // Start a regular 1/2 second pulse timer
  SetTimer(PulseTimer,500,NULL);
  return TRUE;
}

BOOL CWinGlkMainWnd::PreCreateWindow(CREATESTRUCT& cs) 
{
  BOOL bPreCreate = MenuBarFrameWnd::PreCreateWindow(cs);
  cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
  return bPreCreate;
}

void CWinGlkMainWnd::OnDestroy() 
{
  KillTimer(PulseTimer);
  KillTimer(GlkTimer);

  WINDOWPLACEMENT Place;
  GetWindowPlacement(&Place);

  CGlkApp* pApp = (CGlkApp*)AfxGetApp();
  pApp->GetWindowRect() = Place.rcNormalPosition;
  pApp->GetWindowState() = Place.showCmd;

  MenuBarFrameWnd::OnDestroy();
}

BOOL CWinGlkMainWnd::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
  CMap<CWinGlkWnd*,CWinGlkWnd*,int,int>& WindowMap = CWinGlkWnd::GetWindowMap();
  CWinGlkWnd* pWnd = NULL;
  int i;

  POSITION MapPos = WindowMap.GetStartPosition();
  while (MapPos)
  {
    WindowMap.GetNextAssoc(MapPos,pWnd,i);
    if (pWnd->OnCmdMsg(nID,nCode,pExtra,pHandlerInfo))
      return TRUE;
  }

  BOOL bCmdProcessed = MenuBarFrameWnd::OnCmdMsg(nID,nCode,pExtra,pHandlerInfo);
  if (bCmdProcessed == FALSE)
  {
    // Check for commands from the user menu and toolbar
    switch (nCode)
    {
    case CN_COMMAND:
      // Ignore standard MFC identifiers
      if (nID < 0xE000)
      {
        // Add an input event
        ((CGlkApp*)AfxGetApp())->AddEvent(winglk_evtype_GuiInput,0,nID,0);
        bCmdProcessed = TRUE;
      }
      break;
    case CN_UPDATE_COMMAND_UI:
      {
        CCmdUI* pCmdUI = (CCmdUI*)pExtra;
        if (pCmdUI != NULL)
        {
          if (pCmdUI->m_pOther != NULL)
          {
            if (pCmdUI->m_pOther->IsKindOf(RUNTIME_CLASS(CToolBar)))
            {
              // User toolbar buttons are always enabled
              pCmdUI->Enable();
              bCmdProcessed = TRUE;
            }
          }
          else if (pCmdUI->m_pMenu != NULL)
          {
            // User menu items are always enabled
            pCmdUI->Enable();
            bCmdProcessed = TRUE;
          }
        }
      }
      break;
    }
  }
  return bCmdProcessed;
}

void CWinGlkMainWnd::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
  if (CWinGlkWnd::GetExiting() && (CheckMorePending(false) == false))
  {
    ::PostQuitMessage(0);
    return;
  }
  MenuBarFrameWnd::OnChar(nChar,nRepCnt,nFlags);

  CWinGlkWnd* pActiveWnd = CWinGlkWnd::GetActiveWindow();
  if (pActiveWnd)
  {
    // Convert to Unicode
    char c = (char)(nChar & 0xFF);
    unsigned short unicode;
    if (::MultiByteToWideChar(m_CodePage,MB_PRECOMPOSED,&c,1,(LPWSTR)&unicode,1) > 0)
    {
      switch (unicode)
      {
      case L'\b':
      case L'\r':
        if (CheckMorePending(true) == false)
          pActiveWnd->InputChar(unicode);
        break;
      default:
        if ((unicode >= 32 && unicode <= 126) || (unicode >= 160))
        {
          if (CheckMorePending(true) == false)
            pActiveWnd->InputChar(unicode);
        }
        break;
      }
    }
  }
}

LRESULT CWinGlkMainWnd::OnInputLangChange(WPARAM wParam, LPARAM lParam)
{
  CHARSETINFO CharSet;
  if (::TranslateCharsetInfo((DWORD*)wParam,&CharSet,TCI_SRCCHARSET))
    m_CodePage = CharSet.ciACP;
  return DefWindowProc(WM_INPUTLANGCHANGE,wParam,lParam);
}

void CWinGlkMainWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
  if (CWinGlkWnd::GetExiting() && (CheckMorePending(false) == false))
  {
    ::PostQuitMessage(0);
    return;
  }
  MenuBarFrameWnd::OnKeyDown(nChar,nRepCnt,nFlags);

  CWinGlkWnd* pActiveWnd = CWinGlkWnd::GetActiveWindow();
  if (pActiveWnd)
  {
    switch (nChar)
    {
    case VK_TAB:
      {
        CWnd* pNextWnd = pActiveWnd;
        bool bNext = false;
        do
        {
          if (::GetKeyState(VK_SHIFT) & 0x8000)
          {
            pNextWnd = pNextWnd->GetWindow(GW_HWNDPREV);
            if (pNextWnd == NULL)
              pNextWnd = pActiveWnd->GetWindow(GW_HWNDLAST);
          }
          else
          {
            pNextWnd = pNextWnd->GetWindow(GW_HWNDNEXT);
            if (pNextWnd == NULL)
              pNextWnd = pActiveWnd->GetWindow(GW_HWNDFIRST);
          }

          if (pNextWnd == pActiveWnd)
            bNext = true;

          if (pNextWnd)
          {
            if (pNextWnd->IsKindOf(RUNTIME_CLASS(CWinGlkWnd)))
            {
              if (((CWinGlkWnd*)pNextWnd)->InputPending() == true)
                bNext = true;
            }
          }
          else
            bNext = true;
        }
        while (bNext == false);

        if (pNextWnd)
          ((CWinGlkWnd*)pNextWnd)->SetActiveWindow();
      }
      break;
    case VK_PAUSE:   // Pause
      CheckMorePending(true);
      break;
    case VK_CANCEL:  // Break (Ctrl+Pause)
      TextToSpeech::GetSpeechEngine().Destroy();
      break;
    case VK_LEFT:    // Cursor left
    case VK_RIGHT:   // Cursor right
    case VK_UP:      // Cursor up
    case VK_DOWN:    // Cursor down
    case VK_HOME:    // Home
    case VK_END:     // End
    case VK_DELETE:  // Delete
    case VK_ESCAPE:  // Escape
    case VK_PRIOR:   // Page up
    case VK_NEXT:    // Page down
    case VK_F1:      // Function keys...
    case VK_F2:
    case VK_F3:
    case VK_F4:
    case VK_F5:
    case VK_F6:
    case VK_F7:
    case VK_F8:
    case VK_F9:
    case VK_F10:
    case VK_F11:
    case VK_F12:
      if (CheckMorePending(true) == false)
        pActiveWnd->InputChar(nChar + 0x10000);
      break;
    }
  }
}

// F10 gets passed to the application via WM_SYSKEYDOWN as it is
// the legacy window menu key (like Alt).
void CWinGlkMainWnd::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
  if (CWinGlkWnd::GetExiting() && (CheckMorePending(false) == false))
  {
    ::PostQuitMessage(0);
    return;
  }

  if (nChar == VK_F10)
  {
    CWinGlkWnd* pActiveWnd = CWinGlkWnd::GetActiveWindow();
    if (pActiveWnd)
    {
      if (CheckMorePending(true) == false)
        pActiveWnd->InputChar(nChar + 0x10000);
    }
  }
  else
    MenuBarFrameWnd::OnSysKeyDown(nChar,nRepCnt,nFlags);
}

void CWinGlkMainWnd::OnSysCommand(UINT nID, LPARAM lParam) 
{
  switch (nID&0xFFF0)
  {
  case IDM_SYS_SCROLLBACK:
    OnScrollback();
    break;
  case IDM_SYS_HELP:
    OnHelpFinder();
    break;
  case IDM_SYS_ABOUT:
    OnAbout();
    break;
  case IDM_SYS_ABOUT_GAME:
    OnAboutGame();
    break;
  case IDM_FONT_PROPORTIONAL:
    ChangeFont(false);
    break;
  case IDM_FONT_FIXED:
    ChangeFont(true);
    break;
  case IDM_SYS_OPTIONS:
    OnOptions();
    break;
  }
  MenuBarFrameWnd::OnSysCommand(nID, lParam);
}

void CWinGlkMainWnd::OnTimer(UINT nIDEvent) 
{
  MenuBarFrameWnd::OnTimer(nIDEvent);

  switch (nIDEvent)
  {
  case PulseTimer:
    {
      for (CWinGlkSndChannel* pSnd = CWinGlkSndChannel::IterateChannels(NULL,NULL); pSnd; pSnd = CWinGlkSndChannel::IterateChannels(pSnd,NULL))
        pSnd->TimerPulse();
    }
    break;
  case GlkTimer:
    if (CWinGlkWnd::GetMainWindow())
      ((CGlkApp*)AfxGetApp())->AddEvent(evtype_Timer,0,0,0);
    break;
  }
}

BOOL CWinGlkMainWnd::OnToolTipText(UINT, NMHDR* pNMHDR, LRESULT* pResult)
{
  TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*)pNMHDR;
  TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*)pNMHDR;
  TCHAR szFullText[256];
  CString strTipText;
  UINT nID = pNMHDR->idFrom;
  if (pNMHDR->code == TTN_NEEDTEXTA && (pTTTA->uFlags & TTF_IDISHWND) ||
      pNMHDR->code == TTN_NEEDTEXTW && (pTTTW->uFlags & TTF_IDISHWND))
  {
    nID = (UINT)(WORD)::GetDlgCtrlID((HWND)nID);
  }

  if (nID != 0)
  {
    if (AfxLoadString(nID,szFullText) == 0)
    {
      LPCTSTR lpszName = MAKEINTRESOURCE((nID>>4)+1);
      if (::FindResource(NULL,lpszName,RT_STRING) != NULL)
        ::LoadString(NULL,nID,szFullText,255);
    }
    AfxExtractSubString(strTipText,szFullText,1,'\n');
  }

  if (pNMHDR->code == TTN_NEEDTEXTA)
  {
    lstrcpyn(pTTTA->szText,strTipText,
      sizeof(pTTTA->szText)/sizeof(pTTTA->szText[0]));
  }
  else
  {
    ATL::_mbstowcsz(pTTTW->szText,strTipText,
      sizeof(pTTTW->szText)/sizeof(pTTTW->szText[0]));
  }
  *pResult = 0;

  ::SetWindowPos(pNMHDR->hwndFrom,HWND_TOP,0,0,0,0,
    SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOMOVE|SWP_NOOWNERZORDER);
  return TRUE;
}

LRESULT CWinGlkMainWnd::OnSetMessageString(WPARAM wParam, LPARAM lParam)
{
  // Check for idle message
  if ((wParam == AFX_IDS_IDLEMESSAGE) && (lParam == 0))
  {
    const char* title = ((CGlkApp*)AfxGetApp())->GetAppTitle();
    wParam = 0;
    lParam = (LPARAM)title;
  }
  return MenuBarFrameWnd::OnSetMessageString(wParam,lParam);
}

void CWinGlkMainWnd::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
  // Make the size a bit bigger than the display so full screen mode works
  CRect rect = ((CGlkApp*)AfxGetApp())->GetScreenSize(true);
  rect.InflateRect(64,128);
  CPoint size(rect.Size()); 

  lpMMI->ptMaxSize = size;
  lpMMI->ptMaxTrackSize = size;
}

/////////////////////////////////////////////////////////////////////////////
// Command handlers
/////////////////////////////////////////////////////////////////////////////

void CWinGlkMainWnd::OnScrollback() 
{
  CWinGlkWnd* pActiveWnd = CWinGlkWnd::GetActiveWindow();
  if (pActiveWnd)
    pActiveWnd->Scrollback();
}

void CWinGlkMainWnd::OnUpdateScrollback(CCmdUI* pCmdUI) 
{
  BOOL bEnable = FALSE;
  CWinGlkWnd* pWnd = CWinGlkWnd::GetActiveWindow();
  if (pWnd)
  {
    if (pWnd->IsKindOf(RUNTIME_CLASS(CWinGlkWndTextBuffer)))
      bEnable = TRUE;
  }
  pCmdUI->Enable(bEnable);
}

void CWinGlkMainWnd::OnFontProportional() 
{
  ChangeFont(false);
}

void CWinGlkMainWnd::OnFontFixed() 
{
  ChangeFont(true);
}

void CWinGlkMainWnd::OnOptions() 
{
  CGlkApp* pApp = (CGlkApp*)AfxGetApp();
  CWinGlkPropertySheet OptionsDlg(IDS_OPTIONS,this);
  CWinGlkGeneralPage GeneralPage;
  CWinGlkStylePage StylePage;
  CWinGlkSpeechPage SpeechPage;

  OptionsDlg.m_psh.dwFlags |= PSH_NOAPPLYNOW;
  OptionsDlg.AddPage(&GeneralPage);
  OptionsDlg.AddPage(&StylePage);
  if (TextToSpeech::GetSpeechEngine().IsAvailable())
    OptionsDlg.AddPage(&SpeechPage);

  GeneralPage.m_bBorders = pApp->GetWindowBorders();
  GeneralPage.m_bGUI = pApp->GetEnableGUI();
  GeneralPage.m_bStyleHints = pApp->GetStyleHints();

  GeneralPage.SetTextColour(GlkToColour(pApp->GetTextColour()));
  GeneralPage.SetBackColour(GlkToColour(pApp->GetBackColour()));
  GeneralPage.SetLinkColour(pApp->GetLinkColour());

  GeneralPage.m_iFiction = pApp->Get_iFiction();

  StylePage.SetCurrentStyle(wintype_TextBuffer,style_Normal);

  SpeechPage.m_bSpeak = pApp->GetCanSpeak();
  SpeechPage.m_strVoice = pApp->GetSpeechVoice();
  SpeechPage.m_iRate = pApp->GetSpeechRate();

  CWinGlkWnd* pActiveWnd = CWinGlkWnd::GetActiveWindow();
  if (OptionsDlg.DoModal() == IDOK)
  {
    pApp->SetSaveOptions(true);

    bool bBorderChanged = pApp->SetWindowBorders(GeneralPage.m_bBorders ? true : false);
    bool bGUIChanged = pApp->SetEnableGUI(GeneralPage.m_bGUI ? true : false);
    pApp->SetStyleHints(GeneralPage.m_bStyleHints ? true : false);

    pApp->SetTextColour(ColourToGlk(GeneralPage.GetTextColour()));
    pApp->SetBackColour(ColourToGlk(GeneralPage.GetBackColour()));
    pApp->SetLinkColour(GeneralPage.GetLinkColour());

    pApp->Set_iFiction((CGlkApp::Show_iFiction)GeneralPage.m_iFiction);

    pApp->SetCanSpeak(SpeechPage.m_bSpeak ? true : false);
    bool bVoiceChanged = (SpeechPage.m_strVoice != pApp->GetSpeechVoice());
    bool bRateChanged = (SpeechPage.m_iRate != pApp->GetSpeechRate());
    pApp->SetSpeechVoice(SpeechPage.m_strVoice);
    pApp->SetSpeechRate(SpeechPage.m_iRate);
    if (bVoiceChanged || bRateChanged)
      TextToSpeech::GetSpeechEngine().Update(pApp->GetSpeechVoice(),pApp->GetSpeechRate());

    if (bBorderChanged || bGUIChanged)
      GetView()->SizeWindows();

    // Redraw the display
    Invalidate();
  }
  if (pActiveWnd)
    pActiveWnd->SetActiveWindow();
}

void CWinGlkMainWnd::OnAbout() 
{
  CAboutDialog AboutDlg;
  AboutDlg.DoModal();
}

void CWinGlkMainWnd::OnAboutGame() 
{
  AboutGameDialog Dialog(this);
  Dialog.DoModal();
}

void CWinGlkMainWnd::OnEditPaste()
{
  CWinGlkWnd* pActiveWnd = CWinGlkWnd::GetActiveWindow();
  if (pActiveWnd)
  {
    if (OpenClipboard())
    {
      HGLOBAL handle = ::GetClipboardData(CF_TEXT);
      if (handle)
      {
        LPTSTR text = (LPTSTR)::GlobalLock(handle); 
        if (text) 
        {
          CheckMorePending(true);

          int len = strlen(text);
          for (int i = 0; i < len; i++)
          {
            unsigned short unicode;
            if (::MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED,text+i,1,(LPWSTR)&unicode,1) > 0)
            {
              switch (unicode)
              {
              case L'\b':
              case L'\r':
                pActiveWnd->InputChar(unicode);
                break;
              default:
                if ((unicode >= 32 && unicode <= 126) || (unicode >= 160))
                  pActiveWnd->InputChar(unicode);
                break;
              }
            }
          }
          ::GlobalUnlock(handle); 
        }
      }
      CloseClipboard();
    }
  }
}

void CWinGlkMainWnd::OnFullscreen()
{
  // Get the current window size
  WINDOWPLACEMENT place;
  ::ZeroMemory(&place,sizeof(WINDOWPLACEMENT));
  place.length = sizeof(WINDOWPLACEMENT);
  GetWindowPlacement(&place);
  CRect size(place.rcNormalPosition);

  // Get the size of the display
  CGlkApp* pApp = (CGlkApp*)AfxGetApp();
  CRect screen = pApp->GetScreenSize(true);

  // Is the window already full screen?
  if ((size.Width() > screen.Width()) && (size.Height() > screen.Height()))
  {
    // Restore the normal window size
    place.showCmd = SW_SHOWNORMAL;
    if (m_NormalSize.Width() > 0)
      place.rcNormalPosition = m_NormalSize;
    else
      place.rcNormalPosition = GetDefaultSize();
    SetWindowPlacement(&place);
  }
  else
  {
    if (pApp->GetNotifyFullScreen())
    {
      // Tell the user
      if (AfxMessageBox(IDS_FULLSCREEN,MB_YESNO|MB_ICONINFORMATION) == IDNO)
        return;
      pApp->SetNotifyFullScreen(false);
    }

    // Save the current window size
    m_NormalSize = size;

    // Get the current view window size
    CRect client;
    m_View.GetClientRect(&client);
    m_View.ClientToScreen(&client);

    // Calculate the window frame offsets
    GetWindowRect(&size);
    int x1 = client.left-size.left;
    int y1 = client.top-size.top;
    int x2 = size.right-client.right;
    int y2 = size.bottom-client.bottom;

    // Make the window client cover the entire display
    place.showCmd = SW_SHOWNORMAL;
    place.rcNormalPosition.left = screen.left-x1;
    place.rcNormalPosition.top = screen.top-y1;
    place.rcNormalPosition.right = screen.right+x2;
    place.rcNormalPosition.bottom = screen.bottom+y2;
    SetWindowPlacement(&place);
  }
}

void CWinGlkMainWnd::StartTimer(int iMilliSecs)
{
  KillTimer(GlkTimer);

  if (iMilliSecs > 0)
    SetTimer(GlkTimer,iMilliSecs,NULL);
}

void CWinGlkMainWnd::SetBorders(bool bBorders)
{
  ::SetWindowLong(m_View.GetSafeHwnd(),GWL_EXSTYLE,
    bBorders ? 0 : WS_EX_CLIENTEDGE);

  CWinGlkWnd* pWnd = NULL;
  do
  {
    pWnd = CWinGlkWnd::IterateWindows(pWnd,NULL);
    if (pWnd)
    {
      if (pWnd->GetSafeHwnd())
      {
        ::SetWindowLong(pWnd->GetSafeHwnd(),GWL_EXSTYLE,
          bBorders ? WS_EX_CLIENTEDGE : 0);
      }
    }
  }
  while (pWnd);

  CRect WindowRect;
  GetWindowRect(WindowRect);
  MoveWindow(CRect(0,0,0,0),FALSE);
  MoveWindow(WindowRect,TRUE);
}

void CWinGlkMainWnd::SetGUI(bool bGUI)
{
  ShowControlBar(&m_coolBar,bGUI,TRUE);
  ShowControlBar(&m_StatusBar,bGUI,TRUE);
  RecalcLayout(FALSE);
}

void CWinGlkMainWnd::EnableScrollback(bool bEnable)
{
  CMenu* pSysMenu = GetSystemMenu(FALSE);
  if (pSysMenu)
  {
    if (bEnable)
      pSysMenu->EnableMenuItem(IDM_SYS_SCROLLBACK,MF_BYCOMMAND|MF_ENABLED);
    else
      pSysMenu->EnableMenuItem(IDM_SYS_SCROLLBACK,MF_BYCOMMAND|MF_GRAYED);
  }
}

void CWinGlkMainWnd::ChangeFont(bool bFixed)
{
  CGlkApp* pApp = (CGlkApp*)AfxGetApp();
  CFontDialog FontDlg(
    bFixed ? pApp->GetFixedFont() : pApp->GetPropFont(),
    CF_SCREENFONTS|CF_NOSCRIPTSEL|CF_NOVERTFONTS|CF_SCALABLEONLY|(bFixed ? CF_FIXEDPITCHONLY : 0));
  if (FontDlg.DoModal() == IDOK)
  {
    GetTextOut().Reset();
    GetView()->SizeWindows();
    Invalidate();
  }
  if (CWinGlkWnd::GetActiveWindow())
    CWinGlkWnd::GetActiveWindow()->SetActiveWindow();
}

void CWinGlkMainWnd::GetMessageString(UINT nID, CString& rMessage) const
{
  LPTSTR lpsz = rMessage.GetBuffer(255);
  if (AfxLoadString(nID,lpsz) != 0)
  {
    lpsz = _tcschr(lpsz,'\n');
    if (lpsz != NULL)
      *lpsz = '\0';
  }
  else
  {
    LPCTSTR lpszName = MAKEINTRESOURCE((nID>>4)+1);
    if (::FindResource(NULL,lpszName,RT_STRING) != NULL)
    {
      if (::LoadString(NULL,nID,lpsz,255) != 0)
      {
        lpsz = _tcschr(lpsz,'\n');
        if (lpsz != NULL)
          *lpsz = '\0';
      }
    }
  }
  rMessage.ReleaseBuffer();
}

void CWinGlkMainWnd::SetWindowMask(CWinGlkGraphic* pGraphic)
{
  if (m_Mask.GetSafeHandle() == NULL)
  {
    CArray<RECT,RECT&> Regions;
    DWORD dwTransparent = 0x00FFFFFF;
    DWORD dwColour = 0;

    DWORD* ppvBits = (DWORD*)pGraphic->m_pPixels;
    int iHeight = abs(pGraphic->m_pHeader->biHeight);
    int iWidth = pGraphic->m_pHeader->biWidth;

    for (int y = 0; y < iHeight; y++)
    {
      int iLeft = -1;
      for (int x = 0; x < iWidth+1; x++)
      {
        // Get the pixel's colour
        if (x < iWidth)
          dwColour = CDibSection::GetPixel(ppvBits,iWidth,x,y);
        else
          dwColour = dwTransparent;

        if (iLeft >= 0)
        {
          if (dwColour == dwTransparent)
          {
            // Found the right hand edge of a rectangle in the region
            CRect Rect(iLeft,y,x,y+1);
            Regions.Add(Rect);
            iLeft = -1;
          }
        }
        else
        {
          if (dwColour != dwTransparent)
          {
            // Found the left hand edge of a rectangle in the region
            iLeft = x;
          }
        }
      }
    }

    if (Regions.GetSize() > 0)
    {
      // Create a RGNDATA structure
      int iDataSize = sizeof(RGNDATAHEADER)+(sizeof(RECT)*Regions.GetSize());
      RGNDATA* pRegionData = (RGNDATA*)new BYTE[iDataSize];
      ::ZeroMemory(pRegionData,iDataSize);

      // Populate the RGNDATAHEADER
      pRegionData->rdh.dwSize = sizeof(RGNDATAHEADER);
      pRegionData->rdh.iType = RDH_RECTANGLES;
      pRegionData->rdh.nCount = Regions.GetSize();
      pRegionData->rdh.nRgnSize = 0;
      pRegionData->rdh.rcBound.right = iWidth;
      pRegionData->rdh.rcBound.bottom = iHeight;

      // Copy the RECTs into the RGNDATA
      ::CopyMemory(((BYTE*)pRegionData)+sizeof(RGNDATAHEADER),
        Regions.GetData(),sizeof(RECT)*Regions.GetSize());

      // Create the region
      m_Mask.CreateFromData(NULL,iDataSize,pRegionData);
      delete[] pRegionData;
    }
  }
}

bool CWinGlkMainWnd::CheckMorePending(bool update)
{
  bool more = false;
  CMap<CWinGlkWnd*,CWinGlkWnd*,int,int>& WindowMap = CWinGlkWnd::GetWindowMap();
  CWinGlkWnd* pWnd = NULL;
  int i;

  // Update any windows waiting on a [More] prompt
  POSITION MapPos = WindowMap.GetStartPosition();
  while (MapPos)
  {
    WindowMap.GetNextAssoc(MapPos,pWnd,i);
    if (pWnd->CheckMorePending(update))
      more = true;
  }
  return more;
}

CRect CWinGlkMainWnd::GetDefaultSize(void)
{
  // Get the size of the display
  CRect screen = ((CGlkApp*)AfxGetApp())->GetScreenSize(false);
  int l = screen.left;
  int t = screen.top;
  int w = screen.Width();
  int h = screen.Height();

  const int x = 8;
  const int y = 14;
  CRect size(l+(w/x),t+(h/y),(w*(x-1))/x,(h*(y-1))/y);
  return size;
}
