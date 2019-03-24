#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "ssl_locl.h"

/* OSSL_06 at most 2 level function call */

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: xxx <ip> <port>");
        exit(0);
    }
    char *ip = argv[1];
    int port = atoi(argv[2]);

    // init socket
    struct sockaddr_in server_addr;
    bzero( &server_addr, sizeof( server_addr ) );
    server_addr.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &server_addr.sin_addr );
    server_addr.sin_port = htons( port );
    int sock_fd = socket( PF_INET, SOCK_STREAM, 0 );
    if(sock_fd < 0)
        return -1;
    // bind
    int ret = bind(sock_fd, (struct sockaddr *)(&server_addr), sizeof(struct sockaddr));
    if(ret < 0)
        return -1;
    // listen
    if(listen(sock_fd, 10) == -1)
        return -1;
    // accept
    int from = sizeof(struct sockaddr_in);
    struct sockaddr_in client_addr;
    int new_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &from);
    printf("accepted... fd=%d\n", new_fd);    

    // init ssl
    SSL *s_ssl = NULL;
    s_ssl = SSL_new();

	// set fd to flattened ssl structure
	s_ssl->rbio_fd = new_fd;

    char buf[4096];
    int bufsize = 4096;
    // read ssl function unfold
    ssl3_read_bytes(s_ssl, SSL3_RT_APPLICATION_DATA, buf, bufsize, 0);
    
    return 0;
}
