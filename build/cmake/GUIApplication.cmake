function(add_gui_application BINARY_NAME ${SRC_LIST} ${HDR_LIST} ${INL_LIST} ${RES_LIST} ${LIB_LIST} ${MEDIA_PATH} ${OS_DEPENDED_RESOURCES_PATH} ${OS_DEPENDED_BINARY_FILES})

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

elseif(APPLE)

  set(APP_TYPE MACOSX_BUNDLE)

  set(TG_APP_MAINMENU_XIB "TG_APP_MAINMENU_XIB-NOTFOUND" )   #disable cache
  find_file(TG_APP_MAINMENU_XIB NAMES resources_osx/mainmenu.xib PATHS ${CMAKE_CURRENT_SOURCE_DIR})
  if( NOT(${TG_APP_MAINMENU_XIB} STREQUAL "TG_APP_MAINMENU_XIB-NOTFOUND") )

    # Make sure we can find the 'ibtool' program. If we can NOT find it we skip generation of this project
    find_program(IBTOOL ibtool HINTS "/usr/bin" "${OSX_DEVELOPER_ROOT}/usr/bin")
    if(${IBTOOL} STREQUAL "IBTOOL-NOTFOUND")
      message(SEND_ERROR "ibtool can not be found and is needed to compile the .xib files. It should have been installed with the Apple developer tools. The default system paths were searched in addition to ${OSX_DEVELOPER_ROOT}/usr/bin")
    endif()

    # Compile the .xib files using the 'ibtool' program with the destination being the app package
    message("Compiling XIB ${TG_APP_MAINMENU_XIB}")
    execute_process(COMMAND ${IBTOOL} --errors --warnings --notices --output-format human-readable-text --compile ${CMAKE_CURRENT_BINARY_DIR}/mainmenu.nib ${TG_APP_MAINMENU_XIB})
    set(RES_LIST ${RES_LIST} ${CMAKE_CURRENT_BINARY_DIR}/mainmenu.nib)
    set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/mainmenu.nib PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

    mark_as_advanced(IBTOOL)

  endif()
  mark_as_advanced(TG_APP_MAINMENU_XIB)

  # Copy the .icns files to the app package
  foreach(icns ${RES_LIST})
    string(FIND ${icns} ".icns" TG_APP_RES_ICNSEXT)

    if((TG_APP_RES_ICNSEXT EQUAL 0) OR (TG_APP_RES_ICNSEXT GREATER 0))
      set_source_files_properties(${icns} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
    endif()
  endforeach()

  # Link GameKit for AppStore build
  if(STORETYPE STREQUAL "AppStore")
    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-weak_framework GameKit")
  endif()

  # Copy media files
  if(MEDIA_PATH)
    file(GLOB_RECURSE BUNDLE_RESOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" FOLLOW_SYMLINKS "${CMAKE_CURRENT_SOURCE_DIR}/${MEDIA_PATH}/*" )
    foreach(RESOURCE_FILE ${BUNDLE_RESOURCES})
      set(RES_LIST ${RES_LIST} ${RESOURCE_FILE})

      string(REPLACE "${MEDIA_PATH}/" "" RESOURCE_FILE_SHORTNAME ${RESOURCE_FILE})
      get_filename_component(RESOURCE_FILE_PATH_IN_BUNDLE ${RESOURCE_FILE_SHORTNAME} DIRECTORY)
      set_source_files_properties(${RESOURCE_FILE} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources/${RESOURCE_FILE_PATH_IN_BUNDLE}")
    endforeach()
  endif()
  if(OS_DEPENDED_RESOURCES_PATH)
    file(GLOB_RECURSE OS_DEPENDED_BUNDLE_RESOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" FOLLOW_SYMLINKS "${CMAKE_CURRENT_SOURCE_DIR}/${OS_DEPENDED_RESOURCES_PATH}/*" )
    foreach(RESOURCE_FILE ${OS_DEPENDED_BUNDLE_RESOURCES})
      set(RES_LIST ${RES_LIST} ${RESOURCE_FILE})

      string(REPLACE "${OS_DEPENDED_RESOURCES_PATH}/" "" RESOURCE_FILE_SHORTNAME ${RESOURCE_FILE})
      get_filename_component(RESOURCE_FILE_PATH_IN_BUNDLE ${RESOURCE_FILE_SHORTNAME} DIRECTORY)
      set_source_files_properties(${RESOURCE_FILE} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources/${RESOURCE_FILE_PATH_IN_BUNDLE}")
    endforeach()
  endif()
  if(OS_DEPENDED_BINARY_FILES)
    foreach(BINARY_FILE ${OS_DEPENDED_BINARY_FILES})
      set(RES_LIST ${RES_LIST} ${BINARY_FILE})
      set_source_files_properties(${BINARY_FILE} PROPERTIES MACOSX_PACKAGE_LOCATION "MacOS")
    endforeach()
  endif()

endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(${PREPROCESSOR_DEFINITIONS})
source_group("Source Files" FILES ${SRC_LIST} ${INL_LIST})
source_group("Resource Files" FILES ${RES_LIST})
add_executable(${BINARY_NAME} ${APP_TYPE} ${SRC_LIST} ${HDR_LIST} ${INL_LIST} ${RES_LIST})
target_link_libraries(${BINARY_NAME} ${LIB_LIST})


if(APPLE)

  set_target_properties(${BINARY_NAME} PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "${BINARY_NAME}")

  set_target_properties(${BINARY_NAME} PROPERTIES MACOSX_BUNDLE_SHORT_VERSION_STRING "${TG_VERSION_MAJOR}.${TG_VERSION_MINOR}.${TG_VERSION_PATCH}")
  set_target_properties(${BINARY_NAME} PROPERTIES MACOSX_BUNDLE_BUNDLE_VERSION "${TG_VERSION_MAJOR}.${TG_VERSION_MINOR}.${TG_VERSION_PATCH}")

  set_xcode_property( ${BINARY_NAME} MACOSX_DEPLOYMENT_TARGET "${OSX_VERSION_MIN}" )

  # Set a custom plist file for the app bundle if found
  set(TG_APP_PLIST "TG_APP_PLIST-NOTFOUND")   #disable cache
  find_file(TG_APP_PLIST appinfo.plist ${CMAKE_CURRENT_SOURCE_DIR}/resources_osx)
  if( NOT(${TG_APP_PLIST} STREQUAL "TG_APP_PLIST-NOTFOUND") )
    set_target_properties(${BINARY_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${TG_APP_PLIST})
  endif()

  # Set bundle icon
  foreach(icns ${RES_LIST})
    string(FIND ${icns} ".icns" TG_APP_RES_ICNSEXT)

    if((TG_APP_RES_ICNSEXT EQUAL 0) OR (TG_APP_RES_ICNSEXT GREATER 0))
      get_filename_component(TG_OSXBUNDLE_ICON_FILENAME ${icns} NAME)
      set_target_properties(${BINARY_NAME} PROPERTIES MACOSX_BUNDLE_ICON_FILE ${TG_OSXBUNDLE_ICON_FILENAME})
    endif()
  endforeach()

  mark_as_advanced(TG_APP_PLIST)

endif()

endfunction(add_gui_application)
