cmake_minimum_required(VERSION 3.5)

project(Model3DConventer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    mesh.h
        mesh.cpp
        model.h
        model.cpp
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

# Add assimp library
set(ASSIMP_SRC "assimp")
add_subdirectory(${ASSIMP_SRC} ${CMAKE_CURRENT_BINARY_DIR}/assimp)
include_directories("${ASSIMP_SRC}/include")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Model3DConventer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Model3DConventer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Model3DConventer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Model3DConventer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Model3DConventer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
 assimp)

set_target_properties(Model3DConventer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)



install(TARGETS Model3DConventer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Model3DConventer)
endif()
