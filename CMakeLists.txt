cmake_minimum_required(VERSION 3.10)

project(OatApp LANGUAGES CXX)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

find_package(oatpp 1.3.0 REQUIRED)
# find_package(oatpp-sqlite 1.3.0 REQUIRED)
include_directories(src/dto)

add_subdirectory(src)
add_subdirectory(test)
