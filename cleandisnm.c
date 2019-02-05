#include <stdio.h>
int main(int a,char *b[])
{
	if(a<2)
	{
		puts("参数不够");
		return 120;
	};
	FILE *fp=fopen(b[1],"r");
	char as,sdf[500];
	a=0;
	sprintf(sdf,"%saghjkybvg",b[1]);
	FILE *fp1=fopen(sdf,"w");
	while((as=fgetc(fp))!=EOF)
	{
		a++;
		if(a>28)
			fputc(as,fp1);
		if(as=='\n')
			a=0;
	};
	fclose(fp);
	fclose(fp1);
	remove(b[1]);
	rename(sdf,b[1]);
	return 0;
}
