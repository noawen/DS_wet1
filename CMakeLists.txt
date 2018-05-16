cmake_minimum_required(VERSION 3.7)
project(DSwet1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-DNDEBUG" )


set(SOURCE_FILES  avlTree.h   player.h player.cpp oasis.cpp oasis.h clan.h clan.cpp library1.cpp library1.h testMacros.h main1.cpp )
add_executable(DSwet1 ${SOURCE_FILES})