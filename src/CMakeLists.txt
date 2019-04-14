
set(SOURCES HelloWorld.cpp)
set(HEADERS HelloWorld.hpp)

add_library(HelloWorldLib SHARED ${SOURCES} ${HEADERS})
set_target_properties(HelloWorldLib PROPERTIES VERSION ${PROJECT_VERSION})