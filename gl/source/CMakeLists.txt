file(GLOB_RECURSE GLO_PUBLIC ../*.h)
file(GLOB_RECURSE GL_SOURCE ./gl/*.cpp)
file(GLOB_RECURSE GL_INLINE ./gl/*.inl)
file(GLOB_RECURSE GL_HEADER ./gl/*.hpp)
file(GLOB_RECURSE GL5_SOURCE ./gl5/*.cpp)
file(GLOB_RECURSE GL5_INLINE ./gl5/*.inl)
file(GLOB_RECURSE GL5_HEADER ./gl5/*.hpp)
file(GLOB_RECURSE WGL_SOURCE ./wgl/*.cpp)
file(GLOB_RECURSE WGL_INLINE ./wgl/*.inl)
file(GLOB_RECURSE WGL_HEADER ./wgl/*.hpp)
file(GLOB_RECURSE CORE_SOURCE ./core/*.cpp)
file(GLOB_RECURSE CORE_INLINE ./core/*.inl)
file(GLOB_RECURSE CORE_HEADER ./core/*.hpp)

source_group("Public Files" FILES ${GLO_PUBLIC})
source_group("WGL Files" FILES ${WGL_SOURCE} ${WGL_INLINE} ${WGL_HEADER})
source_group("GL Files" FILES ${GL_SOURCE} ${GL_INLINE} ${GL_HEADER})
source_group("GL5 Files" FILES ${GL5_SOURCE} ${GL5_INLINE} ${GL5_HEADER})
source_group("Core Files" FILES ${CORE_SOURCE} ${CORE_INLINE} ${CORE_HEADER})

add_library(glo STATIC
	${GLO_PUBLIC}
	${GL_SOURCE} ${GL_INLINE} ${GL_HEADER}
	${GL5_SOURCE} ${GL5_INLINE} ${GL5_HEADER}
	${WGL_SOURCE} ${WGL_INLINE} ${WGL_HEADER}
	${CORE_SOURCE} ${CORE_INLINE} ${CORE_HEADER})
