cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
cmake_policy(VERSION 2.6)

project(glo)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

#add_definitions(-mfpmath=sse)
#add_definitions(-msse3)
#add_definitions(-Wextra)

set(GLO_NAME glo)

file(GLOB ROOT_FILES glo/*.cpp glo/*.inl glo/*.hpp)
file(GLOB CORE_FILES glo/core/*.cpp glo/core/*.inl glo/core/*.hpp glo/core/*.h)
file(GLOB COMP_FILES glo/compatibility/*.cpp glo/compatibility/*.inl glo/compatibility/*.hpp glo/compatibility/*.h)

source_group("Root Files" FILES ${ROOT_FILES})
source_group("Core Files" FILES ${CORE_FILES})
source_group("Compatibility Files" FILES ${COMP_FILES})

include_directories(..)

add_executable(${GLO_NAME} ${ROOT_FILES} ${CORE_FILES} ${COMP_FILES})

target_link_libraries(${GLO_NAME} OpenGL32.lib)

add_subdirectory(test)

