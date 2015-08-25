//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("mainFrm.cpp", mainForm);
USEFORM("prgFrm.cpp", udpPrgForm);
USEFORM("cfgFrm.cpp", cfgForm);
USEFORM("tcpPrgFrm.cpp", tcpPrgForm);
USEFORM("PasswdDlg.cpp", PasswordDlg);
USEFORM("refreshDlg.cpp", RefreshRateDlg);
USEFORM("upgradeDlg.cpp", upgradeFWDlg);
USEFORM("schIP.cpp", sIPDlg);
USEFORM("upgradePd.cpp", upgradePsswdDlg);
USEFORM("upgradePrgFrm.cpp", upgradePrgForm);
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", Form2);
USEFORM("PasswdDlg2.cpp", PasswordDlg2);
//---------------------------------------------------------------------------
extern int d_f,ndev_f,dhcp_f,usb_f;

//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR cp, int)
{
	for (int i=0;cp[i];++i)
	{
		if ( cp[i]=='-' && cp[i+1]=='d' ) d_f = 1;
		if ( cp[i]=='-' && cp[i+1]=='o' ) ndev_f = 0;
		if ( cp[i]=='-' && cp[i+1]=='p' ) dhcp_f = 1;
                if ( cp[i]=='-' && cp[i+1]=='u' ) usb_f = 1;
	}

	try
	{
                //dhcp_f = 1; //for unlock DHCP,Maolung
		Application->Initialize();
		Application->Title = "Posiflex LAN WIFI Printer Manager";
                 //Application->CreateForm(__classid(TForm3), &Form3);
                 //Application->CreateForm(__classid(TForm2), &Form2);
                 Application->CreateForm(__classid(TmainForm), &mainForm);
                 Application->CreateForm(__classid(TudpPrgForm), &udpPrgForm);
                 Application->CreateForm(__classid(TcfgForm), &cfgForm);
                 Application->CreateForm(__classid(TtcpPrgForm), &tcpPrgForm);
                 Application->CreateForm(__classid(TRefreshRateDlg), &RefreshRateDlg);
                 Application->CreateForm(__classid(TupgradeFWDlg), &upgradeFWDlg);
                 Application->CreateForm(__classid(TsIPDlg), &sIPDlg);
                 Application->CreateForm(__classid(TupgradePsswdDlg), &upgradePsswdDlg);
                 Application->CreateForm(__classid(TupgradePrgForm), &upgradePrgForm);
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TForm2), &Form2);
                 Application->CreateForm(__classid(TPasswordDlg), &PasswordDlg);
                 Application->CreateForm(__classid(TPasswordDlg2), &PasswordDlg2);
                 Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("???");
		}
		catch (Exception &exception)
		{
			Application->ShowException( &exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
