cmake_minimum_required(VERSION 3.13)

# set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# add_compile_definitions(_ENABLE_EXTENDED_ALIGNED_STORAGE )


project(Amber)

set (CMAKE_CXX_STANDARD 20)

SET ( AMBER_SOURCE
    src/main.cpp

)

set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_SOURCE_DIR}/deps/eigen ${CMAKE_BINARY_DIR}/eigen)

# SOURCE_GROUP (core REGULAR_EXPRESSION src/core/.*)


ADD_EXECUTABLE(AmberRenderer src/main/main.cpp)
target_include_directories(AmberRenderer PUBLIC ${CMAKE_SOURCE_DIR}/deps/eigen/)
set_target_properties(AmberRenderer PROPERTIES CXX_STANDARD 20)
# INSTALL (TARGETS
#     Amber
# )

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT AmberRenderer)
