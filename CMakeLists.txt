cmake_minimum_required(VERSION 3.8)
project(Semaphores)

set(CMAKE_C_STANDARD 99)
set(LIB djikstra.h shared.h)

add_executable(init     init.c     ${SOURCE_FILES_INIT}    ${LIB})
add_executable(prod     prod.c     ${SOURCE_FILES_PROD}    ${LIB})
add_executable(conso    conso.c    ${SOURCE_FILES_CONSO}   ${LIB})
add_executable(clear    clear.c    ${SOURCE_FILES_CLEAR}   ${LIB})