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
  \file   coreconfig_cpp11_inmsvc.h
  \brief  detect support c++ 11 features in MSVC compilers family
*/

#ifndef SRC_BACKENDS_CORECONFIG_CPP11_MSVC_H_
#define SRC_BACKENDS_CORECONFIG_CPP11_MSVC_H_

using uint8 = unsigned __int8;
using int8 = __int8;

using uint16 = unsigned __int16;
using int16 = __int16;

using uint32 = unsigned __int32;
using int32 = __int32;

using uint64 = unsigned __int64;
using int64 = __int64;

using byte = unsigned __int8;

#undef SIZEOF_WCHAR_T
#define SIZEOF_WCHAR_T 2

#undef INT8_MAX
#define INT8_MAX SCHAR_MAX
#undef INT8_MIN
#define INT8_MIN SCHAR_MIN

#undef INT16_MAX
#define INT16_MAX SHRT_MAX
#undef INT16_MIN
#define INT16_MIN SHRT_MIN

#undef INT32_MAX
#define INT32_MAX LONG_MAX
#undef INT32_MIN
#define INT32_MIN LONG_MIN

#undef INT64_MAX
#define INT64_MAX LLONG_MAX
#undef INT64_MIN
#define INT64_MIN LLONG_MIN

#undef UINT8_MAX
#define UINT8_MAX UCHAR_MAX

#undef UINT16_MAX
#define UINT16_MAX USHRT_MAX

#undef UINT32_MAX
#define UINT32_MAX ULONG_MAX

#undef UINT64_MAX
#define UINT64_MAX ULLONG_MAX

#endif  // SRC_BACKENDS_CORECONFIG_CPP11_MSVC_H_
