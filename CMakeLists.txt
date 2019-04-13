cmake_minimum_required(VERSION 3.14)

project(CPPTest VERSION 1.0.0 LANGUAGES CXX)

add_library(
    HelloWorldLib SHARED
    HelloWorld.h
    HelloWorld.cpp
)

add_executable(cpptest main.cpp)

target_link_libraries(cpptest PRIVATE HelloWorldLib)