cmake_minimum_required(VERSION 3.6)

project(eop-solutions LANGUAGES CXX)

include(cmake/UseLATEX.cmake)

add_latex_document(doc/eop_sln.tex
	INPUTS
	eop-code/eop.h
	eop-code/integers.h
	doc/chap01.tex
	doc/chap02.tex
	doc/chap03.tex
	doc/chap04.tex
	doc/chap05.tex
	doc/chap06.tex
	doc/chap07.tex
	doc/chap08.tex
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

add_executable(levy code/levy.cpp)
target_include_directories(levy PRIVATE eop-code)

add_executable(brent code/brent.cpp)
target_include_directories(brent PRIVATE eop-code)
