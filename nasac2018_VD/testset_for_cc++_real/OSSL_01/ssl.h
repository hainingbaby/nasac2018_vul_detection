#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "crypto.h"
#include "bio.h"

// heartbeat
#define TLS1_RT_HEARTBEAT 24
#define TLS1_HB_REQUEST		1
#define TLS1_HB_RESPONSE	2
#define SSL3_RT_HEADER_LENGTH			5


#define SSL_ERROR_NONE			0
#define SSL_ERROR_SSL			1
#define SSL_ERROR_WANT_READ		2
#define SSL_ERROR_WANT_WRITE		3
#define SSL_ERROR_WANT_X509_LOOKUP	4
#define SSL_ERROR_SYSCALL		5 /* look at error stack/return value/errno */
#define SSL_ERROR_ZERO_RETURN		6
#define SSL_ERROR_WANT_CONNECT		7
#define SSL_ERROR_WANT_ACCEPT		8

#define SSL_CTRL_NEED_TMP_RSA			1
#define SSL_CTRL_SET_TMP_RSA			2
#define SSL_CTRL_SET_TMP_DH			3
#define SSL_CTRL_SET_TMP_ECDH			4
#define SSL_CTRL_SET_TMP_RSA_CB			5
#define SSL_CTRL_SET_TMP_DH_CB			6
#define SSL_CTRL_SET_TMP_ECDH_CB		7

#define SSL_CTRL_GET_SESSION_REUSED		8
#define SSL_CTRL_GET_CLIENT_CERT_REQUEST	9
#define SSL_CTRL_GET_NUM_RENEGOTIATIONS		10
#define SSL_CTRL_CLEAR_NUM_RENEGOTIATIONS	11
#define SSL_CTRL_GET_TOTAL_RENEGOTIATIONS	12
#define SSL_CTRL_GET_FLAGS			13
#define SSL_CTRL_EXTRA_CHAIN_CERT		14

#define SSL_CTRL_SET_MSG_CALLBACK               15
#define SSL_CTRL_SET_MSG_CALLBACK_ARG           16

/* only applies to datagram connections */
#define SSL_CTRL_SET_MTU                17
/* Stats */
#define SSL_CTRL_SESS_NUMBER			20
#define SSL_CTRL_SESS_CONNECT			21
#define SSL_CTRL_SESS_CONNECT_GOOD		22
#define SSL_CTRL_SESS_CONNECT_RENEGOTIATE	23
#define SSL_CTRL_SESS_ACCEPT			24
#define SSL_CTRL_SESS_ACCEPT_GOOD		25
#define SSL_CTRL_SESS_ACCEPT_RENEGOTIATE	26
#define SSL_CTRL_SESS_HIT			27
#define SSL_CTRL_SESS_CB_HIT			28
#define SSL_CTRL_SESS_MISSES			29
#define SSL_CTRL_SESS_TIMEOUTS			30
#define SSL_CTRL_SESS_CACHE_FULL		31
#define SSL_CTRL_OPTIONS			32
#define SSL_CTRL_MODE				33

#define SSL_CTRL_GET_READ_AHEAD			40
#define SSL_CTRL_SET_READ_AHEAD			41
#define SSL_CTRL_SET_SESS_CACHE_SIZE		42
#define SSL_CTRL_GET_SESS_CACHE_SIZE		43
#define SSL_CTRL_SET_SESS_CACHE_MODE		44
#define SSL_CTRL_GET_SESS_CACHE_MODE		45

#define SSL_CTRL_GET_MAX_CERT_LIST		50
#define SSL_CTRL_SET_MAX_CERT_LIST		51

#define SSL_CTRL_SET_MAX_SEND_FRAGMENT		52

/* see tls1.h for macros based on these */
#ifndef OPENSSL_NO_TLSEXT
#define SSL_CTRL_SET_TLSEXT_SERVERNAME_CB	53
#define SSL_CTRL_SET_TLSEXT_SERVERNAME_ARG	54
#define SSL_CTRL_SET_TLSEXT_HOSTNAME		55
#define SSL_CTRL_SET_TLSEXT_DEBUG_CB		56
#define SSL_CTRL_SET_TLSEXT_DEBUG_ARG		57
#define SSL_CTRL_GET_TLSEXT_TICKET_KEYS		58
#define SSL_CTRL_SET_TLSEXT_TICKET_KEYS		59
#define SSL_CTRL_SET_TLSEXT_OPAQUE_PRF_INPUT	60
#define SSL_CTRL_SET_TLSEXT_OPAQUE_PRF_INPUT_CB	61
#define SSL_CTRL_SET_TLSEXT_OPAQUE_PRF_INPUT_CB_ARG 62
#define SSL_CTRL_SET_TLSEXT_STATUS_REQ_CB	63
#define SSL_CTRL_SET_TLSEXT_STATUS_REQ_CB_ARG	64
#define SSL_CTRL_SET_TLSEXT_STATUS_REQ_TYPE	65
#define SSL_CTRL_GET_TLSEXT_STATUS_REQ_EXTS	66
#define SSL_CTRL_SET_TLSEXT_STATUS_REQ_EXTS	67
#define SSL_CTRL_GET_TLSEXT_STATUS_REQ_IDS	68
#define SSL_CTRL_SET_TLSEXT_STATUS_REQ_IDS	69
#define SSL_CTRL_GET_TLSEXT_STATUS_REQ_OCSP_RESP	70
#define SSL_CTRL_SET_TLSEXT_STATUS_REQ_OCSP_RESP	71

#define SSL_CTRL_SET_TLSEXT_TICKET_KEY_CB	72

#define SSL_CTRL_SET_TLS_EXT_SRP_USERNAME_CB	75
#define SSL_CTRL_SET_SRP_VERIFY_PARAM_CB		76
#define SSL_CTRL_SET_SRP_GIVE_CLIENT_PWD_CB		77

#define SSL_CTRL_SET_SRP_ARG		78
#define SSL_CTRL_SET_TLS_EXT_SRP_USERNAME		79
#define SSL_CTRL_SET_TLS_EXT_SRP_STRENGTH		80
#define SSL_CTRL_SET_TLS_EXT_SRP_PASSWORD		81
#ifndef OPENSSL_NO_HEARTBEATS
#define SSL_CTRL_TLS_EXT_SEND_HEARTBEAT				85
#define SSL_CTRL_GET_TLS_EXT_HEARTBEAT_PENDING		86
#define SSL_CTRL_SET_TLS_EXT_HEARTBEAT_NO_REQUESTS	87
#endif
#endif

#define DTLS_CTRL_GET_TIMEOUT		73
#define DTLS_CTRL_HANDLE_TIMEOUT	74
#define DTLS_CTRL_LISTEN			75

#define SSL_CTRL_GET_RI_SUPPORT			76
#define SSL_CTRL_CLEAR_OPTIONS			77
#define SSL_CTRL_CLEAR_MODE			78

#define SSL_CTRL_GET_EXTRA_CHAIN_CERTS		82
#define SSL_CTRL_CLEAR_EXTRA_CHAIN_CERTS	83

//ssl3
#define SSL3_RT_APPLICATION_DATA	23
#define SSL3_RT_MAX_PLAIN_LENGTH        16384

typedef struct ssl3_buffer_st
{
    unsigned char *buf;     /* at least SSL3_RT_MAX_PACKET_SIZE bytes,
	                         * see ssl3_setup_buffers() */
    size_t len;             /* buffer size */
    int offset;             /* where to 'copy from' */
    int left;               /* how many bytes left */
} SSL3_BUFFER;

typedef struct ssl3_record_st
{
    /*r */	int type;               /* type of record */
    /*rw*/	unsigned int length;    /* How many bytes available */
    /*r */	unsigned int off;       /* read/write offset into 'buf' */
    /*rw*/	unsigned char *data;    /* pointer to the record data */
    /*rw*/	unsigned char *input;   /* where the decode bytes are */
    /*r */	unsigned char *comp;    /* only used with decompression - malloc()ed */
    /*r */  unsigned long epoch;    /* epoch number, needed by DTLS1 */
    /*r */  unsigned char seq_num[8]; /* sequence number, needed by DTLS1 */
} SSL3_RECORD;

typedef struct ssl3_state_st
{
    SSL3_BUFFER rbuf;	/* read IO goes into here */
    SSL3_BUFFER wbuf;	/* write IO goes into here */
    SSL3_RECORD rrec;	/* each decoded record goes in here */
    SSL3_RECORD wrec;	/* goes out from here */
} SSL3_STATE;

typedef struct ssl_st SSL;

typedef struct ssl_method_st {
	int (*ssl_read)(SSL *s,void *buf,int len);
	int (*ssl_read_bytes)(SSL *s, int type, unsigned char *buf, int len, 
		int peek);
} SSL_METHOD;

typedef struct ssl_ctx_st {
	const SSL_METHOD *method;
} SSL_CTX;

struct ssl_st
{
    const SSL_METHOD *method; /* SSLv3 */
    struct ssl3_state_st *s3; /* SSLv3 variables */
    SSL_CTX *ctx;
    BIO *rbio;
    BIO *wbio;
    BIO *bbio;
    unsigned char *packet;
    unsigned int packet_length;
};

void SSL_set_bio(SSL *s,BIO *rbio,BIO *wbio);
SSL *SSL_new(SSL_CTX *ctx);
SSL_CTX *SSL_CTX_new(const SSL_METHOD *meth);
int SSL_read(SSL *s,void *buf,int num);
const SSL_METHOD *SSLv3_method(void);
