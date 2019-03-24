#ifndef OPENCV_CORE_CVSTD_HPP
#define OPENCV_CORE_CVSTD_HPP

#ifndef __cplusplus
#  error cvstd.hpp header must be compiled as C++
#endif

#include <cstddef>
#include <cstring>
#include <cctype>
#include <string>
#include "cvdef.h"

namespace cv
{
    using std::min;
    using std::max;
    using std::swap;
}

namespace cv
{

    CV_EXPORTS void *fastMalloc(size_t bufSize);

    /** @brief Deallocates a memory buffer.

    The function deallocates the buffer allocated with fastMalloc . If NULL pointer is passed, the
    function does nothing. C version of the function clears the pointer *pptr* to avoid problems with
    double memory deallocation.
    @param ptr Pointer to the allocated buffer.
     */
    CV_EXPORTS void fastFree(void *ptr);

    namespace detail
    {

        // Metafunction to avoid taking a reference to void.
        template<typename T>
        struct RefOrVoid
        {
            typedef T &type;
        };

        template<>
        struct RefOrVoid<void>
        {
            typedef void type;
        };

        template<>
        struct RefOrVoid<const void>
        {
            typedef const void type;
        };

        template<>
        struct RefOrVoid<volatile void>
        {
            typedef volatile void type;
        };

        template<>
        struct RefOrVoid<const volatile void>
        {
            typedef const volatile void type;
        };

        // This class would be private to Ptr, if it didn't have to be a non-template.
        struct PtrOwner;

    }

    template<typename Y>
    struct DefaultDeleter
    {
        void operator () (Y *p) const;
    };

    typedef int ptrdiff_t;

    template<typename T>
    struct Ptr
    {
        /** Generic programming support. */
        typedef T element_type;

        /** The default constructor creates a null Ptr - one that owns and stores a null pointer.
        */
        Ptr();

        /**
        If p is null, these are equivalent to the default constructor.
        Otherwise, these constructors assume ownership of p - that is, the created Ptr owns and stores p
        and assumes it is the sole owner of it. Don't use them if p is already owned by another Ptr, or
        else p will get deleted twice.
        With the first constructor, DefaultDeleter\<Y\>() becomes the associated deleter (so p will
        eventually be deleted with the standard delete operator). Y must be a complete type at the point
        of invocation.
        With the second constructor, d becomes the associated deleter.
        Y\* must be convertible to T\*.
        @param p Pointer to own.
        @note It is often easier to use makePtr instead.
         */
        template<typename Y>
#ifdef DISABLE_OPENCV_24_COMPATIBILITY
        explicit
#endif
        Ptr(Y *p);

        /** @overload
        @param d Deleter to use for the owned pointer.
        @param p Pointer to own.
        */
        template<typename Y, typename D>
        Ptr(Y *p, D d);

        /**
        These constructors create a Ptr that shares ownership with another Ptr - that is, own the same
        pointer as o.
        With the first two, the same pointer is stored, as well; for the second, Y\* must be convertible
        to T\*.
        With the third, p is stored, and Y may be any type. This constructor allows to have completely
        unrelated owned and stored pointers, and should be used with care to avoid confusion. A relatively
        benign use is to create a non-owning Ptr, like this:
        @code
            ptr = Ptr<T>(Ptr<T>(), dont_delete_me); // owns nothing; will not delete the pointer.
        @endcode
        @param o Ptr to share ownership with.
        */
        Ptr(const Ptr &o);

        /** @overload
        @param o Ptr to share ownership with.
        */
        template<typename Y>
        Ptr(const Ptr<Y> &o);

        /** @overload
        @param o Ptr to share ownership with.
        @param p Pointer to store.
        */
        template<typename Y>
        Ptr(const Ptr<Y> &o, T *p);

        /** The destructor is equivalent to calling Ptr::release. */
        ~Ptr();

        /**
        Assignment replaces the current Ptr instance with one that owns and stores same pointers as o and
        then destroys the old instance.
        @param o Ptr to share ownership with.
         */
        Ptr &operator = (const Ptr &o);

        /** @overload */
        template<typename Y>
        Ptr &operator = (const Ptr<Y> &o);

        /** If no other Ptr instance owns the owned pointer, deletes it with the associated deleter. Then sets
        both the owned and the stored pointers to NULL.
        */
        void release();

        /**
        `ptr.reset(...)` is equivalent to `ptr = Ptr<T>(...)`.
        @param p Pointer to own.
        */
        template<typename Y>
        void reset(Y *p);

        /** @overload
        @param d Deleter to use for the owned pointer.
        @param p Pointer to own.
        */
        template<typename Y, typename D>
        void reset(Y *p, D d);

        /**
        Swaps the owned and stored pointers (and deleters, if any) of this and o.
        @param o Ptr to swap with.
        */
        void swap(Ptr &o);

        /** Returns the stored pointer. */
        T *get() const;

        /** Ordinary pointer emulation. */
        typename detail::RefOrVoid<T>::type operator * () const;

        /** Ordinary pointer emulation. */
        T *operator -> () const;

        /** Equivalent to get(). */
        operator T *() const;

        /** ptr.empty() is equivalent to `!ptr.get()`. */
        bool empty() const;

        /** Returns a Ptr that owns the same pointer as this, and stores the same
           pointer as this, except converted via static_cast to Y*.
        */
        template<typename Y>
        Ptr<Y> staticCast() const;

        /** Ditto for const_cast. */
        template<typename Y>
        Ptr<Y> constCast() const;

        /** Ditto for dynamic_cast. */
        template<typename Y>
        Ptr<Y> dynamicCast() const;

#ifdef CV_CXX_MOVE_SEMANTICS
        Ptr(Ptr &&o);
        Ptr &operator = (Ptr &&o);
#endif

    private:
        detail::PtrOwner *owner;
        T *stored;

        template<typename Y>
        friend struct Ptr; // have to do this for the cross-type copy constructor
    };

    /** Equivalent to ptr1.swap(ptr2). Provided to help write generic algorithms. */
    template<typename T>
    void swap(Ptr<T> &ptr1, Ptr<T> &ptr2);

    /** Return whether ptr1.get() and ptr2.get() are equal and not equal, respectively. */
    template<typename T>
    bool operator == (const Ptr<T> &ptr1, const Ptr<T> &ptr2);
    template<typename T>
    bool operator != (const Ptr<T> &ptr1, const Ptr<T> &ptr2);

    /** `makePtr<T>(...)` is equivalent to `Ptr<T>(new T(...))`. It is shorter than the latter, and it's
    marginally safer than using a constructor or Ptr::reset, since it ensures that the owned pointer
    is new and thus not owned by any other Ptr instance.
    Unfortunately, perfect forwarding is impossible to implement in C++03, and so makePtr is limited
    to constructors of T that have up to 10 arguments, none of which are non-const references.
     */
    template<typename T>
    Ptr<T> makePtr();
    /** @overload */
    template<typename T, typename A1>
    Ptr<T> makePtr(const A1 &a1);
    /** @overload */
    template<typename T, typename A1, typename A2>
    Ptr<T> makePtr(const A1 &a1, const A2 &a2);
    /** @overload */
    template<typename T, typename A1, typename A2, typename A3>
    Ptr<T> makePtr(const A1 &a1, const A2 &a2, const A3 &a3);
    /** @overload */
    template<typename T, typename A1, typename A2, typename A3, typename A4>
    Ptr<T> makePtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4);
    /** @overload */
    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5>
    Ptr<T> makePtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5);
    /** @overload */
    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
    Ptr<T> makePtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6);
    /** @overload */
    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
    Ptr<T> makePtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7);
    /** @overload */
    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
    Ptr<T> makePtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8);
    /** @overload */
    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
    Ptr<T> makePtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8, const A9 &a9);
    /** @overload */
    template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
    Ptr<T> makePtr(const A1 &a1, const A2 &a2, const A3 &a3, const A4 &a4, const A5 &a5, const A6 &a6, const A7 &a7, const A8 &a8, const A9 &a9, const A10 &a10);



    class CV_EXPORTS String
    {
    public:
        typedef char value_type;
        typedef char &reference;
        typedef const char &const_reference;
        typedef char *pointer;
        typedef const char *const_pointer;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef char *iterator;
        typedef const char *const_iterator;

        static const size_t npos = size_t(-1);

        String();
        String(const String &str);
        String(const String &str, size_t pos, size_t len = npos);
        String(const char *s);
        String(const char *s, size_t n);
        String(size_t n, char c);
        String(const char *first, const char *last);
        template<typename Iterator> String(Iterator first, Iterator last);
        ~String();

        String &operator=(const String &str);
        String &operator=(const char *s);
        String &operator=(char c);

        String &operator+=(const String &str);
        String &operator+=(const char *s);
        String &operator+=(char c);

        size_t size() const;
        size_t length() const;

        char operator[](size_t idx) const;
        char operator[](int idx) const;

        const char *begin() const;
        const char *end() const;

        const char *c_str() const;

        bool empty() const;
        void clear();

        int compare(const char *s) const;
        int compare(const String &str) const;

        void swap(String &str);
        String substr(size_t pos = 0, size_t len = npos) const;

        size_t find(const char *s, size_t pos, size_t n) const;
        size_t find(char c, size_t pos = 0) const;
        size_t find(const String &str, size_t pos = 0) const;
        size_t find(const char *s, size_t pos = 0) const;

        size_t rfind(const char *s, size_t pos, size_t n) const;
        size_t rfind(char c, size_t pos = npos) const;
        size_t rfind(const String &str, size_t pos = npos) const;
        size_t rfind(const char *s, size_t pos = npos) const;

        size_t find_first_of(const char *s, size_t pos, size_t n) const;
        size_t find_first_of(char c, size_t pos = 0) const;
        size_t find_first_of(const String &str, size_t pos = 0) const;
        size_t find_first_of(const char *s, size_t pos = 0) const;

        size_t find_last_of(const char *s, size_t pos, size_t n) const;
        size_t find_last_of(char c, size_t pos = npos) const;
        size_t find_last_of(const String &str, size_t pos = npos) const;
        size_t find_last_of(const char *s, size_t pos = npos) const;

        friend String operator+ (const String &lhs, const String &rhs);
        friend String operator+ (const String &lhs, const char   *rhs);
        friend String operator+ (const char   *lhs, const String &rhs);
        friend String operator+ (const String &lhs, char          rhs);
        friend String operator+ (char          lhs, const String &rhs);

        String toLowerCase() const;

        String(const std::string &str);
        String(const std::string &str, size_t pos, size_t len = npos);
        String &operator=(const std::string &str);
        String &operator+=(const std::string &str);
        operator std::string() const;

        friend String operator+ (const String &lhs, const std::string &rhs);
        friend String operator+ (const std::string &lhs, const String &rhs);

    private:
        char  *cstr_;
        size_t len_;

        char *allocate(size_t len); // len without trailing 0
        void deallocate();

        String(int); // disabled and invalid. Catch invalid usages like, commandLineParser.has(0) problem
    };

    //! @} core_basic

    ////////////////////////// cv::String implementation /////////////////////////

    //! @cond IGNORED

    inline
    String::String()
        : cstr_(0), len_(0)
    {}

    inline
    String::String(const String &str)
        : cstr_(str.cstr_), len_(str.len_)
    {
        if (cstr_)
            CV_XADD(((int *)cstr_) - 1, 1);
    }

    inline
    String::String(const String &str, size_t pos, size_t len)
        : cstr_(0), len_(0)
    {
        pos = min(pos, str.len_);
        len = min(str.len_ - pos, len);
        if (!len) return;
        if (len == str.len_)
        {
            CV_XADD(((int *)str.cstr_) - 1, 1);
            cstr_ = str.cstr_;
            len_ = str.len_;
            return;
        }
        memcpy(allocate(len), str.cstr_ + pos, len);
    }

    inline
    String::String(const char *s)
        : cstr_(0), len_(0)
    {
        if (!s) return;
        size_t len = strlen(s);
        memcpy(allocate(len), s, len);
    }

    inline
    String::String(const char *s, size_t n)
        : cstr_(0), len_(0)
    {
        if (!n) return;
        if (!s) return;
        memcpy(allocate(n), s, n);
    }

    inline
    String::String(size_t n, char c)
        : cstr_(0), len_(0)
    {
        if (!n) return;
        memset(allocate(n), c, n);
    }

    inline
    String::String(const char *first, const char *last)
        : cstr_(0), len_(0)
    {
        size_t len = (size_t)(last - first);
        if (!len) return;
        memcpy(allocate(len), first, len);
    }

    template<typename Iterator> inline
    String::String(Iterator first, Iterator last)
        : cstr_(0), len_(0)
    {
        size_t len = (size_t)(last - first);
        if (!len) return;
        char *str = allocate(len);
        while (first != last)
        {
            *str++ = *first;
            ++first;
        }
    }

    inline
    String::~String()
    {
        deallocate();
    }

    inline
    String &String::operator=(const String &str)
    {
        if (&str == this) return *this;

        deallocate();
        if (str.cstr_) CV_XADD(((int *)str.cstr_) - 1, 1);
        cstr_ = str.cstr_;
        len_ = str.len_;
        return *this;
    }

    inline
    String &String::operator=(const char *s)
    {
        deallocate();
        if (!s) return *this;
        size_t len = strlen(s);
        memcpy(allocate(len), s, len);
        return *this;
    }

    inline
    String &String::operator=(char c)
    {
        deallocate();
        allocate(1)[0] = c;
        return *this;
    }

    inline
    String &String::operator+=(const String &str)
    {
        *this = *this + str;
        return *this;
    }

    inline
    String &String::operator+=(const char *s)
    {
        *this = *this + s;
        return *this;
    }

    inline
    String &String::operator+=(char c)
    {
        *this = *this + c;
        return *this;
    }

    inline
    size_t String::size() const
    {
        return len_;
    }

    inline
    size_t String::length() const
    {
        return len_;
    }

    inline
    char String::operator[](size_t idx) const
    {
        return cstr_[idx];
    }

    inline
    char String::operator[](int idx) const
    {
        return cstr_[idx];
    }

    inline
    const char *String::begin() const
    {
        return cstr_;
    }

    inline
    const char *String::end() const
    {
        return len_ ? cstr_ + len_ : NULL;
    }

    inline
    bool String::empty() const
    {
        return len_ == 0;
    }

    inline
    const char *String::c_str() const
    {
        return cstr_ ? cstr_ : "";
    }

    inline
    void String::swap(String &str)
    {
        cv::swap(cstr_, str.cstr_);
        cv::swap(len_, str.len_);
    }

    inline
    void String::clear()
    {
        deallocate();
    }

    inline
    int String::compare(const char *s) const
    {
        if (cstr_ == s) return 0;
        return strcmp(c_str(), s);
    }

    inline
    int String::compare(const String &str) const
    {
        if (cstr_ == str.cstr_) return 0;
        return strcmp(c_str(), str.c_str());
    }

    inline
    String String::substr(size_t pos, size_t len) const
    {
        return String(*this, pos, len);
    }

    inline
    size_t String::find(const char *s, size_t pos, size_t n) const
    {
        if (n == 0 || pos + n > len_) return npos;
        const char *lmax = cstr_ + len_ - n;
        for (const char *i = cstr_ + pos; i <= lmax; ++i)
        {
            size_t j = 0;
            while (j < n && s[j] == i[j]) ++j;
            if (j == n) return (size_t)(i - cstr_);
        }
        return npos;
    }

    inline
    size_t String::find(char c, size_t pos) const
    {
        return find(&c, pos, 1);
    }

    inline
    size_t String::find(const String &str, size_t pos) const
    {
        return find(str.c_str(), pos, str.len_);
    }

    inline
    size_t String::find(const char *s, size_t pos) const
    {
        if (pos >= len_ || !s[0]) return npos;
        const char *lmax = cstr_ + len_;
        for (const char *i = cstr_ + pos; i < lmax; ++i)
        {
            size_t j = 0;
            while (s[j] && s[j] == i[j])
            {
                if(i + j >= lmax) return npos;
                ++j;
            }
            if (!s[j]) return (size_t)(i - cstr_);
        }
        return npos;
    }

    inline
    size_t String::rfind(const char *s, size_t pos, size_t n) const
    {
        if (n > len_) return npos;
        if (pos > len_ - n) pos = len_ - n;
        for (const char *i = cstr_ + pos; i >= cstr_; --i)
        {
            size_t j = 0;
            while (j < n && s[j] == i[j]) ++j;
            if (j == n) return (size_t)(i - cstr_);
        }
        return npos;
    }

    inline
    size_t String::rfind(char c, size_t pos) const
    {
        return rfind(&c, pos, 1);
    }

    inline
    size_t String::rfind(const String &str, size_t pos) const
    {
        return rfind(str.c_str(), pos, str.len_);
    }

    inline
    size_t String::rfind(const char *s, size_t pos) const
    {
        return rfind(s, pos, strlen(s));
    }

    inline
    size_t String::find_first_of(const char *s, size_t pos, size_t n) const
    {
        if (n == 0 || pos + n > len_) return npos;
        const char *lmax = cstr_ + len_;
        for (const char *i = cstr_ + pos; i < lmax; ++i)
        {
            for (size_t j = 0; j < n; ++j)
                if (s[j] == *i)
                    return (size_t)(i - cstr_);
        }
        return npos;
    }

    inline
    size_t String::find_first_of(char c, size_t pos) const
    {
        return find_first_of(&c, pos, 1);
    }

    inline
    size_t String::find_first_of(const String &str, size_t pos) const
    {
        return find_first_of(str.c_str(), pos, str.len_);
    }

    inline
    size_t String::find_first_of(const char *s, size_t pos) const
    {
        if (len_ == 0) return npos;
        if (pos >= len_ || !s[0]) return npos;
        const char *lmax = cstr_ + len_;
        for (const char *i = cstr_ + pos; i < lmax; ++i)
        {
            for (size_t j = 0; s[j]; ++j)
                if (s[j] == *i)
                    return (size_t)(i - cstr_);
        }
        return npos;
    }

    inline
    size_t String::find_last_of(const char *s, size_t pos, size_t n) const
    {
        if (len_ == 0) return npos;
        if (pos >= len_) pos = len_ - 1;
        for (const char *i = cstr_ + pos; i >= cstr_; --i)
        {
            for (size_t j = 0; j < n; ++j)
                if (s[j] == *i)
                    return (size_t)(i - cstr_);
        }
        return npos;
    }

    inline
    size_t String::find_last_of(char c, size_t pos) const
    {
        return find_last_of(&c, pos, 1);
    }

    inline
    size_t String::find_last_of(const String &str, size_t pos) const
    {
        return find_last_of(str.c_str(), pos, str.len_);
    }

    inline
    size_t String::find_last_of(const char *s, size_t pos) const
    {
        if (len_ == 0) return npos;
        if (pos >= len_) pos = len_ - 1;
        for (const char *i = cstr_ + pos; i >= cstr_; --i)
        {
            for (size_t j = 0; s[j]; ++j)
                if (s[j] == *i)
                    return (size_t)(i - cstr_);
        }
        return npos;
    }

    inline
    String String::toLowerCase() const
    {
        if (!cstr_)
            return String();
        String res(cstr_, len_);
        for (size_t i = 0; i < len_; ++i)
            res.cstr_[i] = (char) ::tolower(cstr_[i]);

        return res;
    }

    //! @endcond

    // ************************* cv::String non-member functions *************************

    //! @relates cv::String
    //! @{

    inline
    String operator + (const String &lhs, const String &rhs)
    {
        String s;
        s.allocate(lhs.len_ + rhs.len_);
        memcpy(s.cstr_, lhs.cstr_, lhs.len_);
        memcpy(s.cstr_ + lhs.len_, rhs.cstr_, rhs.len_);
        return s;
    }

    inline
    String operator + (const String &lhs, const char *rhs)
    {
        String s;
        size_t rhslen = strlen(rhs);
        s.allocate(lhs.len_ + rhslen);
        memcpy(s.cstr_, lhs.cstr_, lhs.len_);
        memcpy(s.cstr_ + lhs.len_, rhs, rhslen);
        return s;
    }

    inline
    String operator + (const char *lhs, const String &rhs)
    {
        String s;
        size_t lhslen = strlen(lhs);
        s.allocate(lhslen + rhs.len_);
        memcpy(s.cstr_, lhs, lhslen);
        memcpy(s.cstr_ + lhslen, rhs.cstr_, rhs.len_);
        return s;
    }

    inline
    String operator + (const String &lhs, char rhs)
    {
        String s;
        s.allocate(lhs.len_ + 1);
        memcpy(s.cstr_, lhs.cstr_, lhs.len_);
        s.cstr_[lhs.len_] = rhs;
        return s;
    }

    inline
    String operator + (char lhs, const String &rhs)
    {
        String s;
        s.allocate(rhs.len_ + 1);
        s.cstr_[0] = lhs;
        memcpy(s.cstr_ + 1, rhs.cstr_, rhs.len_);
        return s;
    }

    static inline bool operator== (const String &lhs, const String &rhs)
    {
        return 0 == lhs.compare(rhs);
    }
    static inline bool operator== (const char   *lhs, const String &rhs)
    {
        return 0 == rhs.compare(lhs);
    }
    static inline bool operator== (const String &lhs, const char   *rhs)
    {
        return 0 == lhs.compare(rhs);
    }
    static inline bool operator!= (const String &lhs, const String &rhs)
    {
        return 0 != lhs.compare(rhs);
    }
    static inline bool operator!= (const char   *lhs, const String &rhs)
    {
        return 0 != rhs.compare(lhs);
    }
    static inline bool operator!= (const String &lhs, const char   *rhs)
    {
        return 0 != lhs.compare(rhs);
    }
    static inline bool operator<  (const String &lhs, const String &rhs)
    {
        return lhs.compare(rhs) <  0;
    }
    static inline bool operator<  (const char   *lhs, const String &rhs)
    {
        return rhs.compare(lhs) >  0;
    }
    static inline bool operator<  (const String &lhs, const char   *rhs)
    {
        return lhs.compare(rhs) <  0;
    }
    static inline bool operator<= (const String &lhs, const String &rhs)
    {
        return lhs.compare(rhs) <= 0;
    }
    static inline bool operator<= (const char   *lhs, const String &rhs)
    {
        return rhs.compare(lhs) >= 0;
    }
    static inline bool operator<= (const String &lhs, const char   *rhs)
    {
        return lhs.compare(rhs) <= 0;
    }
    static inline bool operator>  (const String &lhs, const String &rhs)
    {
        return lhs.compare(rhs) >  0;
    }
    static inline bool operator>  (const char   *lhs, const String &rhs)
    {
        return rhs.compare(lhs) <  0;
    }
    static inline bool operator>  (const String &lhs, const char   *rhs)
    {
        return lhs.compare(rhs) >  0;
    }
    static inline bool operator>= (const String &lhs, const String &rhs)
    {
        return lhs.compare(rhs) >= 0;
    }
    static inline bool operator>= (const char   *lhs, const String &rhs)
    {
        return rhs.compare(lhs) <= 0;
    }
    static inline bool operator>= (const String &lhs, const char   *rhs)
    {
        return lhs.compare(rhs) >= 0;
    }

    //! @} relates cv::String

} // cv

namespace std
{
    static inline void swap(cv::String &a, cv::String &b)
    {
        a.swap(b);
    }
}
#include "ptr.inl.hpp"

#endif //OPENCV_CORE_CVSTD_HPP