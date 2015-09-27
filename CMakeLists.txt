cmake_minimum_required (VERSION 2.6)
project (ndlib)

# the version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# find dependency package
find_package(OpenCV REQUIRED)

# add subfolders
add_subdirectory(modules)
add_subdirectory(examples)
