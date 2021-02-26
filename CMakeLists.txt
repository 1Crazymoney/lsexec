cmake_minimum_required(VERSION 3.10)
project(lsexec CXX)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/demonic)
include_directories(src)
add_executable(lsexec src/main.cpp src/main.h)
target_link_libraries(lsexec demonic)
install(TARGETS lsexec
        LIBRARY
        DESTINATION lib
        COMPONENT Libraries
        NAMELINK_COMPONENT Development
        PUBLIC_HEADER
        DESTINATION include
        COMPONENT Development
        )