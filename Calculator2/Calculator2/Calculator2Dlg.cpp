
// Calculator2Dlg.cpp: 구현 파일
// 20200811 정호진

#include "pch.h"
#include "framework.h"
#include "Calculator2.h"
#include "Calculator2Dlg.h"
#include "afxdialogex.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CCalculator2Dlg 대화 상자



CCalculator2Dlg::CCalculator2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculator2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculator2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON0, &CCalculator2Dlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculator2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculator2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculator2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculator2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculator2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculator2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculator2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculator2Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculator2Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculator2Dlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculator2Dlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTI, &CCalculator2Dlg::OnBnClickedButtonMulti)
	ON_BN_CLICKED(IDC_BUTTON_DIVID, &CCalculator2Dlg::OnBnClickedButtonDivid)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCalculator2Dlg::OnBnClickedButtonEqual)
	
	
	ON_BN_CLICKED(IDC_BUTTON_CE, &CCalculator2Dlg::OnBnClickedButtonCe)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CCalculator2Dlg::OnBnClickedButtonBack)
	
END_MESSAGE_MAP()


// CCalculator2Dlg 메시지 처리기

BOOL CCalculator2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_order = 0;
	m_flag_reset = false;
	m_ccfont.CreateFontW(
		25,//글자 높이
		10,//글자너비
		0,//출력각도
		0,//기준선에서의 각도
		FW_HEAVY,//글자 굵기
		FALSE,//Italic 적용 여부
		FALSE,//밑줄 적용 여부
		FALSE,//취소선 적용 여부
		DEFAULT_CHARSET,//문자셋 종류
		OUT_DEFAULT_PRECIS,//출력 정밀도
		CLIP_CHARACTER_PRECIS,//클리핑 정밀도
		PROOF_QUALITY, //출력문자 품질
		DEFAULT_PITCH,//글꼴 PITCH
		_T("돋움")//글꼴
	);
	GetDlgItem(IDC_EDIT1)->SetFont(&m_ccfont);
	GetDlgItem(IDC_EDIT2)->SetFont(&m_ccfont);




	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCalculator2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCalculator2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCalculator2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculator2Dlg::OnBnClickedButton0()
{
	CHECK_FLAG_RESET();
	InputStr(_T("0"));
}


void CCalculator2Dlg::OnBnClickedButton1()
{
	CHECK_FLAG_RESET();
	InputStr(_T("1"));
}


void CCalculator2Dlg::OnBnClickedButton2()
{
	CHECK_FLAG_RESET();
	InputStr(_T("2"));
}


void CCalculator2Dlg::OnBnClickedButton3()
{
	CHECK_FLAG_RESET();
	InputStr(_T("3"));
}


void CCalculator2Dlg::OnBnClickedButton4()
{
	CHECK_FLAG_RESET();
	InputStr(_T("4"));
}


void CCalculator2Dlg::OnBnClickedButton5()
{
	CHECK_FLAG_RESET();
	InputStr(_T("5"));
}


void CCalculator2Dlg::OnBnClickedButton6()
{
	CHECK_FLAG_RESET();
	InputStr(_T("6"));
}


void CCalculator2Dlg::OnBnClickedButton7()
{
	CHECK_FLAG_RESET();
	InputStr(_T("7"));
}


void CCalculator2Dlg::OnBnClickedButton8()
{
	CHECK_FLAG_RESET();
	InputStr(_T("8"));
}


void CCalculator2Dlg::OnBnClickedButton9()
{
	CHECK_FLAG_RESET();
	InputStr(_T("9"));
}


void CCalculator2Dlg::OnBnClickedButtonPlus()
{
	CHECK_FLAG_RESET();
	InputStr(_T("+"));
	CALCULATE();
}


void CCalculator2Dlg::OnBnClickedButtonMinus()
{
	CHECK_FLAG_RESET();
	InputStr(_T("-"));
	CALCULATE();
}


void CCalculator2Dlg::OnBnClickedButtonMulti()
{
	CHECK_FLAG_RESET();
	InputStr(_T("*"));
	CALCULATE();
}


void CCalculator2Dlg::OnBnClickedButtonDivid()
{
	CHECK_FLAG_RESET();
	InputStr(_T("/"));
	CALCULATE();
}


void CCalculator2Dlg::OnBnClickedButtonEqual()
{
	CHECK_FLAG_RESET();
	InputStr(_T("="));
	m_flag_reset = true;
	CALCULATE();
}

void CCalculator2Dlg::OnBnClickedButtonCe(){	m_flag_reset = true;	CHECK_FLAG_RESET();	}
void CCalculator2Dlg::OnBnClickedButtonBack(){	DELTE_NUMBER();	}


void CCalculator2Dlg::InputStr(CString str2)
{
	m_str += str2;
	SetDlgItemText(IDC_EDIT1, m_str);
}

void CCalculator2Dlg::CALCULATE() {
	CString cs = _T("+-*/=");
	CString o;
	bool flag1 = false;//연산자가 한 개 일 때
	bool flag2 = false;//연산자가 연속적으로 두 개일 때
	

	for (int i = 0; i < cs.GetLength(); i++)
	{
		if (m_str.Left(1) == cs.Mid(i, 1)){
			m_str = '0' + m_str.Left(0);
			SetDlgItemText(IDC_EDIT1, m_str);
			break;
		}
	}
	
	for (int i = 0; i < cs.GetLength(); i++)
	{
		if (m_str.Mid(m_str.GetLength() - 1, 1) == cs.Mid(i, 1)) {	flag1 = true;	}
		if (m_str.Mid(m_str.GetLength() - 2, 1) == cs.Mid(i, 1)) {	flag2 = true;	}
	}

	if (flag1 == true && flag2 == true) 
	{
		m_str.Delete(m_str.GetLength() - 1, 1);
		SetDlgItemText(IDC_EDIT1, m_str);
	}

	if (	m_lf1stNum == 0 && m_lf2ndNum ==0) { m_lf1stNum = _ttof(m_str.Mid(m_order, m_str.GetLength() - 1));	}// 연산자 이전 숫자
	else {	m_lf2ndNum = fabs(_ttof(m_str.Mid(m_order + 1, m_str.GetLength() - 1)));	}// 연산자 이전 숫자
	
	if (m_operate == cs.Left(1)) {	m_lf1stNum = m_lf1stNum + m_lf2ndNum;	}
	else if (m_operate == cs.Mid(1,1)){	m_lf1stNum = m_lf1stNum - m_lf2ndNum;	}
	else if (m_operate == cs.Mid(2,1)) {	m_lf1stNum = m_lf1stNum * m_lf2ndNum;	}
	else if (m_operate == cs.Mid(3,1)){	m_lf1stNum = m_lf1stNum / m_lf2ndNum;	}
	else if (m_operate == cs.Mid(4, 1)){	m_lf1stNum = m_lf1stNum;	m_flag_reset = true;	}

	if (m_operate != cs.Mid(4, 1))	{ m_operate = m_str.Mid(m_str.GetLength() - 1, 1);	}//연산자	

	m_order = m_str.GetLength()-1;
	o.Format(_T("%lf"), m_lf1stNum);
	SetDlgItemText(IDC_EDIT2, o);
}

void CCalculator2Dlg::CHECK_FLAG_RESET()
{
	if (m_flag_reset == true)
	{
		m_lf1stNum = 0;
		m_lf2ndNum = 0;
		m_order = 0;
		m_operate.Empty();
		m_str.Empty();
		SetDlgItemText(IDC_EDIT1, m_str);
		SetDlgItemText(IDC_EDIT2, m_str);
		m_flag_reset = false;
	}

}
void CCalculator2Dlg::DELTE_NUMBER()
{
	for (int i = 0; i < m_str.GetLength(); i++) {		
		if (isdigit(_ttoi(m_str.Right(1))) == TRUE)
		{
			m_str.Delete(m_str.GetLength() - 1, 1);
			SetDlgItemText(IDC_EDIT1, m_str);
		}	
	}
}

BOOL CCalculator2Dlg::PreTranslateMessage(MSG* pMsg)
{
	switch (pMsg->message)
	{
		case WM_KEYDOWN:
			switch (pMsg->wParam) {
				case VK_NUMPAD0:	OnBnClickedButton0();		break;
				case VK_NUMPAD1:	OnBnClickedButton1();		break;
				case VK_NUMPAD2:	OnBnClickedButton2();		break;
				case VK_NUMPAD3:	OnBnClickedButton3();		break;
				case VK_NUMPAD4:	OnBnClickedButton4();		break;
				case VK_NUMPAD5:	OnBnClickedButton5();		break;
				case VK_NUMPAD6:	OnBnClickedButton6();		break;
				case VK_NUMPAD7:	OnBnClickedButton7();		break;
				case VK_NUMPAD8:	OnBnClickedButton8();		break;
				case VK_NUMPAD9:	OnBnClickedButton9();		break;
				case VK_ADD:		OnBnClickedButtonPlus();	break;
				case VK_SUBTRACT:	OnBnClickedButtonMinus();	break;
				case VK_MULTIPLY:	OnBnClickedButtonMulti();	break;
				case VK_DIVIDE:		OnBnClickedButtonDivid();	break;
				case VK_RETURN:		OnBnClickedButtonEqual();	return true;
				case VK_ESCAPE:		OnBnClickedButtonCe();		return true;
			}
		break;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
