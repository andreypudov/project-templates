add_library(program_core STATIC application.cc)

target_include_directories(program_core
  PUBLIC "${PROJECT_SOURCE_DIR}/include"
  PRIVATE "${PROJECT_SOURCE_DIR}/src"
)
target_link_libraries(program_core PRIVATE calclib)
target_compile_features(program_core PUBLIC cxx_std_23)
set_target_properties(program_core PROPERTIES CXX_EXTENSIONS OFF)
enable_strict_warnings(program_core)

add_executable(program main.cc)
target_link_libraries(program PRIVATE program_core)
set_target_properties(program PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
enable_strict_warnings(program)