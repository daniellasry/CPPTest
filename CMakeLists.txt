cmake_minimum_required(VERSION 3.14)

project(CPPTest VERSION 1.0.0 DESCRIPTION "Testing C++ wrappers")

# To build shared libraries in Windows, we set CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS to TRUE.
# See https://cmake.org/cmake/help/v3.4/variable/CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS.html
# See https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# cppyy
execute_process(COMMAND cling-config --cmake OUTPUT_VARIABLE CPYY_MODULE_PATH OUTPUT_STRIP_TRAILING_WHITESPACE)
# Make sure this is set to something like:
# ~/.local/lib/python2.7/site-packages/cpyy_backend/cmake 
message("CPYY_MODULE_PATH: " ${CPYY_MODULE_PATH})
list(INSERT CMAKE_MODULE_PATH 0 ${CPYY_MODULE_PATH})

find_package(Cppyy)

set(SOURCES HelloWorld.cpp)
set(HEADERS HelloWorld.h)

add_library(HelloWorldLib SHARED ${SOURCES})
set_target_properties(HelloWorldLib PROPERTIES VERSION ${PROJECT_VERSION})

# Note this is a necessary compile flag for cppyy bindings to work.
set_target_properties(HelloWorldLib PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(HelloWorldLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

cppyy_add_bindings(
    "CPPTest" "1.0.0" "Daniel Lasry" ""
    LANGUAGE_STANDARD "14"
    GENERATE_OPTIONS "-D__PIC__;-Wno-macro-redefined"
    INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
    LINK_LIBRARIES HelloWorldLib
    H_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
    H_FILES ${HEADERS}
)

add_executable(cpptest main.cpp)
target_link_libraries(cpptest PUBLIC HelloWorldLib)