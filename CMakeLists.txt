cmake_minimum_required(VERSION 3.15...3.26)
project(${SKBUILD_PROJECT_NAME} LANGUAGES C)

find_package(
  Python
  COMPONENTS Interpreter Development.Module
  REQUIRED)

python_add_library(foo MODULE foo/foo.c WITH_SOABI)

install(TARGETS foo DESTINATION foo)

python_add_library(bar MODULE bar/bar.c WITH_SOABI)

install(TARGETS bar DESTINATION bar)
