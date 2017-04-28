function(add_gui_application BINARY_NAME ${SRC_LIST} ${HDR_LIST} ${INL_LIST} ${RES_LIST} ${LIB_LIST} ${MEDIA_PATH} ${OS_DEPENDED_RESOURCES_PATH} ${OS_DEPENDED_BINARY_FILES})

if(APP_VERSION_MAJOR)
  set(PREPROCESSOR_DEFINITIONS "${PREPROCESSOR_DEFINITIONS} -DTG_APP_VERSION_MAJOR=${APP_VERSION_MAJOR}")
endif()
if(APP_VERSION_MINOR)
  set(PREPROCESSOR_DEFINITIONS "${PREPROCESSOR_DEFINITIONS} -DTG_APP_VERSION_MINOR=${APP_VERSION_MINOR}")
endif()
if(APP_VERSION_PATCH)
  set(PREPROCESSOR_DEFINITIONS "${PREPROCESSOR_DEFINITIONS} -DTG_APP_VERSION_PATCH=${APP_VERSION_PATCH}")
endif()

set(APP_TYPE )

if(WIN32)

  set(APP_TYPE WIN32)

  if(CMAKE_SIZEOF_VOID_P MATCHES "8")
    set(PROCESSOR "ia64")
  else()
    set(PROCESSOR "x86")
  endif()

  set(TG_APP_MANIFEST "TG_APP_MANIFEST-NOTFOUND" )
  find_file(TG_APP_MANIFEST app.manifest.in ${CMAKE_CURRENT_SOURCE_DIR}/resources_winapi)
  if( NOT(${TG_APP_MANIFEST} STREQUAL "TG_APP_MANIFEST-NOTFOUND") )
    configure_file( ${TG_APP_MANIFEST} ${CMAKE_CURRENT_BINARY_DIR}/app.manifest @ONLY)
    set(RES_LIST ${RES_LIST} ${CMAKE_CURRENT_BINARY_DIR}/app.manifest)
  endif()

  set(TG_APP_RESOURCES "TG_APP_RESOURCES-NOTFOUND" )
  find_file(TG_APP_RESOURCES appresources.rc.in ${CMAKE_CURRENT_SOURCE_DIR}/resources_winapi)
  if( NOT(${TG_APP_RESOURCES} STREQUAL "TG_APP_RESOURCES-NOTFOUND") )
    configure_file( ${TG_APP_RESOURCES} ${CMAKE_CURRENT_BINARY_DIR}/appresources.rc @ONLY)
    set(RES_LIST ${RES_LIST} ${CMAKE_CURRENT_BINARY_DIR}/appresources.rc)
  endif()

  mark_as_advanced(TG_APP_MANIFEST TG_APP_RESOURCES)

endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(${PREPROCESSOR_DEFINITIONS})
source_group("Source Files" FILES ${SRC_LIST} ${INL_LIST})
source_group("Resource Files" FILES ${RES_LIST})
add_executable(${BINARY_NAME} ${APP_TYPE} ${SRC_LIST} ${HDR_LIST} ${INL_LIST} ${RES_LIST})
target_link_libraries(${BINARY_NAME} ${LIB_LIST})

endfunction(add_gui_application)
