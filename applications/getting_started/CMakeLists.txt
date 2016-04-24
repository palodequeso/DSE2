cmake_minimum_required(VERSION 2.6)
project(DeepSpaceGames)
add_executable(getting_started ./main.cpp)
target_link_libraries(getting_started dsengine ${EXTLIBS})
