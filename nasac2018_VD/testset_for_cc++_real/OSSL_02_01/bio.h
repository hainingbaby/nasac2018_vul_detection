#include <stdarg.h>
#include <sys/types.h>
#define INVALID_SOCKET (-1)

/* BIO_FILENAME_READ|BIO_CLOSE to open or close on free.
 * BIO_set_fp(in,stdin,BIO_NOCLOSE); */
#define BIO_NOCLOSE		0x00
#define BIO_CLOSE		0x01
typedef struct bio_st BIO;
typedef void bio_info_cb(struct bio_st *, int, const char *, int, long, long);
struct bio_st
{
    /* bio, mode, argp, argi, argl, ret */
    int init;
    int shutdown;
    int flags;	/* extra storage */
    int retry_reason;
    int num;
    void *ptr;
    int references;
    unsigned long num_read;
    unsigned long num_write;
};

BIO	*BIO_new();
int	BIO_free(BIO *a);
BIO *BIO_new_socket(int sock, int close_flag);
