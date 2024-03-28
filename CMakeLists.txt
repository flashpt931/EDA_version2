cmake_minimum_required(VERSION 3.27)
project(ProjetoEDA)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjetoEDA main.cpp
        Abertura_de_ficheiro.cpp
        structs.h
        menu.cpp
        Abertura_de_ficheiro.h
        seccoes.cpp
        organizacao_Pecas.h
        organizacao_Pecas.cpp)
