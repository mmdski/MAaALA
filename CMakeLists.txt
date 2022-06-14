cmake_minimum_required(VERSION 3.18)

project(ala)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -pedantic -Werror -fsanitize=address)
add_link_options(-fsanitize=address)

include_directories(include)

add_subdirectory(src)

macro(add_matrix_exe basename)
  add_executable(${basename} ${basename}.c)
  target_link_libraries(${basename} PRIVATE matrix)
endmacro()

add_subdirectory(app)

enable_testing()
add_subdirectory(tests)

add_subdirectory(chapter1)
