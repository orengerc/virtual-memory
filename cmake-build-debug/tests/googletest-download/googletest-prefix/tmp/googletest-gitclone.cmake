
if(NOT "/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitinfo.txt" IS_NEWER_THAN "/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests/googletest-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests/googletest-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --config "advice.detachedHead=false" "https://github.com/google/googletest.git" "googletest-src"
    WORKING_DIRECTORY "/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/google/googletest.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout main --
  WORKING_DIRECTORY "/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests/googletest-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'main'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests/googletest-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests/googletest-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitinfo.txt"
    "/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/cs/usr/oren_gerc/OS/virtual-memory/cmake-build-debug/tests/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt'")
endif()

