cmake_minimum_required(VERSION 3.29)
project(Initiator VERSION 1.0)

set(
    VAR_PATH_TO_SOURCE ${PROJECT_SOURCE_DIR}/Sources
)

set(
    VAR_SOURCE
    ${VAR_PATH_TO_SOURCE}/Initiator.cpp
)

target_include_directories(${PROJECT_SOURCE_DIR}/Headers)

add_executable(${PROJECT_NAME} VAR_SOURCE)