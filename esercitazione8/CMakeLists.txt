cmake_minimum_required(VERSION 3.10)

# Nome del progetto
project(Esercitazione8)

# Impostiamo lo standard C++ al 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Attiviamo i warning per scrivere codice pulito
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Definiamo l'eseguibile e i file sorgente
add_executable(es8 es8.cpp)