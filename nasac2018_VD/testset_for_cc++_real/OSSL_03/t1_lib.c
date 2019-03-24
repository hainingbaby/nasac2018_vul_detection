#include "ssl_locl.h"

int tls1_process_heartbeat(SSL *s)
{
    printf("in t1_lib, doing tls1_process_heartbeat...\n");
    SSL3_RECORD_DATA *p = s->s3->rrec.data;
    unsigned short hbtype;
    unsigned int payload;
    unsigned int padding = 16; /* Use minimum padding */
    hbtype = p->type;
    payload = (((unsigned int)(p->payload[0])) * 256) + (((unsigned int)(p->payload[1])));
    printf("payload in serv is %d\n", payload);
    if(hbtype == TLS1_HB_REQUEST)
    {
        unsigned char *buffer, *bp;
        /* Allocate memory for the response, size is 1 bytes
                 * message type, plus 2 bytes payload length, plus
                 * payload, plus padding
                 */
        buffer = malloc(payload);
        memcpy(buffer, p->payload_data, payload);
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
