cmake_minimum_required(VERSION 3.13)

# set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# add_compile_definitions(_ENABLE_EXTENDED_ALIGNED_STORAGE )


project(Amber)

set (CMAKE_CXX_STANDARD 20)

SET ( AMBER_CORE_SOURCE
    src/core/camera.cpp
)

SET ( AMBER_CORE_HEADERS
    src/core/transform.h
    src/core/amber.h
    src/core/camera.h
)

FILE ( GLOB AMBER_SOURCE
    src/shapes/*
    src/core/*
)

set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(EIGEN_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(EIGEN_BUILD_BTL OFF CACHE BOOL "" FORCE)
# add_subdirectory(${CMAKE_SOURCE_DIR}/deps/eigen ${CMAKE_BINARY_DIR}/eigen)


# find_package(Eigen3)

ADD_LIBRARY (Amber STATIC
    # ${AMBER_CORE_HEADERS}
    # ${AMBER_CORE_SOURCE}
    ${AMBER_SOURCE}
)

INCLUDE_DIRECTORIES(deps/eigen/src)
INCLUDE_DIRECTORIES(deps/eigen)
# INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})

SOURCE_GROUP (core REGULAR_EXPRESSION src/core/.*)
SOURCE_GROUP (shapes REGULAR_EXPRESSION src/shapes/.*)

INCLUDE_DIRECTORIES ( src )
INCLUDE_DIRECTORIES ( src/core )

ADD_EXECUTABLE(AmberRenderer src/main.cpp)

# target_include_directories(AmberRenderer PUBLIC ${CMAKE_SOURCE_DIR}/deps/eigen/)

target_link_libraries(AmberRenderer Amber)
# set_target_properties(AmberRenderer PROPERTIES CXX_STANDARD 17)
# INSTALL (TARGETS
#     Amber
# )

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT AmberRenderer)
