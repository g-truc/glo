file(GLOB_RECURSE GL_PUBLIC ../*.h)
file(GLOB_RECURSE GL_SOURCE *.cpp)
file(GLOB_RECURSE GL_INLINE *.inl)
file(GLOB_RECURSE GL_HEADER *.hpp)

source_group("Public Files" FILES ${GL_PUBLIC})
source_group("Source Files" FILES ${GL_SOURCE})
source_group("Inline Files" FILES ${GL_INLINE})
source_group("Header Files" FILES ${GL_HEADER})

add_library(glo STATIC ${GL_PUBLIC} ${GL_SOURCE} ${GL_INLINE} ${GL_HEADER})
