cmake_minimum_required(VERSION 3.0.0)

project(critical_path_solution)

include_directories(./incl incl)

aux_source_directory(./src src)

add_executable(${PROJECT_NAME} ${src})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE ${incl}
)