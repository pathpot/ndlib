project (webcam_sample)

set(${PROJECT_NAME}_SOURCE webcam_sample.cpp)

# add subfolders
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCE})

# add dependencies
target_link_libraries (${PROJECT_NAME} ndsensor)
target_link_libraries (${PROJECT_NAME} ndutils)
target_link_libraries (${PROJECT_NAME} ndcommon)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})