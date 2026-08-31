add_library(calclib STATIC calclib.cc)

target_include_directories(calclib
  PUBLIC "${PROJECT_SOURCE_DIR}/include"
  PRIVATE "${PROJECT_SOURCE_DIR}/src"
)
target_compile_features(calclib PUBLIC cxx_std_23)
set_target_properties(calclib PROPERTIES CXX_EXTENSIONS OFF)
enable_strict_warnings(calclib)