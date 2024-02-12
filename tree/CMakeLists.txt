cmake_minimum_required(VERSION 3.5)

project(Module13)

set(SRC_LST 
      main.cpp
	  tree.cpp
	  node.cpp)

add_executable( tree ${SRC_LST} )

set(CXX_FLAGS "${CXX_FLAGS} -std=c++11 - Wall")