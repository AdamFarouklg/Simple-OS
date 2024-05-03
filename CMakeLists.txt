cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Set include directories
include_directories(include)

# Set source files
file(GLOB SOURCES src/*.c)
set(SOURCE_FILES ${SOURCES})

# Set object files directory
set(OBJ_DIR obj)

# Set compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")

# Add executable for mem
add_executable(mem ${SOURCE_FILES} ${OBJ_DIR}/paging.o ${OBJ_DIR}/mem.o ${OBJ_DIR}/cpu.o ${OBJ_DIR}/loader.o ${OBJ_DIR}/cpu-tlb.o ${OBJ_DIR}/cpu-tlbcache.o)
target_link_libraries(mem pthread)

# Add executable for sched
add_executable(sched ${SOURCE_FILES} ${OBJ_DIR}/cpu.o ${OBJ_DIR}/loader.o)
target_link_libraries(sched pthread)

# Add executable for os
add_executable(os ${SOURCE_FILES} ${OBJ_DIR}/cpu.o ${OBJ_DIR}/cpu-tlb.o ${OBJ_DIR}/cpu-tlbcache.o ${OBJ_DIR}/mem.o ${OBJ_DIR}/loader.o ${OBJ_DIR}/queue.o ${OBJ_DIR}/os.o ${OBJ_DIR}/sched.o ${OBJ_DIR}/timer.o ${OBJ_DIR}/mm-vm.o ${OBJ_DIR}/mm.o ${OBJ_DIR}/mm-memphy.o)
target_link_libraries(os pthread)

# Create directory for object files
file(MAKE_DIRECTORY ${OBJ_DIR})

# Compile source files to object files
foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
    add_custom_command(
        OUTPUT ${OBJ_DIR}/${FILE_NAME}.o
        COMMAND ${CMAKE_C_COMPILER} ${CMAKE_C_FLAGS} -c ${SOURCE_FILE} -o ${OBJ_DIR}/${FILE_NAME}.o
        DEPENDS ${SOURCE_FILE}
    )
    set(OBJ_FILES ${OBJ_FILES} ${OBJ_DIR}/${FILE_NAME}.o)
endforeach()

# Add a custom target to compile all object files
add_custom_target(obj DEPENDS ${OBJ_FILES})

# Add custom target for cleaning
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${OBJ_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove os sched mem
)