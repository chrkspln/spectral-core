cmake_minimum_required(VERSION 4.2.3)
project(spectral VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # needed by clang-tidy

option(SPECTRAL_BUILD_TESTS    "Build the test suite"        ON)
option(SPECTRAL_CLANG_TIDY     "Enable clang-tidy analysis"  ON)
option(SPECTRAL_CPPCHECK       "Enable cppcheck analysis"    ON)

if(SPECTRAL_CLANG_TIDY)
    find_program(CLANG_TIDY clang-tidy REQUIRED)
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY} --config-file=${CMAKE_SOURCE_DIR}/.clang-tidy)
endif()

if(SPECTRAL_CPPCHECK)
    find_program(CPPCHECK cppcheck REQUIRED)
    set(CMAKE_CXX_CPPCHECK ${CPPCHECK} --suppress=syntaxError --enable=all --inconclusive)
endif()

include(cmake/deps.cmake)

add_subdirectory(src)

if(SPECTRAL_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

add_subdirectory(app)
