
message(STATUS "Vcpkg toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

cmake_minimum_required(VERSION 3.10)

project(example CXX)


find_package(fgt-cpp-lib-01 REQUIRED)

add_executable(example src/main.cpp)

target_include_directories(example PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(example PRIVATE cxx_std_17)

target_link_libraries(example PRIVATE fgt-cpp-lib-01::fgtUtilLib)
