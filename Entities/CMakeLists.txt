cmake_minimum_required(VERSION 3.8)
project(Entities)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME} OBJECT
        src/DocumentEntity.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
        include/
)