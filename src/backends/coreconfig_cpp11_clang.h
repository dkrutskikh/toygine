/*!
  \file   coreconfig_cpp11_clang.h
  \brief  detect support c++ 11 features in CLang
*/

#ifndef CORECONFIG_CPP11_CLANG_H
#define CORECONFIG_CPP11_CLANG_H


#define __STDC_LIMIT_MACROS
#include <limits.h>
#include <stdint.h>
#include <wchar.h>


using uint8 = unsigned char;
using  int8 =   signed char;

using uint16 = unsigned short;
using  int16 =   signed short;

using uint32 = unsigned int;
using  int32 =   signed int;

using uint64 = unsigned long long;
using  int64 =   signed long long;

using byte = unsigned char;


#undef SIZEOF_WCHAR_T
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x0FFFF
# define SIZEOF_WCHAR_T       4
#elif __SIZEOF_WCHAR_T__ == 2 || __WCHAR_MAX__ < 0x10000
# define SIZEOF_WCHAR_T       2
#else
# define SIZEOF_WCHAR_T       -1                                                                                                   // Unknown GCC platform
#endif


#undef INT8_MAX
#define INT8_MAX              SCHAR_MAX
#undef INT8_MIN
#define INT8_MIN              SCHAR_MIN

#undef INT16_MAX
#define INT16_MAX             SHRT_MAX
#undef INT16_MIN
#define INT16_MIN             SHRT_MIN

#undef INT32_MAX
#define INT32_MAX             INT_MAX
#undef INT32_MIN
#define INT32_MIN             INT_MIN

#undef UINT8_MAX
#define UINT8_MAX             UCHAR_MAX

#undef UINT16_MAX
#define UINT16_MAX            USHRT_MAX

#undef UINT32_MAX
#define UINT32_MAX            UINT_MAX


#if (TARGET_OS == OS_LINUX)

#undef major
#undef minor

#endif // (TARGET_OS == OS_LINUX)

#endif // CORECONFIG_CPP11_CLANG_H
