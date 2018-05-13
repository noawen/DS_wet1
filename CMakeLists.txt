cmake_minimum_required(VERSION 3.7)
project(DSwet1)

set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_CXX_FLAGS "-DNDEBUG -Wall" )


set(SOURCE_FILES  avlTree.h   player.h player.cpp oasis.cpp oasis.h clan.h clan.cpp library1.cpp library1.h tests2.cpp testMacros.h)
add_executable(DSwet1 ${SOURCE_FILES})