cmake_minimum_required(VERSION 3.21)
project(maaala VERSION 0.1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -pedantic -Werror)

include(FetchContent)
FetchContent_Declare(
  spam
  GIT_REPOSITORY https://github.com/mmdski/spa-matrix.git
  GIT_TAG main
)
FetchContent_MakeAvailable(spam)

include_directories(${spam_SOURCE_DIR}/include)

add_subdirectory(src)
include_directories(include)

macro(add_spam_exe basename)
  add_executable(${basename} ${basename}.c)
  target_link_libraries(${basename} spam m)
endmacro()

macro(add_ala_exe basename)
  add_executable(${basename} ${basename}.c)
  target_link_libraries(${basename} spam ala m)
endmacro()

add_subdirectory(chapter01)
add_subdirectory(chapter02)
add_subdirectory(chapter03)
add_subdirectory(chapter04)
