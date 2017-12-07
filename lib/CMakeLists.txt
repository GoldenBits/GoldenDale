project(GoldenDaleLib)


set(lib_SRCS
        Point.cpp
        RectangleArea.cpp
        )
set(lib_HEADERS
        Area.h
        Point.h
        RectangleArea.h
        )

add_library(golden ${lib_SRCS} ${lib_HEADERS})
