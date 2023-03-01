cmake_minimum_required(VERSION 3.18)
project(gameoflife)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

set(SFML_VERSION "2.5.1")

FetchContent_Declare(
        sfml
        URL "https://github.com/SFML/SFML/archive/refs/tags/2.5.1.tar.gz"
        DOWNLOAD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/_deps
)

FetchContent_MakeAvailable(sfml)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(gameoflife main.cpp Cell.cpp ConfigFile.cpp Simulation.cpp)

target_link_libraries(
        gameoflife
        PRIVATE
        sfml-network
        sfml-system
        sfml-graphics
        sfml-audio
        sfml-window
)