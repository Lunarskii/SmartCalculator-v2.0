cmake_minimum_required(VERSION 3.5)

project(untitled VERSION 0.1 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "/usr/local/qt;/opt/qt;$ENV{QT_INSTALL_DIR};$ENV{QTDIR};~/Qt/")
set(CMAKE_PREFIX_PATH "/home/lunarskii/Qt/6.4.2/gcc_64/lib/cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR}PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(PROJECT_SOURCES
        model/smart.cpp
        model/credit.cpp
        model/deposit.cpp
        model/stack.cpp
        model/model.h

        view/view.cpp
        view/view.h
        view/smartview.cpp
        view/smartview.h
        view/creditview.cpp
        view/creditview.h
        view/depositview.cpp
        view/depositview.h
        view/qcustomplot.cpp
        view/qcustomplot.h

        view/.ui/view.ui
        view/.ui/smartview.ui
        view/.ui/creditview.ui
        view/.ui/depositview.ui

        view/.ui/ui_view.h
        view/.ui/ui_smartview.h
        view/.ui/ui_creditview.h
        view/.ui/ui_depositview.h

        controller/controller.cpp
        controller/controller.h

        main.cpp
)

set(TEST_SOURCES
        model/smart.cpp
        model/credit.cpp
        model/deposit.cpp
        model/stack.cpp
        model/model.h

        tests/test_core.cpp
        tests/test_core.h
        tests/test_smartcalc.cpp
        tests/test_creditcalc.cpp
        tests/test_depositcalc.cpp
)

add_executable(tests 
        ${TEST_SOURCES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(untitled
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET untitled APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(untitled SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(untitled
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(untitled PUBLIC Qt${QT_VERSION_MAJOR}::PrintSupport)
target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(tests PRIVATE ${GTEST_LIBRARIES} pthread)

include(GoogleTest)
gtest_discover_tests(tests)

set_target_properties(untitled PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS untitled
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled)
endif()
