cmake_minimum_required(VERSION 3.0)

project(leetcode)

# Option to include all subdirectories that contain a CMakeLists.txt
file(GLOB children RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)
foreach(child ${children})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${child})
        if(EXISTS ${CMAKE_SOURCE_DIR}/${child}/CMakeLists.txt)
            add_subdirectory(${child})
        endif()
    endif()
endforeach()
