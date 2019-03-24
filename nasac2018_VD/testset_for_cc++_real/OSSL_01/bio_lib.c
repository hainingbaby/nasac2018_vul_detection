#include <stdio.h>
#include <errno.h>
#include "bio.h"
#include "err.h"
#include "crypto.h"

int BIO_set(BIO *bio, BIO_METHOD *method)
	{
	bio->method=method;
	bio->callback=NULL;
	bio->cb_arg=NULL;
	bio->init=0;
	bio->shutdown=1;
	bio->flags=0;
	bio->retry_reason=0;
	bio->num=0;
	bio->ptr=NULL;
	bio->prev_bio=NULL;
	bio->next_bio=NULL;
	bio->references=1;
	bio->num_read=0L;
	bio->num_write=0L;
	if (method->create != NULL)
		if (!method->create(bio))
			{
			return(0);
			}
	return(1);
	}

BIO *BIO_new(BIO_METHOD *method)
	{
	BIO *ret=NULL;

	ret=(BIO *)OPENSSL_malloc(sizeof(BIO));
	if (ret == NULL)
		{
		return(NULL);
		}
	if (!BIO_set(ret,method))
		{
		OPENSSL_free(ret);
		ret=NULL;
		}
	return(ret);
	}
int BIO_free(BIO *a)
	{
	int i;

	if (a == NULL) return(0);

	i=CRYPTO_add(&a->references,-1,CRYPTO_LOCK_BIO);
#ifdef REF_PRINT
	REF_PRINT("BIO",a);
#endif
	if (i > 0) return(1);
#ifdef REF_CHECK
	if (i < 0)
		{
		fprintf(stderr,"BIO_free, bad reference count\n");
		abort();
		}
#endif
	if ((a->callback != NULL) &&
		((i=(int)a->callback(a,BIO_CB_FREE,NULL,0,0L,1L)) <= 0))
			return(i);

	//CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

	if ((a->method == NULL) || (a->method->destroy == NULL)) return(1);
	a->method->destroy(a);
	OPENSSL_free(a);
	return(1);
	}

void BIO_free_all(BIO *bio)
	{
	BIO *b;
	int ref;

	while (bio != NULL)
		{
		b=bio;
		ref=b->references;
		bio=bio->next_bio;
		BIO_free(b);
		/* Since ref count > 1, don't free anyone else. */
		if (ref > 1) break;
		}
	}

void BIO_clear_flags(BIO *b, int flags)
	{
	b->flags &= ~flags;
	}

void	BIO_set_flags(BIO *b, int flags)
	{
	b->flags |= flags;
	}
long BIO_ctrl(BIO *b, int cmd, long larg, void *parg)
	{
	long ret;
	long (*cb)(BIO *,int,const char *,int,long,long);

	if (b == NULL) return(0);

	if ((b->method == NULL) || (b->method->ctrl == NULL))
		{
		return(-2);
		}

	cb=b->callback;

	if ((cb != NULL) &&
		((ret=cb(b,BIO_CB_CTRL,parg,cmd,larg,1L)) <= 0))
		return(ret);

	ret=b->method->ctrl(b,cmd,larg,parg);

	if (cb != NULL)
		ret=cb(b,BIO_CB_CTRL|BIO_CB_RETURN,parg,cmd,
			larg,ret);
	return(ret);
	}

long BIO_int_ctrl(BIO *b, int cmd, long larg, int iarg)
	{
	int i;

	i=iarg;
	return(BIO_ctrl(b,cmd,larg,(char *)&i));
	}

long BIO_callback_ctrl(BIO *b, int cmd, void (*fp)(struct bio_st *, int, const char *, int, long, long))
	{
	long ret;
	long (*cb)(BIO *,int,const char *,int,long,long);

	if (b == NULL) return(0);

	if ((b->method == NULL) || (b->method->callback_ctrl == NULL))
		{
		return(-2);
		}

	cb=b->callback;

	if ((cb != NULL) &&
		((ret=cb(b,BIO_CB_CTRL,(void *)&fp,cmd,0,1L)) <= 0))
		return(ret);

	ret=b->method->callback_ctrl(b,cmd,fp);

	if (cb != NULL)
		ret=cb(b,BIO_CB_CTRL|BIO_CB_RETURN,(void *)&fp,cmd,
			0,ret);
	return(ret);
	}


int BIO_read(BIO *b, void *out, int outl)
{
    int i=b->method->bread(b,out,outl);
    return i;
}
