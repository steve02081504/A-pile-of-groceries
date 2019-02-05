#include <unistd.h>
#include <stdio.h>
int main()
{
    char path[80];
    getcwd(path, sizeof(path));
    printf("PATH is : %s\n", path);
    return 0;
}
