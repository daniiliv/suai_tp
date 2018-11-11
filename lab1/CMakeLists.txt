cmake_minimum_required(VERSION 3.12)
project(suai_tp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_SXX_FLAGS "-lncurses")
add_executable(suai_tp main.cpp train.cpp trainList.cpp userInterface.cpp train.h trainList.h userInterface.h)