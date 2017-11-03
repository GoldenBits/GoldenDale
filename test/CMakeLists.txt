enable_testing()

project(GoldenDaleTest)

set(googleTest_Dir ${CMAKE_CURRENT_SOURCE_DIR}/googletest)
if (EXISTS ${googleTest_Dir})
    SET(GTestSrc ${googleTest_Dir}/googletest)
    SET(GMockSrc ${googleTest_Dir}/googlemock)
else ()
    message(FATAL_ERROR "No googletest src dir found!")
endif ()

include_directories(${GTestSrc} ${GTestSrc}/include ${GMockSrc} ${GMockSrc}/include)
include_directories(${CMAKE_HOME_DIRECTORY} ${CMAKE_HOME_DIRECTORY}/test)

set(test_HEADERS
        StdInc.h
        )
set(test_SOURCES
        main.cpp
        )

add_executable(GoldenDaleTest ${test_SOURCES} ${test_HEADERS} ${mock_HEADERS} ${GTestSrc}/src/gtest-all.cc ${GMockSrc}/src/gmock-all.cc)

target_link_libraries(GoldenDaleTest pthread)