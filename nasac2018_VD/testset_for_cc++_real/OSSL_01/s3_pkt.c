#include "ssl_locl.h"

int ssl3_read_n(SSL *s, int n, int max, int extend)
{
    SSL3_BUFFER *rb;
    int read_n=0;
    rb    = &(s->s3->rbuf);
    if(rb->buf == NULL)
    {
        rb->buf = (char*)malloc((SSL3_RT_MAX_PLAIN_LENGTH + SSL3_RT_HEADER_LENGTH)*sizeof(char));
        if(rb->buf == NULL)
            return -1;
        rb->len = SSL3_RT_MAX_PLAIN_LENGTH + SSL3_RT_HEADER_LENGTH;
        rb->offset = 0;
        rb->left = rb->len - rb->offset;
    }

    unsigned char* pkt;
    pkt = rb->buf+rb->offset;
    s->packet = pkt;
    s->packet_length = 0;

    int left = n;
    while(read_n<n)
    {
        left = n-read_n;
        if(s->rbio != NULL)
        {
            int i=BIO_read(s->rbio,pkt,left);
            if(i>0) {
                read_n += i;
                pkt += i;
                s->packet_length += i;
            }
            else
                return i;
        }
    }

    printf("what we have read...\n");
    int i=0;
    for (i=0;i<s->packet_length;i++) {
        printf("%x ", s->packet[i]);
    }
    printf("\n");

    s->s3->rbuf.offset += n;
    s->s3->rbuf.left = s->s3->rbuf.len - s->s3->rbuf.offset;
    return n;
}

static int ssl3_get_record(SSL *s)
{
    SSL3_RECORD *rr;
    rr= &(s->s3->rrec);
    int n = ssl3_read_n(s, SSL3_RT_HEADER_LENGTH, s->s3->rbuf.len, 0);
    if (n <= 0) return(n);
    unsigned char *p = s->packet;
    rr->type= *(p++);
    int ssl_major= *(p++);
    int ssl_minor= *(p++);
    short version=(ssl_major<<8)|ssl_minor;
    n2s(p,rr->length);
    if(rr->length > SSL3_RT_MAX_PLAIN_LENGTH || rr->length < 1+2+16) {
        printf("SSL_AD_RECORD_OVERFLOW\n");
        return -1;
    }
    n = ssl3_read_n(s, rr->length, rr->length, 0);
    if (n <= 0) return(n);
    rr->input = s->packet;
    rr->data = rr->input;
    return n+SSL3_RT_HEADER_LENGTH;
}

int ssl3_read_bytes(SSL *s, int type, unsigned char *buf, int len, int peek)
{
    printf("in s3_pkt.c, doing ssl3_read_bytes...\n");
    SSL3_RECORD *rr;
    rr = &(s->s3->rrec);
    ssl3_get_record(s);

    printf("getrecord complete, rrec->length=%d\n", rr->length);
    printf("rrec->type=%d\n", rr->type);
    if(rr->type == TLS1_RT_HEARTBEAT) {
        tls1_process_heartbeat(s);
        return -1; 
    }   
    return 0;
}
