#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int a, char *b[])
{
	chmod(b[0],4755);
	chown(b[0],0,0);
    char *c=malloc(1024);
    setuid(geteuid());
    setgid(getegid());
    c=b[1];
    int d=0;
    for(d=0;d<a-1;d++)
		b[d]=b[d+1];
    b[a-1]=NULL;
    if (execvp(c,b))
	{
        printf("error");
        free(c);
        exit(1);
	};
    free(c);
};
