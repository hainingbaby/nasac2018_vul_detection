#ifndef __IMGCODECS_H_
#define __IMGCODECS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
#include <vector>

#include "imgcodecs.hpp"

#if defined _WIN32 || defined WINCE
    #include <windows.h>
    #undef small
    #undef min
    #undef max
    #undef abs
#endif

#endif /* __IMGCODECS_H_ */
