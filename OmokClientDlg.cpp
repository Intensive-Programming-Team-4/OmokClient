
// OmokClientDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "OmokClient.h"
#include "OmokClientDlg.h"
#include "afxdialogex.h"

#include "DlgConnect.h"		// 연결 다이얼로그

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


// COmokClientDlg 대화 상자



COmokClientDlg::COmokClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OMOKCLIENT_DIALOG, pParent)
	, m_strSend(_T(""))
	, m_strConnect(_T("접속 전입니다."))
	, m_strMe(_T("대기중"))
	, m_strStatus(_T("대기중"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COmokClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SEND, m_strSend);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_STATIC_CONNECT, m_strConnect);
	DDX_Text(pDX, IDC_STATIC_ME, m_strMe);
	DDX_Text(pDX, IDC_STATIC_STATUS, m_strStatus);
}

BEGIN_MESSAGE_MAP(COmokClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &COmokClientDlg::OnBnClickedButtonConnect)
END_MESSAGE_MAP()


// COmokClientDlg 메시지 처리기

BOOL COmokClientDlg::OnInitDialog()
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

	// 방화벽 개방
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return -1;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void COmokClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COmokClientDlg::OnPaint()
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
HCURSOR COmokClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COmokClientDlg::OnBnClickedButtonConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDlgConnect* dlg = new CDlgConnect;

	if (dlg->DoModal() == IDOK) {
		m_socCom.Create();

		// 접속 성공 시
		if (m_socCom.Connect(dlg->m_strIP, 5000)) {
			m_socCom.Init(this->m_hWnd);
			m_strConnect = _T("접속성공");
			m_strStatus = _T("게임을 초기화 하십시오.");

			m_bConnect = TRUE;
			// 전송버튼 활성화
			GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
			// 접속버튼 비활성화
			GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(FALSE);
		}
		else {
			CString strErr;

			strErr.Format(_T("ERROR : Fail to connect Server (ERROR CODE : %d)"), m_socCom.GetLastError());
			MessageBox(strErr);
			m_strConnect = _T("접속실패");
			m_strStatus = _T("서버 접속에 실패 했습니다.");

			m_bConnect = FALSE;
			GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
		}
		UpdateData(FALSE);
	}
}


LPARAM COmokClientDlg::OnReceive(UINT wParam, LPARAM lParam) {
	// 접속된 곳에서 데이터가 도착했을 때

	char pTmp[256];
	CString strTmp, str;
	memset(pTmp, '\0', 256);

	// 데이터를 pTmp에 받는다
	m_socCom.Receive(pTmp, 256);

	// strTmp에 헤더 저장
	strTmp.Format(_T("%c"), pTmp[0]);

	int iType = atoi((char*)(LPCTSTR)strTmp);

	if (iType == SOC_GAMESTART) {
		m_bStartSvr = TRUE;

		if (m_bStart) {
			m_strMe = _T("상대방의 차례입니다.");
			m_strStatus = _T("대기 하세요.");
			m_bMe = FALSE;
			UpdateData(FALSE);
		}

	}

	// 채팅
	else if (iType == SOC_TEXT) {
		str.Format(_T("%s"), (LPCTSTR)(pTmp + 1));
		m_list.AddString(str);
	}

	// 보드판 클릭
	else if (iType == SOC_CHECK) {
		str.Format(_T("%s"), (LPCTSTR)(pTmp + 1));
		int iRow = -1, iCol = -1;
		//NumToIndex(atoi((char*)(LPCTSTR)str), iRow, iCol);

		//DrawCheck(iRow, iCol);

		// 차례 변경
		m_bMe = TRUE;
		m_strMe = _T("당신의 차례입니다.");
		m_strStatus = _T("원하는 곳을 선택 하세요.");
		UpdateData(FALSE);

		//if (IsGameEnd()) {
		//	m_bCntEnd = TRUE;
		//	SendGame(SOC_GAMEEND, "");
		//	Sleep(1000);
		//	SetGameEnd();
		//	InitGame(); // 추가
		//	Invalidate(TRUE); // 추가
		//}
	}

	else if (iType == SOC_GAMEEND) {
		m_bSvrEnd = TRUE;
		Sleep(1000);
		//SetGameEnd();
	}
	return TRUE;
}