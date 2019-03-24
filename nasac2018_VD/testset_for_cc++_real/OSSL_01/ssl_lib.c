#include "ssl.h"

void SSL_set_bio(SSL *s,BIO *rbio,BIO *wbio)
	{
	/* If the output buffering BIO is still in place, remove it
	 */
	if (s->bbio != NULL)
		{
		if (s->wbio == s->bbio)
			{
			s->wbio=s->wbio->next_bio;
			s->bbio->next_bio=NULL;
			}
		}
	if ((s->rbio != NULL) && (s->rbio != rbio))
		BIO_free_all(s->rbio);
	if ((s->wbio != NULL) && (s->wbio != wbio) && (s->rbio != s->wbio))
		BIO_free_all(s->wbio);
	s->rbio=rbio;
	s->wbio=wbio;
	}

SSL *SSL_new(SSL_CTX *ctx)
{
    SSL *ssl;
    ssl = (SSL *)malloc(sizeof(SSL));
    if(ssl == NULL)
        return NULL;
    memset(ssl,0,sizeof(SSL));
    if(ctx != NULL && ctx->method != NULL)
    {   
        ssl->ctx = ctx;
        ssl->method = ctx->method;
    }   
    SSL3_STATE *s3;
    if ((s3 = OPENSSL_malloc(sizeof * s3)) == NULL)
        return NULL;
    memset(s3, 0, sizeof * s3);
    memset(s3->rrec.seq_num, 0, sizeof(s3->rrec.seq_num));
    memset(s3->wrec.seq_num, 0, sizeof(s3->wrec.seq_num));
    ssl->s3 = s3; 
    return ssl;
}


SSL_CTX *SSL_CTX_new(const SSL_METHOD *meth)
{   
    SSL_CTX *ret = NULL;
    ret = (SSL_CTX*)OPENSSL_malloc(sizeof(SSL_CTX));
    if(meth == NULL)
        return NULL;
    ret->method = meth;
    return ret;
}

int SSL_read(SSL *s,void *buf,int num)
{
    return(s->method->ssl_read(s,buf,num));
}
