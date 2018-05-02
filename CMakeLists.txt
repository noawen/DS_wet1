cmake_minimum_required(VERSION 3.7)
project(DSwet1)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "-DNDEBUG -Wall" )

set(SOURCE_FILES main.cpp  avlTree.cpp avlTree.h)
add_executable(DSwet1 ${SOURCE_FILES})