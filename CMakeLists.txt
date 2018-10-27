cmake_minimum_required(VERSION 3.10)
project(strset)

set(CMAKE_CXX_STANDARD 17)

add_executable(strsetgit main.c strsetconst.h strsetconst.cc strset.h strset.cc)
