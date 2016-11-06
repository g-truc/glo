cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
cmake_policy(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(NAME glo)

project(${NAME})

include_directories(external)
include_directories(external/glm)
include_directories(external/gli)
include_directories(base)

find_library(VULKAN_LIB NAMES vulkan-1 vulkan PATHS ${CMAKE_SOURCE_DIR}/libs/vulkan)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_WIN32_KHR")

message(STATUS ${VULKAN_LIB})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNOMINMAX -D_USE_MATH_DEFINES")

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

function(buildExample EXAMPLE_NAME)
	file(GLOB SOURCE *.cpp base/*.cpp *.hpp base/*.hpp ${EXAMPLE_NAME}/*.cpp)
	add_executable(${EXAMPLE_NAME} WIN32 samples/${EXAMPLE_NAME}.cpp ${SOURCE})
	target_link_libraries(${EXAMPLE_NAME} glo ${VULKAN_LIB} ${WINLIBS})
	add_dependencies(${EXAMPLE_NAME} glo)
endfunction(buildExample)

function(buildExamples)
	foreach(EXAMPLE ${EXAMPLES})
		buildExample(${EXAMPLE})
	endforeach(EXAMPLE)
endfunction(buildExamples)

option(IN_SOURCE_BUILD "IN_SOURCE_BUILD" OFF)
if(OGL_SAMPLES_IN_SOURCE_BUILD)
	add_definitions(-DSOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
	add_definitions(-DBINARY_DIR="../")
else()
	add_definitions(-DSOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
	add_definitions(-DBINARY_DIR="${CMAKE_CURRENT_BINARY_DIR}")
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

set(EXAMPLES texture triangle)

buildExamples()

add_subdirectory(gl/source)

