#include <stdio.h>
#include <stdlib.h>
#include "my-include.h"
#include <string.h>
#include <assert.h>

int main(int argc, char **argv)
{
    char resolved_path[MAXPATHLEN];
    char path[100];
    FILE *f;

    printf ("MAXPATHLEN=%d\n", MAXPATHLEN);

    assert (argc == 2);

    strcpy(path, argv[1]);

    printf("Input path = %s, strlen(path) = %d\n", path, strlen(path));
    printf("MAXPATHLEN = %d\n", MAXPATHLEN);
    fb_realpath(path, resolved_path);

    return 0;
}