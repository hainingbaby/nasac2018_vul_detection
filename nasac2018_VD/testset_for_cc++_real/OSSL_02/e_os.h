#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define closesocket(s)          close(s)
#define clear_socket_error()	errno=0
#define readsocket(s,b,n)       recv((s),(b),(n),0)
#define writesocket(s,b,n)      send((s),(b),(n),0)
#define get_last_socket_error() errno

#define SHUTDOWN2(fd)		close(fd)
