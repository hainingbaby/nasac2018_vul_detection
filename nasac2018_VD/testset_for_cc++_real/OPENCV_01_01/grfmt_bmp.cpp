#include "precomp.hpp"
#include "grfmt_bmp.hpp"

namespace cv
{

    static const char *fmtSignBmp = "BM";

    /************************ BMP decoder *****************************/

    BmpDecoder::BmpDecoder()
    {
        m_signature = fmtSignBmp;
        m_offset = -1;
        m_buf_supported = true;
        m_origin = 0;
        m_bpp = 0;
        m_rle_code = BMP_RGB;
    }


    BmpDecoder::~BmpDecoder()
    {
    }


    void  BmpDecoder::close()
    {
        m_strm.close();
    }

    ImageDecoder BmpDecoder::newDecoder() const
    {
        return makePtr<BmpDecoder>();
    }

    bool  BmpDecoder::readHeader()
    {
        bool result = false;
        bool iscolor = false;

        if( !m_strm.open( m_filename ))
            return false;
        try
        {
            m_strm.skip( 10 ); //@zeqi. Skip 10 bytes in bitmap file header
            m_offset = m_strm.getDWord(); //@zeqi. Read data offset in bitmap file header

            int  size = m_strm.getDWord(); //@zeqi. Read the size of the bitmap info header, 40 in most condition

            if( size >= 36 ) //@zeqi. Goes here
            {
                m_width  = m_strm.getDWord(); //@zeqi. Read bitmap width pixel number
                m_height = m_strm.getDWord(); //@zeqi. Read bitmap height pixel number
                m_bpp    = m_strm.getDWord() >> 16; //@zeqi. Read bitmap planes(2bytes) and bitmap bit depth(2bytes), right shift to fetch bit depth
                m_rle_code = (BmpCompression)m_strm.getDWord(); //@zeqi. Read compression method, 0 represents no compression
                m_strm.skip(12); //@zeqi. Skip 12 bytes
                int clrused = m_strm.getDWord(); //@zeqi. Read palette number, ##WARNING## this could be bigger than 256
                m_strm.skip( size - 36 ); //@zeqi. Skip the remained bytes in bitmap info header

                if( m_width > 0 && m_height != 0 &&
                        (((m_bpp == 1 || m_bpp == 4 || m_bpp == 8 ||
                           m_bpp == 24 || m_bpp == 32 ) && m_rle_code == BMP_RGB) ||
                         ((m_bpp == 16 || m_bpp == 32) && (m_rle_code == BMP_RGB || m_rle_code == BMP_BITFIELDS)) ||
                         (m_bpp == 4 && m_rle_code == BMP_RLE4) ||
                         (m_bpp == 8 && m_rle_code == BMP_RLE8)))
                {
                    iscolor = true;
                    result = true;

                    if( m_bpp <= 8 ) //@zeqi. Goes here
                    {
                        memset( m_palette, 0, sizeof(m_palette)); //@zeqi. #9376 adds "CV_Assert(clrused < 256);" before this statement
                        if (clrused < 256)
                            m_strm.getBytes( m_palette, (clrused == 0 ? 1 << m_bpp : clrused) * 4 ); //@zeqi. Read palette from bitmap file to m_palette. ##WARNING## param 2 is tainted in line 106.
                        else
                            return false;
                        iscolor = IsColorPalette( m_palette, m_bpp );
                    }
                }
            }
        }
        catch(...)
        {
        }
        // in 32 bit case alpha channel is used - so require CV_8UC4 type
        m_type = iscolor ? (m_bpp == 32 ? CV_8UC4 : CV_8UC3 ) : CV_8UC1;
        m_origin = m_height > 0 ? IPL_ORIGIN_BL : IPL_ORIGIN_TL;
        m_height = std::abs(m_height);

        if( !result )
        {
            m_offset = -1;
            m_width = m_height = -1;
            m_strm.close();
        }
        return result;
    }

}