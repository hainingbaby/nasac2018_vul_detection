#include <stdio.h>
#include <string.h>

#define	MAXSIZE		40

int main(int argc, char **argv)
{
    char buf[MAXSIZE];
    buf[0] = '\0';
    //
    char good[10] = "Hello";
    if(argc > 1)
    {
        if(strlen(argv[1]) > MAXSIZE)
            return -1;
        //
        strcat(buf, good);
        printf("result: %s\n", buf);
    }
    return 0;
}