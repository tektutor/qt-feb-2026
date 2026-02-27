# CMakeGrids.txt
cmake_minimum_required(VERSION 3.16)

project(GridViewDemo
    VERSION 1.0
    LANGUAGES CXX
)

# Find Qt6 (adjust version requirement if needed)
find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

# Create the executable
qt_add_executable(GridViewDemo
    main.cpp
)

# Define the QML module (this is the modern Qt 6 way)
qt_add_qml_module(GridViewDemo
    URI App
    VERSION 1.0
    QML_FILES
        main.qml
    # RESOURCES
    #     images/icon.png     # uncomment & add files if you have resources
)

# Link Qt Quick
target_link_libraries(GridViewDemo PRIVATE
    Qt6::Quick
)

# Optional: install targets (useful for packaging)
install(TARGETS GridViewDemo
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
