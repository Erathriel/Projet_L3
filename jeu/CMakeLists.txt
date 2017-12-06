cmake_minimum_required(VERSION 3.0)

project(GF
  VERSION 0.6.0
  LANGUAGES CXX C
)

if(NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
  message(STATUS "Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

option(GF_DEBUG "Activate debug build" ON)
option(GF_BUILD "Build" ON)
option(GF_SINGLE_COMPILTATION_UNIT "Build the library in a single file (unity build)" OFF)

include(GNUInstallDirs)
set(GF_DATADIR ${CMAKE_INSTALL_FULL_DATADIR})

if(MSVC)
  message(STATUS "Environment variables:")
  message(STATUS "- BOOST_INCLUDEDIR: $ENV{BOOST_INCLUDEDIR}")
  message(STATUS "- BOOST_LIBRARYDIR: $ENV{BOOST_LIBRARYDIR}")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(SDL2_BUILDING_LIBRARY TRUE)
find_package(SDL2 REQUIRED)

find_package(Boost REQUIRED COMPONENTS filesystem system)
find_package(Freetype REQUIRED)
find_package(ZLIB REQUIRED)

if(MSVC)
  message(STATUS "Using MSVC compiler")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DNOMINMAX /W4 /utf-8")
  link_directories(${Boost_LIBRARY_DIRS})
else()
  message(STATUS "Using GCC or Clang compiler")
  # assume it's a GNU-like compiler (GCC, clang)
  set(CMAKE_CXX_FLAGS                 "-Wall -Wextra -std=c++11")
  set(CMAKE_CXX_FLAGS_DEBUG           "-O0 -g")
  set(CMAKE_CXX_FLAGS_MINSIZEREL      "-Os -DNDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE         "-O3 -DNDEBUG")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO  "-O2 -g")
endif()

add_subdirectory(library)

install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/gf"
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)



if(GF_BUILD)
  add_subdirectory(game)
endif()

