
// Calculator2Dlg.h: 헤더 파일
// 20200811 정호진

#pragma once

using namespace std;

// CCalculator2Dlg 대화 상자
class CCalculator2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CCalculator2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMulti();
	afx_msg void OnBnClickedButtonDivid();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonCe();
	afx_msg void OnBnClickedButtonBack();

	void InputStr(CString str);
	void CALCULATE();
	void CHECK_FLAG_RESET();
	void DELTE_NUMBER();
public:
	CString m_str, m_operate; // 연산자
	double m_lf1stNum, m_lf2ndNum; // 앞 숫자, 뒷 숫자
	int m_order;// 연산자 번째 수
	bool m_flag_reset;// reset을 위한 스위치
	CFont m_ccfont; // 폰트
	
	virtual BOOL PreTranslateMessage(MSG* pMsg);// 키보드 이벤트 처리
};
