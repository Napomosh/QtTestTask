cmake_minimum_required(VERSION 3.8)

project(TestTaskQt)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
#add_compile_options(/Wall)

find_package(Qt6Quick REQUIRED)
find_package(Qt6Qml REQUIRED)

include_directories(Models)
include_directories(Entities/include)

add_executable(${PROJECT_NAME}
    main.cpp
)
add_subdirectory(Entities)
add_subdirectory(Models)

target_link_libraries(${PROJECT_NAME}
        Qt6::Quick
        Qt6::Qml
        Entities
        Models
)