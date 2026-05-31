cmake_minimum_required(VERSION 3.16)

# Version can be overridden at configure time by the release workflow:
#   cmake -DAUDIOQ_VERSION=1.2.3 ...
if(NOT DEFINED AUDIOQ_VERSION)
    set(AUDIOQ_VERSION "1.0.0")
endif()

project(AudioQ
    VERSION     ${AUDIOQ_VERSION}
    DESCRIPTION "Qt6 audio format converter for Linux"
    LANGUAGES   CXX
)

# ── Build settings ────────────────────────────────────────────────────────────
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Improve reproducibility for release builds
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-O2 -DNDEBUG)
endif()

# ── Dependencies ──────────────────────────────────────────────────────────────
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# ── Main executable ───────────────────────────────────────────────────────────
add_executable(audioq
    main.cpp
    mainwindow.cpp
    mainwindow.h
    settingsdialog.cpp
    settingsdialog.h
)

target_link_libraries(audioq PRIVATE Qt6::Widgets)

target_compile_definitions(audioq PRIVATE
    AUDIOQ_VERSION_STRING="${PROJECT_VERSION}"
)

# ── Install targets ───────────────────────────────────────────────────────────
include(GNUInstallDirs)

install(TARGETS audioq
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES audioq.svg
    DESTINATION ${CMAKE_INSTALL_DATADIR}/icons/hicolor/scalable/apps
    RENAME audioq.svg
)

install(FILES audioq.desktop
    DESTINATION ${CMAKE_INSTALL_DATADIR}/applications
)

# ── Tests ─────────────────────────────────────────────────────────────────────
enable_testing()
add_subdirectory(tests)
