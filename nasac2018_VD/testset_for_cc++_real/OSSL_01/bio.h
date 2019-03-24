#include <stdarg.h>
#include <sys/types.h>
#define INVALID_SOCKET (-1)
#define DECIMAL_SIZE(type)	((sizeof(type)*8+2)/3+1)
#define BIO_clear_retry_flags(b) \
		BIO_clear_flags(b, (BIO_FLAGS_RWS|BIO_FLAGS_SHOULD_RETRY))

/* Mostly used in the SSL BIO */
/* Not used anymore
 * #define BIO_FLAGS_PROTOCOL_DELAYED_READ 0x10
 * #define BIO_FLAGS_PROTOCOL_DELAYED_WRITE 0x20
 * #define BIO_FLAGS_PROTOCOL_STARTUP	0x40
 */

#define BIO_FLAGS_BASE64_NO_NL	0x100

/* This is used with memory BIOs: it means we shouldn't free up or change the
 * data in any way.
 */
#define BIO_FLAGS_MEM_RDONLY	0x200
/* The next three are used in conjunction with the
 * BIO_should_io_special() condition.  After this returns true,
 * BIO *BIO_get_retry_BIO(BIO *bio, int *reason); will walk the BIO 
 * stack and return the 'reason' for the special and the offending BIO.
 * Given a BIO, BIO_get_retry_reason(bio) will return the code. */
/* Returned from the SSL bio when the certificate retrieval code had an error */
#define BIO_RR_SSL_X509_LOOKUP		0x01
/* Returned from the connect BIO when a connect would have blocked */
#define BIO_RR_CONNECT			0x02
/* Returned from the accept BIO when an accept would have blocked */
#define BIO_RR_ACCEPT			0x03

/* These are passed by the BIO callback */
#define BIO_CB_FREE	0x01
#define BIO_CB_READ	0x02
#define BIO_CB_WRITE	0x03
#define BIO_CB_PUTS	0x04
#define BIO_CB_GETS	0x05
#define BIO_CB_CTRL	0x06

/* The callback is called before and after the underling operation,
 * The BIO_CB_RETURN flag indicates if it is after the call */
#define BIO_CB_RETURN	0x80
#define BIO_CB_return(a) ((a)|BIO_CB_RETURN))
#define BIO_cb_pre(a)	(!((a)&BIO_CB_RETURN))
#define BIO_cb_post(a)	((a)&BIO_CB_RETURN)

/* modifiers */
#define BIO_FP_READ		0x02
#define BIO_FP_WRITE		0x04
#define BIO_FP_APPEND		0x08
#define BIO_FP_TEXT		0x10

#define BIO_FLAGS_READ		0x01
#define BIO_FLAGS_WRITE		0x02
#define BIO_FLAGS_IO_SPECIAL	0x04
#define BIO_FLAGS_RWS (BIO_FLAGS_READ|BIO_FLAGS_WRITE|BIO_FLAGS_IO_SPECIAL)
#define BIO_FLAGS_SHOULD_RETRY	0x08

/* These are used in the following macros and are passed to
 * BIO_ctrl() */
#define BIO_CTRL_RESET		1  /* opt - rewind/zero etc */
#define BIO_CTRL_EOF		2  /* opt - are we at the eof */
#define BIO_CTRL_INFO		3  /* opt - extra tit-bits */
#define BIO_CTRL_SET		4  /* man - set the 'IO' type */
#define BIO_CTRL_GET		5  /* man - get the 'IO' type */
#define BIO_CTRL_PUSH		6  /* opt - internal, used to signify change */
#define BIO_CTRL_POP		7  /* opt - internal, used to signify change */
#define BIO_CTRL_GET_CLOSE	8  /* man - set the 'close' on free */
#define BIO_CTRL_SET_CLOSE	9  /* man - set the 'close' on free */
#define BIO_CTRL_PENDING	10  /* opt - is their more data buffered */
#define BIO_CTRL_FLUSH		11  /* opt - 'flush' buffered output */
#define BIO_CTRL_DUP		12  /* man - extra stuff for 'duped' BIO */
#define BIO_CTRL_WPENDING	13  /* opt - number of bytes still to write */
/* callback is int cb(BIO *bio,state,ret); */
#define BIO_CTRL_SET_CALLBACK	14  /* opt - set callback function */
#define BIO_CTRL_GET_CALLBACK	15  /* opt - set callback function */

#define BIO_CTRL_SET_FILENAME	30	/* BIO_s_file special */

/* dgram BIO stuff */
#define BIO_CTRL_DGRAM_CONNECT       31  /* BIO dgram special */
#define BIO_CTRL_DGRAM_SET_CONNECTED 32  /* allow for an externally
					  * connected socket to be
					  * passed in */ 
#define BIO_CTRL_DGRAM_SET_RECV_TIMEOUT 33 /* setsockopt, essentially */
#define BIO_CTRL_DGRAM_GET_RECV_TIMEOUT 34 /* getsockopt, essentially */
#define BIO_CTRL_DGRAM_SET_SEND_TIMEOUT 35 /* setsockopt, essentially */
#define BIO_CTRL_DGRAM_GET_SEND_TIMEOUT 36 /* getsockopt, essentially */

#define BIO_CTRL_DGRAM_GET_RECV_TIMER_EXP 37 /* flag whether the last */
#define BIO_CTRL_DGRAM_GET_SEND_TIMER_EXP 38 /* I/O operation tiemd out */
					
/* #ifdef IP_MTU_DISCOVER */
#define BIO_CTRL_DGRAM_MTU_DISCOVER       39 /* set DF bit on egress packets */
/* #endif */

#define BIO_CTRL_DGRAM_QUERY_MTU          40 /* as kernel for current MTU */
#define BIO_CTRL_DGRAM_GET_FALLBACK_MTU   47
#define BIO_CTRL_DGRAM_GET_MTU            41 /* get cached value for MTU */
#define BIO_CTRL_DGRAM_SET_MTU            42 /* set cached value for
					      * MTU. want to use this
					      * if asking the kernel
					      * fails */

#define BIO_CTRL_DGRAM_MTU_EXCEEDED       43 /* check whether the MTU
					      * was exceed in the
					      * previous write
					      * operation */

#define BIO_CTRL_DGRAM_GET_PEER           46
#define BIO_CTRL_DGRAM_SET_PEER           44 /* Destination for the data */

#define BIO_CTRL_DGRAM_SET_NEXT_TIMEOUT   45 /* Next DTLS handshake timeout to
                                              * adjust socket timeouts */
/* connect BIO stuff */
#define BIO_CONN_S_BEFORE		1
#define BIO_CONN_S_GET_IP		2
#define BIO_CONN_S_GET_PORT		3
#define BIO_CONN_S_CREATE_SOCKET	4
#define BIO_CONN_S_CONNECT		5
#define BIO_CONN_S_OK			6
#define BIO_CONN_S_BLOCKED_CONNECT	7
#define BIO_CONN_S_NBIO			8
/*#define BIO_CONN_get_param_hostname	BIO_ctrl */

#define BIO_C_SET_CONNECT			100
#define BIO_C_DO_STATE_MACHINE			101
#define BIO_C_SET_NBIO				102
#define BIO_C_SET_PROXY_PARAM			103
#define BIO_C_SET_FD				104
#define BIO_C_GET_FD				105
#define BIO_C_SET_FILE_PTR			106
#define BIO_C_GET_FILE_PTR			107
#define BIO_C_SET_FILENAME			108
#define BIO_C_SET_SSL				109
#define BIO_C_GET_SSL				110
#define BIO_C_SET_MD				111
#define BIO_C_GET_MD				112
#define BIO_C_GET_CIPHER_STATUS			113
#define BIO_C_SET_BUF_MEM			114
#define BIO_C_GET_BUF_MEM_PTR			115
#define BIO_C_GET_BUFF_NUM_LINES		116
#define BIO_C_SET_BUFF_SIZE			117
#define BIO_C_SET_ACCEPT			118
#define BIO_C_SSL_MODE				119
#define BIO_C_GET_MD_CTX			120
#define BIO_C_GET_PROXY_PARAM			121
#define BIO_C_SET_BUFF_READ_DATA		122 /* data to read first */
#define BIO_C_GET_CONNECT			123
#define BIO_C_GET_ACCEPT			124
#define BIO_C_SET_SSL_RENEGOTIATE_BYTES		125
#define BIO_C_GET_SSL_NUM_RENEGOTIATES		126
#define BIO_C_SET_SSL_RENEGOTIATE_TIMEOUT	127
#define BIO_C_FILE_SEEK				128
#define BIO_C_GET_CIPHER_CTX			129
#define BIO_C_SET_BUF_MEM_EOF_RETURN		130/*return end of input value*/
#define BIO_C_SET_BIND_MODE			131
#define BIO_C_GET_BIND_MODE			132
#define BIO_C_FILE_TELL				133
#define BIO_C_GET_SOCKS				134
#define BIO_C_SET_SOCKS				135

#define BIO_C_SET_WRITE_BUF_SIZE		136/* for BIO_s_bio */
#define BIO_C_GET_WRITE_BUF_SIZE		137
#define BIO_C_MAKE_BIO_PAIR			138
#define BIO_C_DESTROY_BIO_PAIR			139
#define BIO_C_GET_WRITE_GUARANTEE		140
#define BIO_C_GET_READ_REQUEST			141
#define BIO_C_SHUTDOWN_WR			142
#define BIO_C_NREAD0				143
#define BIO_C_NREAD				144
#define BIO_C_NWRITE0				145
#define BIO_C_NWRITE				146
#define BIO_C_RESET_READ_REQUEST		147
#define BIO_C_SET_MD_CTX			148

#define BIO_C_SET_PREFIX			149
#define BIO_C_GET_PREFIX			150
#define BIO_C_SET_SUFFIX			151
#define BIO_C_GET_SUFFIX			152

#define BIO_C_SET_EX_ARG			153
#define BIO_C_GET_EX_ARG			154

#define BIO_set_app_data(s,arg)		BIO_set_ex_data(s,0,arg)
#define BIO_get_app_data(s)		BIO_get_ex_data(s,0)

/* These are the 'types' of BIOs */
#define BIO_TYPE_NONE		0
#define BIO_TYPE_MEM		(1|0x0400)
#define BIO_TYPE_FILE		(2|0x0400)

#define BIO_TYPE_FD		(4|0x0400|0x0100)
#define BIO_TYPE_SOCKET		(5|0x0400|0x0100)
#define BIO_TYPE_NULL		(6|0x0400)
#define BIO_TYPE_SSL		(7|0x0200)
#define BIO_TYPE_MD		(8|0x0200)		/* passive filter */
#define BIO_TYPE_BUFFER		(9|0x0200)		/* filter */
#define BIO_TYPE_CIPHER		(10|0x0200)		/* filter */
#define BIO_TYPE_BASE64		(11|0x0200)		/* filter */
#define BIO_TYPE_CONNECT	(12|0x0400|0x0100)	/* socket - connect */
#define BIO_TYPE_ACCEPT		(13|0x0400|0x0100)	/* socket for accept */
#define BIO_TYPE_PROXY_CLIENT	(14|0x0200)		/* client proxy BIO */
#define BIO_TYPE_PROXY_SERVER	(15|0x0200)		/* server proxy BIO */
#define BIO_TYPE_NBIO_TEST	(16|0x0200)		/* server proxy BIO */
#define BIO_TYPE_NULL_FILTER	(17|0x0200)
#define BIO_TYPE_BER		(18|0x0200)		/* BER -> bin filter */
#define BIO_TYPE_BIO		(19|0x0400)		/* (half a) BIO pair */
#define BIO_TYPE_LINEBUFFER	(20|0x0200)		/* filter */
#define BIO_TYPE_DGRAM		(21|0x0400|0x0100)
#ifndef OPENSSL_NO_SCTP
#define BIO_TYPE_DGRAM_SCTP	(24|0x0400|0x0100)
#endif
#define BIO_TYPE_ASN1 		(22|0x0200)		/* filter */
#define BIO_TYPE_COMP 		(23|0x0200)		/* filter */

#define BIO_TYPE_DESCRIPTOR	0x0100	/* socket, fd, connect or accept */
#define BIO_TYPE_FILTER		0x0200
#define BIO_TYPE_SOURCE_SINK	0x0400

/* Function codes. */
#define BIO_F_ACPT_STATE				 100
#define BIO_F_BIO_ACCEPT				 101
#define BIO_F_BIO_BER_GET_HEADER			 102
#define BIO_F_BIO_CALLBACK_CTRL				 131
#define BIO_F_BIO_CTRL					 103
#define BIO_F_BIO_GETHOSTBYNAME				 120
#define BIO_F_BIO_GETS					 104
#define BIO_F_BIO_GET_ACCEPT_SOCKET			 105
#define BIO_F_BIO_GET_HOST_IP				 106
#define BIO_F_BIO_GET_PORT				 107
#define BIO_F_BIO_MAKE_PAIR				 121
#define BIO_F_BIO_NEW					 108
#define BIO_F_BIO_NEW_FILE				 109
#define BIO_F_BIO_NEW_MEM_BUF				 126
#define BIO_F_BIO_NREAD					 123
#define BIO_F_BIO_NREAD0				 124
#define BIO_F_BIO_NWRITE				 125
#define BIO_F_BIO_NWRITE0				 122
#define BIO_F_BIO_PUTS					 110
#define BIO_F_BIO_READ					 111
#define BIO_F_BIO_SOCK_INIT				 112
#define BIO_F_BIO_WRITE					 113
#define BIO_F_BUFFER_CTRL				 114
#define BIO_F_CONN_CTRL					 127
#define BIO_F_CONN_STATE				 115
#define BIO_F_DGRAM_SCTP_READ				 132
#define BIO_F_FILE_CTRL					 116
#define BIO_F_FILE_READ					 130
#define BIO_F_LINEBUFFER_CTRL				 129
#define BIO_F_MEM_READ					 128
#define BIO_F_MEM_WRITE					 117
#define BIO_F_SSL_NEW					 118
#define BIO_F_WSASTARTUP				 119

/* Reason codes. */
#define BIO_R_ACCEPT_ERROR				 100
#define BIO_R_BAD_FOPEN_MODE				 101
#define BIO_R_BAD_HOSTNAME_LOOKUP			 102
#define BIO_R_BROKEN_PIPE				 124
#define BIO_R_CONNECT_ERROR				 103
#define BIO_R_EOF_ON_MEMORY_BIO				 127
#define BIO_R_ERROR_SETTING_NBIO			 104
#define BIO_R_ERROR_SETTING_NBIO_ON_ACCEPTED_SOCKET	 105
#define BIO_R_ERROR_SETTING_NBIO_ON_ACCEPT_SOCKET	 106
#define BIO_R_GETHOSTBYNAME_ADDR_IS_NOT_AF_INET		 107
#define BIO_R_INVALID_ARGUMENT				 125
#define BIO_R_INVALID_IP_ADDRESS			 108
#define BIO_R_IN_USE					 123
#define BIO_R_KEEPALIVE					 109
#define BIO_R_NBIO_CONNECT_ERROR			 110
#define BIO_R_NO_ACCEPT_PORT_SPECIFIED			 111
#define BIO_R_NO_HOSTNAME_SPECIFIED			 112
#define BIO_R_NO_PORT_DEFINED				 113
#define BIO_R_NO_PORT_SPECIFIED				 114
#define BIO_R_NO_SUCH_FILE				 128
#define BIO_R_NULL_PARAMETER				 115
#define BIO_R_TAG_MISMATCH				 116
#define BIO_R_UNABLE_TO_BIND_SOCKET			 117
#define BIO_R_UNABLE_TO_CREATE_SOCKET			 118
#define BIO_R_UNABLE_TO_LISTEN_SOCKET			 119
#define BIO_R_UNINITIALIZED				 120
#define BIO_R_UNSUPPORTED_METHOD			 121
#define BIO_R_WRITE_TO_READ_ONLY_BIO			 126
#define BIO_R_WSASTARTUP				 122

/* These are passed by the BIO callback */
#define BIO_CB_FREE	0x01
#define BIO_CB_READ	0x02
#define BIO_CB_WRITE	0x03
#define BIO_CB_PUTS	0x04
#define BIO_CB_GETS	0x05
#define BIO_CB_CTRL	0x06
#define BIO_CB_RETURN	0x80

/* BIO_FILENAME_READ|BIO_CLOSE to open or close on free.
 * BIO_set_fp(in,stdin,BIO_NOCLOSE); */
#define BIO_NOCLOSE		0x00
#define BIO_CLOSE		0x01
typedef struct bio_st BIO;
typedef struct bio_method_st BIO_METHOD;
typedef void bio_info_cb(struct bio_st *, int, const char *, int, long, long);
struct bio_method_st
	{
	int type;
	const char *name;
	int (*bwrite)(BIO *, const char *, int);
	int (*bread)(BIO *, char *, int);
	int (*bputs)(BIO *, const char *);
	int (*bgets)(BIO *, char *, int);
	long (*ctrl)(BIO *, int, long, void *);
	int (*create)(BIO *);
	int (*destroy)(BIO *);
        long (*callback_ctrl)(BIO *, int, bio_info_cb *);
	};
struct bio_st
	{
	BIO_METHOD *method;
	/* bio, mode, argp, argi, argl, ret */
	long (*callback)(struct bio_st *,int,const char *,int, long,long);
	char *cb_arg; /* first argument for the callback */

	int init;
	int shutdown;
	int flags;	/* extra storage */
	int retry_reason;
	int num;
	void *ptr;
	struct bio_st *next_bio;	/* used by filter BIOs */
	struct bio_st *prev_bio;	/* used by filter BIOs */
	int references;
	unsigned long num_read;
	unsigned long num_write;
	/* @zeqi */
	//CRYPTO_EX_DATA ex_data;
	};
typedef struct bio_f_buffer_ctx_struct
	{
	/* Buffers are setup like this:
	 *
	 * <---------------------- size ----------------------->
	 * +---------------------------------------------------+
	 * | consumed | remaining          | free space        |
	 * +---------------------------------------------------+
	 * <-- off --><------- len ------->
	 */

	/* BIO *bio; */ /* this is now in the BIO struct */
	int ibuf_size;	/* how big is the input buffer */
	int obuf_size;	/* how big is the output buffer */

	char *ibuf;		/* the char array */
	int ibuf_len;		/* how many bytes are in it */
	int ibuf_off;		/* write/read offset */

	char *obuf;		/* the char array */
	int obuf_len;		/* how many bytes are in it */
	int obuf_off;		/* write/read offset */
	} BIO_F_BUFFER_CTX;

int BIO_sock_should_retry(int i);
#define BIO_set_retry_read(b) \
		BIO_set_flags(b, (BIO_FLAGS_READ|BIO_FLAGS_SHOULD_RETRY))
#define BIO_set_retry_write(b) \
		BIO_set_flags(b, (BIO_FLAGS_WRITE|BIO_FLAGS_SHOULD_RETRY))
/* BIO_s_connect() and BIO_s_socks4a_connect() */
#define BIO_set_conn_hostname(b,name) BIO_ctrl(b,BIO_C_SET_CONNECT,0,(char *)name)
#define BIO_set_conn_port(b,port) BIO_ctrl(b,BIO_C_SET_CONNECT,1,(char *)port)
#define BIO_set_nbio(b,n)	BIO_ctrl(b,BIO_C_SET_NBIO,(n),NULL)
#define BIO_set_info_callback(b,cb) (int)BIO_callback_ctrl(b,BIO_CTRL_SET_CALLBACK,cb)

BIO*	BIO_new(BIO_METHOD* type);
int	BIO_free(BIO *a);
long	BIO_ctrl(BIO *bp,int cmd,long larg,void *parg);
long	BIO_int_ctrl(BIO *bp,int cmd,long larg,int iarg);
long BIO_callback_ctrl(BIO *b, int cmd, void (*fp)(struct bio_st *, int, const char *, int, long, long));

void BIO_clear_flags(BIO *b, int flags);
void BIO_set_flags(BIO *b, int flags);

/*long BIO_ghbn_ctrl(int cmd,int iarg,char *parg);*/

#ifdef __GNUC__
#  define __bio_h__attr__ __attribute__
#else
#  define __bio_h__attr__(x)
#endif
int BIO_printf(BIO *bio, const char *format, ...)
        __bio_h__attr__((__format__(__printf__,2,3)));
int BIO_vprintf(BIO *bio, const char *format, va_list args)
        __bio_h__attr__((__format__(__printf__,2,0)));
int BIO_snprintf(char *buf, size_t n, const char *format, ...)
        __bio_h__attr__((__format__(__printf__,3,4)));
int BIO_vsnprintf(char *buf, size_t n, const char *format, va_list args)
        __bio_h__attr__((__format__(__printf__,3,0)));


BIO_METHOD *BIO_s_mem(void);
BIO_METHOD *BIO_s_connect(void);
BIO *BIO_new_socket(int sock, int close_flag);
void	BIO_free_all(BIO *a);
int	BIO_read(BIO *b, void *data, int len);
#define BIO_set_fd(b,fd,c)	BIO_int_ctrl(b,BIO_C_SET_FD,c,fd)
#define BIO_get_fd(b,c)		BIO_ctrl(b,BIO_C_GET_FD,0,(char *)c)
