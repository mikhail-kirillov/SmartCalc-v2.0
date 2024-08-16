cmake_minimum_required(VERSION 3.16)

project(SmartCalc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 COMPONENTS PrintSupport REQUIRED)
find_package(Qt6 COMPONENTS Core REQUIRED)

set(PROJECT_SOURCES
        src/main.cc
        src/view/window.cc
        src/view/window.h
        src/view/window.ui
        src/view/calculator/calculator.cc
        src/view/calculator/calculator.h
        src/view/credit/credit.cc
        src/view/credit/credit.h
        src/view/deposit/deposit.cc
        src/view/deposit/deposit.h
        src/view/graph/graph.cc
        src/view/graph/graph.h
        src/view/graph/qcustomplot/qcustomplot.cpp
        src/view/graph/qcustomplot/qcustomplot.h
        src/model/calculator/calculator.cc
        src/model/calculator/calculator.h
        src/model/credit/credit.cc
        src/model/credit/credit.h
        src/model/deposit/deposit.cc
        src/model/deposit/deposit.h
        src/model/graph/graph.cc
        src/model/graph/graph.h
        src/controller/calculator/calculator.cc
        src/controller/calculator/calculator.h
        src/controller/credit/credit.cc
        src/controller/credit/credit.h
        src/controller/deposit/deposit.cc
        src/controller/deposit/deposit.h
        src/controller/graph/graph.cc
        src/controller/graph/graph.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartCalc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/view/graph/qcustomplot/qcustomplot.cpp src/view/graph/qcustomplot/qcustomplot.h
    )
else()
    message(FATAL_ERROR "Error with QT 6!")
endif()

target_link_libraries(SmartCalc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(SmartCalc PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SmartCalc)
endif()
set_target_properties(SmartCalc PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SmartCalc
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartCalc)
endif()

