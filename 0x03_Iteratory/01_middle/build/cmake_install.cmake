<<<<<<<< HEAD:0x01_Kontenery sekwencyjne/removeVowels/build/_deps/googletest-subbuild/cmake_install.cmake
# Install script for directory: /home/patryks/Workspace/STL/exercises/06_removeVowels/build/_deps/googletest-subbuild
========
# Install script for directory: C:/Programming/GIT/workspace/STL/ex/0x06_iteratory/01_middle
>>>>>>>> f0e320d693c2f3b18096881c80abe336ffce0a9a:0x03_Iteratory/01_middle/build/cmake_install.cmake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/middle")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

<<<<<<<< HEAD:0x01_Kontenery sekwencyjne/removeVowels/build/_deps/googletest-subbuild/cmake_install.cmake
========
# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/msys64/mingw64/bin/objdump.exe")
endif()

>>>>>>>> f0e320d693c2f3b18096881c80abe336ffce0a9a:0x03_Iteratory/01_middle/build/cmake_install.cmake
if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<<< HEAD:0x01_Kontenery sekwencyjne/removeVowels/build/_deps/googletest-subbuild/cmake_install.cmake
file(WRITE "/home/patryks/Workspace/STL/exercises/06_removeVowels/build/_deps/googletest-subbuild/${CMAKE_INSTALL_MANIFEST}"
========
file(WRITE "C:/Programming/GIT/workspace/STL/ex/0x06_iteratory/01_middle/build/${CMAKE_INSTALL_MANIFEST}"
>>>>>>>> f0e320d693c2f3b18096881c80abe336ffce0a9a:0x03_Iteratory/01_middle/build/cmake_install.cmake
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
