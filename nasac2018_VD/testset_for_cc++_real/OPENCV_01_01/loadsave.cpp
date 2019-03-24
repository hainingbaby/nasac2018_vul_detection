#include "precomp.hpp"
#include "grfmts.hpp"
#include "utils.hpp"
#undef min
#undef max
#include <iostream>
#include <fstream>

namespace cv
{
    enum { LOAD_CVMAT = 0, LOAD_IMAGE = 1, LOAD_MAT = 2 };

    /**
    * @struct ImageCodecInitializer
    *
    * Container which stores the registered codecs to be used by OpenCV
    */
    struct ImageCodecInitializer
    {
        /**
         * Default Constructor for the ImageCodeInitializer
        */
        ImageCodecInitializer()
        {
            /// BMP Support
            decoders.push_back( makePtr<BmpDecoder>() );
            decoders.push_back( makePtr<HdrDecoder>() );
        }

        std::vector<Ptr<BaseImageDecoder> > decoders;
    };

    static ImageCodecInitializer codecs;
    /**
    * Find the decoders
    *
    * @param[in] filename File to search
    *
    * @return Image decoder to parse image file.
    */
    static Ptr<BaseImageDecoder> findDecoder( const String &filename )
    {

        size_t i, maxlen = 0;

        /// iterate through list of registered codecs
        for( i = 0; i < codecs.decoders.size(); i++ )
        {
            size_t len = codecs.decoders[i]->signatureLength();
            maxlen = std::max(maxlen, len);
        }

        /// Open the file
        FILE *f = fopen( filename.c_str(), "rb" );

        /// in the event of a failure, return an empty image decoder
        if( !f )
            return Ptr<BaseImageDecoder>();

        // read the file signature
        String signature(maxlen, ' ');
        maxlen = fread( (void *)signature.c_str(), 1, maxlen, f );
        fclose(f);
        signature = signature.substr(0, maxlen);

        /// compare signature against all decoders
        for( i = 0; i < codecs.decoders.size(); i++ )
        {
            if( codecs.decoders[i]->checkSignature(signature) )
                return codecs.decoders[i]->newDecoder();
        }

        /// If no decoder was found, return base type
        return Ptr<BaseImageDecoder>();
    }

    static void *
    imread_( const String &filename, int flags, int hdrtype)
    {
        /// Search for the relevant decoder to handle the imagery
        Ptr<BaseImageDecoder> decoder;
        decoder = findDecoder( filename );

        /// if no decoder was found, return nothing.
        if( !decoder )
        {
            return 0;
        }

        int scale_denom = 1;
        if( flags > IMREAD_LOAD_GDAL )
        {
            if( flags & IMREAD_REDUCED_GRAYSCALE_2 )
                scale_denom = 2;
            else if( flags & IMREAD_REDUCED_GRAYSCALE_4 )
                scale_denom = 4;
            else if( flags & IMREAD_REDUCED_GRAYSCALE_8 )
                scale_denom = 8;
        }

        /// set the scale_denom in the driver
        decoder->setScale( scale_denom );

        /// set the filename in the driver
        decoder->setSource( filename );

        // read the header to make sure it succeeds
        if( !decoder->readHeader() )
            return 0;
        return 0;
    }

    /**
     * Read an image
     *
     *  This function merely calls the actual implementation above and returns itself.
     *
     * @param[in] filename File to load
     * @param[in] flags Flags you wish to set.
    */
    int imread( const String &filename, int flags )
    {
        /// load the data
        imread_( filename, flags, LOAD_MAT);

        /// return a reference to the data
        return 0;
    }
}