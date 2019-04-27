cmake_minimum_required(VERSION 3.0.0)
project(dyingChaos VERSION 0.0.0)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -O3 -g")
include(CTest)
enable_testing()

add_executable(dyingChaos main.cpp ensemble.cpp bifurcation.cpp model.cpp )


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
