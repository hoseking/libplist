cmake_minimum_required(VERSION 3.0.2)

file(GLOB INCLUDE_FILES "include/plist/*.h")
file(GLOB SRC_FILES "src/*.h" "src/*.c" "src/*.cpp")

source_group(include FILES ${INCLUDE_FILES})
source_group(src FILES ${SRC_FILES})

add_library(libplist SHARED ${INCLUDE_FILES} ${SRC_FILES})
target_include_directories(libplist PUBLIC "include" "src" "vendor/include")

if(WIN32)
  set(CMAKE_MFC_FLAG 2)
  target_compile_definitions(libplist PUBLIC -D_AFXDLL -D_UNICODE -DHAVE_CONFIG_H)
endif()
target_compile_definitions(libplist PUBLIC -Dlibplist_DLL -Dlibplist_DLL_EXPORTS)

add_subdirectory(libcnary)
find_library(libxml2_LIBRARY NAMES libxml2 PATHS "vendor/lib")

target_link_libraries(libplist libcnary ${libxml2_LIBRARY})
