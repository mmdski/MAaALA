add_library(matrix
  matrix.c)

macro(add_matrix_exe basename)
  add_executable(${basename} ${basename}.c)
  target_link_libraries(${basename} PRIVATE matrix)
endmacro()
