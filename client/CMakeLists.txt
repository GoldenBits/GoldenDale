project(GoldenDaleClient)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_HOME_DIRECTORY}/lib)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
link_libraries(${OPENGL_gl_LIBRARY})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

find_package(glfw3 3.2.1 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(glfw)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(GoldenDale-SRCS
        RectangleItem.cpp
        render/RenderData.cpp
        render/RenderItem.cpp
        render/shader/ShaderProgram.cpp
        render/shader/shader.cpp
        render/vertex/Vertex.cpp
        render/vertex/VertexArrayObject.cpp
        render/vertex/buffer/ElementBufferObject.cpp
        render/vertex/buffer/VertexBufferObject.cpp
        window/MainWindow.cpp
        main.cpp
        )

set(GoldenDale-HEADERS
        RectangleItem.h
        StdInc.h
        render/RenderData.h
        render/RenderItem.h
        render/shader/ShaderProgram.h
        render/shader/ShaderType.h
        render/shader/shader.h
        render/vertex/Vertex.h
        render/vertex/VertexArrayObject.h
        render/vertex/buffer/ElementBufferObject.h
        render/vertex/buffer/VertexBufferObject.h
        window/MainWindow.h
        window/Window.h
        render/Texture.cpp)

add_executable(GoldenDale ${GoldenDale-SRCS} ${GoldenDale-HEADERS})
target_link_libraries(GoldenDale golden ${Boost_LIBRARIES})

file (GLOB_RECURSE resources "resources/*.*")
foreach(resource ${resources})
    get_filename_component(filename ${resource} NAME)
    get_filename_component(dir ${resource} DIRECTORY)
    get_filename_component(dirname ${dir} NAME)

    set (output "")

    while(NOT ${dirname} STREQUAL resources)
        get_filename_component(path_component ${dir} NAME)
        set (output "${path_component}/${output}")
        get_filename_component(dir ${dir} DIRECTORY)
        get_filename_component(dirname ${dir} NAME)
    endwhile()

    set(output "${CMAKE_CURRENT_BINARY_DIR}/resources/${output}/${filename}")

    add_custom_command(
            COMMENT "Moving updated resource-file '${filename}'"
            OUTPUT ${output}
            DEPENDS ${resource}
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${resource}
            ${output}
    )
    add_custom_target(${filename} ALL DEPENDS ${resource} ${output})

endforeach()