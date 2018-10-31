cmake_minimum_required(VERSION 3.10)
project(strset)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

add_executable(strset strset_test1.c strsetconst.h strsetconst.cc strset.h strset.cc)