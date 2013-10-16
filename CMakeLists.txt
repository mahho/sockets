cmake_minimum_required(VERSION 2.6)

#add_subdirectory(modules)

add_executable (server main.cpp server.cpp)

target_link_libraries (server pthread)



