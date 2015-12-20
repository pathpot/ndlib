project (hello_world)

# add project files
file(GLOB ${PROJECT_NAME}_SOURCE_FILES 	"${PROJECT_SOURCE_DIR}/src/*.cpp" 
										"${PROJECT_SOURCE_DIR}/src/*/*.cpp")

# add executable
add_executable(${PROJECT_NAME} 	${${PROJECT_NAME}_SOURCE_FILES})
