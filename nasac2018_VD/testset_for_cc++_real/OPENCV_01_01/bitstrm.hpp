#ifndef _BITSTRM_H_
#define _BITSTRM_H_

#include <stdio.h>
#include "cvstd.hpp"
namespace cv
{

enum
{
    RBS_THROW_EOS=-123,  // <end of stream> exception code
    RBS_THROW_FORB=-124,  // <forrbidden huffman code> exception code
    RBS_HUFF_FORB=2047,  // forrbidden huffman code "value"
    RBS_BAD_HEADER=-125 // invalid header
};

typedef unsigned long ulong;

// class RBaseStream - base class for other reading streams.
class RBaseStream
{
public:
    //methods
    RBaseStream();
    virtual ~RBaseStream();

    virtual bool  open( const String& filename );
    virtual void  close();
    bool          isOpened();
    void          setPos( int pos );
    int           getPos();
    void          skip( int bytes );

protected:

    bool    m_allocated;
    uchar*  m_start;
    uchar*  m_end;
    uchar*  m_current;
    FILE*   m_file;
    int     m_block_size;
    int     m_block_pos;
    bool    m_is_opened;

    virtual void  readBlock();
    virtual void  release();
    virtual void  allocate();
};


// class RLByteStream - uchar-oriented stream.
// l in prefix means that the least significant uchar of a multi-uchar value goes first
class RLByteStream : public RBaseStream
{
public:
    virtual ~RLByteStream();

    int     getByte();
    int     getBytes( void* buffer, int count );
    int     getWord();
    int     getDWord();
};
}

#endif/*_BITSTRM_H_*/
