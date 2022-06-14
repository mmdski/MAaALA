macro(add_matrix_test basename)
    add_matrix_exe(${basename})
    add_test(NAME ${basename} COMMAND ${basename})

    if(("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang"))
        set_tests_properties(${basename} PROPERTIES ENVIRONMENT
            "ASAN_OPTIONS=detect_leaks=1:abort_on_error=0;LSAN_OPTIONS=suppressions=${CMAKE_SOURCE_DIR}/lsan.supp")
    endif()
endmacro()

add_matrix_test(test_matrix)
