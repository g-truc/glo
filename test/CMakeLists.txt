set(NAME glo-test)

file(GLOB ROOT_SOURCE *.cpp)
file(GLOB ROOT_INLINE *.inl)
file(GLOB ROOT_HEADER *.hpp)

source_group("Header Files" FILES ${ROOT_HEADER})
source_group("Inline Files" FILES ${ROOT_INLINE})
source_group("Source Files" FILES ${ROOT_SOURCE})

include_directories(..)

add_executable(${NAME}
	${ROOT_SOURCE} 
	${ROOT_INLINE} 
	${ROOT_HEADER})
