cmake_minimum_required(VERSION 3.5)
project(Labo-testing)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-pthread")

add_library(gtest lib/gtest-all.cc)

add_executable(Labo-testing
        main.cpp
        src/esPrimo.h
        src/esPrimo.cpp
        src/puntaje.h
        src/puntaje.cpp
        src/sandia.h
        src/sandia.cpp
        src/contarPicos.h
        src/contarPicos.cpp
        src/sopaDeLetras.h
        src/sopaDeLetras.cpp
        src/aTriplas.h
        src/aTriplas.cpp
        src/filasQueSuman.cpp
        src/filasQueSuman.h
        test/esPrimoTEST.cpp
        test/puntajeTEST.cpp
        test/sandiaTEST.cpp
        test/contarPicosTEST.cpp
        test/aTriplasTEST.cpp
        test/sopaDeLetrasTEST.cpp
        test/filasQueSumanTEST.cpp
        )

set_target_properties(Labo-testing PROPERTIES COMPILE_FLAGS "-g --coverage")
set_target_properties(Labo-testing PROPERTIES LINK_FLAGS "-g --coverage")

target_link_libraries(Labo-testing gtest)


