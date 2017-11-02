cmake_minimum_required(VERSION 3.9.4)

project(GoldenDale)

set(GoldenDale-SRCS main.cpp)

add_subdirectory(test)

find_package(Qt5 REQUIRED
        Core
        Widgets
        )

add_executable(GoldenDale ${GoldenDale-SRCS})

target_link_libraries(GoldenDale Qt5::Widgets Qt5::Core)