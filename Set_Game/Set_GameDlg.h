
// Set_GameDlg.h: Headerdatei
//

#pragma once


// CSet_GameDlg-Dialogfeld
class CSet_GameDlg : public CDialogEx
{
// Konstruktion
public:
	CSet_GameDlg(CWnd* pParent = NULL);	// Standardkonstruktor

// Dialogfelddaten
	enum { IDD = IDD_SET_GAME_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnNeuesspiel1spieler();
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnSpielerSpieler1();
	afx_msg void OnOnspielneuesspiel();
	afx_msg void OnHilfeInfo();
	afx_msg void OnHilfeAnleitung();
};
