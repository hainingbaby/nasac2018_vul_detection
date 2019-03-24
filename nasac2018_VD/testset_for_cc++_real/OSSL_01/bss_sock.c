#include <string.h>
#include <stdlib.h>
#include "bio.h"
#include "e_os.h"

static int sock_write(BIO *h, const char *buf, int num);
static int sock_read(BIO *h, char *buf, int size);
static int sock_puts(BIO *h, const char *str);
static long sock_ctrl(BIO *h, int cmd, long arg1, void *arg2);
static int sock_new(BIO *h);
static int sock_free(BIO *data);
int BIO_sock_should_retry(int s);

static BIO_METHOD methods_sockp=
	{
	BIO_TYPE_SOCKET,
	"socket",
	sock_write,
	sock_read,
	sock_puts,
	NULL, /* sock_gets, */
	sock_ctrl,
	sock_new,
	sock_free,
	NULL,
	};

BIO_METHOD *BIO_s_socket(void)
	{
	return(&methods_sockp);
	}

BIO *BIO_new_socket(int fd, int close_flag)
	{
	BIO *ret;

	ret=BIO_new(BIO_s_socket());
	if (ret == NULL) return(NULL);
	BIO_set_fd(ret,fd,close_flag);
	return(ret);
	}

static int sock_new(BIO *bi)
	{
	bi->init=0;
	bi->num=0;
	bi->ptr=NULL;
	bi->flags=0;
	return(1);
	}

static int sock_free(BIO *a)
	{
	if (a == NULL) return(0);
	if (a->shutdown)
		{
		if (a->init)
			{
			SHUTDOWN2(a->num);
			}
		a->init=0;
		a->flags=0;
		}
	return(1);
	}
	
static int sock_read(BIO *b, char *out, int outl)
	{
	int ret=0;

	if (out != NULL)
		{
		clear_socket_error();
		ret=readsocket(b->num,out,outl);
		BIO_clear_retry_flags(b);
		if (ret <= 0)
			{
			if (BIO_sock_should_retry(ret))
				BIO_set_retry_read(b);
			}
		}
	return(ret);
	}

static int sock_write(BIO *b, const char *in, int inl)
	{
	int ret;
	
	clear_socket_error();
	ret=writesocket(b->num,in,inl);
	BIO_clear_retry_flags(b);
	if (ret <= 0)
		{
		if (BIO_sock_should_retry(ret))
			BIO_set_retry_write(b);
		}
	return(ret);
	}

static long sock_ctrl(BIO *b, int cmd, long num, void *ptr)
	{
	long ret=1;
	int *ip;

	switch (cmd)
		{
	case BIO_C_SET_FD:
		sock_free(b);
		b->num= *((int *)ptr);
		b->shutdown=(int)num;
		b->init=1;
		break;
	case BIO_C_GET_FD:
		if (b->init)
			{
			ip=(int *)ptr;
			if (ip != NULL) *ip=b->num;
			ret=b->num;
			}
		else
			ret= -1;
		break;
	case BIO_CTRL_GET_CLOSE:
		ret=b->shutdown;
		break;
	case BIO_CTRL_SET_CLOSE:
		b->shutdown=(int)num;
		break;
	case BIO_CTRL_DUP:
	case BIO_CTRL_FLUSH:
		ret=1;
		break;
	default:
		ret=0;
		break;
		}
	return(ret);
	}

static int sock_puts(BIO *bp, const char *str)
	{
	int n,ret;

	n=strlen(str);
	ret=sock_write(bp,str,n);
	return(ret);
	}

int BIO_sock_should_retry(int i)
	{
	int err;

	if ((i == 0) || (i == -1))
		{
		err=get_last_socket_error();

#if defined(OPENSSL_SYS_WINDOWS) && 0 /* more microsoft stupidity? perhaps not? Ben 4/1/99 */
		if ((i == -1) && (err == 0))
			return(1);
#endif

		return(err);
		}
	return(0);
	}
