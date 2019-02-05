#include <evest.h>
#define ST_ST_CARG
#include <steve.h>
#include <windows.h>
#include <process.h>
void ha()
{
	MessageBox(NULL,TEXT("-1s"),TEXT("膜法"),MB_ICONWARNING|MB_OK);
};
int stst(int a,char**b)
{
	ShowWindow(FindWindow("ConsoleWindowClass",b[0]),0);
	floop _beginthread(ha,0,NULL);
};
