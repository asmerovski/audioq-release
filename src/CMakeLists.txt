cmake_minimum_required(VERSION 3.16)
project(AudioQ VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(audioq
    main.cpp
    mainwindow.cpp
    mainwindow.h
    settingsdialog.cpp
    settingsdialog.h
)

target_link_libraries(audioq PRIVATE Qt6::Widgets)

install(TARGETS audioq DESTINATION bin)

enable_testing()
add_subdirectory(tests)
