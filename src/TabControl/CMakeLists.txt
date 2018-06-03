cmake_minimum_required(VERSION 3.2)

project(TabControl VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0)
if(NOT GTKMM_FOUND)
  message(FATAL_ERROR "gtkmm-3.0 not found!")
endif()
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(TabControl TabControl.cpp)
target_link_libraries(TabControl ${GTKMM_LIBRARIES})
