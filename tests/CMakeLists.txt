# Install Unity
include(FetchContent)
FetchContent_Declare(
  unity_test_framework
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG cbcd08fa7de711053a3deec6339ee89cad5d2697
)
FetchContent_MakeAvailable(unity_test_framework)
add_executable(division_tests)
target_sources(division_tests PRIVATE division_tests.c)
target_include_directories(division_tests
  PRIVATE
  ${CMAKE_SOURCE_DIR}/nasm_examples/
  ${unity_SOURCE_DIR}/src/
)
target_link_libraries(division_tests PRIVATE div_by_mult unity)



