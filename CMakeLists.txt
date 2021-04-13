cmake_minimum_required(VERSION 3.16.3)

project(OBSTACLE_AVOIDANCE VERSION 0.1)

set(TITLE "OBSTACLE AVOIDANCE")
message(STATUS ${TITLE} " Version: " ${PROJECT_VERSION})

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

FIND_PACKAGE(OpenCV REQUIRED)

INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )

add_subdirectory(examples)
