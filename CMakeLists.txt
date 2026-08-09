#The root CMakeLists.txt file.
cmake_minimum_required(VERSION 3.28)

set(CMAKE_TOOLCHAIN_FILE 
    "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" 
    CACHE STRING 
    "Vcpkg toolchain file"
)

project(pong  VERSION 1.0.0 LANGUAGES CXX)

#Require C++23
set(CMAKE_CXX_STANDARD_REQUIRED ON) #Make C++23 a hard requirement
set(CMAKE_CXX_STANDARD 23) # Default C++ standard for targets
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(fmt CONFIG REQUIRED)
find_package(
    SFML 3 
    CONFIG REQUIRED 
    COMPONENTS
        Graphics
        Window
        System
)

message(STATUS "SFML version: ${SFML_VERSION}")
message(STATUS "SFML directory: ${SFML_DIR}")

add_executable(${PROJECT_NAME})

        target_sources(${PROJECT_NAME}
                PRIVATE
                    src/main.cpp
                    
                PUBLIC
                FILE_SET CXX_MODULES 
                FILES
                    modules/utilities.ixx
        )
        target_link_libraries(${PROJECT_NAME} 
            PRIVATE 
                fmt::fmt
                SFML::Graphics
                SFML::Window
                SFML::System
        )