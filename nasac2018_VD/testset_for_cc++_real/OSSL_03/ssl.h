#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bio.h"

// heartbeat
#define TLS1_RT_HEARTBEAT 24
#define TLS1_HB_REQUEST     1
#define TLS1_HB_RESPONSE    2
#define SSL3_RT_HEADER_LENGTH           5

// ssl3
#define SSL3_RT_APPLICATION_DATA    23
#define SSL3_RT_MAX_PLAIN_LENGTH        16384

// OSSL_03 semantic information
// 1byte record type, 2bytes ssl version, 2bytes record data length
typedef struct ssl3_record_header_st
{
    unsigned char type;
    unsigned char ver[2];
    unsigned char len[2];
} SSL3_RECORD_HEADER;
// OSSL_03 semantic information
// 1byte heartbeat type, 2bytes payload length, n bytes payload data, 16bytes padding
typedef struct ssl3_record_data_st
{
    unsigned char type;
    unsigned char payload[2];
    unsigned char *payload_data;
    unsigned char padding[16];
} SSL3_RECORD_DATA;



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
    /*r */  int type;               /* type of record */
    /*rw*/  unsigned int length;    /* How many bytes available */
    /*r */  unsigned int off;       /* read/write offset into 'buf' */
    // /*rw*/  unsigned char *data;    /* pointer to the record data */
    // OSSL_03, use structure SSL3_RECORD_DATA to carry senmantic information
    SSL3_RECORD_DATA *data;         /* pointer to the record data */
    /*rw*/  unsigned char *input;   /* where the decode bytes are */
    /*r */  unsigned char *comp;    /* only used with decompression - malloc()ed */
    /*r */  unsigned long epoch;    /* epoch number, needed by DTLS1 */
    /*r */  unsigned char seq_num[8]; /* sequence number, needed by DTLS1 */
} SSL3_RECORD;

typedef struct ssl3_state_st
{
    SSL3_BUFFER rbuf;   /* read IO goes into here */
    SSL3_BUFFER wbuf;   /* write IO goes into here */
    SSL3_RECORD rrec;   /* each decoded record goes in here */
    SSL3_RECORD wrec;   /* goes out from here */
} SSL3_STATE;

typedef struct ssl_st SSL;

struct ssl_st
{
    struct ssl3_state_st *s3; /* SSLv3 variables */
    BIO *rbio;
    unsigned char *packet;
    unsigned int packet_length;
};

void SSL_set_bio(SSL *s, BIO *rbio, BIO *wbio);
SSL *SSL_new(void);
int SSL_read(SSL *s, void *buf, int num);
