cmake_minimum_required(VERSION 3.5)

project(Module13)

set(SRC_LIST
    main.cpp
	binarytree.cpp
	node.cpp)

add_executable(binarytree ${SRC_LIST})

set(CXX_FLAGS "${CXX_FLAGS} -std=c++11 - Wall")