cmake_minimum_required(
  VERSION 3.18.4 FATAL_ERROR
)

project( BankAccount
  VERSION 1.0.0
  LANGUAGES CXX
)

set( target "bank_account" )

add_executable( ${target}
  app/account.cpp
  app/app.cpp
)

target_link_libraries( ${target} PRIVATE
  pthread
)

target_compile_features( ${target} PRIVATE
  cxx_std_17
)

target_compile_options( ${target} PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -Wshadow
  -Wdouble-promotion
)

set_target_properties( ${target} PROPERTIES
  OUTPUT_NAME bank_account
  RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)
