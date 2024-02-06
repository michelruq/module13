cmake_minimum_required(VERSION 3.5)

project(module13)

set(SOURCE_LST 
    main.cpp
	graph.cpp
	)

add_executable(graph ${SOURCE_LST})

set(CXX_FLAGS "${CXX_FLAGS} -std=c++11 - Wall")