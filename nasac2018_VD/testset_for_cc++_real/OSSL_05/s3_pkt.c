#include "ssl_locl.h"
#include "e_os.h"

int ssl3_read_bytes(SSL *s, int type, unsigned char *buf, int len, int peek)
{
    printf("in s3_pkt.c, doing ssl3_read_bytes...\n");

    // unfold function ssl3_get_record(SSL *s)
    // read rrec header
    SSL3_RECORD_HEADER rrec_header;
    recv(s->rbio_fd, &rrec_header.type, 1, 0);
    recv(s->rbio_fd, rrec_header.ver, 2, 0);
    recv(s->rbio_fd, rrec_header.len, 2, 0);

    s->rrec_type = (int) rrec_header.type;
    short version = (rrec_header.ver[0] << 8) | rrec_header.ver[1];
    s->rrec_length = ((unsigned int)(rrec_header.len[0] << 8)) | ((unsigned int)(rrec_header.len[1]));
    if(s->rrec_length > SSL3_RT_MAX_PLAIN_LENGTH || s->rrec_length < 1 + 2 + 16)
    {
        printf("SSL_AD_RECORD_OVERFLOW\n");
        return -1;
    }

    // read rrec data
    int payloadlen = s->rrec_length - 1 - 2 - 16;
    s->hb_payload_data = (unsigned char *)malloc(payloadlen * sizeof(unsigned char));
    if (s->hb_payload_data == NULL) return -1;
    recv(s->rbio_fd, &s->hb_type, 1, 0);
    recv(s->rbio_fd, s->hb_payload, 2, 0);
    recv(s->rbio_fd, s->hb_payload_data, payloadlen, 0);
    recv(s->rbio_fd, s->hb_padding, 16, 0);

    printf("getrecord complete, rrec->length=%d\n", s->rrec_length);
    printf("rrec->type=%d\n", s->rrec_type);
    if(s->rrec_type == TLS1_RT_HEARTBEAT)
    {
        // unfold function tls1_process_heartbeat(SSL* s)
        printf("in t1_lib, doing tls1_process_heartbeat...\n");
        unsigned short hbtype;
        unsigned int payload;
        unsigned int padding = 16; /* Use minimum padding */
        hbtype = s->hb_type;
        payload = (((unsigned int)(s->hb_payload[0])) << 8) | (((unsigned int)(s->hb_payload[1])));
        printf("payload in serv is %d\n", payload);
        if(hbtype == TLS1_HB_REQUEST)
        {
            unsigned char *buffer, *bp;
            /* Allocate memory for the response, size is 1 bytes
                     * message type, plus 2 bytes payload length, plus
                     * payload, plus padding
                     */
            buffer = malloc(payload);
            // heap over read
            memcpy(buffer, s->hb_payload_data, payload);
            int i = 0, j = 0;
            for(i = 0; i < payload; i++)
            {
                j = (j + 1) % 32;
                if(j == 0)
                    printf("\n");
                printf("%x ", buffer[i]);
            }
            return payload;
        }
        return 0;
    }
    return 0;
}
