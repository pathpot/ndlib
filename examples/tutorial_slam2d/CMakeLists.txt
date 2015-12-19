project (tutorial_slam2d)

# add project files
file(GLOB ${PROJECT_NAME}_SOURCE_FILES 	"${PROJECT_SOURCE_DIR}/src/*.cpp" 
										"${PROJECT_SOURCE_DIR}/src/*/*.cpp")

# add executable
add_executable(${PROJECT_NAME} 	${${PROJECT_NAME}_SOURCE_FILES} 
								${NDLIB_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${NDLIB_LIBS})