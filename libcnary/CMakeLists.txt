file(GLOB INCLUDE_FILES "include/*.h")
file(GLOB SRC_FILES "*.c")

source_group(include FILES ${INCLUDE_FILES})
source_group(src FILES ${SRC_FILES})

add_library(libcnary ${INCLUDE_FILES} ${SRC_FILES})
target_include_directories(libcnary PUBLIC include)

if(WIN32)
  set(CMAKE_MFC_FLAG 2)
  target_compile_definitions(libcnary PUBLIC -D_AFXDLL -D_UNICODE)
endif()
