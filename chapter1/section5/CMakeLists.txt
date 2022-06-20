add_executable(example example.c)
link_math(example)

add_executable(example1.5.1 example1.5.1.c matrix.c gauss.c)
link_math(example1.5.1)

add_executable(example1.5.2 example1.5.2.c matrix.c gauss.c)
target_link_libraries(example1.5.2)
link_math(example1.5.2)

add_executable(example1.5.3 example1.5.3.c matrix.c gauss.c)
target_link_libraries(example1.5.3)
link_math(example1.5.3)

add_executable(problem1.5.1 problem1.5.1.c matrix.c gauss.c)
target_link_libraries(problem1.5.1)
link_math(problem1.5.1)

add_executable(problem1.5.2 problem1.5.2.c matrix.c gauss.c)
target_link_libraries(problem1.5.2)
link_math(problem1.5.2)
