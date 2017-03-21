/*!
  \file   backend_config.h
  \brief  additional backend header
*/

#ifndef BACKEND_CONFIG_H
#define BACKEND_CONFIG_H

//-----------------------------------------------------------------------------------------------------------------------------

#if TARGET_OS_MAC

#  define TARGET_OS OS_MAC_OSX

#  if defined(__LP64__)
#    define TARGET_CPU CPU_INTEL_x64
#  else
#    define TARGET_CPU CPU_INTEL_x86
#  endif

#endif

//-----------------------------------------------------------------------------------------------------------------------------

#if defined(__llvm__) && (__clang__)
  #include "../coreconfig_cpp11_clang.h"
#else
  #include "../coreconfig_cpp11_gcc.h"
#endif

//-----------------------------------------------------------------------------------------------------------------------------

#endif // BACKEND_CONFIG_H
