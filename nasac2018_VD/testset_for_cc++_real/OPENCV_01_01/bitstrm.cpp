#include "precomp.hpp"
#include "bitstrm.hpp"

namespace cv
{

const int BS_DEF_BLOCK_SIZE = 1<<15;

bool  bsIsBigEndian( void )
{
    return (((const int*)"\0\x1\x2\x3\x4\x5\x6\x7")[0] & 255) != 0;
}

/////////////////////////  RBaseStream ////////////////////////////

bool  RBaseStream::isOpened()
{
    return m_is_opened;
}

void  RBaseStream::allocate()
{
    if( !m_allocated )
    {
        m_start = new uchar[m_block_size];
        m_end = m_start + m_block_size;
        m_current = m_end;
        m_allocated = true;
    }
}


RBaseStream::RBaseStream()
{
    m_start = m_end = m_current = 0;
    m_file = 0;
    m_block_pos = 0;
    m_block_size = BS_DEF_BLOCK_SIZE;
    m_is_opened = false;
    m_allocated = false;
}


RBaseStream::~RBaseStream()
{
    close();    // Close files
    release();  // free  buffers
}


void  RBaseStream::readBlock()
{
    setPos( getPos() ); // normalize position

    if( m_file == 0 )
    {
        if( m_block_pos == 0 && m_current < m_end )
            return;
        throw RBS_THROW_EOS;
    }

    fseek( m_file, m_block_pos, SEEK_SET );
    size_t readed = fread( m_start, 1, m_block_size, m_file );
    m_end = m_start + readed;
    m_current = m_start;

    if( readed == 0 || m_current >= m_end )
        throw RBS_THROW_EOS;
}


bool  RBaseStream::open( const String& filename )
{
    close();
    allocate();

    m_file = fopen( filename.c_str(), "rb" );
    if( m_file )
    {
        m_is_opened = true;
        setPos(0);
        readBlock();
    }
    return m_file != 0;
}


void  RBaseStream::close()
{
    if( m_file )
    {
        fclose( m_file );
        m_file = 0;
    }
    m_is_opened = false;
    if( !m_allocated )
        m_start = m_end = m_current = 0;
}


void  RBaseStream::release()
{
    if( m_allocated )
        delete[] m_start;
    m_start = m_end = m_current = 0;
    m_allocated = false;
}


void  RBaseStream::setPos( int pos )
{
    assert( isOpened() && pos >= 0 );

    if( !m_file )
    {
        m_current = m_start + pos;
        m_block_pos = 0;
        return;
    }

    int offset = pos % m_block_size;
    m_block_pos = pos - offset;
    m_current = m_start + offset;
}


int  RBaseStream::getPos()
{
    assert( isOpened() );
    return m_block_pos + (int)(m_current - m_start);
}


void  RBaseStream::skip( int bytes )
{
    assert( bytes >= 0 );
    m_current += bytes;
}

/////////////////////////  RLByteStream ////////////////////////////

RLByteStream::~RLByteStream()
{
}


int  RLByteStream::getByte()
{
    uchar *current = m_current;
    int   val;

    if( current >= m_end )
    {
        readBlock();
        current = m_current;
    }

    val = *((uchar*)current);
    m_current = current + 1;
    return val;
}


int RLByteStream::getBytes( void* buffer, int count )
{
    uchar*  data = (uchar*)buffer;
    int readed = 0;
    assert( count >= 0 );

    while( count > 0 )
    {
        int l;

        for(;;)
        {
            l = (int)(m_end - m_current);
            if( l > count ) l = count;
            if( l > 0 ) break;
            readBlock();
        }
        memcpy( data, m_current, l );
        m_current += l;
        data += l;
        count -= l;
        readed += l;
    }
    return readed;
}


int  RLByteStream::getWord()
{
    uchar *current = m_current;
    int   val;

    if( current+1 < m_end )
    {
        val = current[0] + (current[1] << 8);
        m_current = current + 2;
    }
    else
    {
        val = getByte();
        val|= getByte() << 8;
    }
    return val;
}


int  RLByteStream::getDWord()
{
    uchar *current = m_current;
    int   val;

    if( current+3 < m_end )
    {
        val = current[0] + (current[1] << 8) +
              (current[2] << 16) + (current[3] << 24);
        m_current = current + 4;
    }
    else
    {
        val = getByte();
        val |= getByte() << 8;
        val |= getByte() << 16;
        val |= getByte() << 24;
    }
    return val;
}

}
