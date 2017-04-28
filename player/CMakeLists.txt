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

set(APP_VERSION_MAJOR TG_VERSION_MAJOR)
set(APP_VERSION_MINOR TG_VERSION_MINOR)
set(APP_VERSION_PATCH TG_VERSION_PATCH)

if(BACKEND STREQUAL "Windows Desktop")
  set(SRC_LIST ${SRC_LIST} main_windows.cpp)
endif()

# TODO: remove
if(BACKEND STREQUAL "Windows Desktop")
#
# Non Builds programmer should not need to change anything beyond this #
  add_gui_application(${APP_NAME} ${SRC_LIST} ${HDR_LIST} ${INL_LIST} ${RES_LIST} ${LIB_LIST} ${MEDIA_PATH} ${OS_DEPENDED_RESOURCES_PATH} ${OS_DEPENDED_BINARY_PATH})
endif()
