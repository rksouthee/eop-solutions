cmake_minimum_required(VERSION 3.6)

project(eop-solutions LANGUAGES NONE)

include(UseLATEX.cmake)

add_latex_document(eop.tex
	INPUTS chap01.tex chap02.tex
	)
