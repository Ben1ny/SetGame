#pragma once


// Set_GameDlg2 dialog

class Set_GameDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(Set_GameDlg2)

public:
	Set_GameDlg2(CWnd* pParent = NULL);   // standard constructor
	virtual ~Set_GameDlg2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedOk();
};
