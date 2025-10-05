cmake_minimum_required(VERSION 3.16)
project(MiniCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SRC src/calculator.cpp)
set(MAIN src/main.cpp)

set(LIBDIR ${CMAKE_SOURCE_DIR}/lib)
file(MAKE_DIRECTORY ${LIBDIR})

add_library(calculator STATIC ${SRC})
set_target_properties(calculator PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${LIBDIR}
)

add_executable(calculator_app ${MAIN})
target_link_libraries(calculator_app PRIVATE calculator fmt)

set_target_properties(calculator_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/compile
)
