#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "bio.h"
#include "err.h"
#include "e_os.h"

int BIO_set(BIO *bio)
{
    bio->init = 0;
    bio->shutdown = 1;
    bio->flags = 0;
    bio->retry_reason = 0;
    bio->num = 0;
    bio->ptr = NULL;
    bio->references = 1;
    bio->num_read = 0L;
    bio->num_write = 0L;
    return(1);
}

BIO *BIO_new()
{
    BIO *ret = NULL;

    ret = (BIO *)malloc(sizeof(BIO));
    if (ret == NULL)
    {
        return(NULL);
    }
    if (!BIO_set(ret))
    {
        free(ret);
        ret = NULL;
    }
    return(ret);
}
int BIO_free(BIO *a)
{
    int i;
    if (a == NULL) return(0);
    free(a);
    return(1);
}
