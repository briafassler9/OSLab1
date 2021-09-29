# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Author> Bria Fassler (briafassler@gmail.com)

solution: main.c list.c list.h
		gcc -o list list.c main.c -I. -std=c99