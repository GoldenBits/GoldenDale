project(GoldenDaleClient)

set(GoldenDale-SRCS main.cpp)

find_package(Qt5 REQUIRED
        Core
        Widgets
        )

add_executable(GoldenDale ${GoldenDale-SRCS})

target_link_libraries(GoldenDale Qt5::Widgets Qt5::Core)