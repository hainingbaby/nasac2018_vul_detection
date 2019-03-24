#ifndef _GRFMT_BASE_H_
#define _GRFMT_BASE_H_

#include "utils.hpp"
#include "bitstrm.hpp"

/****************************************************************************************\
*                                  Image type (IplImage)                                 *
\****************************************************************************************/



/*
 * The following definitions (until #endif)
 * is an extract from IPL headers.
 * Copyright (c) 1995 Intel Corporation.
 */
#define IPL_DEPTH_SIGN 0x80000000

#define IPL_DEPTH_1U     1
#define IPL_DEPTH_8U     8
#define IPL_DEPTH_16U   16
#define IPL_DEPTH_32F   32

#define IPL_DEPTH_8S  (IPL_DEPTH_SIGN| 8)
#define IPL_DEPTH_16S (IPL_DEPTH_SIGN|16)
#define IPL_DEPTH_32S (IPL_DEPTH_SIGN|32)

#define IPL_DATA_ORDER_PIXEL  0
#define IPL_DATA_ORDER_PLANE  1

#define IPL_ORIGIN_TL 0
#define IPL_ORIGIN_BL 1

#define IPL_ALIGN_4BYTES   4
#define IPL_ALIGN_8BYTES   8
#define IPL_ALIGN_16BYTES 16
#define IPL_ALIGN_32BYTES 32

#define IPL_ALIGN_DWORD   IPL_ALIGN_4BYTES
#define IPL_ALIGN_QWORD   IPL_ALIGN_8BYTES

#define IPL_BORDER_CONSTANT   0
#define IPL_BORDER_REPLICATE  1
#define IPL_BORDER_REFLECT    2
#define IPL_BORDER_WRAP       3

namespace cv
{
	class BaseImageDecoder;
	typedef Ptr<BaseImageDecoder> ImageDecoder;

    ///////////////////////////////// base class for decoders ////////////////////////
    class BaseImageDecoder
    {
    public:
        BaseImageDecoder();
        virtual ~BaseImageDecoder() {}

        int width() const
        {
            return m_width;
        }
        int height() const
        {
            return m_height;
        }
        virtual int type() const
        {
            return m_type;
        }

        virtual bool setSource( const String &filename );
        virtual int setScale( const int &scale_denom );
        virtual bool readHeader() = 0;

        /// Called after readData to advance to the next page, if any.
        virtual bool nextPage()
        {
            return false;
        }

        virtual size_t signatureLength() const;
        virtual bool checkSignature( const String &signature ) const;
        virtual ImageDecoder newDecoder() const;

    protected:
        int  m_width;  // width  of the image ( filled by readHeader )
        int  m_height; // height of the image ( filled by readHeader )
        int  m_type;
        int  m_scale_denom;
        String m_filename;
        String m_signature;
        //Mat m_buf; //@zeqi. We don't need m_buf in this case
        bool m_buf_supported;
    };
}

#endif