cmake_minimum_required(VERSION 3.14)

project(CPPTest VERSION 1.0.0 LANGUAGES CXX DESCRIPTION "Testing C++ wrappers")

# To build shared libraries in Windows, we set CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS to TRUE.
# See https://cmake.org/cmake/help/v3.4/variable/CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS.html
# See https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(SOURCES HelloWorld.cpp)
set(HEADERS HelloWorld.h)

add_library(HelloWorldLib SHARED ${SOURCES})
set_target_properties(HelloWorldLib PROPERTIES VERSION ${PROJECT_VERSION})

add_executable(cpptest main.cpp)
target_link_libraries(cpptest PUBLIC HelloWorldLib)