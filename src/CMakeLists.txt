#**********************************************************************************
# @File      CMakeLists.txt
# @Author    Alexis Nicole Benini, Ph.D.
# @Date      May 20th, 2022
#*********************************************************************************/

cmake_minimum_required (VERSION 3.8)

# The follow includes the Config.h containing the git hash.
include_directories(${CMAKE_SOURCE_DIR}/include)

# ================================================================
# Boost
# ----------------------------------------------------------------
#set(Boost_INCLUDE_DIR " " CACHE PATH "Boost header folder" )
#set(Boost_LIBRARY_DIR " " CACHE PATH "Boost library folder" )

#if(${Boost_INCLUDE_DIR} STREQUAL " ")
#  message(FATAL_ERROR "Boost_INCLUDE_DIR CANNOT BE EMPTY")
#endif() 
#if(${Boost_LIBRARY_DIR} STREQUAL " ")
#  message(FATAL_ERROR "Boost_LIBRARY_DIR CANNOT BE EMPTY")
#endif() 
#include_directories(${Boost_INCLUDE_DIR})
#link_directories(${Boost_LIBRARY_DIR})
# ================================================================

file(GLOB _HEADERS *.h *.hpp)
file(GLOB _SOURCES *.cpp)

add_executable(${PROJECT_NAME} ${_SOURCES} ${_HEADERS})

target_link_libraries(${PROJECT_NAME} boost_program_options)
target_link_libraries(${PROJECT_NAME} boost_chrono)
target_link_libraries(${PROJECT_NAME} pthread)



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()