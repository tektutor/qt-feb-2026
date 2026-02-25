cmake_minimum_required(VERSION 3.16)
project(GUIThreadsApp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

set(PROJECT_SOURCES
        main.cpp
        MainDlg.cpp
        MainDlg.h
	TabDlg.cpp
	TabDlg.h
	Thread.cpp
	Thread.h
)

qt_add_executable(GUIThreadsApp
        ${PROJECT_SOURCES}
)

target_link_libraries(GUIThreadsApp PRIVATE Qt6::Widgets)
