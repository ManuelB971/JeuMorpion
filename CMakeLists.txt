cmake_minimum_required(VERSION 3.27)
project(JeuMorpion)

set(CMAKE_CXX_STANDARD 23)

add_executable(JeuMorpion main.cpp
        Morpion.cpp
        Morpion.h
        Joueur.cpp
        Joueur.h
        Grille.cpp
        Grille.h
        robot.cpp
        robot.h)
