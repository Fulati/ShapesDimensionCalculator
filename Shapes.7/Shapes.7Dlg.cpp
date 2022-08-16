
// Shapes.7Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Shapes.7.h"
#include "Shapes.7Dlg.h"
#include "afxdialogex.h"
#include "pShapes.h"

#include <sstream>
#include <vector>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShapes7Dlg dialog



CShapes7Dlg::CShapes7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPES7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapes7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CShapes7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO2, &CShapes7Dlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDOK, &CShapes7Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CShapes7Dlg message handlers

BOOL CShapes7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//Drop Down Menu
	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO2));
	pCombo->InsertString(0, _T("Select A Shape"));
	pCombo->InsertString(1, _T("Square"));
	pCombo->InsertString(2, _T("Rectangle"));
	pCombo->InsertString(3, _T("Circle"));
	pCombo->InsertString(4, _T("Triangle"));
	pCombo->InsertString(5, _T("Cube"));
	pCombo->InsertString(6, _T("Box"));
	pCombo->InsertString(7, _T("Cylinder"));
	pCombo->InsertString(8, _T("Prism"));
	pCombo->SetCurSel(0); // or -1 for unselected

	//Thank You Picture 
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC2));
	pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture->SetBitmap(hb);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShapes7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShapes7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShapes7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShapes7Dlg::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO2));
	int n = pCombo->GetCurSel(); // 0 for first item...

	//Static Text
	CStatic* pText1 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC3));
	CStatic* pText2 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC4));
	CStatic* pText3 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC5));

	//Input Boxes
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));

	switch (n)
	{
	case 0:

		// Show all relevant controls
		pText1->ShowWindow(SW_SHOW);
		pText2->ShowWindow(SW_SHOW);
		pText3->ShowWindow(SW_SHOW);
	  // Hide all irrelevant controls
	  pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_SHOW);
		//Set Static Text
		pText1->SetWindowTextW(CString(_T("Dimension1")));
		pText2->SetWindowTextW(CString(_T("Dimension2")));
		pText3->SetWindowTextW(CString(_T("Dimension3")));
	  break;

	case 1:

		// Show all relevant controls
		pText1->ShowWindow(SW_SHOW);
		pText2->ShowWindow(SW_HIDE);
		pText3->ShowWindow(SW_HIDE);
		// Hide all irrelevant controls
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);
		//Set Static Text
		pText1->SetWindowTextW(CString(_T("Side")));
		break;

	case 2:
		// Show all relevant controls
		pText1->ShowWindow(SW_SHOW);
		pText2->ShowWindow(SW_SHOW);
		pText3->ShowWindow(SW_HIDE);
		// Hide all irrelevant controls
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_HIDE);
		pText1->SetWindowTextW(CString(_T("Length")));
		pText2->SetWindowTextW(CString(_T("Width")));
		break;

	case 3:
		// Show all relevant controls
		pText1->ShowWindow(SW_SHOW);
		pText2->ShowWindow(SW_HIDE);
		pText3->ShowWindow(SW_HIDE);
		// Hide all irrelevant controls
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);
		pText1->SetWindowTextW(CString(_T("Radius")));
		break;

	case 4:
		// Show all relevant controls
		pText1->ShowWindow(SW_SHOW);
		pText2->ShowWindow(SW_HIDE);
		pText3->ShowWindow(SW_HIDE);
		// Hide all irrelevant controls
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);
		pText1->SetWindowTextW(CString(_T("Side")));
		break;

	case 5:
		// Show all relevant controls
		pText1->ShowWindow(SW_SHOW);
		pText2->ShowWindow(SW_HIDE);
		pText3->ShowWindow(SW_HIDE);
		// Hide all irrelevant controls
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);
		pText1->SetWindowTextW(CString(_T("Side")));
		break;

	case 6:
		// Show all relevant controls
		pText1->ShowWindow(SW_SHOW);
		pText2->ShowWindow(SW_SHOW);
		pText3->ShowWindow(SW_SHOW);
		// Hide all irrelevant controls
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_SHOW);
		pText1->SetWindowTextW(CString(_T("Length")));
		pText2->SetWindowTextW(CString(_T("Width")));
		pText3->SetWindowTextW(CString(_T("Height")));
		break;

	case 7:
		// Show all relevant controls
		pText1->ShowWindow(SW_SHOW);
		pText2->ShowWindow(SW_SHOW);
		pText3->ShowWindow(SW_HIDE);
		// Hide all irrelevant controls
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_HIDE);
		pText1->SetWindowTextW(CString(_T("Radius")));
		pText2->SetWindowTextW(CString(_T("Height")));
		break;

	case 8:
		// Show all relevant controls
		pText1->ShowWindow(SW_SHOW);
		pText2->ShowWindow(SW_SHOW);
		pText3->ShowWindow(SW_HIDE);
		// Hide all irrelevant controls
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_HIDE);
		pText1->SetWindowTextW(CString(_T("Side")));
		pText2->SetWindowTextW(CString(_T("Height")));
		break;

	} // end of switch
}


void CShapes7Dlg::OnBnClickedOk()
{
	vector<string> tokens;
	tokens.push_back("");

	CString mEdit1; // a blank MFC string for use below
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2)); // reference to an Edit Control
	pEdit1->GetWindowText(mEdit1); // copy Edit Control's text into the MFC string
	string e1 = CStringA(mEdit1);
	tokens.push_back(e1);

	CString mEdit2; // a blank MFC string for use below
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3)); // reference to an Edit Control
	pEdit2->GetWindowText(mEdit2); // copy Edit Control's text into the MFC string
	string e2 = CStringA(mEdit2);
	tokens.push_back(e2);

	CString mEdit3; // a blank MFC string for use below
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4)); // reference to an Edit Control
	pEdit3->GetWindowText(mEdit3); // copy Edit Control's text into the MFC string
	string e3 = CStringA(mEdit3);
	tokens.push_back(e3);

	//The Shapes
	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO2));
	int n = pCombo->GetCurSel(); // 0 for first item...

	//Result Text
	CStatic* pText8 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC8));
	

	//output
	ostringstream sout;

	if (n == 1) {
		Square square(tokens);
		sout << &square;  
		pText8->SetWindowText(CString(sout.str().c_str()));
	}
	else if (n == 2) {
		comsc::Rectangle rectangle(tokens);
		sout << &rectangle;
		pText8->SetWindowText(CString(sout.str().c_str()));
	}
	else if (n == 3) {
		Circle circle(tokens);
		sout << &circle;
		pText8->SetWindowText(CString(sout.str().c_str()));
	}
	else if (n == 4) {
		Triangle triangle(tokens);
		sout << &triangle;
		pText8->SetWindowText(CString(sout.str().c_str()));
	}
	else if (n == 5) {
		Cube cube(tokens);
		sout << &cube;
		pText8->SetWindowText(CString(sout.str().c_str()));
	}
	else if (n == 6) {
		Box box(tokens);
		sout << &box;
		pText8->SetWindowText(CString(sout.str().c_str()));
	}
	else if (n == 7) {
		Cylinder cylinder(tokens);
		sout << &cylinder;
		pText8->SetWindowText(CString(sout.str().c_str()));
	}
	else if (n == 8) {
		Prism prism(tokens);
		sout << &prism;
		pText8->SetWindowText(CString(sout.str().c_str()));
	}
}

