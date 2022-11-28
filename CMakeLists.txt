cmake_minimum_required(VERSION 3.6)
project(resampler)
add_definitions(-DWEBRTC_MAC)
add_compile_options(-mcpu=apple-m1)
set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUGS "$ENV{CXXFLAGS} -lldb")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# if (CMAKE_BUILD_TYPE STREQUAL "Debug")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall -Wno-unused-variable")
# else ()
#     set(CMAKE_BUILD_TYPE "Release")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")
# endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

file(GLOB resample_src
        ${CMAKE_CURRENT_LIST_DIR}/src/*.c
        ${CMAKE_CURRENT_LIST_DIR}/src/*.cc
        )
file(GLOB resample_inc ${CMAKE_CURRENT_LIST_DIR}/inc/*.h)
list(FILTER resample_inc EXCLUDE REGEX ".*signal_processing_library.h")
message("resample_inc:" ${resample_inc})
message("current_list_dir:"${CMAKE_CURRENT_LIST_DIR})

set(RESAMPLER_COMPILE_CODE ${resample_src})
include_directories(${resample_inc})
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/demo/demo_resample.cc ${RESAMPLER_COMPILE_CODE})