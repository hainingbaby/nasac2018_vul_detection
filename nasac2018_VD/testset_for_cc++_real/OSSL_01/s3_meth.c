#include "ssl_locl.h"

static const SSL_METHOD *ssl3_get_method(int ver);

static const SSL_METHOD *ssl3_get_method(int ver)
{
    return(SSLv3_method());
}

IMPLEMENT_ssl3_meth_func(SSLv3_method)
