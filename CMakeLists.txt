cmake_minimum_required(VERSION 2.8.9)
project(monodec)

include_directories(include)
include_directories(/usr/include/libnl3)

file(GLOB_RECURSE SOURCES "src/*".cc)

set (CMAKE_CXX_STANDARD 17)
# SET(GCC_COVERAGE_LINK_FLAGS    "-lnl-3 -lnl-route-3 -llxc -lpthread")
# SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}
# ${GCC_COVERAGE_LINK_FLAGS}")

add_executable(monodec ${SOURCES})

install(TARGETS monodec DESTINATION /usr/bin)
