set(SOURCES gmath.cpp)
set(LIBRARIES gmath)

add_executable(tests ${SOURCES})

include(${PROJECT_SOURCE_DIR}/dependencies/catch2/catch2.cmake)

target_include_directories(tests PUBLIC ${CATCH2_INCLUDE_DIRS})

set_target_properties(tests PROPERTIES 
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(tests	${LIBRARIES})