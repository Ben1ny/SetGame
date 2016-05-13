// Set_GameDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "Set_Game.h"
#include "Set_GameDlg2.h"
#include "afxdialogex.h"

#include "Set_Algorithmus.h"
#include "Set_Repository.h"
#include "Set_BuildUp.h"
#include "Set_GameDlg.h"


// Set_GameDlg2 dialog

IMPLEMENT_DYNAMIC(Set_GameDlg2, CDialogEx)

Set_GameDlg2::Set_GameDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Set_GameDlg2::~Set_GameDlg2()
{
}

void Set_GameDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Set_GameDlg2, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &Set_GameDlg2::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &Set_GameDlg2::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT5, &Set_GameDlg2::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT4, &Set_GameDlg2::OnEnChangeEdit4)
	ON_BN_CLICKED(IDOK, &Set_GameDlg2::OnBnClickedOk)
END_MESSAGE_MAP()


// Set_GameDlg2 message handlers

void Set_GameDlg2::OnBnClickedOk()
{
	//a.getName();
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
	CDialogEx::OnOK();
}

void Set_GameDlg2::OnEnChangeEdit2()
{
	// TODO:  Falls dies ein RICHEDIT-Steuerelement ist, wird das Kontrollelement
	// diese Benachrichtigung nicht senden, es sei denn, Sie überschreiben die CDialogEx::OnInitDialog()-
	// Funktion und rufen CRichEditCtrl().SetEventMask() auf
	// mit dem ENM_CHANGE-Flag ORed in der Eingabe.

	// TODO:  Fügen Sie hier Ihren Code für die Kontrollbenachrichtigungsbehandlung ein.
}


void Set_GameDlg2::OnEnChangeEdit1()
{
	// TODO:  Falls dies ein RICHEDIT-Steuerelement ist, wird das Kontrollelement
	// diese Benachrichtigung nicht senden, es sei denn, Sie überschreiben die CDialogEx::OnInitDialog()-
	// Funktion und rufen CRichEditCtrl().SetEventMask() auf
	// mit dem ENM_CHANGE-Flag ORed in der Eingabe.

	// TODO:  Fügen Sie hier Ihren Code für die Kontrollbenachrichtigungsbehandlung ein.
}


void Set_GameDlg2::OnEnChangeEdit5()
{
	// TODO:  Falls dies ein RICHEDIT-Steuerelement ist, wird das Kontrollelement
	// diese Benachrichtigung nicht senden, es sei denn, Sie überschreiben die CDialogEx::OnInitDialog()-
	// Funktion und rufen CRichEditCtrl().SetEventMask() auf
	// mit dem ENM_CHANGE-Flag ORed in der Eingabe.

	// TODO:  Fügen Sie hier Ihren Code für die Kontrollbenachrichtigungsbehandlung ein.
}


void Set_GameDlg2::OnEnChangeEdit4()
{
	// TODO:  Falls dies ein RICHEDIT-Steuerelement ist, wird das Kontrollelement
	// diese Benachrichtigung nicht senden, es sei denn, Sie überschreiben die CDialogEx::OnInitDialog()-
	// Funktion und rufen CRichEditCtrl().SetEventMask() auf
	// mit dem ENM_CHANGE-Flag ORed in der Eingabe.

	// TODO:  Fügen Sie hier Ihren Code für die Kontrollbenachrichtigungsbehandlung ein.
}



