This repository provides a few examples of the division by multiplication method using NASM. It also includes a program to calculate the parameters required by the division by multiplication method. You can find a note on the division by multiplication method on [this page](https://functor.network/user/3329/entry/1938).

The following three directories contain source files.

- `find_magic_number`: The source files for the program to calculate the parameters. You can build and install this program, if you like. The build of this program requires [GNU Multiple Precision Arithmetic Library (GMP)](https://gmplib.org/). If it is not installed on your computer, the build process automatically downloads its source code and builds the GMP library.

- `nasm_examples`: Examples of the division by multiplication method implemented in NASM. You can build a library including the example functions. But it is not built by default, because the library is only used for the unit tests of the example codes.

- `tests`: The unit test files for the codes in `nasm_examples`. If you build them, the test executable is tests/division_tests in the build directory. You can also run the test by the `ctest` command. The build of the tests requires the [Unity unit testing framework](https://www.throwtheswitch.org/unity). If it is not installed on your computer, the build process automatically downloads it and builds the required library.

To build the `find_margic_number` program and install it to the standard binary directory, run the following commands in the project root directory.
```
mkdir build
cmake -S . -B build 
cmake --build build
cmake --install 
```

If you also want to build the nasm example library and unit tests, run the following commands intead:
```
mkdir build
cmake -Dtest_nasm_examples=True -S . -B build 
cmake --build build
cmake --install 
```
The test executable is `build/tests/division_tests`.


