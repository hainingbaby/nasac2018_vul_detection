#ifndef _GRFMT_HDR_H_
#define _GRFMT_HDR_H_

#include "grfmt_base.hpp"

namespace cv
{

    enum HdrCompression
    {
        HDR_NONE = 0,
        HDR_RLE = 1
    };

    // Radiance rgbe (.hdr) reader
    class HdrDecoder : public BaseImageDecoder
    {
    public:
        HdrDecoder();
        ~HdrDecoder();
        bool readHeader();
        bool checkSignature( const String &signature ) const;
        ImageDecoder newDecoder() const;
        size_t signatureLength() const;
    protected:
        String m_signature_alt;
        FILE *file;
    };

}


#endif/*_GRFMT_HDR_H_*/