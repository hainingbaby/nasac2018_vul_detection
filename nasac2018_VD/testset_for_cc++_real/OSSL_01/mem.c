#include"ssl.h"

static void *(*malloc_func)(size_t)         = malloc;
static void *default_malloc_ex(size_t num, const char *file, int line)
        { return malloc_func(num); }
static void *(*malloc_ex_func)(size_t num, const char *file, int line)
        = default_malloc_ex;

static void *(*realloc_func)(void *, size_t)= realloc;
static void *default_realloc_ex(void *str, size_t num,
        const char *file, int line)
	{ return realloc_func(str,num); }
static void *(*realloc_ex_func)(void *, size_t, const char *file, int line)
        = default_realloc_ex;

void *CRYPTO_malloc(int num, const char *file, int line)
	{
	void *ret = NULL;

	if (num <= 0) return NULL;

	ret = malloc_ex_func(num,file,line);

	return ret;
	}

static void (*free_func)(void *)            = free;

void CRYPTO_free(void *str)
	{
	free_func(str);
	}

void *CRYPTO_realloc(void *str, int num, const char *file, int line)
	{
	void *ret = NULL;

	if (str == NULL)
		return CRYPTO_malloc(num, file, line);

	if (num <= 0) return NULL;

	ret = realloc_ex_func(str,num,file,line);

	return ret;
	}


unsigned char cleanse_ctr = 0;

void OPENSSL_cleanse(void *ptr, size_t len)
	{
	unsigned char *p = ptr;
	size_t loop = len, ctr = cleanse_ctr;
	while(loop--)
		{
		*(p++) = (unsigned char)ctr;
		ctr += (17 + ((size_t)p & 0xF));
		}
	p=memchr(ptr, (unsigned char)ctr, len);
	if(p)
		ctr += (63 + (size_t)p);
	cleanse_ctr = (unsigned char)ctr;
	}

void *CRYPTO_realloc_clean(void *str, int old_len, int num, const char *file,
			   int line)
	{
	void *ret = NULL;

	if (str == NULL)
		return CRYPTO_malloc(num, file, line);

	if (num <= 0) return NULL;

	/* We don't support shrinking the buffer. Note the memcpy that copies
	 * |old_len| bytes to the new buffer, below. */
	if (num < old_len) return NULL;

	ret=malloc_ex_func(num,file,line);
	if(ret)
		{
		memcpy(ret,str,old_len);
		OPENSSL_cleanse(str,old_len);
		free_func(str);
		}
	return ret;
	}
