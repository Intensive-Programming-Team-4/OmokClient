// DlgConnect.cpp: 구현 파일
//

#include "pch.h"
#include "OmokClient.h"
#include "DlgConnect.h"
#include "afxdialogex.h"


// CDlgConnect 대화 상자

IMPLEMENT_DYNAMIC(CDlgConnect, CDialogEx)

CDlgConnect::CDlgConnect(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CONNECT, pParent)
	, m_strIP(_T("127.0.0.1"))
{

}

CDlgConnect::~CDlgConnect()
{
}

void CDlgConnect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_IP, m_strIP);
}


BEGIN_MESSAGE_MAP(CDlgConnect, CDialogEx)
END_MESSAGE_MAP()


// CDlgConnect 메시지 처리기
