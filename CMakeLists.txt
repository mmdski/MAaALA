cmake_minimum_required(VERSION 3.18)

project(ala)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

if(MSVC)
  add_compile_options(/guard:cf /analyze /permissive- /W4 /WX)

  macro(link_math target)
  endmacro()

else()
  add_compile_options(-Wall -Wextra -pedantic -Werror -fsanitize=address)
  add_link_options(-fsanitize=address)

  macro(link_math target)
    target_link_libraries(${target} m)
  endmacro()
endif()

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
add_subdirectory(chapter2)
