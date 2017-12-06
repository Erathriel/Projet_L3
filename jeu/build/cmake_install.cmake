# Install script for directory: /home/evan/gf

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/evan/gf/include/gf")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/GF" TYPE DIRECTORY FILES "/home/evan/gf/examples" FILES_MATCHING REGEX "/[^/]*\\.cc$" REGEX "/[^/]*\\.png$" REGEX "/[^/]*\\.ttf$" REGEX "/[^/]*\\.xml$" REGEX "/CREDITS$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share" TYPE DIRECTORY FILES "/home/evan/gf/data/gf_tools")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/evan/gf/build/library/cmake_install.cmake")
  include("/home/evan/gf/build/examples/cmake_install.cmake")
  include("/home/evan/gf/build/tests/cmake_install.cmake")
  include("/home/evan/gf/build/docs/snippets/cmake_install.cmake")
  include("/home/evan/gf/build/games/bank_robbery_for_dummies/cmake_install.cmake")
  include("/home/evan/gf/build/games/gf_pong/cmake_install.cmake")
  include("/home/evan/gf/build/games/gf_2048/cmake_install.cmake")
  include("/home/evan/gf/build/games/huaca/cmake_install.cmake")
  include("/home/evan/gf/build/games/islands/cmake_install.cmake")
  include("/home/evan/gf/build/games/lux/cmake_install.cmake")
  include("/home/evan/gf/build/tools/gf_info/cmake_install.cmake")
  include("/home/evan/gf/build/tools/gf_noise/cmake_install.cmake")
  include("/home/evan/gf/build/tools/gf_dungeons/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/evan/gf/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
