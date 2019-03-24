#include "ssl_locl.h"
#include "e_os.h"

static int sock_read(BIO *b, char *out, int outl)
{
    int ret = 0;

    if (out != NULL)
    {   
        clear_socket_error();
        ret = readsocket(b->num, out, outl);
    }
    return(ret);
}

// OSSL_03 eliminates complex function ssl3_read_n
/*
int ssl3_read_n(SSL *s, int n, int max, int extend)
{
    SSL3_BUFFER *rb;
    int read_n = 0;
    rb    = &(s->s3->rbuf);
    if(rb->buf == NULL)
    {
        rb->buf = (char *)malloc((SSL3_RT_MAX_PLAIN_LENGTH + SSL3_RT_HEADER_LENGTH) * sizeof(char));
        if(rb->buf == NULL)
            return -1;
        rb->len = SSL3_RT_MAX_PLAIN_LENGTH + SSL3_RT_HEADER_LENGTH;
        rb->offset = 0;
        rb->left = rb->len - rb->offset;
    }

    unsigned char *pkt;
    pkt = rb->buf + rb->offset;
    s->packet = pkt;
    s->packet_length = 0;

    int left = n;
    while(read_n < n)
    {
        left = n - read_n;
        if(s->rbio != NULL)
        {
            int i = sock_read(s->rbio, pkt, left);
            printf("read %d bytes\n", i);
            if(i > 0)
            {
                read_n += i;
                pkt += i;
                s->packet_length += i;
            }
            else
                return i;
        }
    }

    printf("what we have read...\n");
    int i = 0;
    for (i = 0; i < s->packet_length; i++)
    {
        printf("%x ", s->packet[i]);
    }
    printf("\n");

    s->s3->rbuf.offset += n;
    s->s3->rbuf.left = s->s3->rbuf.len - s->s3->rbuf.offset;
    return n;
}
*/

// OSSL_03 modifies this func to carry more semantic info
static int ssl3_get_record(SSL *s)
{
    // read rrec header
    SSL3_RECORD_HEADER rrec_header;
    sock_read(s->rbio, &rrec_header.type, 1);
    sock_read(s->rbio, rrec_header.ver, 2);
    sock_read(s->rbio, rrec_header.len, 2);

    SSL3_RECORD *rr = &(s->s3->rrec);
    rr->type = (int) rrec_header.type;
	short version = (rrec_header.ver[0] << 8) | rrec_header.ver[1];
	rr->length = ((unsigned int)(rrec_header.len[0] << 8)) | ((unsigned int)(rrec_header.len[1]));
    if(rr->length > SSL3_RT_MAX_PLAIN_LENGTH || rr->length <1+2+16)
    {
        printf("SSL_AD_RECORD_OVERFLOW\n");
        return -1;
    }
	
	// read rrec data
    int payloadlen = s->s3->rrec.length - 1 - 2 - 16;
    SSL3_RECORD_DATA *rrec_data = (SSL3_RECORD_DATA*)malloc(sizeof(SSL3_RECORD_DATA));
    if (rrec_data == NULL) return -1;
    rrec_data->payload_data = (unsigned char *)malloc(payloadlen * sizeof(unsigned char));
    if (rrec_data->payload_data == NULL) return -1;
    sock_read(s->rbio, &rrec_data->type, 1);
    sock_read(s->rbio, rrec_data->payload, 2);
    sock_read(s->rbio, rrec_data->payload_data, payloadlen);
    sock_read(s->rbio, rrec_data->padding, 16);

    rr->data = rrec_data;
    return rr->length + SSL3_RT_HEADER_LENGTH;
}

int ssl3_read_bytes(SSL *s, int type, unsigned char *buf, int len, int peek)
{
    printf("in s3_pkt.c, doing ssl3_read_bytes...\n");
    SSL3_RECORD *rr;
    rr = &(s->s3->rrec);
    ssl3_get_record(s);

    printf("getrecord complete, rrec->length=%d\n", rr->length);
    printf("rrec->type=%d\n", rr->type);
    if(rr->type == TLS1_RT_HEARTBEAT)
    {
        tls1_process_heartbeat(s);
        return -1;
    }
    return 0;
}
