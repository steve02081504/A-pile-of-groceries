#define ST_ST_TYPE int
#define ST_ST_MARG
#define ST_SYSTEMF
#include <steve.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
int stst(int a,char *b[50])
{
	if(a!=2)
		goto a;
	char *c;
	c=b;
	if(strcmp(b[1],"up,steve.")&&strcmp(b[1],"up,steve"))
	{
a:		printf("bash:%s:command not found...\n",b[0]);
		return 0;
	};
	puts("well...can I ?");
	gets(c);
	if(*********)
		puts("let me try.....");
	else
		{
			puts("I can't...\nNo.....");
			return EXIT_FAILURE;
		};
	puts("error:none.");
	chmod("/bin/callst",4755);
	chown("/bin/callst",0,0);
	return 0;
};

