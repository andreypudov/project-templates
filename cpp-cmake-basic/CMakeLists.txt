cmake_minimum_required(VERSION 4.4)

project(cpp_cmake_basic LANGUAGES CXX)

add_executable(program program.cc)

target_compile_features(program PRIVATE cxx_std_23)
set_target_properties(program PROPERTIES CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  target_compile_options(program PRIVATE -g -Wall -Wextra -Wpedantic -Werror)
elseif(MSVC)
  target_compile_options(program PRIVATE /W4 /WX)
endif()