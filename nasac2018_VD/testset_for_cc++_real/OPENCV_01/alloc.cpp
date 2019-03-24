#include "precomp.hpp"

#ifdef HAVE_POSIX_MEMALIGN
#include <stdlib.h>
#elif defined HAVE_MALLOC_H
#include <malloc.h>
#endif

/* the alignment of all the allocated buffers */
#define  CV_MALLOC_ALIGN    64

namespace cv {

/** @brief Aligns a pointer to the specified number of bytes.

The function returns the aligned pointer of the same type as the input pointer:
\f[\texttt{(_Tp*)(((size_t)ptr + n-1) & -n)}\f]
@param ptr Aligned pointer.
@param n Alignment size that must be a power of two.
 */
template<typename _Tp> static inline _Tp* alignPtr(_Tp* ptr, int n=(int)sizeof(_Tp))
{
    return (_Tp*)(((size_t)ptr + n-1) & -n);
}


static void* OutOfMemoryError(size_t size)
{
    return 0;
}


void* fastMalloc( size_t size )
{
#ifdef HAVE_POSIX_MEMALIGN
    void* ptr = NULL;
    if(posix_memalign(&ptr, CV_MALLOC_ALIGN, size))
        ptr = NULL;
    if(!ptr)
        return OutOfMemoryError(size);
    return ptr;
#elif defined HAVE_MEMALIGN
    void* ptr = memalign(CV_MALLOC_ALIGN, size);
    if(!ptr)
        return OutOfMemoryError(size);
    return ptr;
#else
    uchar* udata = (uchar*)malloc(size + sizeof(void*) + CV_MALLOC_ALIGN);
    if(!udata)
        return OutOfMemoryError(size);
    uchar** adata = alignPtr((uchar**)udata + 1, CV_MALLOC_ALIGN);
    adata[-1] = udata;
    return adata;
#endif
}

void fastFree(void* ptr)
{
#if defined HAVE_POSIX_MEMALIGN || defined HAVE_MEMALIGN
    free(ptr);
#else
    if(ptr)
    {
        uchar* udata = ((uchar**)ptr)[-1];
        free(udata);
    }
#endif
}

} // namespace

CV_EXTERN_C void* cvAlloc( size_t size )
{
    return cv::fastMalloc( size );
}

CV_EXTERN_C void cvFree_( void* ptr )
{
    cv::fastFree( ptr );
}

/* End of file. */
