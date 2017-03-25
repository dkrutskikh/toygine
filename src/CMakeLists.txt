if(WIN32 AND MSVC)
  set(PREPROCESSOR_DEFINITIONS "${PREPROCESSOR_DEFINITIONS} -D_LIB")
endif()

if(BACKEND STREQUAL "Windows Desktop")
  set(BACKEND_CONFIG_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/backends/windows/backend_config.hpp)
elseif(BACKEND STREQUAL "Linux Desktop")
  set(BACKEND_CONFIG_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/backends/linux/backend_config.hpp)
elseif(BACKEND STREQUAL "OSX Desktop")
  set(BACKEND_CONFIG_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/backends/osx/backend_config.hpp)
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/core/core.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/../include/core.hpp @ONLY)

#
# Stuff the average programmer needs to change #
set(SRC_CORE_LIST core/hashes.cpp)
set(HDR_CORE_LIST core/hashes.hpp ../include/core.hpp)

source_group("Core" FILES ${SRC_CORE_LIST} ${HDR_CORE_LIST})

set(SRC_LIST ${SRC_LIST} ${SRC_CORE_LIST})
set(HDR_LIST ${HDR_LIST} ${HDR_CORE_LIST})
set(LIB_LIST ${LIB_LIST})

#
# Non Builds programmer should not need to change anything beyond this #
set(LIBRARY_NAME toygine2)

add_definitions(${PREPROCESSOR_DEFINITIONS})
add_library(${LIBRARY_NAME} STATIC ${SRC_LIST} ${HDR_LIST} ${INL_LIST})
target_link_libraries(${LIBRARY_NAME} ${LIB_LIST})
