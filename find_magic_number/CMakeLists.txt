add_executable(find_magic_number)
target_sources(find_magic_number PRIVATE find_magic_number.c)
find_library(GMP_LIB
  NAMES gmp
)
if (GMP_LIB)
  target_link_libraries(find_magic_number PRIVATE ${GMP_LIB})
else ()
  cmake_minimum_required(VERSION 3.20)

  project(myproject C)

  include(ExternalProject)

  set(GMP_PREFIX ${CMAKE_BINARY_DIR}/gmp)

  ExternalProject_Add(gmp
    URL https://gmplib.org/download/gmp/gmp-6.3.0.tar.xz
    PREFIX ${CMAKE_BINARY_DIR}/gmp-build

    CONFIGURE_COMMAND
    <SOURCE_DIR>/configure
    --prefix=${GMP_PREFIX}
    --disable-shared
    --enable-static

    TEST_COMMAND make check
    
    BUILD_BYPRODUCTS ${GMP_PREFIX}/lib/libgmp.a
  )
  add_dependencies(find_magic_number gmp)
  target_include_directories(find_magic_number PRIVATE ${GMP_PREFIX}/include)
  target_link_libraries(find_magic_number PRIVATE ${GMP_PREFIX}/lib/libgmp.a)
endif ()

install(TARGETS find_magic_number)
