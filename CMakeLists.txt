cmake_minimum_required (VERSION 2.8)
project (ndlib)

# the version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# add eigen
include_directories(${PROJECT_SOURCE_DIR}/ext/Eigen/include)

# add opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# set source files
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB NDLIB_SOURCE_FILES 	"${PROJECT_SOURCE_DIR}/src/*.cpp" 
								"${PROJECT_SOURCE_DIR}/src/*/*.cpp")

# set libraries
set(NDLIB_LIBS ${OpenCV_LIBS})

# add subfolders
add_subdirectory(examples)

set(CMAKE_CXX_FLAGS "-Ofast")
set(CMAKE_BUILD_TYPE Release)