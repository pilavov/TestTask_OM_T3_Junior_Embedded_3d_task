cmake_minimum_required(VERSION 3.24)
project(TestTask_OM_T3_Junior_Embedded_3d_task)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.71.0 REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(server server.cpp)
target_link_libraries(server ${Boost_LIBRARIES})



add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)
