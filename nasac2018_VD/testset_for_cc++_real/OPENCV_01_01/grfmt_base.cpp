#include "grfmt_base.hpp"
#include "bitstrm.hpp"

namespace cv
{

BaseImageDecoder::BaseImageDecoder()
{
    m_width = m_height = 0;
    m_type = -1;
    m_buf_supported = false;
    m_scale_denom = 1;
}

bool BaseImageDecoder::setSource( const String& filename )
{
    m_filename = filename;
    //m_buf.release();
    return true;
}

size_t BaseImageDecoder::signatureLength() const
{
    return m_signature.size();
}

bool BaseImageDecoder::checkSignature( const String& signature ) const
{
    size_t len = signatureLength();
    return signature.size() >= len && memcmp( signature.c_str(), m_signature.c_str(), len ) == 0;
}

int BaseImageDecoder::setScale( const int& scale_denom )
{
    int temp = m_scale_denom;
    m_scale_denom = scale_denom;
    return temp;
}

ImageDecoder BaseImageDecoder::newDecoder() const
{
    return ImageDecoder();
}

}

/* End of file. */
