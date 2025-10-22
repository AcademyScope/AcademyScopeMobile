cmake_minimum_required(VERSION 3.16)

project(AcademyScopeMobile VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Sql)

qt_standard_project_setup(REQUIRES 6.8)

file(GLOB ProjectSrc
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/BackEnd/Src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/BackEnd/Src/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/BackEnd/Src/Utils/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/BackEnd/Src/Utils/*.hpp"

)

file(GLOB ProjectUI RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/UI/*.qml"
)

set(CMAKE_AUTOUIC_SEARCH_PATHS
    "Src"
    "UI"
)

include_directories(src)
include_directories(src/Util)
include_directories(Components/BackEnd/src)


qt_add_executable(appAcademyScopeMobile
    ${ProjectSrc}
)

qt_add_qml_module(appAcademyScopeMobile
    URI AcademyScopeMobile
    VERSION 1.0
    QML_FILES
        ${ProjectUI}
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
