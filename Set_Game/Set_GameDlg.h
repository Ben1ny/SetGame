
// Set_GameDlg.h: Headerdatei
//

#pragma once
#include "Resource.h"
//#include <array>

using namespace std;

class Set_Algorithmus;
class Set_Deck;
class Set_Card;


// CSet_GameDlg-Dialogfeld
class CSet_GameDlg : public CDialogEx
{
// Konstruktion
public:
	CSet_GameDlg(CWnd* pParent = NULL);	// Standardkonstruktor

// Dialogfelddaten
	enum { IDD = IDD_SET_GAME_DIALOG};

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
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnSpielerSpieler1();
	afx_msg void OnOnspielneuesspiel();
	afx_msg void OnHilfeInfo();
	afx_msg void OnHilfeAnleitung();
	afx_msg void OnBnClickedKarte0();
	afx_msg void OnBnClickedKarte1();
	afx_msg void OnBnClickedKarte2();
	afx_msg void OnBnClickedKarte3();
	afx_msg void OnBnClickedKarte4();
	afx_msg void OnBnClickedKarte5();
	afx_msg void OnBnClickedKarte6();
	afx_msg void OnBnClickedKarte7();
	afx_msg void OnBnClickedKarte8();
	afx_msg void OnBnClickedKarte9();
	afx_msg void OnBnClickedKarte10();
	afx_msg void OnBnClickedKarte11();
	afx_msg void OnBnClickedKarte12();
	afx_msg void OnBnClickedKarte13();
	afx_msg void OnBnClickedKarte14();
	Set_Algorithmus *SpielBeginnt;
	Set_Deck *CardStack;
	Set_Card *p;
	CString points;
};
