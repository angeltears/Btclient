cmake_minimum_required(VERSION 3.9)
project(Btclient)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        BTclient
        main.cc
        Log.cc
        Log.h
)
target_link_libraries(BTclient muduo_base)
target_link_libraries(BTclient pthread)