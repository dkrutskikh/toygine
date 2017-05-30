include(GUIApplication)

#
# Stuff the average programmer needs to change #
set(SRC_LIST app.cpp)
set(HDR_LIST app.hpp)
set(INL_LIST app.inl)
set(LIB_LIST toygine2)
set(RES_LIST )
set(MEDIA_PATH )
set(OS_DEPENDED_RESOURCES_PATH)
set(OS_DEPENDED_BINARY_FILES)
set(APP_NAME player)

if(BACKEND STREQUAL "OSX Desktop")
  find_library(APPKIT_LIBRARY NAMES AppKit)

  set(SRC_LIST ${SRC_LIST} main_osx.cpp main_osx.mm)
  set(LIB_LIST ${LIB_LIST} ${APPKIT_LIBRARY})
  set(RES_LIST ${RES_LIST} "resources_osx/icon.icns")
  set(OSX_VERSION_MIN "10.7")

  mark_as_advanced(FOUNDATION_LIBRARY)
elseif(BACKEND STREQUAL "Windows Desktop")
  set(SRC_LIST ${SRC_LIST} main_windows.cpp)
endif()

#
# Non Builds programmer should not need to change anything beyond this #
add_gui_application(${APP_NAME} ${SRC_LIST} ${HDR_LIST} ${INL_LIST} ${RES_LIST} ${LIB_LIST} ${MEDIA_PATH} ${OS_DEPENDED_RESOURCES_PATH} ${OS_DEPENDED_BINARY_PATH})
