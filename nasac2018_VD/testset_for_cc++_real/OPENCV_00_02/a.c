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
	//
	unsigned long count = 250;
	int ret = getBytes(data, count);
	return ret;
}
