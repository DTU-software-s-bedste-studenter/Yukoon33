cmake_minimum_required(VERSION 3.24)
project(Yukoon33 C)

set(CMAKE_C_STANDARD 23)

add_executable(Yukoon33 src/src/main.c src/src/utils.c src/headders/utils.h src/src/initcmds.c src/headders/initcmds.h src/src/view.c src/headders/view.h src/headders/structs.h src/src/linkedlists.c src/headders/linkedlists.h)
