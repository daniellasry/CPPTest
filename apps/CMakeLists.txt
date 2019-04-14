add_executable(cpptest cpptesttest.cpp)
target_link_libraries(cpptest PRIVATE HelloWorldLib)
target_include_directories(cpptest PRIVATE ${PROJECT_SOURCE_DIR}/src)