cmake_minimum_required(VERSION 3.9)

get_filename_component(PROJECT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_DIR_NAME})

# Find all .cpp files in the current directory
file(GLOB SOURCES "*.cpp")

foreach(SOURCE ${SOURCES})
    # Get the file name without the extension
    get_filename_component(FILE_NAME ${SOURCE} NAME_WE)
    set(TARGET_NAME "${PROJECT_DIR_NAME}_${FILE_NAME}")

    # Check if the corresponding header file exists
    set(HEADER_FILE "${FILE_NAME}.h")
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${HEADER_FILE}")
        # If the header exists, include it in the executable
        add_executable(${FILE_NAME} ${SOURCE} ${HEADER_FILE})
    else()
        # If no corresponding header, just add the source file
        add_executable(${TARGET_NAME} ${SOURCE})
    endif()

    # Link libraries here if needed
    # target_link_libraries(${FILE_NAME} ...)
endforeach()