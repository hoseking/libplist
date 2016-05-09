cmake_minimum_required(VERSION 3.0.2)

file(GLOB INCLUDE_FILES "include/plist/*.h")
file(GLOB SRC_FILES "src/*.h" "src/*.c" "src/*.cpp")

source_group(include FILES ${INCLUDE_FILES})
source_group(src FILES ${SRC_FILES})

add_library(libplist SHARED ${INCLUDE_FILES} ${SRC_FILES})
target_include_directories(libplist PUBLIC "include" "src" "../libxml2/include")
target_compile_definitions(libplist PUBLIC -Dlibplist_DLL -Dlibplist_DLL_EXPORTS)

if(WIN32)
  set(CMAKE_MFC_FLAG 2)
  target_compile_definitions(libplist PUBLIC -D_AFXDLL -D_UNICODE -DHAVE_CONFIG_H)
  find_library(libxml2_LIBRARY NAMES libxml2.lib PATHS "../libxml2/win32/bin.msvc")
  target_link_libraries(libplist ${libxml2_LIBRARY})
endif()

add_subdirectory(libcnary)
target_link_libraries(libplist libcnary)
