cmake_minimum_required(VERSION 4.4)

project(cpp_cmake_prod LANGUAGES CXX)

include(CTest)

function(enable_strict_warnings target)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${target} PRIVATE -g -Wall -Wextra -Wpedantic -Werror)
  elseif(MSVC)
    target_compile_options(${target} PRIVATE /W4 /WX)
  endif()
endfunction()

add_subdirectory(src/calclib)
add_subdirectory(src/program)

if(BUILD_TESTING)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.18.0
    GIT_SHALLOW TRUE
    EXCLUDE_FROM_ALL
    SYSTEM
  )
  FetchContent_MakeAvailable(googletest)
  include(GoogleTest)
  add_subdirectory(tests)
endif()