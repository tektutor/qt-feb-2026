cmake_minimum_required(VERSION 3.16)
project(VBox)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(VBox
    main.cpp
    MyDlg.h
    MyDlg.cpp
)

target_link_libraries(VBox PRIVATE Qt6::Widgets)
