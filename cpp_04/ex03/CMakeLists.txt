cmake_minimum_required(VERSION 3.25)
project(ex03)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        ex03
        AMateria.cpp
        Character.cpp
        Cure.cpp
        Ice.cpp
        main.cpp
        MateriaSource.cpp)
