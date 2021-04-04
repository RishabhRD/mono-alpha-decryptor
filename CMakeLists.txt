cmake_minimum_required(VERSION 2.8.9)
project(monodec)

enable_testing()

include_directories(include)
include_directories(/usr/include/libnl3)

file(GLOB_RECURSE SOURCES "src/*".cc)

set (CMAKE_CXX_STANDARD 17)
# SET(GCC_COVERAGE_LINK_FLAGS    "-lnl-3 -lnl-route-3 -llxc -lpthread")
# SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}
# ${GCC_COVERAGE_LINK_FLAGS}")

add_executable(monodec ${SOURCES})
find_package(Catch2 REQUIRED)
file(GLOB testfiles "test/*".cc "src/*".cc)
add_executable(tests ${testfiles})
target_link_libraries(tests PRIVATE Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)

install(
	TARGETS tests
	RUNTIME DESTINATION bin
)

install(TARGETS monodec DESTINATION /usr/bin)
