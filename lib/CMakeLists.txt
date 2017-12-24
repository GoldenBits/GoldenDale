project(GoldenDaleLib)

set(lib_SRCS
        Point.cpp
        RectangleArea.cpp
        )
set(lib_HEADERS
        ConstLoader.h
        C.h
        Strings.h
        RenderConst.h
        Area.h
        Point.h
        RectangleArea.h
        battle/HexGrid.cpp battle/HexGrid.h battle/field/HexField.cpp battle/field/HexField.h)

add_library(golden ${lib_SRCS} ${lib_HEADERS})
