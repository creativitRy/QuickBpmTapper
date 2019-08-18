SET(pwd ${CMAKE_CURRENT_LIST_DIR})

SET(src "")
add_executable(QuickBpmTapper main.cpp)

# musicbee
IF (WIN32)
    add_custom_command(
            TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND cmd /c ${CMAKE_SOURCE_DIR}/InstallChangeMusicBee.bat ${CMAKE_SOURCE_DIR}/src ${CMAKE_CURRENT_BINARY_DIR}
    )
ENDIF ()

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/resources
        ${CMAKE_CURRENT_BINARY_DIR}/resources
        DEPENDS ${MY_TARGET}
)
