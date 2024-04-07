cmake_minimum_required(VERSION 3.8)
project(Models)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6Quick REQUIRED)


add_library(${PROJECT_NAME} OBJECT
    "DocumentViewerModel.cpp"
    "DocumentEditorModel.cpp")
target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt6::Quick
)
target_include_directories(${PROJECT_NAME} PUBLIC
        ../Entities/include
)