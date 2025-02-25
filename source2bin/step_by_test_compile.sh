#!/bin/bash

#Preprocessor
gcc -E -o hello_world.i hello_world.c

#Compiler
gcc -S -o hello_world.s hello_world.i

#Assembler
as -o hello_world.o hello_world.s

#Linker
gcc -o hello_world hello_world.o
