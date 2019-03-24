#include "ssl_locl.h"

#define IPADDR "127.0.0.1"
#define PORT 8888

int ssl3_read(SSL *s, void *buf, int len)
{
    printf("in s3_lib.c, doing ssl3_read...\n");
    int ret = s->method->ssl_read_bytes(s,SSL3_RT_APPLICATION_DATA,buf,len,0);
    return ret;
}

