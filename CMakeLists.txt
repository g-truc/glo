cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
cmake_policy(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(NAME glo)

project(${NAME})

include_directories(external)
include_directories(external/glm)
include_directories(external/gli)
include_directories(external/cityhash)

find_library(VULKAN_LIB NAMES vulkan-1 vulkan PATHS ${CMAKE_SOURCE_DIR}/external/vulkan)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNOMINMAX -D_USE_MATH_DEFINES -DVK_USE_PLATFORM_WIN32_KHR /EHsc")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

function(glCreateSampleGTC EXAMPLE_NAME)
	file(GLOB SOURCE samples/base/*.cpp samples/base/*.hpp)
	add_executable(${EXAMPLE_NAME} WIN32 samples/${EXAMPLE_NAME}.cpp ${SOURCE})
	target_link_libraries(${EXAMPLE_NAME} glo ${VULKAN_LIB} ${WINLIBS})
	add_dependencies(${EXAMPLE_NAME} glo)
endfunction(glCreateSampleGTC)

option(IN_SOURCE_BUILD "IN_SOURCE_BUILD" OFF)
if(OGL_SAMPLES_IN_SOURCE_BUILD)
	add_definitions(-DSOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
	add_definitions(-DBINARY_DIR="../")
else()
	add_definitions(-DSOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
	add_definitions(-DBINARY_DIR="${CMAKE_CURRENT_BINARY_DIR}")
endif()

glCreateSampleGTC(gl-450-draw)
glCreateSampleGTC(gl-500-draw)

add_subdirectory(gl/source)

