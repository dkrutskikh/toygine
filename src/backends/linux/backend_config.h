/*!
  \file   backend_config.h
  \brief  additional backend header
*/

#ifndef BACKEND_CONFIG_H
#define BACKEND_CONFIG_H

//-----------------------------------------------------------------------------------------------------------------------------

#define TARGET_OS OS_LINUX

#if defined(__x86_64__)
#  define TARGET_CPU CPU_INTEL_x64
#else
#  define TARGET_CPU CPU_INTEL_x86
#endif

//-----------------------------------------------------------------------------------------------------------------------------

#if defined(__llvm__) && (__clang__)
  #include "../coreconfig_cpp11_clang.h"
#else
  #include "../coreconfig_cpp11_gcc.h"
#endif

//-----------------------------------------------------------------------------------------------------------------------------

#endif // BACKEND_CONFIG_H
