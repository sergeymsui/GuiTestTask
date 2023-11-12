cmake_minimum_required(VERSION 3.5)

project(GuiTestTask VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)
include_directories(${CMAKE_BINARY_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data/cell.qss ${CMAKE_BINARY_DIR}/cell.qss COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data/cellbutton.qss ${CMAKE_BINARY_DIR}/cellbutton.qss COPYONLY)

set(PROJECT_HDR
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include/cell.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include/celldialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include/mainwindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include/cellbutton.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include/cellbuttoneventfilter.h
)

set(PROJECT_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cell.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/celldialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cellbutton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cellbuttoneventfilter.cpp
)

set(PROJECT_UI
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/mainwindow.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/cell.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/celldialog.ui
)

set(PROJECT_QRC
    ${CMAKE_CURRENT_SOURCE_DIR}/data/icons.qrc
)

qt6_wrap_ui(UI_HDR ${PROJECT_UI})

add_executable(GuiTestTask
    ${PROJECT_HDR}
    ${PROJECT_SRC}
    ${PROJECT_QRC}
    ${UI_HDR}
)

target_link_libraries(GuiTestTask PRIVATE Qt6::Widgets)
