#**********************************************************************************
# @File      CMakeLists.txt
# @Author    Alexis Nicole Benini, Ph.D.
# @Date      May 20th, 2022
#*********************************************************************************/

cmake_minimum_required (VERSION 3.8)

project ("has3")

# Set the software version
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)

# Get the latest abbreviated commit hash of the working branch
execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Configure a header file to pass some of the CMake settings
# to the source code (i.e. version number)
configure_file (
  "${PROJECT_SOURCE_DIR}/conf/Config.h.in"
  "${PROJECT_SOURCE_DIR}/src/Config.h"
)
  
# Include sub-projects.
add_subdirectory ("src")
