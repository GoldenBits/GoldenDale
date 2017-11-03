project(GoldenDaleClient)
include_directories(${CMAKE_HOME_DIRECTORY} ${CMAKE_HOME_DIRECTORY}/include ${CMAKE_CURRENT_SOURCE_DIR})

set(GoldenDale-SRCS main.cpp)

find_package(OpenGL REQUIRED)
find_package(Qt5 REQUIRED
        Core
        Widgets
        )

add_executable(GoldenDale ${GoldenDale-SRCS})

target_link_libraries(GoldenDale ${OPENGL_gl_LIBRARY})
target_link_libraries(GoldenDale Qt5::Widgets Qt5::Core)