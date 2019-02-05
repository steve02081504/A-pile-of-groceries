//表白.c
// 
//闲极无聊
#include <evest.h>
#define ST_FULLSCR
#define ST_BOMB
#define ST_ST_END
#include <steve.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
//
#define GFNAME "Alex Jas De Brad"
#define NAMESIZE 17
//
#define U 0.1
#define V 0.057
#define M 1.1
#define N 1.2
void theststend_(){
	unfullscreen();
}
void showLove()
{
	double x,y;
	int i=0;
	char WhatYouWantToSay[][255]=
	{
		" "," "," "," ","亲爱的:",
		"──────────────────",
		"\t~\(≧▽≦)/~","──────────────────",
		"\t你","──────────────────",
		"\t终于来了","──────────────────",
		"\t世界是黑暗的","──────────────────",
		"\t唯有有你的地方才是光明",
		"──────────────────","\t★我★爱★你★!",
		"──────────────────",
		"\t不需要太多的言语去修饰",
		"──────────────────",
		"\t我要你幸福","──────────────────",
		" ","\t2017年8月1日"," ","\t---永远爱你的：石凋衍"," "
	};
	for(y=1.3;y>=-1.3;y-=U)
	{
		for(x=-1.2;x<=2.7;x+=V)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|BACKGROUND_INTENSITY);
			if((((x*x+y*y-1)*(x*x+y*y-1)*(x*x+y*y-1)-x*x*y*y*y)<=0))
				printf("*");
			else if(x>1.2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|BACKGROUND_INTENSITY);
				printf("\t");
				for(int j=0;WhatYouWantToSay[i][j]!='\0';j++)
				{
					printf("%c",WhatYouWantToSay[i][j]);
					if(i%2)
						Sleep(1);
					else
						Sleep(rand()%90);
				}
				if(i==4)
					printf("★%s★",GFNAME);
				break;
			} else
				printf(" ");
			fflush(stdout);
			Sleep(10);
		};
		printf("\n");
		i++;
	};
};
void showSkull() {
	system("color 2A");
	char buf[]="\
\t\t\t                        ****                      \n\
\t\t\t                    **  *** * *                   \n\
\t\t\t                  * * ****** ** *                 \n\
\t\t\t                * *************  *                \n\
\t\t\t                * *************                   \n\
\t\t\t               *  ************* * **              \n\
\t\t\t               * ******************               \n\
\t\t\t                * *****************               \n\
\t\t\t             *       ******* *   *  *             \n\
\t\t\t                ***  ******  * * *  **            \n\
\t\t\t             *     * *******         *            \n\
\t\t\t              *     **  *** *      **             \n\
\t\t\t                      *                           \n\
\t\t\t                       *  *                       \n\
\t\t\t                       ** *                       \n\
\t\t\t                       **                         \n\
\t\t\t             *         *            *             \n\
\t\t\t                       *            *             \n\
\t\t\t            **        *     **       *            \n\
\t\t\t            *  **    **     *  *  *               \n\
\t\t\t             *    * * *     *  * * *              \n\
\t\t\t                    *    ****** **                \n\
\t\t\t     ****      ** *         *** *                 \n\
\t\t\t    *   *         *   *  *  ***          **  *    \n\
\t\t\t   * ****          * ***********         * *  *   \n\
\t\t\t    ****           *************          * * *   \n\
\t\t\t    ***  *         * **********          *  * *   \n\
\t\t\t   *    * *         * * *  **  *       * *****    \n\
\t\t\t    *    *  **      *** ****** *     *   ***  **  \n\
\t\t\t   *  *  **   **   *           *   *     *** ***  \n\
\t\t\t    **      **  **              ** * ***     **   \n\
\t\t\t                *              *   *              \n\
\t\t\t                  *  **      * * *                \n\
\t\t\t                    * ***  *   *                  \n\
\t\t\t                     **      *                    \n\
\t\t\t                     ** *    *                    \n\
\t\t\t                   ** *   **   *                  \n\
\t\t\t                ** ***      ** * *                \n\
\t\t\t              *   *           ** * *              \n\
\t\t\t           **  *                *  * **           \n\
\t\t\t  ********    *                    *    *         \n\
\t\t\t    *  *  *  *                      * * * * *  *  \n\
\t\t\t   ***   *  *                        ***   *  *   \n\
\t\t\t       *  *                         *  *          \n\
\t\t\t       **   *                       *  * *        \n\
\t\t\t         ***                         ****         \n";
	printf("%s",buf);
	printf("\n");
};
int stst()
{
	unfullscreen();
	system("title 一个礼物！");
	char name[NAMESIZE];
	int a=-3;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY);
a:	system("cls");
	printf("\t\t\t请输入你的名字,查看神秘礼物,回车确定:\n\t\t\t");
	fgets(name,NAMESIZE,stdin);
	system("cls");
	if(strcmp(name,GFNAME)==0)
	{
		fullscreen();
		showLove();
	}
	else
	{
		++a;
		if(!a)
		{
			fullscreen();
			showSkull();
			forkbomb();
		};
		system("cls");
		printf("这不是这份礼物要给的人的名字。\n你还有%d次机会，亦或点击关闭按钮。\n任意键重新尝试。\n",-a);
		getch();
		goto a;
	};
	Sleep(7); 
	return 0;
};
//
