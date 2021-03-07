cmake_minimum_required(VERSION 3.6)

project(eop-solutions LANGUAGES CXX)

include(UseLATEX.cmake)

add_latex_document(eop.tex
	INPUTS chap01.tex chap02.tex code/ex_2_1.cpp code/ex_2_2.cpp eop-code/eop.h
	chap03.tex
	)

add_executable(ex_2_1 code/ex_2_1.cpp)
target_include_directories(ex_2_1 PRIVATE eop-code)

add_executable(ex_2_2 code/ex_2_2.cpp)
target_include_directories(ex_2_2 PRIVATE eop-code)

add_executable(levy code/levy.cpp)
target_include_directories(levy PRIVATE eop-code)

add_executable(brent code/brent.cpp)
target_include_directories(brent PRIVATE eop-code)
