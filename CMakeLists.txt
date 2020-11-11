cmake_minimum_required(VERSION 3.5)

project(load LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package (SQLite3)
add_executable(
     ${PROJECT_NAME}
        "main.cpp"
)

add_subdirectory( ${PROJECT_SOURCE_DIR}/lib/libsqlite3-master)
add_subdirectory( ${PROJECT_SOURCE_DIR}/lib/glm )

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/lib/libsqlite3-master
)

add_compile_options(-fPIC -O3 -march=haswell -std=c++1z)

target_include_directories(${PROJECT_NAME}  PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME}  PUBLIC ${PROJECT_SOURCE_DIR}/source)

target_link_libraries(${PROJECT_NAME} glm sqlite3)
