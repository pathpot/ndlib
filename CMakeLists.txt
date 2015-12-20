cmake_minimum_required (VERSION 2.8)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project (ndlib)

# the version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# set output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# set build options
set(CMAKE_CXX_FLAGS "-Ofast")
set(CMAKE_BUILD_TYPE Release)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

# include eigen
include_directories(${PROJECT_SOURCE_DIR}/ext/Eigen/include)

# include opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
list(APPEND NDLIB_LIBS ${OpenCV_LIBS})

# include g2o
include_directories(${PROJECT_SOURCE_DIR}/ext/g2o)
file(GLOB G2O_SOURCE_FILES 	"${PROJECT_SOURCE_DIR}/ext/g2o/*.cpp"
							"${PROJECT_SOURCE_DIR}/ext/g2o/*/*.cpp"
							"${PROJECT_SOURCE_DIR}/ext/g2o/*/*/*.cpp"
							"${PROJECT_SOURCE_DIR}/ext/g2o/*/*/*/*.cpp" )
add_library(g2o ${G2O_SOURCE_FILES})
link_libraries(g2o)

# include csparse
include_directories(${PROJECT_SOURCE_DIR}/ext/csparse)
file(GLOB CSPARSE_SOURCE_FILES 	"${PROJECT_SOURCE_DIR}/ext/csparse/*.c")
add_library(csparse ${CSPARSE_SOURCE_FILES})
link_libraries(csparse)

# set source files
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB NDLIB_SOURCE_FILES 	"${PROJECT_SOURCE_DIR}/src/*.cpp" 
								"${PROJECT_SOURCE_DIR}/src/*/*.cpp")

# add core library of ndlib
add_library(ndlib ${NDLIB_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${NDLIB_LIBS})
link_libraries(ndlib)

# add subfolders
add_subdirectory(examples)