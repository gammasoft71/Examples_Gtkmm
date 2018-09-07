cmake_minimum_required(VERSION 3.0)
project(Label VERSION 1.0.0)

find_path(GTKMM_INCLUDE_DIRS gtkmm.h)
find_library(GTKMM_LIBRARY gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
link_libraries(${GTKMM_LIBRARIES})

if (MSVC)
  set(GUI_OPTION WIN32)
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(Label ${GUI_OPTION} Label.cpp)
