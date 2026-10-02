cmake_minimum_required(VERSION 3.16)

project(PRACTICA3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PRACTICA3 main.cpp
    RLE.h
    RLE.cpp
    LZ78.h
    LZ78.cpp
    ENCRIPTACION.h
    ENCRIPTACION.cpp
    Integracion.h
    Integracion.cpp)

include(GNUInstallDirs)
install(TARGETS PRACTICA3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
