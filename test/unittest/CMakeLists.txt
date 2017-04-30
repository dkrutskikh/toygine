#
# Stuff the average programmer needs to change #
set(FRAMEWORK_LIST       ../../ext/catch/single_include/catch.hpp)

set(CORETESTS            core/hashes.cpp core/logger.cpp core/utils.cpp)
set(FILESYSTEMTESTS      filesystem/filename.cpp)
set(MATHEMATICSTESTS     mathematics/point.cpp mathematics/vector2d.cpp)
set(APPLICATIONTESTS     )
set(GEOMETRYTESTS        )
set(ANIMATIONSYSTEMTESTS )
set(NETWORKTESTS         )
set(VIDEOTESTS           )

set(SRC_LIST test_runner.cpp)
set(HDR_LIST )
set(INL_LIST )
set(LIB_LIST toygine2)
set(BINARY_NAME unittest)

add_definitions(${PREPROCESSOR_DEFINITIONS})
source_group("FrameWork Files" FILES ${FRAMEWORK_LIST})
source_group("Test\\animationsystem" FILES ${ANIMATIONSYSTEMTESTS})
source_group("Test\\application" FILES ${APPLICATIONTESTS})
source_group("Test\\core" FILES ${CORETESTS})
source_group("Test\\filesystem" FILES ${FILESYSTEMTESTS})
source_group("Test\\geometry" FILES ${GEOMETRYTESTS})
source_group("Test\\mathematics" FILES ${MATHEMATICSTESTS})
source_group("Test\\network" FILES ${NETWORKTESTS})
source_group("Test\\video" FILES ${VIDEOTESTS})
source_group("Source Files" FILES ${SRC_LIST} ${INL_LIST})
set(SRC_LIST ${SRC_LIST} ${CORETESTS} ${FILESYSTEMTESTS} ${MATHEMATICSTESTS} ${APPLICATIONTESTS} ${GEOMETRYTESTS} ${ANIMATIONSYSTEMTESTS} ${NETWORKTESTS} ${VIDEOTESTS})
set(HDR_LIST ${HDR_LIST} ${FRAMEWORK_LIST})

add_console_application(${BINARY_NAME} ${SRC_LIST} ${HDR_LIST} ${INL_LIST} ${RES_LIST} ${LIB_LIST})
