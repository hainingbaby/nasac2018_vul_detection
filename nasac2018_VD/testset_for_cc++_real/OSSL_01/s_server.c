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
#include "ssl.h"


static SSL_CTX *s_ctx = NULL; // server
static SSL *s_ssl = NULL;

int main(int argc, char* argv[])
{
    BIO *sbio;

    if (argc!=3) {
        printf("usage: xxx <ip> <port>");
        exit(0);
    }
    char* ip = argv[1];
    int port = atoi(argv[2]);
    
    struct sockaddr_in server_addr;
    bzero( &server_addr, sizeof( server_addr ) );    
    // init socket
    server_addr.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &server_addr.sin_addr );
    server_addr.sin_port = htons( port );
    int sock_fd = socket( PF_INET, SOCK_STREAM, 0 );
    if(sock_fd<0)
        return -1;
    // bind
    int ret = bind(sock_fd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr));
    if(ret<0)
        return -1;
    // listen
    if(listen(sock_fd, 10) == -1)
        return -1;
    // accept
    int from=sizeof(struct sockaddr_in);
    struct sockaddr_in client_addr;
    int new_fd=accept(sock_fd,(struct sockaddr *)&client_addr, &from);
    // init bio_socket
    sbio=BIO_new_socket(new_fd,BIO_NOCLOSE);

    // init meth
    const SSL_METHOD *meth = NULL;
    meth = SSLv3_method();
    // init ssl ctx
    SSL_CTX *ctx;
    ctx = SSL_CTX_new(meth);
    // init ssl
    SSL *con = NULL;
    con=SSL_new(ctx);
    
    // set bio
    SSL_set_bio(con,sbio,sbio);
    
    //read ssl
    char buf[4096];
    int bufsize = 4096;
    SSL_read(con, buf, bufsize);
    
/*
    const SSL_METHOD *meth = NULL;
    // init meth
    meth = SSLv3_method();
    // init ctx
    s_ctx = SSL_CTX_new(meth);
    s_ssl = SSL_new(s_ctx);

    //s_ssl->method->ssl_read(s_ssl, buf, len);
*/

    return 0;
}
