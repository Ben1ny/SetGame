
// Set_GameDlg.cpp: Implementierungsdatei
//
//

#include "stdafx.h"
#include "Set_Game.h"
#include "Set_GameDlg.h"
#include "afxdialogex.h"

#include "Set_Algorithmus.h"
#include "Set_Repository.h"
#include "Set_BuildUp.h"
#include "Set_GameDlg2.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
	
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSet_GameDlg-Dialogfeld



CSet_GameDlg::CSet_GameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSet_GameDlg::IDD, pParent)
{
//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSet_GameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSet_GameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CSet_GameDlg::OnBnClickedOk)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CSet_GameDlg::OnCbnDropdownCombo1)
	ON_COMMAND(ID_SPIELER_SPIELER1, &CSet_GameDlg::OnSpielerSpieler1)
	ON_COMMAND(OnSpielNeuesspiel, &CSet_GameDlg::OnOnspielneuesspiel)
	ON_COMMAND(ID_HILFE_Anleitung, &CSet_GameDlg::OnHilfeAnleitung)
	ON_COMMAND(ID_HILFE_INFO, &CSet_GameDlg::OnHilfeInfo)
	ON_BN_CLICKED(IDC_Karte0, &CSet_GameDlg::OnBnClickedKarte0)
	ON_BN_CLICKED(IDC_Karte1, &CSet_GameDlg::OnBnClickedKarte1)
	ON_BN_CLICKED(IDC_Karte2, &CSet_GameDlg::OnBnClickedKarte2)
END_MESSAGE_MAP()


// CSet_GameDlg-Meldungshandler

BOOL CSet_GameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

void CSet_GameDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CSet_GameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CSet_GameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSet_GameDlg::OnBnClickedOk()
{
	
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
	CDialogEx::OnOK();
}


void CSet_GameDlg::OnCbnDropdownCombo1()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}


void CSet_GameDlg::OnSpielerSpieler1()
{
	Set_BuildUp a(1);
	Set_GameDlg2 window2;
	window2.DoModal();
	//MessageBox(_T("a"), _T("Information"),
	//MB_ICONINFORMATION | MB_OK | MB_ABORTRETRYIGNORE);
	// TODO: Fügen Sie hier Ihren Befehlsbehandlungscode ein.

}

void CSet_GameDlg::OnOnspielneuesspiel()
{
	Set_Deck CardStack;
	array <Set_Card, 12> CardsOnTable;
	for (int i = 0; i < 12; i++)
	{
		CardsOnTable[i] = CardStack.getCardFromDeck();
	}
	Set_Algorithmus SpielBeginnt;
	if (SpielBeginnt.CheckBuildUp(CardsOnTable) == true)
	{
		SpielBeginnt.BuildtheDeck(CardsOnTable, this);
	}
	else
	{
		SpielBeginnt.BuildtheDeckThreeMore(CardStack.getCardFromDeck(), CardStack.getCardFromDeck(), CardStack.getCardFromDeck(), CardsOnTable, this);
	}
}


void CSet_GameDlg::OnHilfeAnleitung()
{
	// Aufrufen der Anleitung
	ShellExecute(NULL, _T("open"), _T("anleitung.pdf"), NULL, NULL, SW_SHOWNORMAL);
}


void CSet_GameDlg::OnHilfeInfo()
{
	// TODO: Fügen Sie hier Ihren Befehlsbehandlungscode ein.
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
	CDialogEx::OnOK();
}


void CSet_GameDlg::OnBnClickedKarte0()
{
	
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte1()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte2()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte3()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte4()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte5()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte6()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte7()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte8()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte9()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte10()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte11()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte12()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte13()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
void CSet_GameDlg::OnBnClickedKarte14()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
}
