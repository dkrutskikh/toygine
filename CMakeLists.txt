cmake_minimum_required(VERSION 3.2.0 FATAL_ERROR)

project(ToyGine)
set(TG_VERSION_MAJOR 0)
set(TG_VERSION_MINOR 0)
set(TG_VERSION_PATCH 0)
set(TG_SOURCE_DIR    ${CMAKE_CURRENT_SOURCE_DIR})

# Knock off ZERO_TEST at least BUILD_ALL remains
set(CMAKE_SUPPRESS_REGENERATION 1)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo" CACHE STRING "" FORCE)

# Make release build as default
if(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/cmake")

if(NOT DEFINED BUILD_TESTS)
  option(BUILD_TESTS "Set when you want to build engine tests" ON)
endif()

include(BackendsSelecting)
include(BuildSettings)

add_subdirectory(src)

if(BUILD_TESTS)
  add_subdirectory(test)
endif()
