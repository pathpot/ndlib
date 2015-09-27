project (webcam)

set(${PROJECT_NAME}_SOURCE webcam.cpp)

# add subfolders
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCE})

# add dependencies
target_link_libraries (${PROJECT_NAME} ndutils)
