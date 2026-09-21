cmake_minimum_required(VERSION 3.16)

project(PRACTICA2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PRACTICA2 main.cpp
    Funciones.h
    Funciones.cpp
    Funciones.h)

include(GNUInstallDirs)
install(TARGETS PRACTICA2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
