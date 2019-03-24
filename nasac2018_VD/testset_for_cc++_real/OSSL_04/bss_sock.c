#include <string.h>
#include <stdlib.h>
#include "bio.h"
#include "e_os.h"

BIO *BIO_new_socket(int fd, int close_flag)
{
    BIO *ret;
    ret = BIO_new();
    if (ret == NULL) return(NULL);
    ret->num = fd;
    ret->shutdown=(int)close_flag;
    ret->init= 1;
    return(ret);
}
