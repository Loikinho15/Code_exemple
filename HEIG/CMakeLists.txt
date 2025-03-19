cmake_minimum_required(VERSION 3.29)
project(HEIG)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(HEIG
        ../HEIG_VD/ClasseRecueuilExercice/Date.cpp
        ../HEIG_VD/ClasseRecueuilExercice/jours_entre.cpp
        Labos/Labo2/Labo_02.cpp
        Labos/Labo3/Labo_03.cpp
        Labos/Labo4/Labo_04.cpp
        ../HEIG_VD/ClasseRecueuilExercice/maLibrairie.cpp
        MesLibrairies/personne.h
        receuil_exercice.cpp
        ../HEIG_VD/ClasseRecueuilExercice/to_string.cpp
        MesLibrairies/maLibrairie.h
        Labos/Labo5/main.cpp
        Labos/Labo5/montantEnToutesLettres.cpp
        Labos/Labo5/montantEnToutesLettres.h
)
