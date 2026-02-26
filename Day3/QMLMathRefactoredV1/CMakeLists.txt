# CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(MathApp
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC               ON)
set(CMAKE_AUTORCC               ON)

# Find Qt6 (adjust version requirement if needed)
find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

# Create the executable
qt_add_executable(MathApp
    main.cpp
    Math.h
    Math.cpp
)

# Define the QML module (this is the modern Qt 6 way)
qt_add_qml_module(MathApp
    URI App
    VERSION 1.0
    QML_FILES
        main.qml
    # RESOURCES
    #     images/icon.png     # uncomment & add files if you have resources
)

# Link Qt Quick
target_link_libraries(MathApp PRIVATE
    Qt6::Quick
)

# Optional: install targets (useful for packaging)
install(TARGETS MathApp
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
