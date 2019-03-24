#include "ssl.h"

void SSL_set_bio(SSL *s, BIO *rbio, BIO *wbio)
{
    s->rbio = rbio;
}

SSL *SSL_new(void)
{
    SSL *ssl;
    ssl = (SSL *)malloc(sizeof(SSL));
    if(ssl == NULL)
        return NULL;
    memset(ssl, 0, sizeof(SSL));
    SSL3_STATE *s3;
    if ((s3 = malloc(sizeof * s3)) == NULL)
        return NULL;
    memset(s3, 0, sizeof * s3);
    memset(s3->rrec.seq_num, 0, sizeof(s3->rrec.seq_num));
    memset(s3->wrec.seq_num, 0, sizeof(s3->wrec.seq_num));
    ssl->s3 = s3;
    return ssl;
}
