#include "precomp.hpp"
#include "grfmt_hdr.hpp"

namespace cv
{

    HdrDecoder::HdrDecoder()
    {
        m_signature = "#?RGBE";
        m_signature_alt = "#?RADIANCE";
        file = NULL;
        m_type = CV_32FC3;
    }

    HdrDecoder::~HdrDecoder()
    {
    }

    size_t HdrDecoder::signatureLength() const
    {
        return m_signature.size() > m_signature_alt.size() ?
               m_signature.size() : m_signature_alt.size();
    }

    bool  HdrDecoder::readHeader()
    {
        //@zeqi. omit
        return true;
    }

    bool HdrDecoder::checkSignature( const String &signature ) const
    {
        if(signature.size() >= m_signature.size() &&
                (!memcmp(signature.c_str(), m_signature.c_str(), m_signature.size()) ||
                 !memcmp(signature.c_str(), m_signature_alt.c_str(), m_signature_alt.size())))
            return true;
        return false;
    }

    ImageDecoder HdrDecoder::newDecoder() const
    {
        return makePtr<HdrDecoder>();
    }
}