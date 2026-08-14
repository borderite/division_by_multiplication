cmake_minimum_required(VERSION 3.31.6)
project(division_by_multiplication VERSION 0.0.1
  LANGUAGES C ASM_NASM)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(build_find_magic_number "Want to build the find magic number program" Yes)
option(test_nasm_examples "Want to build the nasm examples and thier unit tests" No)
if (build_find_magic_number)
  add_subdirectory(find_magic_number)
endif ()
if (test_nasm_examples)
  enable_testing()
  add_subdirectory(nasm_examples)
  add_subdirectory(tests)
#  add_test(NAME all_test COMMAND division_tests)
#  add_test(NAME unsigned_div_by_3_down_32 COMMAND test_unsigned_div_by_3_down_32)
endif ()

