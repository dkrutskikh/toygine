//
// Copyright (c) 2017 Dmitry Krutskikh
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//
/*!
  \file   coreconfig_cpp11_gcc.h
  \brief  detect support c++ 11 features in GNU compilers family
*/

#ifndef SRC_BACKENDS_CORECONFIG_CPP11_GCC_H_
#define SRC_BACKENDS_CORECONFIG_CPP11_GCC_H_

#define __STDC_LIMIT_MACROS
#include <limits.h>
#include <stdint.h>
#include <wchar.h>

using uint8 = unsigned char;
using int8 = char;

using uint16 = unsigned short;
using int16 = short;

using uint32 = unsigned int;
using int32 = int;

using uint64 = unsigned long long;
using int64 = long long;

using byte = unsigned char;

#undef SIZEOF_WCHAR_T
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x0FFFF
#define SIZEOF_WCHAR_T 4
#elif __SIZEOF_WCHAR_T__ == 2 || __WCHAR_MAX__ < 0x10000
#define SIZEOF_WCHAR_T 2
#else
#define SIZEOF_WCHAR_T -1  // Unknown GCC platform
#endif

#undef INT8_MAX
#define INT8_MAX SCHAR_MAX
#undef INT8_MIN
#define INT8_MIN SCHAR_MIN

#undef INT16_MAX
#define INT16_MAX SHRT_MAX
#undef INT16_MIN
#define INT16_MIN SHRT_MIN

#undef INT32_MAX
#define INT32_MAX INT_MAX
#undef INT32_MIN
#define INT32_MIN INT_MIN

#undef UINT8_MAX
#define UINT8_MAX UCHAR_MAX

#undef UINT16_MAX
#define UINT16_MAX USHRT_MAX

#undef UINT32_MAX
#define UINT32_MAX UINT_MAX

#if (TARGET_OS == OS_LINUX)

#undef major
#undef minor

#endif  // (TARGET_OS == OS_LINUX)

#endif  // SRC_BACKENDS_CORECONFIG_CPP11_GCC_H_
