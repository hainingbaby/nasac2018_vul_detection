#include <errno.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>

void heap_buffer_over_read_sock_to_memcpy(unsigned short len)
{
    char * data;
    data = NULL;
    data = (char *)malloc(50*sizeof(char));
    memset(data, 'A', 50-1); 
    data[50-1] = '\0'; 
    // 
    assert(len <= 50);
    {
        char dest[65535];
        memset(dest, 'C', 65535);
        dest[100-1] = '\0'; 
        /* */
        memcpy(dest, data, len);
        dest[65534] = '\0';
        printf("%s\n", dest);
        free(data);
    }
}

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

int main(int argc, char * argv[])
{
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
    // recv
    unsigned char uc;
    recv(new_fd, &uc, 1, 0);
    heap_buffer_over_read_sock_to_memcpy((unsigned short)uc);
    return 0;
}