cmake_minimum_required(VERSION 3.6)

project(eop-solutions LANGUAGES CXX)

include(UseLATEX.cmake)

add_latex_document(eop.tex
	INPUTS chap01.tex chap02.tex code/ex_2_1.cpp
	)

add_executable(ex_2_1 code/ex_2_1.cpp)
