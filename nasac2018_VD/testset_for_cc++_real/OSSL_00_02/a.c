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

void heap_buffer_over_read_sock_to_memcpy(unsigned short len)
{
    char * data;
    data = NULL;
    data = (char *)malloc(50*sizeof(char));
    memset(data, 'A', 50-1); 
    data[50-1] = '\0'; 
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
    //
    unsigned short good = 40;
    heap_buffer_over_read_sock_to_memcpy(good);
    return 0;
}