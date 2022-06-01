cmake_minimum_required(VERSION 2.8.2)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           main
  SOURCE_DIR        "/cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/tests_os_ex4/googletest-src"
  BINARY_DIR        "/cs/usr/nitaiseri/Desktop/OS/virtual-memory/cmake-build-debug/tests_os_ex4/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
