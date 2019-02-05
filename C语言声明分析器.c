//cdecl.c --madeby Alex Jas de Brad and Steve Green
//
#include <evest.h>
#define ST_ST_TYPE void
#define ST_ST_MARG
#include <steve.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#define MAXTOKENS 100
#define MAXTOKENLEN 64
#define pop (stack[top--])
#define push(s) (stack[++top]=s)
int leixing;
int yige;
int boolinline;
int boolvirtual;
enum type_tag {IDENTIFIER,QUALIFIER,TYPE};
struct token
{
	char type;
	char string[MAXTOKENLEN];
};
int top=-1;
struct token stack[MAXTOKENS];
struct token this;
enum type_tag classify_string(void)
{
	char *s=this.string;
	if(!strcmp(s,"extern"))
	{
		strcpy(s,",其具有外部链接");
		return QUALIFIER;
	};
	if(!strcmp(s,"inline"))
	{
		boolinline=1;
		strcpy(s,"");
		return QUALIFIER;
	};
	if(!strcmp(s,"namespace")&&leixing)
	{
		strcpy(s,"名称空间");
		leixing=0;
		return QUALIFIER;
	};
	if(!strcmp(s,"virtual"))
	{
		boolvirtual=1;
		strcpy(s,"");
		return QUALIFIER;
	};
	if(!strcmp(s,"const"))
	{
		strcpy(s,"只读");
		return QUALIFIER;
	};
	if(!strcmp(s,"volatile"))
	{
		strcpy(s,"易变");
		return QUALIFIER;
	};
	if(!strcmp(s,"signed"))
	{
		strcpy(s,"有符号");
		return QUALIFIER;
	};
	if(!strcmp(s,"unsigned"))
	{
		strcpy(s,"无符号");
		return QUALIFIER;
	};
	if(!strcmp(s,"short"))
	{
		strcpy(s,"短");
		return QUALIFIER;
	};
	if(!strcmp(s,"long"))
	{
		strcpy(s,"长");
		return QUALIFIER;
	};
	if(!strcmp(s,"int")&&leixing)
	{
		strcpy(s,"整数类型");
		leixing=0;
		return QUALIFIER;
	};
	if(!strcmp(s,"void")&&leixing)
	{
		strcpy(s,"空类型");
		leixing=0;
		return QUALIFIER;
	};
	if(!strcmp(s,"char")&&leixing)
	{
		strcpy(s,"字符类型");
		leixing=0;
		return QUALIFIER;
	};
	if(!strcmp(s,"float")&&leixing)
	{
		strcpy(s,"单精度浮点数类型");
		leixing=0;
		return QUALIFIER;
	};
	if(!strcmp(s,"double")&&leixing)
	{
		strcpy(s,"双精度浮点数类型");
		leixing=0;
		return QUALIFIER;
	};
	if(!strcmp(s,"struct")&&leixing)
	{
		strcpy(s,"结构体类型");
		leixing=0;
		return QUALIFIER;
	};
	if(!strcmp(s,"union")&&leixing)
	{
		strcpy(s,"联合体类型");
		leixing=0;
		return QUALIFIER;
	};
	if(!strcmp(s,"enum")&&leixing)
	{
		strcpy(s,"枚举体类型");
		leixing=0;
		return QUALIFIER;
	};
	if(!strcmp(s,"auto")&&leixing)
	{
		strcpy(s,"自动（未知）类型");
		leixing=0;
		return QUALIFIER;
	};
	if(!strcmp(s,"bool")&&leixing)
	{
		strcpy(s,"布尔数类型");
		leixing=0;
		return QUALIFIER;
	};
	return IDENTIFIER;
}
void gettoken(void)
{
	char *p=this.string;
	while((*p=getchar())==' ');
	if(isalnum(*p))
	{
		while(isalnum(*++p=getchar()));
		ungetc(*p,stdin);
		*p='\0';
		this.type=classify_string();
		return ;
	};
	this.string[1]='\0';
	this.type=*p;
	return;
}
void initialize(),get_array(),get_params(),get_lparen(),get_ptr_part(),get_type(),declmain(),quit();
void (*nextstate)(void);
void stst(int a,char **b)
{
	rename(b[0],"cdecl.exe");
	system("title cdecl");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|BACKGROUND_INTENSITY);
	system("cls");
	puts("声明：本程序不进行任何语法错误检查，在声明具有语法错误时程序可能崩溃。");
	declmain();
	return;
}
void declmain()
{
a:
	printf("请键入一个在一行内的c语言声明以供程序分析\n声明：");
	nextstate=initialize;
	top=-1;
	yige=1;
	leixing=1;
	boolinline=0;
	boolvirtual=0;
	while(nextstate!=NULL)
		if(nextstate==declmain)
			goto a;
		else
			(*nextstate)();;;
	return;
}
void initialize()
{
	gettoken();
	while(this.type!=IDENTIFIER)
	{
		push(this);
		gettoken();
	};
	printf("“%s”是",this.string);
	gettoken();
	nextstate=get_array;
}
void get_array()
{
	nextstate=get_params;
	while(this.type=='[')
	{
		if(yige)printf("一个");
		printf("数组，数组内容");
		yige=0;
		gettoken();
		if(isdigit(this.string[0]))
		{
			printf("是从0排列至%d的，",atoi(this.string)-1);
			gettoken();
		};
		gettoken();
		printf("都是");
		nextstate=get_lparen;
	};
}
void get_params()
{
	nextstate=get_lparen;
	if(this.type=='(')
	{
		while(this.type!=')')
			gettoken();;
		gettoken();
		if(yige)printf("一个");
		if(boolinline)printf("内联");
		if(boolvirtual)printf("虚");
		printf("函数，函数返回");
		boolinline=0;
		boolvirtual=0;
		yige=0;
	};
}
void get_lparen()
{
	nextstate=get_ptr_part;
	if(top>=0)
	{
		if(stack[top].type=='(')
		{
			pop;
			gettoken();
			nextstate=get_array;
		};
	};
}
void get_ptr_part()
{
	nextstate=get_type;
	if(stack[top].type=='*')
	{
		if(yige)printf("一个");
		printf("指针，指针内容指向");
		yige=0;
		pop;
		nextstate=get_lparen;
	}
	else
		if(stack[top].type==QUALIFIER)
		{
			printf("%s",pop.string);
			nextstate=get_lparen;
		};;
}
void get_type()
{
	nextstate=quit;
	while(top>=0)
		printf("%s",pop.string);;
	if(leixing)
		printf("整数类型");;
	puts("。");
}
void quit()
{
	puts("下一个？(Y/N)");
	char a;
a:
	a=toupper(getchar());
	if(a=='Y')
	{
		nextstate=declmain;
		return;
	};
	if(a=='N')
	{
		nextstate=NULL;
		return;
	};
	//puts("出错，请重新输入。");
	goto a;
}
//

