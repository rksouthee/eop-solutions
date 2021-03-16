cmake_minimum_required(VERSION 3.6)

project(eop-solutions LANGUAGES CXX)

include(cmake/UseLATEX.cmake)

add_latex_document(eop_sln.tex
	INPUTS
	eop-code/eop.h
	eop-code/integers.h
	chap01.tex
	chap02.tex code/ex_2_1.cpp code/ex_2_2.cpp
	chap03.tex
	chap04.tex code/ex_4_1.cpp
	chap05.tex
	chap06.tex
	chap07.tex
	chap08.tex
	)

add_executable(eop
	eop-code/assertions.h
	eop-code/drivers.h
	eop-code/eop.h
	eop-code/integers.h
	eop-code/intrinsics.h
	eop-code/measurements.h
	eop-code/pointers.h
	eop-code/print.h
	eop-code/read.h
	eop-code/tests.h
	eop-code/type_functions.h
	eop-code/eop.cpp
	)

add_executable(ex_2_1 code/ex_2_1.cpp)
target_include_directories(ex_2_1 PRIVATE eop-code)

add_executable(ex_2_2 code/ex_2_2.cpp)
target_include_directories(ex_2_2 PRIVATE eop-code)

add_executable(levy code/levy.cpp)
target_include_directories(levy PRIVATE eop-code)

add_executable(brent code/brent.cpp)
target_include_directories(brent PRIVATE eop-code)

add_executable(ex_4_1 code/ex_4_1.cpp)
target_include_directories(ex_4_1 PRIVATE eop-code)
