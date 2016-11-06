file(GLOB_RECURSE GLO_PUBLIC ../*.h)
file(GLOB_RECURSE GLL_SOURCE ./gll/*.cpp)
file(GLOB_RECURSE GLL_INLINE ./gll/*.inl)
file(GLOB_RECURSE GLL_HEADER ./gll/*.hpp)
file(GLOB_RECURSE GL5_SOURCE ./gl5/*.cpp)
file(GLOB_RECURSE GL5_INLINE ./gl5/*.inl)
file(GLOB_RECURSE GL5_HEADER ./gl5/*.hpp)
file(GLOB_RECURSE WGL_SOURCE ./wgl/*.cpp)
file(GLOB_RECURSE WGL_INLINE ./wgl/*.inl)
file(GLOB_RECURSE WGL_HEADER ./wgl/*.hpp)
file(GLOB_RECURSE GLO_SOURCE ./glo/*.cpp)
file(GLOB_RECURSE GLO_INLINE ./glo/*.inl)
file(GLOB_RECURSE GLO_HEADER ./glo/*.hpp)

source_group("Public Files" FILES ${GLO_PUBLIC})
source_group("WGL Files" FILES ${WGL_SOURCE} ${WGL_INLINE} ${WGL_HEADER})
source_group("GLL Files" FILES ${GLL_SOURCE} ${GLL_INLINE} ${GLL_HEADER})
source_group("GL5 Files" FILES ${GL5_SOURCE} ${GL5_INLINE} ${GL5_HEADER})
source_group("GLO Files" FILES ${GLO_SOURCE} ${GLO_INLINE} ${GLO_HEADER})

add_library(glo STATIC
	${GLO_PUBLIC}
	${GLL_SOURCE} ${GLL_INLINE} ${GLL_HEADER}
	${GL5_SOURCE} ${GL5_INLINE} ${GL5_HEADER}
	${WGL_SOURCE} ${WGL_INLINE} ${WGL_HEADER}
	${GLO_SOURCE} ${GLO_INLINE} ${GLO_HEADER})
