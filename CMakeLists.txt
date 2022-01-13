cmake_minimum_required (VERSION 3.8)
project (gmath VERSION 0.1 DESCRIPTION "Stupidly simple maths library")


if (DEFINED BUILD_TESTS)
	add_subdirectory(${PROJECT_SOURCE_DIR}/src/tests)
endif()

SET(SOURCES	${PROJECT_SOURCE_DIR}/src/gmath/gmath.h)

# Header-only library, i.e. no build output or source files provided
add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME} INTERFACE ${SOURCES})
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/src/gmath)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)