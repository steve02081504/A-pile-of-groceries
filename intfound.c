#include <stdio.h>
#include <stdlib.h>
int main(int a,char *b[])
{
    if(a<2)
    {
        puts("参数错误。");
        return EXIT_FAILURE;
    }
    while (--a)
    {
        FILE *c,*d;
        int e[1024];
        int f,g;
        char h[500];
        sprintf(h,"%s.intfound",b[a]);
        if((!(d=fopen(h,"w")))||(!(c=fopen(b[a],"rb"))))
        {
            puts("打开文件错误。");
            return EXIT_FAILURE;
        }
        fputs("do\n{\nint buf[1024];\n",d);
        while((g=fread(e,sizeof(int),1024,c))!=0)
        {
            f=0;
            while(f!=g)
            {
                fprintf(d,"buf[%d]=%#x;",f,e[f]);
                f++;
            }
            fprintf(d,"\nfwrite(buf,sizeof(int),%d,intfound);\n",g);
        }
        fputs("fclose(intfound);\n}\nwhile(0);\n",d);
        fclose(c);
        fclose(d);
    }
    return 0;
}
