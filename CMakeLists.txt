cmake_minimum_required(VERSION 3.24)
project(paper_mash)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(OPENGL_LIBRARY_DIR "libs/freeglut/lib")
set(GLUT_INCLUDE_DIR "libs/freeglut/include")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        OpenGL
        OpenGLWidgets
        REQUIRED)

include_directories(include)

add_executable(paper_mash   src/main.cpp
        forms/mainwindow.cpp
                            forms/mainwindow.h
                            forms/mainwindow.ui
                            src/mesh.cpp
                            include/mesh.h
                            src/render-window.cpp
                            include/render-window.h
                            include/paper-structs.h
                            src/image-io.cpp
                            include/image-io.h)
target_link_libraries(paper_mash
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::OpenGL
        Qt::OpenGLWidgets
        ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARY}
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()


file(COPY resources/color.frag DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources/ )
file(COPY resources/color.vert DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources/ )
file(COPY resources/mask.frag DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources/ )
file(COPY resources/mask.vert DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources/ )
file(COPY resources/texture.frag DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources/ )
file(COPY resources/texture.vert DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources/ )