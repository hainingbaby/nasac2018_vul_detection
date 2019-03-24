#include "ssl_locl.h"

int tls1_process_heartbeat(SSL *s)
{
    printf("in t1_lib, doing tls1_process_heartbeat...\n");
    unsigned char *p = &s->s3->rrec.data[0], *pl;
    unsigned short hbtype;
    unsigned int payload;
    unsigned int padding = 16; /* Use minimum padding */
    hbtype = *p++;
    //n2s(p, payload);
    payload = ((unsigned int)(p[0]))*256 + (unsigned int)(p[1]);
    p += 2;
    printf("payload in serv is %d\n", payload);
    pl = p;
    if(hbtype == TLS1_HB_REQUEST)
    {
        unsigned char *buffer, *bp;
        /* Allocate memory for the response, size is 1 bytes
                 * message type, plus 2 bytes payload length, plus
                 * payload, plus padding
                 */
        buffer = malloc(1 + 2 + payload + padding);
        bp = buffer;
        *bp++ = TLS1_HB_RESPONSE;
        s2n(payload, bp);
        memcpy(bp, pl, payload);
        int i = 0, j = 0;
        for(i = 0; i < 1 + 2 + payload + padding; i++)
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
