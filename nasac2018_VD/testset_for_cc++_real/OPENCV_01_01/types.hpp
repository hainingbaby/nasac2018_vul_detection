#ifndef OPENCV_CORE_TYPES_HPP
#define OPENCV_CORE_TYPES_HPP

#ifndef __cplusplus
#  error types.hpp header must be compiled as C++
#endif

#include <climits>
#include <cfloat>
#include <vector>
#include <limits>

namespace cv
{
    //////////////////////////////// Size_ ////////////////////////////////

    /** @brief Template class for specifying the size of an image or rectangle.

    The class includes two members called width and height. The structure can be converted to and from
    the old OpenCV structures CvSize and CvSize2D32f . The same set of arithmetic and comparison
    operations as for Point_ is available.

    OpenCV defines the following Size_\<\> aliases:
    @code
        typedef Size_<int> Size2i;
        typedef Size2i Size;
        typedef Size_<float> Size2f;
    @endcode
    */
    template<typename _Tp> class Size_
    {
    public:
        typedef _Tp value_type;

        //! various constructors
        Size_();
        Size_(_Tp _width, _Tp _height);
        Size_(const Size_& sz);
        Size_(const Point_<_Tp> &pt);

        Size_ &operator = (const Size_& sz);
        //! the area (width*height)
        _Tp area() const;
        //! true if empty
        bool empty() const;

        //! conversion of another data type.
        template<typename _Tp2> operator Size_<_Tp2>() const;

        _Tp width, height; // the width and the height
    };

    typedef Size_<int> Size2i;
    typedef Size_<int64> Size2l;
    typedef Size_<float> Size2f;
    typedef Size_<double> Size2d;
    typedef Size2i Size;
}

#endif