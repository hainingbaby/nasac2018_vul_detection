#ifndef OPENCV_CORE_CVSTDINL_HPP
#define OPENCV_CORE_CVSTDINL_HPP

#include <complex>
#include <ostream>

//! @cond IGNORED

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable: 4127 )
#endif

namespace cv
{
    inline
    String::String(const std::string &str)
        : cstr_(0), len_(0)
    {
        if (!str.empty())
        {
            size_t len = str.size();
            memcpy(allocate(len), str.c_str(), len);
        }
    }

    inline
    String::String(const std::string &str, size_t pos, size_t len)
        : cstr_(0), len_(0)
    {
        size_t strlen = str.size();
        pos = min(pos, strlen);
        len = min(strlen - pos, len);
        if (!len) return;
        memcpy(allocate(len), str.c_str() + pos, len);
    }

    inline
    String &String::operator = (const std::string &str)
    {
        deallocate();
        if (!str.empty())
        {
            size_t len = str.size();
            memcpy(allocate(len), str.c_str(), len);
        }
        return *this;
    }

    inline
    String &String::operator += (const std::string &str)
    {
        *this = *this + str;
        return *this;
    }

    inline
    String::operator std::string() const
    {
        return std::string(cstr_, len_);
    }

    inline
    String operator + (const String &lhs, const std::string &rhs)
    {
        String s;
        size_t rhslen = rhs.size();
        s.allocate(lhs.len_ + rhslen);
        memcpy(s.cstr_, lhs.cstr_, lhs.len_);
        memcpy(s.cstr_ + lhs.len_, rhs.c_str(), rhslen);
        return s;
    }

    inline
    String operator + (const std::string &lhs, const String &rhs)
    {
        String s;
        size_t lhslen = lhs.size();
        s.allocate(lhslen + rhs.len_);
        memcpy(s.cstr_, lhs.c_str(), lhslen);
        memcpy(s.cstr_ + lhslen, rhs.cstr_, rhs.len_);
        return s;
    }

#ifdef _MSC_VER
#pragma warning( pop )
#endif

    //! @endcond

#endif // OPENCV_CORE_CVSTDINL_HPP
