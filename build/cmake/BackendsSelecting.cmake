cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

find_package(Qt5Core)
if(Qt5Core_FOUND)
  message("Qt5Core_FOUND - ${Qt5Core_FOUND}")
endif()

if(NOT DEFINED BACKEND)
  if(CMAKE_SYSTEM_NAME MATCHES Windows)

    set(AVAILABLEBACKENDS "Windows Desktop")

    set(BACKEND "Windows Desktop" CACHE STRING "Select destination backend for app")

  elseif(UNIX AND NOT APPLE)

    set(AVAILABLEBACKENDS "Linux Desktop")
    set(BACKEND "Linux Desktop" CACHE STRING "Select destination backend for app")

  elseif(APPLE)

    set(AVAILABLEBACKENDS "OSX Desktop")

    set(BACKEND "OSX Desktop" CACHE STRING "Select destination backend for app")

  endif()

endif()
