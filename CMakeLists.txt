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

# add g2o
include_directories(${PROJECT_SOURCE_DIR}/ext/g2o/include)
link_directories(${PROJECT_SOURCE_DIR}/ext/g2o/lib)
set(G2O_LIBS g2o_cli g2o_core g2o_csparse_extension 
	g2o_ext_freeglut_minimal g2o_interface 
	g2o_opengl_helper g2o_parser g2o_simulator g2o_solver_csparse 
	g2o_solver_dense g2o_solver_eigen g2o_solver_pcg g2o_solver_slam2d_linear 
	g2o_solver_structure_only g2o_stuff g2o_tutorial_slam2d g2o_types_data 
	g2o_types_icp g2o_types_sba g2o_types_sclam2d g2o_types_sim3 
	g2o_types_slam2d g2o_types_slam2d_addons g2o_types_slam3d g2o_types_slam3d_addons) 

# set libraries
set(NDLIB_LIBS ${OpenCV_LIBS} ${G2O_LIBS})

# add subfolders
add_subdirectory(examples)

set(CMAKE_CXX_FLAGS "-Ofast")
set(CMAKE_BUILD_TYPE Release)