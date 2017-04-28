#set(PREPROCESSOR_DEFINITIONS "${PREPROCESSOR_DEFINITIONS} -DFORCE_NOT_DEBUG_MEMORY")

if(WIN32 AND NOT(CMAKE_SYSTEM_NAME MATCHES WindowsStore))

  set(LIB_SUFFIX "")
  if(MSVC)

    message(STATUS "Compiler: MSVC, version: " ${MSVC_VERSION})

    # Disable display of the copyright banner
    # Set common win32 defines
    # Enable exception handling
    # Float Model: precise
    # Embedding type whcar_t
    # Enable RTTI
    set(CMAKE_C_FLAGS   "/nologo /W4 /WX /DWIN32 /D_WINDOWS /EHsc /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /GR")
    set(CMAKE_CXX_FLAGS "/nologo /W4 /WX /DWIN32 /D_WINDOWS /EHsc /fp:precise /Zc:forScope /Zc:inline /Zc:rvalueCast /Zc:wchar_t /GR /std:c++latest")
    set(PREPROCESSOR_DEFINITIONS "${PREPROCESSOR_DEFINITIONS} -DUNICODE -D_UNICODE")


    if(CMAKE_SIZEOF_VOID_P MATCHES "8")

      set(CMAKE_C_FLAGS_DEBUG            "/Zi /sdl  /Od /Ob0         /Oy-     /D_DEBUG /GF- /Gm  /RTC1 /MTd /GS  /Gy /fp:except")
      set(CMAKE_CXX_FLAGS_DEBUG          "/Zi /sdl  /Od /Ob0         /Oy-     /D_DEBUG /GF- /Gm  /RTC1 /MTd /GS  /Gy /fp:except")

      set(CMAKE_C_FLAGS_RELWITHDEBINFO   "/Zi /sdl  /Ox /Ob2 /Oi /Ot /Oy- /GL /D_DEBUG /GF  /Gm        /MTd /GS")
      set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/Zi /sdl  /Ox /Ob2 /Oi /Ot /Oy- /GL /D_DEBUG /GF  /Gm        /MTd /GS")

      set(CMAKE_C_FLAGS_RELEASE          "    /sdl- /Ox /Ob2 /Oi /Ot /Oy  /GL /DNDEBUG /GF  /Gm-       /MT  /GS-     /fp:except-")
      set(CMAKE_CXX_FLAGS_RELEASE        "    /sdl- /Ox /Ob2 /Oi /Ot /Oy  /GL /DNDEBUG /GF  /Gm-       /MT  /GS-     /fp:except-")

    else()

      set(CMAKE_C_FLAGS_DEBUG            "/ZI /sdl  /Od /Ob0         /Oy-     /D_DEBUG /GF- /Gm  /RTC1 /MTd /GS  /Gy            /fp:except")
      set(CMAKE_CXX_FLAGS_DEBUG          "/ZI /sdl  /Od /Ob0         /Oy-     /D_DEBUG /GF- /Gm  /RTC1 /MTd /GS  /Gy            /fp:except")

      set(CMAKE_C_FLAGS_RELWITHDEBINFO   "/Zi /sdl  /Ox /Ob2 /Oi /Ot /Oy- /GL /D_DEBUG /GF  /Gm        /MTd /GS      /arch:SSE2")
      set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/Zi /sdl  /Ox /Ob2 /Oi /Ot /Oy- /GL /D_DEBUG /GF  /Gm        /MTd /GS      /arch:SSE2")

      set(CMAKE_C_FLAGS_RELEASE          "    /sdl- /Ox /Ob2 /Oi /Ot /Oy  /GL /DNDEBUG /GF  /Gm-       /MT  /GS-     /arch:SSE2 /fp:except-")
      set(CMAKE_CXX_FLAGS_RELEASE        "    /sdl- /Ox /Ob2 /Oi /Ot /Oy  /GL /DNDEBUG /GF  /Gm-       /MT  /GS-     /arch:SSE2 /fp:except-")

    endif()


    set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "")
    set(CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO "/LTCG")
    set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "/LTCG")

    set(CMAKE_EXE_LINKER_FLAGS_DEBUG          "/DEBUG /INCREMENTAL          /SAFESEH:NO")
    set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "/DEBUG /INCREMENTAL:NO /LTCG /SAFESEH:NO")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE        "       /INCREMENTAL:NO /LTCG /SAFESEH:NO")

    set(STATIC_LIBRARY_FLAGS_RELWITHDEBINFO "/LTCG")
    set(STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")

  endif()

elseif(UNIX AND NOT APPLE)

  if(CMAKE_COMPILER_IS_GNUCC)
    execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
    string(REGEX MATCHALL "[0-9]+" GCC_VERSION_COMPONENTS ${GCC_VERSION})
    list(GET GCC_VERSION_COMPONENTS 0 GCC_MAJOR)
    list(GET GCC_VERSION_COMPONENTS 1 GCC_MINOR)
  endif()

  message(STATUS "Compiler: GCC, version: " ${GCC_MAJOR} "." ${GCC_MINOR})
  set(LINUX ON)

  set(LIB_SUFFIX "/${CMAKE_BUILD_TYPE}")

  #options https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html
  set(CMAKE_C_FLAGS   "-Wall -Werror -Wextra -Wpedantic -std=c11")
  set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -Wpedantic -std=c++14")

  set(CMAKE_C_FLAGS_DEBUG "-g -D_DEBUG -fprofile-arcs -ftest-coverage")
  set(CMAKE_C_FLAGS_RELWITHDEBINFO "-g -O3 -D_DEBUG -flto")
  set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG -flto")

  set(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG -fprofile-arcs -ftest-coverage")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O3 -D_DEBUG -flto")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -flto")

  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "-lgcov")

elseif(APPLE)

  macro(set_xcode_property targ xc_prop_name xc_prop_val)
    set_property( TARGET ${targ} PROPERTY XCODE_ATTRIBUTE_${xc_prop_name} ${xc_prop_val} )
  endmacro(set_xcode_property)

  message(STATUS "Compiler: Xcode, version: " ${XCODE_VERSION})
  set(LIB_SUFFIX "/${CMAKE_BUILD_TYPE}")

  #warnings http://clang.llvm.org/docs/DiagnosticsReference.html
  set(CMAKE_C_FLAGS   "-Wall -Wextra                  -std=c11                  -fobjc-arc -Werror          -Wstrict-selector-match -Wundeclared-selector -Wexplicit-ownership-type -Wimplicit-retain-self -Warc-repeated-use-of-weak")
  set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wold-style-cast -std=c++14 -stdlib=libc++ -fobjc-arc -Werror -Weffc++ -Wstrict-selector-match -Wundeclared-selector -Wexplicit-ownership-type -Wimplicit-retain-self -Warc-repeated-use-of-weak")

  set(CMAKE_C_FLAGS_DEBUG "-g -D_DEBUG")
  set(CMAKE_C_FLAGS_RELWITHDEBINFO "-g -O3 -D_DEBUG -flto")
  set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG -flto")

  set(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O3 -D_DEBUG -flto")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -flto")

  set(CMAKE_EXE_LINKER_FLAGS "-lc++")

  set(CMAKE_OSX_ARCHITECTURES "$(ARCHS_STANDARD_64_BIT)")
  set(CMAKE_OSX_DEPLOYMENT_TARGET "10.7")
  set(CMAKE_OSX_SYSROOT macosx)

endif()

if(TG_VERSION_MAJOR OR (TG_VERSION_MAJOR EQUAL 0))
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DTG_VERSION_MAJOR=${TG_VERSION_MAJOR}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DTG_VERSION_MAJOR=${TG_VERSION_MAJOR}")
endif()
if(TG_VERSION_MINOR OR (TG_VERSION_MINOR EQUAL 0))
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DTG_VERSION_MINOR=${TG_VERSION_MINOR}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DTG_VERSION_MINOR=${TG_VERSION_MINOR}")
endif()
if(TG_VERSION_MAINTENANCE OR (TG_VERSION_PATCH EQUAL 0))
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DTG_VERSION_PATCH=${TG_VERSION_PATCH}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DTG_VERSION_PATCH=${TG_VERSION_PATCH}")
endif()

if(NOT DEFINED TG_SRC_PATH)
  set(TG_SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/../../")
  message(STATUS "Engine path: ${TG_SRC_PATH}")
endif()


message("CMAKE_C_FLAGS=${CMAKE_C_FLAGS}")
message("CMAKE_C_FLAGS_DEBUG=${CMAKE_C_FLAGS_DEBUG}")
message("CMAKE_C_FLAGS_RELWITHDEBINFO=${CMAKE_C_FLAGS_RELWITHDEBINFO}")
message("CMAKE_C_FLAGS_RELEASE=${CMAKE_C_FLAGS_RELEASE}")
message("CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")
message("CMAKE_CXX_FLAGS_DEBUG=${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELWITHDEBINFO=${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message("CMAKE_CXX_FLAGS_RELEASE=${CMAKE_CXX_FLAGS_RELEASE}")

message("STATIC_LIBRARY_FLAGS=${STATIC_LIBRARY_FLAGS}")
message("STATIC_LIBRARY_FLAGS_DEBUG=${STATIC_LIBRARY_FLAGS_DEBUG}")
message("STATIC_LIBRARY_FLAGS_RELWITHDEBINFO=${STATIC_LIBRARY_FLAGS_RELWITHDEBINFO}")
message("STATIC_LIBRARY_FLAGS_RELEASE=${STATIC_LIBRARY_FLAGS_RELEASE}")

message("CMAKE_CXX_LINKER_PREFERENCE=${CMAKE_CXX_LINKER_PREFERENCE}")
message("CMAKE_CXX_LINKER_PREFERENCE_PROPAGATES=${CMAKE_CXX_LINKER_PREFERENCE_PROPAGATES}")
message("CMAKE_CXX_LINK_EXECUTABLE=${CMAKE_CXX_LINK_EXECUTABLE}")

message("LIBRARY_OUTPUT_DIRECTORY=${LIBRARY_OUTPUT_DIRECTORY}")
message("PREPROCESSOR_DEFINITIONS=${PREPROCESSOR_DEFINITIONS}")
message("CMAKE_LIBRARY_OUTPUT_DIRECTORY=${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
