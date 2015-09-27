project (ndsensor)

set (${PROJECT_NAME}_SOURCE camera_interface.cpp webcam.cpp)

add_library (${PROJECT_NAME} ${${PROJECT_NAME}_SOURCE})
