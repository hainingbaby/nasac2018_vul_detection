#include <stdio.h>
#include <string.h>

#define	MAXSIZE		40

int main(int argc, char **argv)
{
    char buf[MAXSIZE];
    if(argc > 1)
    {
        if(strlen(argv[1]) > MAXSIZE)
            return -1;
        // 
        printf("%s", argv[1]);
        printf("result: %s\n", buf);
    }
    return 0;
}