cmake_minimum_required(VERSION 3.10)

project(wjson)

set(TARGET ${CMAKE_PROJECT_NAME})
set(DIR ${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE SOURCES ${DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${DIR}/src/*.h*)

add_executable(${TARGET} ${SOURCES})

target_include_directories(${TARGET}
  PRIVATE
  ${DIR}/src
)
