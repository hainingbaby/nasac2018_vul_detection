#include "e_os.h"
#include "ssl.h"

#define n2s(c,s)	((s=(((unsigned int)(c[0]))<< 8)| \
			    (((unsigned int)(c[1]))    )),c+=2)
#define s2n(s,c)	((c[0]=(unsigned char)(((s)>> 8)&0xff), \
			  c[1]=(unsigned char)(((s)    )&0xff)),c+=2)

int ssl3_read_bytes(SSL *s, int type, unsigned char *buf, int len, int peek);
int tls1_process_heartbeat(SSL *s);
