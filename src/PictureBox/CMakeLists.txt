cmake_minimum_required(VERSION 3.2)

project(PictureBox VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
  set(GUI_OPTION WIN32)
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
elseif(UNIX)
  set(GUI_OPTION )
endif ()

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0)
if(NOT GTKMM_FOUND)
  message(FATAL_ERROR "gtkmm-3.0 not found!")
endif()
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Resources/Logo.png COPYONLY)

add_executable(PictureBox ${GUI_OPTION} PictureBox.cpp)
target_link_libraries(PictureBox ${GTKMM_LIBRARIES})
