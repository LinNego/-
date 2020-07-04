// FUN.cpp : implementation file
//

#include "stdafx.h"
#include "library_reader.h"
#include "FUN.h"
#include "BORROW.h"
#include "Return.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// FUN dialog


FUN::FUN(CWnd* pParent /*=NULL*/)
	: CDialog(FUN::IDD, pParent)
{
	//{{AFX_DATA_INIT(FUN)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	//�ָ���
}
FUN::~FUN()
{
	delete fun;
}

void FUN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(FUN)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(FUN, CDialog)
	//{{AFX_MSG_MAP(FUN)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// FUN message handlers


void FUN::Build()
{	
	CStdioFile file;
	file.Open("account_isbn.dat", CFile::modeRead);
	CString line;
	while(file.ReadString(line))
	{
		CString acc, isbn;
		int index = line.Find(' ');
		acc = line.Mid(0, index);
		isbn = line.Mid(index + 1, line.GetLength() - index - 1);
		acc_isbn.SetAt(acc, isbn);
	
	}
}
void FUN::OnOK() 
{
	
	BORROW borrow;
	Build();
	CString temp;
	if(!acc_isbn.Lookup(account,temp))
	{	MessageBox("��������Ҫ������ISBN��");
		borrow.account = account;
		borrow.DoModal();
	
	}
	else 
		MessageBox("�����鱾û�������ȹ黹");
	CDialog::OnOK();
}
void FUN::OnCancel()
{
	CDialog::OnCancel();

}




void FUN::OnButton1() 
{
	Return r;
	Build();
	CString temp;
	if(acc_isbn.Lookup(account, temp))
	{
		MessageBox("��������Ҫ�������isbn��");
		r.user = account;
		r.DoModal();
	
	}
	else 
	{
		MessageBox("��û�н赽�鱾");
	}
	
	// TODO: Add extra cleanup here
	//MessageBox("������Ҫ������");
	CDialog::OnCancel();	
}
