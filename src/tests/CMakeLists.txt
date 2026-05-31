cmake_minimum_required(VERSION 3.16)
project(AudioQTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(tst_audioq tst_audioq.cpp)
target_link_libraries(tst_audioq PRIVATE Qt6::Test)
add_test(NAME AudioQTests COMMAND tst_audioq)
