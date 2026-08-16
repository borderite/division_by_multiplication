# Install Unity
include(FetchContent)
FetchContent_Declare(
  unity_test_framework
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG cbcd08fa7de711053a3deec6339ee89cad5d2697
)
FetchContent_MakeAvailable(unity_test_framework)
set(TEST_COMMON_SOURCES test_common.h)
set(TEST_UNSIGNED_COMMON_SOURCES test_unsigned_div_common.inc ${TEST_COMMON_SOURCES})
set(TEST_SIGNED_COMMON_SOURCES test_signed_div_common.inc ${TEST_COMMON_SOURCES})
set(TEST_UNSIGNED_DOWN_SOURCES test_unsigned_div_down.inc ${TEST_UNSIGNED_COMMON_SOURCES})
set(TEST_UNSIGNED_UP_SOURCES test_unsigned_div_up.inc ${TEST_UNSIGNED_COMMON_SOURCES})
set(TEST_SIGNED_DOWN_SOURCES test_signed_div_down.inc ${TEST_UNSIGNED_COMMON_SOURCES})
set(TEST_SIGNED_ZERO_SOURCES test_signed_div_zero.inc ${TEST_UNSIGNED_COMMON_SOURCES})
set(TEST_SIGNED_UP_SOURCES test_signed_div_up.inc ${TEST_UNSIGNED_COMMON_SOURCES})
set_source_files_properties(
  test_unsigned_div_down.inc
  test_unsigned_div_up.inc
  ${TEST_UNSIGNED_COMMON_SOURCES}
  test_signed_div_down.inc
  test_signed_div_zero.inc
  test_signed_div_up.inc
  ${TEST_SIGNED_COMMON_SOURCES}
  PROPERTIES
  HEADER_FILE_ONLY TRUE
)
set(unsigned_down_tests
  test_unsigned_div_by_3_down_32
  test_unsigned_div_by_7_down_32
  test_unsigned_div_by_3_down_64
  test_unsigned_div_by_21_down_64
)

set(unsigned_up_tests
  test_unsigned_div_by_3_up_32
  test_unsigned_div_by_7_up_32
  test_unsigned_div_by_3_up_64
  test_unsigned_div_by_21_up_64
)
  
set(signed_zero_tests
  test_signed_div_by_3_zero_32
  test_signed_div_by_7_zero_32
  test_signed_div_by_3_zero_64
  test_signed_div_by_21_zero_64
)
set(signed_down_tests
  test_signed_div_by_3_down_32
  test_signed_div_by_7_down_32
  test_signed_div_by_3_down_64
  test_signed_div_by_21_down_64
)  
set(signed_up_tests
  test_signed_div_by_3_up_32
  test_signed_div_by_7_up_32
  test_signed_div_by_3_up_64
  test_signed_div_by_21_up_64
)
foreach (test ${unsigned_down_tests})
  add_executable(${test})
  target_sources(${test} PRIVATE ${test}.c ${TEST_UNSIGNED_DOWN_SOURCE}
  )
  target_include_directories(${test}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/nasm_examples/
    ${unity_SOURCE_DIR}/src/
  )
  target_link_libraries(${test} PRIVATE div_by_mult unity)
  add_test(NAME ${test} COMMAND ${test})
endforeach()
foreach (test ${unsigned_up_tests})
  add_executable(${test})
  target_sources(${test} PRIVATE ${test}.c ${TEST_UNSIGNED_UP_SOURCE}
  )
  target_include_directories(${test}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/nasm_examples/
    ${unity_SOURCE_DIR}/src/
  )
  target_link_libraries(${test} PRIVATE div_by_mult unity)
  add_test(NAME ${test} COMMAND ${test})
endforeach()
foreach (test ${signed_zero_tests})
  add_executable(${test})
  target_sources(${test} PRIVATE ${test}.c ${TEST_SIGNED_ZERO_SOURCE})
  target_include_directories(${test}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/nasm_examples/
    ${unity_SOURCE_DIR}/src/
  )
  target_link_libraries(${test} PRIVATE div_by_mult unity)
  add_test(NAME ${test} COMMAND ${test})
endforeach()
foreach (test ${signed_down_tests})
  add_executable(${test})
  target_sources(${test} PRIVATE ${test}.c ${TEST_SIGNED_DOWN_SOURCE})
  target_include_directories(${test}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/nasm_examples/
    ${unity_SOURCE_DIR}/src/
  )
  target_link_libraries(${test} PRIVATE div_by_mult unity)
  add_test(NAME ${test} COMMAND ${test})
endforeach()
foreach (test ${signed_up_tests})
  add_executable(${test})
  target_sources(${test} PRIVATE ${test}.c ${TEST_SIGNED_UP_SOURCE})
  target_include_directories(${test}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/nasm_examples/
    ${unity_SOURCE_DIR}/src/
  )
  target_link_libraries(${test} PRIVATE div_by_mult unity)
  add_test(NAME ${test} COMMAND ${test})
endforeach()

if (NO)
  add_executable(division_tests)
  target_sources(division_tests PRIVATE division_tests.c)
  target_include_directories(division_tests
    PRIVATE
    ${CMAKE_SOURCE_DIR}/nasm_examples/
    ${unity_SOURCE_DIR}/src/
  )
  target_link_libraries(division_tests PRIVATE div_by_mult unity)
endif()
