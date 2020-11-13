cmake_minimum_required(VERSION 3.17)
project(Speech)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. DIR_SRCS)


add_executable(Speech ${DIR_SRCS} speechManger.cpp speechManger.h)

