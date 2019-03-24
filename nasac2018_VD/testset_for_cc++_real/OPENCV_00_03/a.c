#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int getBytes(void *buffer, int count)
{
	unsigned char *data = (unsigned char*) buffer;
	unsigned char *src = "AAAA";
	int len = strlen(src);
	int ret = 0;
	// 
	assert(count < 256);
	while(count >= 0)
	{
		// 
		memcpy((unsigned char*)data, src, len);
		data += len;
		count -= len;
		ret += len;
	}
	return ret;
}

int main(int argc, char **argv)
{
	unsigned char data[256];
	unsigned char buf[2];
	unsigned long count = 1024;
    if (argc < 2)
    	exit(0);
    FILE *m_file = fopen(argv[1], "rb");
    if (!m_file)
    {
        exit(0);
    }
    // 
    fread(buf, 1, 2, m_file);
    count = ((unsigned int)buf[1])*256+(unsigned int)buf[0];
	int ret = getBytes(data, count);
	return ret;
}
