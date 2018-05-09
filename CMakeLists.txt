cmake_minimum_required(VERSION 3.7)
project(DSwet1)

set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_CXX_FLAGS "-DNDEBUG -Wall" )


set(SOURCE_FILES main.cpp  avlTree.cpp avlTree.h player.cpp player.h clan.cpp clan.h library1.cpp library1.h oasis.cpp oasis.h oasis.cpp )
add_executable(DSwet1 ${SOURCE_FILES})