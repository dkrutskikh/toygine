/*!
  \file   backend_config.h
  \brief  additional backend header
*/

#ifndef BACKEND_CONFIG_H
#define BACKEND_CONFIG_H

//-----------------------------------------------------------------------------------------------------------------------------

#ifndef NOMINMAX
#  define NOMINMAX
#endif // NOMINMAX
#include <windows.h>

#if defined(_MSC_VER)

#  define TARGET_OS OS_WINDOWS_MSVC

#  if defined(_M_IX86)
#    define TARGET_CPU CPU_INTEL_x86
#  elif defined(_M_X64)
#    define TARGET_CPU CPU_INTEL_x64
#  endif

#endif

//-----------------------------------------------------------------------------------------------------------------------------

#include "../coreconfig_cpp11_msvc.h"

//-----------------------------------------------------------------------------------------------------------------------------

#endif // BACKEND_CONFIG_H
