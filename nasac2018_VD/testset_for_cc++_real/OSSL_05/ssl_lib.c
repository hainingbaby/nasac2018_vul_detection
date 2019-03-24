#include "ssl.h"

SSL *SSL_new(void)
{
    SSL *ssl;
    ssl = (SSL *)malloc(sizeof(SSL));
    if(ssl == NULL)
        return NULL;
    memset(ssl, 0, sizeof(SSL));
    return ssl;
}
