#include <unistd.h>
#include <stdio.h>
main()
{
    char path[80];
    getcwd(path, sizeof(path));
    printf("路径如下 : %s\n", path);
}
