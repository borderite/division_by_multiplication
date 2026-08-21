#!/usr/bin/env bash
cmake --fresh -DCMAKE_BUILD_TYPE=Debug -Dtest_nasm_examples=True -S . -B build
