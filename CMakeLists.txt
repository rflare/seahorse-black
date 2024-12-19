cmake_minimum_required( VERSION 3.5 )

project( seahorse-black )

find_package( OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} include)

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_TESTS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( glfw )



set( SB-SRC
    src/glad.c
    src/main.cpp
    src/window.cpp
    src/sprite.cpp
    src/shader.cpp
    src/sb_file.cpp
)

add_executable( out WIN32 ${SB-SRC} )
target_link_libraries( out ${OPENGL_LIBRARIES} glfw )
if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0")
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'GLFW-CMake-starter' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT out )
    endif()
endif()
