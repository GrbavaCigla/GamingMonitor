cmake_minimum_required(VERSION 3.5)

project(GamingMonitor LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES GamingMonitor_en_US.ts)

add_executable(GamingMonitor
  main.cpp
  dashboard.cpp
  dashboard.h
  ssh_get_info.cpp
  ssh_get_info.h
  login.cpp
  login.h
  login.ui
  ${TS_FILES}
)

add_subdirectory(libssh/)
add_subdirectory(psutil-cpp/)

target_link_libraries(GamingMonitor PRIVATE ssh psutil-cpp Qt5::Widgets)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
