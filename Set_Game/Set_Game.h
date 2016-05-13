
// Set_Game.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CSet_GameApp:
// Siehe Set_Game.cpp für die Implementierung dieser Klasse
//

class CSet_GameApp : public CWinApp
{
public:
	CSet_GameApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
	afx_msg void OnOnspielneuesspiel();
};

extern CSet_GameApp theApp;