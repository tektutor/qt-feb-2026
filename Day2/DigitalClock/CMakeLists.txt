cmake_minimum_required(VERSION 3.16)
project(DigitalClock)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

set(PROJECT_SOURCES
        main.cpp
	ClockDlg.cpp
	ClockDlg.h
)

qt_add_executable(DigitalClock
        ${PROJECT_SOURCES}
)

target_link_libraries(DigitalClock PRIVATE Qt6::Widgets Qt6::Core )
