cmake_minimum_required(VERSION 3.15)
project(catchExample)

set(CMAKE_CXX_STANDARD 14)
include_directories(/Users/rarce/ccom3034)
include_directories(/home/rarce/Dropbox/ccom3034-b92)
add_executable(main main.cpp List.h AList.cpp AList.h)
