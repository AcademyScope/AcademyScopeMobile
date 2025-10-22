cmake_minimum_required(VERSION 3.16)

project(AcademyScopeMobile VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

file(GLOB ProjectSrc
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/*.hpp"
)

file(GLOB ProjectQML RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/QML/*.qml"
)
qt_add_executable(appAcademyScopeMobile
    ${ProjectSrc}
)

qt_add_qml_module(appAcademyScopeMobile
    URI AcademyScopeMobile
    VERSION 1.0
    QML_FILES
        ${ProjectQML}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appAcademyScopeMobile PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appAcademyScopeMobile
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appAcademyScopeMobile
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appAcademyScopeMobile
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
